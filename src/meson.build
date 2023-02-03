cli_srcs = [
  'cli.cpp',
]
executable(
  'bobaclient',
  cli_srcs,
  include_directories: include,
  dependencies: [curl_dep],
  install: true,
)

lib_srcs = [
  'bobaclient.cpp',
]
lib = library(
  'libbobaclient',
  lib_srcs,
  soversion: soversion,
  include_directories: include,
  dependencies: [curl_dep],
  install: true,
)
