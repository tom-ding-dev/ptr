# ptr

persnoal-technical-records

# CMake 构建方式学习

1. 创建构建目录（推荐 out-of-source 构建）
mkdir build
cd build

2. 生成 Makefile 并配置项目
cmake ..

3. 编译项目
make

4. 运行生成的可执行文件
./myapp

# 原始构建方式

步骤1：编译 src/Calculator.cpp 为对象文件（.o）
g++ -Iinclude -std=c++17 -c src/Calculator.cpp -o Calculator.o

步骤2：编译 main.cpp 为对象文件
g++ -Iinclude -std=c++17 -c main.cpp -o main.o

步骤3：链接两个对象文件，生成可执行文件
g++ Calculator.o main.o -o myapp

# 使用 Bazel 官方安装脚本

Buildifier was not found; linting and formatting of Bazel files will not be available. Please download it from https://github.com/bazelbuild/buildtools/releases and install it on your system PATH or set its location in Settings.

curl -LO "https://github.com/bazelbuild/bazel/releases/download/6.5.0/bazel-6.5.0-installer-linux-x86_64.sh"
chmod +x bazel-6.5.0-installer-linux-x86_64.sh
./bazel-6.5.0-installer-linux-x86_64.sh --user


Bazel is now installed!

Make sure you have "/home/codespace/bin" in your path.

For bash completion, add the following line to your :
  source /home/codespace/.bazel/bin/bazel-complete.bash

For fish shell completion, link this file into your
/home/codespace/.config/fish/completions/ directory:
  ln -s /home/codespace/.bazel/bin/bazel.fish /home/codespace/.config/fish/completions/bazel.fish

See http://bazel.build/docs/getting-started.html to start a new project!

# GPT-4.1 帮助我写代码

现在目录结构是这样的，

```
@tom-ding-dev ➜ /workspaces/ptr/src (bazel-build-learn-deps) $ tree -L 2
.
├── BUILD
├── hello.cpp
├── hello.h
└── main.cpp

1 directory, 4 files
```

BUILD文件内容是这样的

```
cc_library(
    name = "hello",
    srcs = ["hello.cpp"],
    hdrs = ["hello.h"],
)


cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":hello"],
)
```

这样执行：export PATH="$PATH:/home/codespace/bin" && bazel build //src:main 可以通过

# 接下来的尝试，将 hello.h 放到 include 目录下

看起来是废了，

```
项目现在的结构是：

hello.cpp - 包含库实现
hello.h - 头文件
main.cpp - 主程序
hello_test.cpp - 单元测试
BUILD - Bazel 构建配置
这是一个完整的 Bazel C++ 项目示例，展示了：

如何组织代码结构
如何定义和使用库
如何编写和运行测试
如何管理依赖关系
```

# Bazel C++ 工业化项目头文件 include 路径最佳实践

1. 每个库的头文件放在本 package 的 include 子目录下，如：
   - lib/util/include/util/str_utils.h
   - lib/core/include/core/greeter.h
2. BUILD 文件这样写：
   ```python
   cc_library(
       name = "str_utils",
       srcs = ["str_utils.cpp"],
       hdrs = ["include/util/str_utils.h"],
       includes = ["include"],
       visibility = ["//visibility:public"],
   )
   ```
3. 代码中直接：
   ```cpp
   #include "util/str_utils.h"
   #include "core/greeter.h"
   ```
4. 这样 include 路径简洁、跨 package 依赖清晰，且不会出现头文件找不到的问题。

5. 推荐所有库都采用这种结构，避免头文件全局乱放。

6. 如果有第三方依赖，统一放在 third_party/，并用 Bazel 的外部依赖机制管理。

这样你的 include 路径就会非常简洁，项目结构也更易维护。
  

# Bazel + cppzmq C++ 通信项目复现步骤

本项目已集成 ZeroMQ (libzmq) 和 cppzmq，支持用 Bazel 构建现代 C++ 客户端/服务端通信。

## 依赖准备
1. 安装 ZeroMQ 系统开发包：
   ```sh
   sudo apt-get update && sudo apt-get install -y libzmq3-dev
   ```
2. cppzmq 头文件已自动下载到 third_party/cppzmq，无需额外操作。

## Bazel 构建
1. 构建服务端和客户端：
   ```sh
   bazel build //app:server //app:client
   ```
2. 运行服务端（新终端）：
   ```sh
   ./bazel-bin/app/server
   ```
