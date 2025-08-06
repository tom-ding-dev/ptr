# BUILD FIRST VERSION

# # BUILD
# # 声明一个 C++ 可执行目标
# cc_binary(
#     name = "calculator-app",
#     srcs = [
#         "main.cpp",
#         "src/Calculator.cpp",
#     ],
#     hdrs = [
#         "include/Calculator.hpp",
#     ],
#     # 指定头文件包含路径
#     # copts = ["-Iinclude"],
#     # 可选：指定 C++ 标准
#     copts = ["-Iinclude", "-std=c++17"],
# )

# BUILD SECOND VERSION

# BUILD

# # 1. 定义一个 C++ 库，包含头文件和实现
# cc_library(
#     name = "calculator_lib",
#     srcs = ["src/Calculator.cpp"],
#     hdrs = ["include/Calculator.hpp"],
#     copts = ["-Iinclude"],
#     # 允许 main 程序依赖这个库
#     visibility = ["//visibility:public"],
# )

# # 2. 定义可执行文件，依赖上面的库
# cc_binary(
#     name = "calculator-app",
#     srcs = ["main.cpp"],
#     deps = [":calculator_lib"],  # 依赖 calculator_lib
# )


# BUILD

cc_library(
    name = "calculator_lib",
    srcs = ["src/Calculator.cpp"],
    hdrs = ["include/Calculator.hpp"],
    # ✅ 关键：告诉 Bazel 头文件的根目录是 `include`
    includes = ["include"],
    # 可选：如果你用了 C++17
    copts = ["-std=c++17"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "calculator-app",
    srcs = ["main.cpp"],
    deps = [":calculator_lib"],  # 依赖库
)