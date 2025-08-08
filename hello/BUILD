cc_library(
    name = "greet",
    srcs = ["greet.cc"],
    hdrs = ["greet.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "time_util",
    srcs = ["time_util.cc"],
    hdrs = ["time_util.h"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "hello",
    srcs = ["hello.cc"],
    deps = [":greet", ":time_util"],
)
