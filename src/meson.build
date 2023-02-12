lib_srcs = [
  'bobaclient/bobaclient.cpp',
  'bobaclient/display.cpp',
  'bobaclient/errors.cpp',
  'bobaclient/json.cpp',
  'bobaclient/types.cpp',
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
  'curl.cpp',
]
executable(
  'bobaclient',
  cli_srcs,
  include_directories: include,
  dependencies: [curl_dep, json_dep],
  link_with: lib,
  install: true,
)
