# modules/module_a/BUILD


# modules/module_a/BUILD

cc_library(
    name = "module_a",
    srcs = ["a.cc"],
    hdrs = ["a.h"],
    deps = [
        "//third_party/libmath:math_lib",  # 依赖 cc_import
    ],
    
    # 可选：显式添加 includes（通常不需要，cc_import 会传播）
    # includes = ["../third_party/libmath"],

    includes = ["."],
    visibility = ["//visibility:public"],
)