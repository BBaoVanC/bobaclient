include_lib = include_directories('include')

subdir('include')
subdir('src')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  libraries: lib,
  version: meson.project_version(),
  name: 'bobaclient',
  filebase: 'bobaclient',
  description: 'Library to interact with bobashare',
)
