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

# 运行服务

# 构建应用
bazel build //app:calculator-app

# 运行（Bazel 会自动处理 data 依赖）
bazel run //app:calculator-app