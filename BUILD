cc_binary(
    name = "http_server",
    srcs = ["http_server.cpp"],
    deps = ["//third_party/cpp-httplib:httplib"],
)

cc_binary(
    name = "http_client",
    srcs = ["http_client.cpp"],
    deps = ["//third_party/cpp-httplib:httplib"],
)
# load("@com_google_googletest//:gtest.bzl", "gtest_binary")

# gtest_binary(
#     name = "unit_tests",
#     srcs = ["tests/test_main.cpp"],
#     deps = [":person_lib"],
#     visibility = ["//visibility:public"],
# )

cc_library(
    name = "person_lib",
    srcs = [
        "src/person.cpp",
        "src/student.cpp",
        "src/json_utils.cpp"
    ],
    hdrs = [
        "include/mylib/person.h",
        "include/mylib/student.h",
        "include/mylib/utils.h",
        "include/mylib/json_utils.h",
    ],
    includes = ["include"],
    visibility = ["//visibility:public"],
    deps = ["//third_party/jsoncpp:jsoncpp"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":person_lib", "//third_party/jsoncpp:jsoncpp"],
)
