cmake_minimum_required(VERSION 2.6)


project(AppLauncher)
set(EXECUTABLE_OUTPUT_PATH bin/)

include_directories(src)

file(GLOB_RECURSE source_files src/*)

add_executable(applauncher ${source_files})