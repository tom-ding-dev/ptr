
cc_binary(
    name = "modern_app",
    srcs = ["main.cpp"],
    deps = ["//lib/core:greeter"],
)


cc_binary(
    name = "server",
    srcs = ["server.cpp"],
    deps = ["//third_party:cppzmq"],

)


cc_binary(
    name = "client",
    srcs = ["client.cpp"],
    deps = ["//third_party:cppzmq"],

)
