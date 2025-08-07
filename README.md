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