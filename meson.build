project(
  'bobaclient',
  'cpp',
  version: '0.1.0',
  license: 'MIT',
  default_options: ['cpp_std=c++17']
)

curl_dep = dependency('libcurl')

include = include_directories('include')

subdir('include')
subdir('src')
#subdir('test')

#pkg_mod = import('pkgconfig')
#pkg_mod.generate(
#  libraries: libbobaclient,
#  version: '0.1.0'
#  name: 'libbobaclient',
#  filebase: 'bobaclient',
#  description: 'Library to interact with bobashare',
#)
