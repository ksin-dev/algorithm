load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")


########### RUST SETUP START ###################################
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
http_archive(
    name = "rules_rust",
    sha256 = "0cc7e6b39e492710b819e00d48f2210ae626b717a3ab96e048c43ab57e61d204",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_rust/releases/download/0.10.0/rules_rust-v0.10.0.tar.gz",
        "https://github.com/bazelbuild/rules_rust/releases/download/0.10.0/rules_rust-v0.10.0.tar.gz",
    ],
)

load("@rules_rust//rust:repositories.bzl", "rules_rust_dependencies", "rust_register_toolchains")

rules_rust_dependencies()

rust_register_toolchains()

########### RUST SETUP END ###################################


########### CPP SETUP START ###################################

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "fce83babe3f6287bccb45d2df013a309fa3194b8",
    remote = "https://github.com/nelhage/rules_boost",
    shallow_since = "1591047380 -0700",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
  name = "googletest",
  remote = "https://github.com/google/googletest",
  tag = "release-1.10.0",
)

########### CPP SETUP END  ###################################


# http_archive(
#         name = "rules_foreign_cc",
#         strip_prefix = "rules_foreign_cc-master",
#         url = "https://github.com/bazelbuild/rules_foreign_cc/archive/master.zip",
# )

# load("@rules_foreign_cc//:workspace_definitions.bzl", "rules_foreign_cc_dependencies")

# rules_foreign_cc_dependencies()

# http_archive(
#         name = "boost",
#         build_file_content = all_content,
#         strip_prefix = "boost_1_71_0",
#         sha256 = "da3411ea45622579d419bfda66f45cd0f8c32a181d84adfa936f5688388995cf",
#         urls = ["https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.gz"],
# )