cmake_minimum_required(VERSION 2.8)

# Project creation

project(AppLauncher)
set(EXECUTABLE_OUTPUT_PATH bin/)

include_directories(src/Common)

file(GLOB_RECURSE source_files_common src/Common/*.cpp src/Common/*.h)

IF (WIN32)
	include_directories(src/Windows)
    file(GLOB_RECURSE source_files_win src/Windows/*.cpp src/Windows/*h)
    add_executable(Applauncher_Win ${source_files_common} ${source_files_win})
    target_compile_definitions(Applauncher_Win PRIVATE WINDOWS)
ELSE()
	include_directories(src/Unix)
    file(GLOB_RECURSE source_files_unix src/Unix/*.cpp src/Unix/*h)
    add_executable(Applauncher_Unix ${source_files_common} ${source_files_unix})
    target_compile_definitions(Applauncher_Unix PRIVATE UNIX)
ENDIF()

# Group creation

####################
#    FileSystem    #
####################

SOURCE_GROUP("FileSystem" FILES
				src/Common/FileSystem/FileSystem.cpp
				src/Common/FileSystem/FileSystem.h)

SOURCE_GROUP("FileSystem\\Factories" FILES
				src/Common/FileSystem/Factories/FileSystemFactory.h
				src/Windows/FileSystem/Factories/FileSystemFactoryWindows.cpp)

SOURCE_GROUP("FileSystem\\Entities" FILES 
                src/Common/FileSystem/Entities/Executable.cpp
                src/Common/FileSystem/Entities/Executable.h
                src/Common/FileSystem/Entities/Path.cpp
                src/Common/FileSystem/Entities/Path.h)

SOURCE_GROUP("FileSystem\\Operations" FILES 
                src/Common/FileSystem/Operations/IExecutableLauncher.cpp
                src/Common/FileSystem/Operations/IExecutableLauncher.h
                src/Unix/FileSystem/Operations/ExecutableLauncherUnix.cpp
                src/Unix/FileSystem/Operations/ExecutableLauncherUnix.h
				src/Windows/FileSystem/Operations/ExecutableLauncherWindows.cpp
                src/Windows/FileSystem/Operations/ExecutableLauncherWindows.h)
				
####################
#      Utils      #
####################
SOURCE_GROUP("Utils" FILES
				src/Common/Utils/StringUtils.cpp
				src/Common/Utils/StringUtils.h)