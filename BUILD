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


# BUILD THIRD VERSION

# cc_library(
#     name = "calculator_lib",
#     srcs = ["src/Calculator.cpp"],
#     hdrs = ["include/Calculator.hpp"],
#     # ✅ 关键：告诉 Bazel 头文件的根目录是 `include`
#     includes = ["include"],
#     # 可选：如果你用了 C++17
#     copts = ["-std=c++17"],
#     visibility = ["//visibility:public"],
# )

# cc_binary(
#     name = "calculator-app",
#     srcs = ["main.cpp"],
#     deps = [":calculator_lib"],  # 依赖库
# )


# BUILD - 构建动态库 错误的构建动态库方式

# # 1. 构建动态库（Shared Library）
# cc_binary(
#     name = "libcalculator.so",  # Linux/macOS 下动态库扩展名为 .so
#     srcs = ["src/Calculator.cpp"],
#     hdrs = ["include/Calculator.hpp"],
#     # ✅ 关键：设置 linkshared=True 生成动态库
#     linkshared = True,
#     # 头文件搜索路径
#     includes = ["include"],
#     # C++ 标准
#     copts = ["-std=c++17"],
#     # 公开可见
#     visibility = ["//visibility:public"],
# )

# # 2. 主程序，链接动态库
# cc_binary(
#     name = "calculator-app",
#     srcs = ["main.cpp"],
#     # 依赖动态库
#     deps = [":libcalculator.so"],
#     # 确保运行时能找到动态库（Bazel 会自动处理）
#     linkstatic = False,  # 可选：明确使用动态链接
# )


# BUILD

# 1. 用 cc_library 管理头文件和实现（不生成独立库）
cc_library(
    name = "calculator",
    srcs = ["src/Calculator.cpp"],
    hdrs = ["include/Calculator.hpp"],
    includes = ["include"],
    copts = ["-std=c++17"],
    visibility = ["//visibility:public"],
)

# 2. 用 cc_binary 生成动态库（.so），依赖上面的 cc_library
cc_binary(
    name = "libcalculator.so",  # 输出文件名
    deps = [":calculator"],     # 依赖 cc_library
    linkshared = True,          # ✅ 关键：生成共享库
)

# 直接使用 cc_library

# cc_binary(
#     name = "calculator-app",
#     srcs = ["main.cpp"],
#     deps = [":calculator"],  # 直接依赖 cc_library
# )

# error use

# cc_binary(
#     name = "calculator-app",
#     srcs = ["main.cpp"],
#     # 依赖动态库
#     deps = [":libcalculator.so"],
#     # 确保运行时能找到动态库（Bazel 会自动处理）
#     linkstatic = False,  # 可选：明确使用动态链接
# )