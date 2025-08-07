cc_library(
    name = "hello",
    srcs = ["hello.cpp"],
    hdrs = ["include/hello.h"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":hello"],
)

cc_test(
    name = "hello_test",
    srcs = ["hello_test.cpp"],
    deps = [":hello"],
)
