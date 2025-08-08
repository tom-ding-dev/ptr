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
    ],
    hdrs = [
        "include/mylib/person.h",
        "include/mylib/student.h",
        "include/mylib/utils.h",
    ],
    includes = ["include"],
    visibility = ["//visibility:public"],
    deps = ["@jsoncpp//:jsoncpp"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":person_lib", "@jsoncpp//:jsoncpp"],
)
