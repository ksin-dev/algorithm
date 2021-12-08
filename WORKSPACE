load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_rust",
    sha256 = "531bdd470728b61ce41cf7604dc4f9a115983e455d46ac1d0c1632f613ab9fc3",
    strip_prefix = "rules_rust-d8238877c0e552639d3e057aadd6bfcf37592408",
    urls = [
        # `main` branch as of 2021-08-23
        "https://github.com/bazelbuild/rules_rust/archive/d8238877c0e552639d3e057aadd6bfcf37592408.tar.gz",
    ],
)

load("@rules_rust//rust:repositories.bzl", "rust_repositories")

rust_repositories()

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "fce83babe3f6287bccb45d2df013a309fa3194b8",
    remote = "https://github.com/nelhage/rules_boost",
    shallow_since = "1591047380 -0700",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()

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