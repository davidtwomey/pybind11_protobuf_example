workspace(name = "com_google_pybind11_protobuf")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")


## `pybind11_bazel`
# See https://github.com/pybind/pybind11_bazel
git_repository(
  name = "pybind11_bazel",
  remote = "https://github.com/pybind/pybind11_bazel.git",
  commit = "26973c0ff320cb4b39e45bc3e4297b82bc3a6c09",
)

# We still require the pybind library.
# new_git_repository(
#   name = "pybind11",
#   build_file = "@pybind11_bazel//:pybind11.BUILD",
#   remote = "https://github.com/pybind/pybind11.git",
#   tag = "v2.7.1",
# )
new_git_repository(
    name = "pybind11",
    build_file = "@pybind11_bazel//:pybind11.BUILD",
    remote = "https://github.com/pybind/pybind11.git",
    commit = "6bce3bd72e8d0838cdb1586abd6d3cfb9c598a8f",
)



load("@pybind11_bazel//:python_configure.bzl", "python_configure")
python_configure(name = "local_config_python")

# proto_library, cc_proto_library, and java_proto_library rules implicitly
# depend on @com_google_protobuf for protoc and proto runtimes.
# This statement defines the @com_google_protobuf repo.
git_repository(
    name = "com_google_protobuf",
    remote = "https://github.com/protocolbuffers/protobuf.git",
    tag = "v3.18.0-rc1",
    patches = ["com_google_protobuf_build.patch"],
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()

# GRPC v1.38, for proto rules.
# For a related discussion of the pro/cons of various open-source py proto rule
# repositories, see b/189457935.
git_repository(
    name = "com_github_grpc_grpc",
    remote = "https://github.com/grpc/grpc.git",
    tag = "v1.38.0",
)
load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()

bind(
    name = "python_headers",
    actual = "@local_config_python//:python_headers",
)

git_repository(
    name = "pybind11_protobuf",
    commit = "921a68428f6a24b2623063a1a0254da9f81273c3",
    remote = "https://github.com/pybind/pybind11_protobuf.git",
)
