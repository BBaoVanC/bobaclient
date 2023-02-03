bobaclient_srcs = [
  'bobaclient.cpp',
  'curl.cpp',
]
executable(
  'bobaclient',
  bobaclient_srcs,
  include_directories: include,
  dependencies: [curl_dep],
  install: true,
)

libbobaclient_srcs = [
  'libbobaclient.cpp',
]
libbobaclient = shared_library(
  'libbobaclient',
  libbobaclient_srcs,
  include_directories: include,
  dependencies: [curl_dep],
  install: true
)
