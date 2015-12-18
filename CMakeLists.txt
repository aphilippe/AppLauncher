cmake_minimum_required(VERSION 2.8)

# Project creation

project(AppLauncher)
set(EXECUTABLE_OUTPUT_PATH bin/)

file(GLOB_RECURSE source_files src/*.cpp src/*.h)
add_executable(Applauncher ${source_files})

# Group creation

# MODEL_FILE
file(GLOB_RECURSE MODEL_FILE src/Model/File/*)
SET(MODEL_FILE_GROUP ${MODEL_FILE})
SOURCE_GROUP("Model\\File" FILES ${MODEL_FILE_GROUP})

# MODEL_PATH
file(GLOB_RECURSE MODEL_PATH src/Model/Path/*)
SET(MODEL_PATH_GROUP ${MODEL_PATH})
SOURCE_GROUP("Model\\Path" FILES ${MODEL_PATH_GROUP})