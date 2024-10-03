cc_library(
    name = "hello-greet",
    srcs = ["hello-greet.cc"],
    hdrs = ["hello-greet.h"],
)

cc_library(
    name = "guess-number",
    srcs = ["guess-number.cc"],
    hdrs = ["guess-number.h"],
)

cc_binary(
    name = "hello-world",
    srcs = ["hello-world.cc"],
    deps = [
        ":hello-greet", 
        ":guess-number",
        "//lib:hello-time",     
    ],
)
