package(
    default_visibility = [
        "//visibility:public",
    ],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "val",
    hdrs = glob(["*.h"]),
    srcs = glob(
        ["*.cc"],
        exclude = ["value_test.cc"],
    ),
    copts = ["-std=c++14"],
)

cc_test(
    name = "val_test",
    srcs = ["value_test.cc"],
    deps = [
        ":val",
        "@xunit_cctest//cctest:main",
    ],
    copts = ["-std=c++14"],
)
