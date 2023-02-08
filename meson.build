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

#include = include_directories('include')

if get_option('buildtype').startswith('debug')
  if meson.get_compiler('cpp').get_id() == 'clang'
    # fix "error: summary string parsing error" in lldb
    add_project_arguments('-fstandalone-debug', language: 'cpp')
  endif
endif

subdir('lib')
subdir('main')
#subdir('test')
