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

# Mark

# Stage 1

https://bazel.google.cn/versions/7.4.0/start/cpp

This showcases how to build a single file to create a runnable application.

This BUILD file shows that we want to build a C++ binary using the ```cc_binary``` rule provided by Bazel.
In the ```cc_binary``` rule, name of the binary is specified in ```name``` attribute (in this example, it's ```hello-world```), required source files to be built are provided in ```srcs``` attribute.

```
cc_binary(
    name = "hello-world",
    srcs = ["hello-world.cc"],
)
```

To build this example, use
```
bazel build //main:hello-world
```

If the build is successful, Bazel prints the output similar to
```
____Loading complete.  Analyzing...
____Found 1 target...
____Building...
Target //main:hello-world up-to-date:
  C:/tools/msys64/tmp/_bazel_woden/vqeu6v3v/execroot/__main__/bazel-out/msvc_x64-fastbuild/bin/main/hello-world.exe
____Elapsed time: 0,400s, Critical Path: 0,01s
```

In the run log above you can see where the executable was built so you can locate it and use it.

You can also get the output path with the bazel cquery command. For
example, the command below would print the path to the output file. This
is a useful technique for use in scripts, where you do not want to parse the
`bazel build` output.

```
bazel cquery --output=files //main:hello-world
```

# 项目为什么会变得很复杂

很高兴你想深入学习 Bazel 构建现代 C++ 项目！下面为你梳理学习路径和项目复杂化的原因与方式：

一、为什么项目会变复杂？

代码量增加：功能增多，模块/库数量上升。
依赖管理：需要集成第三方库（如 abseil、gRPC、protobuf 等）。
多平台/多配置：支持不同操作系统、编译选项、测试环境。
代码复用与分层：引入静态库、动态库、接口分离、单元测试等。
构建优化：增量构建、缓存、分布式构建等。
二、如何用 Bazel 构建更复杂的现代 C++ 项目？

基础入门

了解 cc_binary、cc_library、cc_test 规则。
学会用 BUILD 文件组织源代码和目标。
项目结构演进

单一可执行文件 → 多个库（cc_library）+ 多个可执行文件（cc_binary）。
目录分层：src/、include/、tests/、third_party/ 等。
依赖管理

使用 Bazel 的外部依赖（bazel_dep、http_archive、git_repository）。
集成第三方 C++ 库（如 abseil、gtest）。
现代 C++ 特性

C++17/20 标准支持：在 BUILD 文件中设置 copts = ["-std=c++17"]。
使用智能指针、lambda、模板、并发等现代特性。
测试与持续集成

添加 cc_test 目标，编写单元测试。
配置 CI 工具自动运行 bazel test。
进阶特性

多平台支持（select()、config_setting）。
代码生成（如 protobuf、gRPC）。
性能分析与构建优化。
三、推荐实践步骤

从一个 hello world 项目起步，理解 BUILD 文件和 Bazel 基本命令。
拆分功能为多个 cc_library，主程序依赖这些库。
添加单元测试（cc_test）。
引入第三方库（如 abseil、gtest），并在 Bazel 中声明依赖。
逐步引入更复杂的构建需求（如多平台、代码生成等）。
如果你需要具体的项目模板、示例代码或某一步的详细指导，请告诉我你的需求，我可以帮你一步步搭建和讲解！