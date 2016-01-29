cmake_minimum_required(VERSION 2.8)

# Project creation

project(AppLauncher)
set(EXECUTABLE_OUTPUT_PATH bin/)

include_directories(src/Common)
include_directories(src/Win)
include_directories(src/Unix)

file(GLOB_RECURSE source_files_common src/Common/*.cpp src/Common/*.h)

IF (WIN32)
    file(GLOB_RECURSE source_files_win src/Win/*.cpp src/Win/*h)
    add_executable(Applauncher_Win ${source_files_common} ${source_file_win})
    target_compile_definitions(Applauncher_Win PRIVATE WINDOWS)
ELSE()
    file(GLOB_RECURSE source_files_unix src/Unix/*.cpp src/Unix/*h)
    add_executable(Applauncher_Unix ${source_files_common} ${source_files_unix})
    target_compile_definitions(Applauncher_Unix PRIVATE UNIX)
ENDIF()

# Group creation

####################
#      System      #
####################

SOURCE_GROUP("System\\Entities" FILES 
                src/Common/System/Entities/Executable.cpp
                src/Common/System/Entities/Executable.h
                src/Common/System/Entities/Path.cpp
                src/Common/System/Entities/Path.h)

SOURCE_GROUP("System\\Operations" FILES 
                src/Common/System/Operations/IExecutableLauncher.cpp
                src/Common/System/Operations/IExecutableLauncher.h
                src/Unix/System/Operations/ExecutableLauncherUnix.cpp
                src/Unix/System/Operations/ExecutableLauncherUnix.h)           