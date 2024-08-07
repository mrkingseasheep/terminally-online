# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/yang/000-Projects/terminal_rpg/terminally-online/build/_deps/ftxui-src")
  file(MAKE_DIRECTORY "/home/yang/000-Projects/terminal_rpg/terminally-online/build/_deps/ftxui-src")
endif()
file(MAKE_DIRECTORY
  "/home/yang/000-Projects/terminal_rpg/terminally-online/build/_deps/ftxui-build"
  "/home/yang/000-Projects/terminal_rpg/terminally-online/build/_deps/ftxui-subbuild/ftxui-populate-prefix"
  "/home/yang/000-Projects/terminal_rpg/terminally-online/build/_deps/ftxui-subbuild/ftxui-populate-prefix/tmp"
  "/home/yang/000-Projects/terminal_rpg/terminally-online/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp"
  "/home/yang/000-Projects/terminal_rpg/terminally-online/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src"
  "/home/yang/000-Projects/terminal_rpg/terminally-online/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/yang/000-Projects/terminal_rpg/terminally-online/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/yang/000-Projects/terminal_rpg/terminally-online/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
