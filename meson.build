project('stingray3d', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14','default_library=static'])

sdl2_dep = dependency('sdl2')

executable('stingray3d',
           'main.cpp',
           win_subsystem:'windows',
           dependencies:sdl2_dep)
