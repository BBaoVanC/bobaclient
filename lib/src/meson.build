lib_srcs = [
  'bobaclient.cpp',
  'errors.cpp',
  'json.cpp',
]
lib = library(
  'bobaclient',
  lib_srcs,
  soversion: soversion,
  include_directories: include,
  dependencies: [curl_dep],
  install: true,
)
