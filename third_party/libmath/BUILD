
#  更优雅的方式：使用 cc_library 的 interface_library 和 shared_library
# third_party/libmath/BUILD

# third_party/libmath/BUILD

# cc_library(
#     name = "math_lib",
#     srcs = ["my_math.cc"],
#     hdrs = ["my_math.h"],
#     includes = ["."],  # 允许 #include "my_math.h"
#     visibility = ["//visibility:public"],
# )

# cc_binary(
#     name = "libmath",
#     deps = [":math_lib"],
#     linkshared = True,
#     visibility = ["//visibility:public"],
# )

# cc_import(
#     name = "math",
#     shared_library = ":libmath",
#     hdrs = ["my_math.h"],
    
#     # 关键：设置 includes，让依赖者能 #include
#     includes = ["."],           # ← 必须！

#     # 关键：设置 compatible_with 或 visibility
#     visibility = ["//visibility:public"],
# )


cc_library(
    name = "math_lib",
    srcs = ["my_math.cc"],
    hdrs = ["my_math.h"],
    includes = ["."],  # 允许 #include "my_math.h"
    linkstatic = False,       # 关键：自动生成和链接 .so
    visibility = ["//visibility:public"],
)