cmake_minimum_required(VERSION 2.8)

# Project creation

project(AppLauncher)
set(EXECUTABLE_OUTPUT_PATH bin/)

include_directories(src/Common)
include_directories(src/Win)
include_directories(src/Unix)

file(GLOB_RECURSE source_files_common src/Common/*.cpp src/Common/*.h)

file(GLOB_RECURSE source_files_win src/Win/*.cpp src/Win/*h)
add_executable(Applauncher_Win ${source_files_common} ${source_file_win})
target_compile_definitions(Applauncher_Win PRIVATE WINDOWS)

file(GLOB_RECURSE source_files_unix src/Unix/*.cpp src/Unix/*h)
add_executable(Applauncher_Unix ${source_files_common} ${source_files_unix})
target_compile_definitions(Applauncher_Unix PRIVATE UNIX)


# Group creation

####################
#      DOMAIN      #
####################

SOURCE_GROUP("Domain\\FileSystem" FILES 
                src/Common/Domain/FileSystem/Executable.cpp
                src/Common/Domain/FileSystem/Executable.h
                src/Common/Domain/FileSystem/Path.cpp
                src/Common/Domain/FileSystem/Path.h)