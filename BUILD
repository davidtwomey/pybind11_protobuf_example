load("@com_github_grpc_grpc//bazel:python_rules.bzl", "py_proto_library")
load("@pybind11_bazel//:build_defs.bzl", "pybind_extension")


proto_library(
    name = "example_proto",
    srcs = ["example.proto"],
)

py_proto_library(
    name = "example_py_pb2",
    deps = [":example_proto"],
)

cc_proto_library(
    name = "example_cc_proto",
    deps = [":example_proto"],
)

# tests for wrapped_proto_caster
pybind_extension(
    name = "my_extension",
    srcs = ["my_extension.cc"],
    deps = [
        ":example_cc_proto",
        "@pybind11_protobuf//pybind11_protobuf:wrapped_proto_caster",
        "@pybind11_protobuf//pybind11_protobuf:native_proto_caster",
        "@com_google_protobuf//:protobuf",
    ],
)

py_binary(
    name = "example",
    srcs = ["example.py"],
    python_version = "PY3",
    deps = [
        ":example_py_pb2",
    ],
        data = [
        ":my_extension.so",
    ],
)