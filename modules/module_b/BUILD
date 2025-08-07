cc_library(
    name = "module_b",
    srcs = ["b.cc"],
    hdrs = ["b.h"],
    deps = [
        "//modules/module_a:module_a",  # 依赖 module_a
    ],
    includes = ["."],
    visibility = ["//visibility:public"],
)