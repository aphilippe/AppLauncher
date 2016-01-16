cmake_minimum_required(VERSION 2.8)

# Project creation

project(AppLauncher)
set(EXECUTABLE_OUTPUT_PATH bin/)

include_directories(src/Common)
include_directories(src/Win)
include_directories(src/Unix)
include_directories(src/Common/Model)

file(GLOB_RECURSE source_files_common src/Common/*.cpp src/Common/*.h)

file(GLOB_RECURSE source_files_win src/Win/*.cpp src/Win/*h)
add_executable(Applauncher_Win ${source_files_common} ${source_file_win})

file(GLOB_RECURSE source_files_unix src/Unix/*.cpp src/Unix/*h)
add_executable(Applauncher_Unix ${source_files_common} ${source_files_unix}) 

# Group creation

# MODEL_FILE
file(GLOB_RECURSE MODEL_FILE src/Common/Model/FileSystem/File/*)
SET(MODEL_FILE_GROUP ${MODEL_FILE})
SOURCE_GROUP("Model\\FileSystem\\File" FILES ${MODEL_FILE_GROUP})

# MODEL_PATH
file(GLOB_RECURSE MODEL_PATH src/Common/Model/FileSystem/Path/*)
SET(MODEL_PATH_GROUP ${MODEL_PATH})
SOURCE_GROUP("Model\\FileSystem\\Path" FILES ${MODEL_PATH_GROUP})

#BUSINESS_EXECUTABLE_LAUNCHER
SOURCE_GROUP("Business\\ExecutableLaunchers" FILES 	src/Common/Business/ExecutableLaunchers/ExecutableLauncher.h
													src/Common/Business/ExecutableLaunchers/ExecutableLauncher.cpp)

#BUSINESS_EXECUTABLE_LAUNCHER_SPEC
SOURCE_GROUP("Business\\ExecutableLaunchers\\Spec" FILES src/Common/Business/ExecutableLaunchers/IExecutableLauncherSpec.h
														 src/Unix/Business/ExecutableLaunchers/ExecutableLauncherUnix.h
														 src/Unix/Business/ExecutableLaunchers/ExecutableLauncherUnix.cpp)

#BUSINESS_EXECUTABLE_LAUNCHER_FACTORY
SOURCE_GROUP("Business\\ExecutableLaunchers\\Factory" FILES src/Common/Business/ExecutableLaunchers/ExecutableLauncherFactory.h
															src/Common/Business/ExecutableLaunchers/ExecutableLauncherFactory.cpp)