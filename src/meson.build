lib_srcs = [
  'bobaclient.cpp',
]
lib = library(
  'bobaclient',
  lib_srcs,
  soversion: soversion,
  include_directories: include,
  dependencies: [curl_dep],
  install: true,
)

cli_srcs = [
  'main.cpp',
]
executable(
  'bobaclient',
  cli_srcs,
  include_directories: include,
  dependencies: [curl_dep],
  link_with: lib,
  install: true,
)
