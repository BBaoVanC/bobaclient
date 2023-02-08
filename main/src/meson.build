cli_srcs = [
  'main.cpp',
  'curl.cpp',
  'log.cpp',
]
executable(
  'bobaclient',
  cli_srcs,
  include_directories: include,
  dependencies: [curl_dep, json_dep],
  link_with: lib,
  install: true,
)