3. 运行客户端（另一个终端）：
   ```sh
   ./bazel-bin/app/client
   ```

## 关键 Bazel 配置说明
- third_party/BUILD 只暴露 cppzmq 头文件，ZeroMQ 用系统包链接（linkopts = ["-lzmq"]）
- app/server.cpp 和 app/client.cpp 为最小可用示例
- 你可以在此基础上扩展更复杂的消息协议和多线程通信

## 参考代码片段
server.cpp:
```cpp
#include <zmq.hpp>
#include <string>
#include <iostream>

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::rep);
    socket.bind("tcp://*:5555");
    while (true) {
        zmq::message_t request;
        socket.recv(request, zmq::recv_flags::none);
        std::cout << "Received: " << request.to_string() << std::endl;
        std::string reply = "World";
        socket.send(zmq::buffer(reply), zmq::send_flags::none);
    }
}
```
client.cpp:
```cpp
#include <zmq.hpp>
#include <string>
#include <iostream>

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, zmq::socket_type::req);
    socket.connect("tcp://localhost:5555");
    std::string msg = "Hello";
    socket.send(zmq::buffer(msg), zmq::send_flags::none);
    zmq::message_t reply;
    socket.recv(reply, zmq::recv_flags::none);
    std::cout << "Received: " << reply.to_string() << std::endl;
}
```

---
如需扩展更复杂的通信模式、自动化测试或集成 CI/CD，可在此基础上继续完善。


# 【进阶】ZeroMQ 动态库（so）与 Bazel 工业化集成与部署

## 步骤一：用 CMake 构建 libzmq.so

```sh
cd third_party/zmq
mkdir build && cd build
cmake .. -DBUILD_SHARED=ON
make -j
# 生成的 libzmq.so 一般在 build/lib 或 build/ 目录下
```

## 步骤二：拷贝 so 和 include 到 third_party
- 将 `build/libzmq.so` 拷贝到 `third_party/zmq/libzmq.so`
- 保留 `third_party/zmq/include` 目录（ZeroMQ 头文件）

## 步骤三：Bazel 配置

third_party/zmq/BUILD:
```python
cc_import(
    name = "zmq_so",
    shared_library = "libzmq.so",
    hdrs = glob(["include/**/*.h", "include/**/*.hpp"]),
    includes = ["include"],
    visibility = ["//visibility:public"],
)
```

third_party/BUILD:
```python
cc_library(
    name = "cppzmq",
    hdrs = glob(["cppzmq/*.hpp"]),
    includes = ["cppzmq"],
    visibility = ["//visibility:public"],
    deps = ["//third_party/zmq:zmq_so"],
)
```

app/BUILD:
```python
cc_binary(
    name = "server",
    srcs = ["server.cpp"],
    deps = ["//third_party:cppzmq"],
    linkopts = ["-Wl,-rpath,$$ORIGIN/../third_party/zmq"],
)
cc_binary(
    name = "client",
    srcs = ["client.cpp"],
    deps = ["//third_party:cppzmq"],
    linkopts = ["-Wl,-rpath,$$ORIGIN/../third_party/zmq"],
)
```

## 步骤四：部署
## 步骤五：自动化打包部署产物（tar.gz）

你可以用如下命令自动构建并打包 server、client 和 libzmq.so 到 tar.gz 文件，方便分发和部署：

```sh
# 1. 构建可执行文件
bazel build //app:server //app:client

# 2. 打包（在项目根目录下）
tar -czvf deploy.tar.gz -C bazel-bin/app server client -C ../../third_party/zmq libzmq.so
```

解压后即可按上文 LD_LIBRARY_PATH 或 rpath 方式运行。


### 方式一：设置 LD_LIBRARY_PATH（推荐灵活部署）
1. 拷贝 `bazel-bin/app/server`、`bazel-bin/app/client` 和 `third_party/zmq/libzmq.so` 到目标环境，保持相对目录结构。
2. 运行时设置环境变量：
   ```sh
   export LD_LIBRARY_PATH=$(pwd)/third_party/zmq:$LD_LIBRARY_PATH
   ./app/server
   # 或一行：
   LD_LIBRARY_PATH=$(pwd)/third_party/zmq ./app/server
   ```

### 方式二：rpath（无需环境变量，已在前文介绍）
1. 构建时在 BUILD 文件 linkopts 设置 rpath，部署时保持相对路径一致即可。

