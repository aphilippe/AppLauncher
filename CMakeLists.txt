cmake_minimum_required(VERSION 2.8)

set(executableName applauncher)

# Project creation

project(AppLauncher)
set(EXECUTABLE_OUTPUT_PATH bin/)

include_directories(src/Common)
include_directories(src/Libraries)
include_directories(src)

file(GLOB_RECURSE source_files_common src/Common/*.cpp src/Common/*.h src/Core/*.cpp src/Core/*.h)

IF (WIN32)
	include_directories(src/Windows)
    file(GLOB_RECURSE source_files_win src/Windows/*.cpp src/Windows/*h)
    add_executable(${executableName} ${source_files_common} ${source_files_win})
ELSE()
	include_directories(src/Unix)
    file(GLOB_RECURSE source_files_unix src/Unix/*.cpp src/Unix/*h)
    add_executable(${executableName} ${source_files_common} ${source_files_unix})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
ENDIF()

# Group creation

###################
#     Core        #
###################

SOURCE_GROUP("Core" FILES
				src/Core/DataObject.cpp
				src/Core/DataObject.h)

SOURCE_GROUP("Core\\JSON\\DataObjectBuilder" FILES
				src/Core/JSON/DataObjectBuilder/IDataObjectJSONBuilder.h
				src/Core/JSON/DataObjectBuilder/RootDataObjectJSONBuilder.h
				src/Core/JSON/DataObjectBuilder/RootDataObjectJSONBuilder.cpp
				src/Core/JSON/DataObjectBuilder/MapDataObjectBuilder.cpp
				src/Core/JSON/DataObjectBuilder/MapDataObjectBuilder.h
				src/Core/JSON/DataObjectBuilder/StringDataObjectBuilder.cpp
				src/Core/JSON/DataObjectBuilder/StringDataObjectBuilder.h)

SOURCE_GROUP("Core\\JSON\\Parsers" FILES
				src/Core/JSON/Parser/JSONParser.cpp
				src/Core/JSON/Parser/JSONParser.h)

SOURCE_GROUP("Core\\JSON\\Parsers\\Handler" FILES
				src/Core/JSON/Parser/Handler/JSONHandler.h
				src/Core/JSON/Parser/Handler/JSONHandler.cpp)


###################
#   UserParameter   #
###################

SOURCE_GROUP("UserParameter\\Domain" FILES
				src/Common/UserParameter/Domain/UserParameter.cpp
				src/Common/UserParameter/Domain/UserParameter.h)

SOURCE_GROUP("UserParameter\\Repositories" FILES
				src/Common/UserParameter/Repositories/UserParameterRepository.cpp
				src/Common/UserParameter/Repositories/UserParameterRepository.h)

SOURCE_GROUP("UserParameter\\DataAccess" FILES
				src/Common/UserParameter/DataAccess/IUserParameterDAO.h
				src/Common/UserParameter/DataAccess/JSONUserParameterDAO.h
				src/Common/UserParameter/DataAccess/JSONUserParameterDAO.cpp)

SOURCE_GROUP("UserParameter\\Factories" FILES
				src/Common/UserParameter/Factories/UserParameterFactory.h
				src/Common/UserParameter/Factories/UserParameterFactory.cpp)

###################
#   Application   #
###################

SOURCE_GROUP("Application\\Parameters" FILES
				src/Common/Application/Parameters/ApplicationParameters.cpp
				src/Common/Application/Parameters/ApplicationParameters.h)

SOURCE_GROUP("Application\\Parameters\\Builders" FILES
				src/Common/Application/Parameters/ApplicationParametersBuilder.cpp
				src/Common/Application/Parameters/ApplicationParametersBuilder.h)

SOURCE_GROUP("Application\\Parameters\\Manager" FILES
				src/Common/Application/Parameters/ApplicationParametersManager.cpp
				src/Common/Application/Parameters/ApplicationParametersManager.h)

SOURCE_GROUP("Application\\Parameters\\Reader" FILES
				src/Common/Application/Parameters/ApplicationParametersReader.cpp
				src/Common/Application/Parameters/ApplicationParametersReader.h)

####################
#    FileSystem    #
####################

SOURCE_GROUP("FileSystem" FILES
				src/Common/FileSystem/FileSystem.cpp
				src/Common/FileSystem/FileSystem.h)

SOURCE_GROUP("FileSystem\\Factories" FILES
				src/Common/FileSystem/Factories/FileSystemFactory.h
				src/Windows/FileSystem/Factories/FileSystemFactoryWindows.cpp
				src/Common/FileSystem/Factories/EntityFactory.h
				src/Windows/FileSystem/Factories/EntityFactoryWindows.cpp
                src/Unix/FileSystem/Factories/EntityFactoryUnix.cpp)

SOURCE_GROUP("FileSystem\\Entities" FILES 
                src/Common/FileSystem/Entities/Executable.cpp
                src/Common/FileSystem/Entities/Executable.h
                src/Common/FileSystem/Entities/Path.cpp
                src/Common/FileSystem/Entities/Path.h)
                
SOURCE_GROUP("FileSystem\\Entities\\Exceptions" FILES 
                src/Common/FileSystem/Entities/Exceptions/InvalidExecutablePathException.cpp
                src/Common/FileSystem/Entities/Exceptions/InvalidExecutablePathException.h) 

SOURCE_GROUP("FileSystem\\Entities\\Validators" FILES
				src/Common/FileSystem/Entities/Validators/IPathValidator.h
                src/Common/FileSystem/Entities/Validators/ValidatorBrokenRules.cpp
                src/Common/FileSystem/Entities/Validators/ValidatorBrokenRules.h
				src/Unix/FileSystem/Entities/Validators/UnixExecutablePathValidator.cpp
				src/Unix/FileSystem/Entities/Validators/UnixExecutablePathValidator.h
				src/Windows/FileSystem/Entities/Validators/WindowsExecutablePathValidator.cpp
				src/Windows/FileSystem/Entities/Validators/WindowsExecutablePathValidator.h)

SOURCE_GROUP("FileSystem\\Operations\\ExecutableLaunchers" FILES 
                src/Common/FileSystem/Operations/IExecutableLauncher.h
                src/Unix/FileSystem/Operations/ExecutableLauncherUnix.cpp
                src/Unix/FileSystem/Operations/ExecutableLauncherUnix.h
				src/Windows/FileSystem/Operations/ExecutableLauncherWindows.cpp
                src/Windows/FileSystem/Operations/ExecutableLauncherWindows.h)

SOURCE_GROUP("FileSystem\\Operations\\FileInformationReaders" FILES 
                src/Common/FileSystem/Operations/IPathInformationReader.h
				src/Unix/FileSystem/Operations/UnixPathInformationReader.cpp
                src/Unix/FileSystem/Operations/UnixPathInformationReader.h
				src/Windows/FileSystem/Operations/WindowsPathInformationReader.cpp
                src/Windows/FileSystem/Operations/WindowsPathInformationReader.h)
				
####################
#      Utils      #
####################
SOURCE_GROUP("Utils" FILES
				src/Common/Utils/StringUtils.cpp
				src/Common/Utils/StringUtils.h)

