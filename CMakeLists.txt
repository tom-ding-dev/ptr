# CMakeLists.txt
cmake_minimum_required(VERSION 3.14)

# 项目名称和版本
project(MyCalculatorProject VERSION 1.0 LANGUAGES CXX)

# 设置 C++ 标准（C++17）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加头文件搜索路径（include 目录）
include_directories(include)

# 定义可执行文件，包含 main.cpp 和 src/Calculator.cpp
add_executable(calculator-app
    main.cpp
    src/Calculator.cpp
)

# 可选：为大型项目，推荐使用 target_include_directories
# target_include_directories(calculator-app PRIVATE include)