cmake_minimum_required(VERSION 2.8)

# Project creation

project(AppLauncher)
set(EXECUTABLE_OUTPUT_PATH bin/)

include_directories(src)
include_directories(src/Model)

file(GLOB_RECURSE source_files src/*.cpp src/*.h)
add_executable(Applauncher ${source_files})

# Group creation

# MODEL_FILE
file(GLOB_RECURSE MODEL_FILE src/Model/FileSystem/File/*)
SET(MODEL_FILE_GROUP ${MODEL_FILE})
SOURCE_GROUP("Model\\FileSystem\\File" FILES ${MODEL_FILE_GROUP})

# MODEL_PATH
file(GLOB_RECURSE MODEL_PATH src/Model/FileSystem/Path/*)
SET(MODEL_PATH_GROUP ${MODEL_PATH})
SOURCE_GROUP("Model\\FileSystem\\Path" FILES ${MODEL_PATH_GROUP})

#BUSINESS_EXECUTABLE_LAUNCHER
SOURCE_GROUP("Business\\ExecutableLaunchers" FILES 	src/Business/ExecutableLaunchers/ExecutableLauncher.h
													src/Business/ExecutableLaunchers/ExecutableLauncher.cpp)

#BUSINESS_EXECUTABLE_LAUNCHER_SPEC
SOURCE_GROUP("Business\\ExecutableLaunchers\\Spec" FILES src/Business/ExecutableLaunchers/IExecutableLauncherSpec.h)

#BUSINESS_EXECUTABLE_LAUNCHER_FACTORY
SOURCE_GROUP("Business\\ExecutableLaunchers\\Factory" FILES src/Business/ExecutableLaunchers/ExecutableLauncherFactory.h
															src/Business/ExecutableLaunchers/ExecutableLauncherFactory.cpp)