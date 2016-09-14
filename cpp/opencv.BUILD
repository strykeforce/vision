cc_library(
    name = "lib",
    srcs = glob(["lib/*.dylib"]) + glob(["lib/*.so*"]),
    hdrs = glob(["include/**/*.hpp"]),
    includes = ["include"],
    visibility = ["//visibility:public"],
    linkstatic = 1,
)
