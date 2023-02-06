project(
  'bobaclient',
  'cpp',
  version: '0.1.0',
  license: 'MIT',
  default_options: ['cpp_std=c++17'],
)

soversion = 0

curl_dep = dependency('libcurl')
json_dep = dependency('nlohmann_json')

include = include_directories('include')

if get_option('buildtype').startswith('debug')
  if meson.get_compiler('cpp').get_id() == 'clang'
    # fix "error: summary string parsing error" in lldb
    add_project_arguments('-fstandalone-debug', language: 'cpp')
  endif
endif

subdir('include')
subdir('src')
#subdir('test')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  libraries: lib,
  version: meson.project_version(),
  name: 'bobaclient',
  filebase: 'bobaclient',
  description: 'Library to interact with bobashare',
)
