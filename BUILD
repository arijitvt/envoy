load("//bazel:envoy_build_system.bzl", "envoy_package")
load("//tools/python:namespace.bzl", "envoy_py_namespace")


load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")

refresh_compile_commands(
    name = "refresh_compile_commands",

    # Specify the targets of interest.
    # For example, specify a dict of targets and any flags required to build.
    targets = ["//source/exe:envoy"],
    # No need to add flags already in .bazelrc. They're automatically picked up.
    # If you don't need flags, a list of targets is also okay, as is a single target string.
    # Wildcard patterns, like //... for everything, *are* allowed here, just like a build.
      # As are additional targets (+) and subtractions (-), like in bazel query https://docs.bazel.build/versions/main/query.html#expressions
    # And if you're working on a header-only library, specify a test or binary target that compiles it.
)

licenses(["notice"])  # Apache 2

envoy_package()

envoy_py_namespace()

exports_files([
    "VERSION.txt",
    "API_VERSION.txt",
    ".clang-format",
    "pytest.ini",
    ".coveragerc",
    "CODEOWNERS",
    "OWNERS.md",
    ".github/config.yml",
    "reviewers.yaml",
])

alias(
    name = "envoy",
    actual = "//source/exe:envoy",
)

alias(
    name = "envoy.stripped",
    actual = "//source/exe:envoy-static.stripped",
)

filegroup(
    name = "clang_tidy_config",
    srcs = [".clang-tidy"],
    visibility = ["//visibility:public"],
)

# These two definitions exist to help reduce Envoy upstream core code depending on extensions.
# To avoid visibility problems, see notes in source/extensions/extensions_build_config.bzl
#
# TODO(#9953) //test/config_test:__pkg__ should probably be split up and removed.
# TODO(#9953) the config fuzz tests should be moved somewhere local and //test/config_test and //test/server removed.
package_group(
    name = "extension_config",
    packages = [
        "//source/exe",
        "//source/extensions/...",
        "//test/config_test",
        "//test/extensions/...",
        "//test/server",
        "//test/server/config_validation",
        "//test/tools/...",
        "//tools/extensions/...",
    ],
)

package_group(
    name = "extension_library",
    packages = [
        "//source/extensions/...",
        "//test/extensions/...",
    ],
)

package_group(
    name = "contrib_library",
    packages = [
        "//contrib/...",
    ],
)

package_group(
    name = "mobile_library",
    packages = [
        "//mobile/...",
    ],
)