---
两种方式都被工业界广泛采用，可根据实际场景选择。LD_LIBRARY_PATH 更灵活，rpath 更傻瓜。

---
这样即可实现完全自包含、可复现、易部署的现代 C++/Bazel/ZeroMQ 工业化项目！

# 跨平台 C++ 第三方库集成方式

这是工业界最常用、最稳妥的跨平台 C++ 第三方库集成方式



工业界最常用、最稳妥的跨平台 C++ 第三方库集成方式主要有以下几种：

1. 源码集成 + 本地构建（推荐）
将第三方库源码（如 ZeroMQ、glog、protobuf 等）下载到项目的 third_party 目录。
用 CMake、Bazel、Makefile 等主项目构建系统直接编译第三方库，生成 .so 或 .a。
用 Bazel 的 cc_import 或 CMake 的 add_library/target_link_libraries 方式集成。
优点：版本可控、跨平台一致、无需目标环境预装依赖，升级/回滚灵活。
部署：只需分发你的可执行文件和第三方库的 so/a 文件，或静态链接后只分发可执行文件。
2. 静态链接
构建时将第三方库编译为 .a 静态库，主程序静态链接。
优点：最终产物只需一个可执行文件，部署极简。
缺点：可执行文件体积大，升级第三方库需重新编译。
3. 动态链接 + rpath
构建时将第三方库编译为 .so，主程序动态链接，并设置 rpath，如 -Wl,-rpath,$ORIGIN/../third_party/xxx。
优点：可执行文件小，第三方库可独立升级。
缺点：部署时需保证 so 文件和可执行文件的相对路径一致。
4. 包管理器（如 vcpkg、conan、hunter）
用 vcpkg/conan/hunter 等工具自动下载、编译、集成第三方库。
优点：依赖声明简单，自动跨平台。
缺点：有时不如源码集成灵活，部分公司不允许自动联网下载。
5. 系统包依赖（不推荐生产环境）
依赖目标环境的 apt/yum/brew 等包管理器安装第三方库。
优点：开发环境搭建快。
缺点：生产环境不可控，版本不一致，升级/回滚难。
推荐实践
生产环境/跨平台/可复现性要求高：源码集成 + 本地构建（如 Bazel + cc_import + CMake 预编译 so/a）。
部署极简：静态链接。
需灵活升级第三方库：动态链接 + rpath。
团队有统一包管理策略：可用 vcpkg/conan。
总结：
将第三方库源码纳入项目，构建出 so/a 并用 Bazel/CMake 集成，是工业界最稳妥、最可控、最易跨平台的 C++ 第三方库集成方式。

如需具体操作示例或自动化脚本，可继续提问！


# 本次学习与实践总结

## 实践内容回顾

1. 学习并实践了 Bazel C++ 项目结构、头文件 include 路径规范、BUILD 文件写法、模块化组织等工业级最佳实践。
2. 下载并集成了 ZeroMQ 和 cppzmq 到 third_party 目录，掌握了第三方库源码集成与本地构建的工业级方案。
3. 用 CMake 在本地构建 ZeroMQ 的 libzmq.so，并将 so 文件和 include 头文件拷贝到 third_party/zmq。
4. 用 Bazel 的 cc_import 规则将 libzmq.so 集成到 Bazel 构建系统，cppzmq 头文件同样在 third_party/，并用 cc_library 规则实现 C++ 代码对 ZeroMQ 的依赖。
5. 在 app/server 和 app/client 的 BUILD 文件中用 linkopts 设置 rpath，保证运行时自动找到本地 so。
6. 自动化打包 server、client、libzmq.so 到 deploy.zip，实现一键分发和部署。
7. 在 README.md 中详细记录了所有集成、构建、部署步骤和最佳实践，方便后续复现和团队协作。

## 关键知识点总结

- 工业界最稳妥的 C++ 第三方库集成方式是“源码集成 + 本地构建 + cc_import 动态链接/静态链接”，可实现跨平台、可控、可复现。
- rpath 配置可让可执行文件自动找到本地 so，只需保证部署包内的相对路径不变。
- Bazel 的 cc_import 适合集成已编译好的 so/a，源码构建推荐用 CMake 或 Bazel 原生规则。
- 自动化打包和文档沉淀是工程化项目可维护性的关键。

---
如需进一步自动化、CI/CD、跨平台适配或其他 C++ 工程化问题，随时可以继续提问！