cmake_minimum_required(VERSION 2.8)

set(executableName applauncher)

# Project creation

project(AppLauncher)
set(EXECUTABLE_OUTPUT_PATH bin/)

include_directories(src/Libraries)
include_directories(src)

file(GLOB_RECURSE source_files_common src/main.cpp src/Core/*.cpp src/Core/*.h src/Settings/*.cpp src/Settings/*.h src/AppLauncher/*.cpp src/AppLauncher/*.h src/FileSystem/*.cpp src/FileSystem/*.h)


find_package(Boost 1.55 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

link_directories(${Boost_LIBRARY_DIRS})

IF (WIN32)
    add_executable(${executableName} ${source_files_common})
	target_link_libraries (${executableName} Shlwapi)

ELSE()
    add_executable(${executableName} ${source_files_common})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
ENDIF()

target_link_libraries( ${executableName} ${Boost_LIBRARIES} )

add_custom_command(TARGET ${executableName} POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${Boost_LIBRARY_DIRS}/boost_atomic-vc140-mt-1_61.dll"      # <--this is in-file
		${EXECUTABLE_OUTPUT_PATH}) 

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
				src/Core/JSON/DataObjectBuilder/MapDataObjectJSONBuilder.cpp
				src/Core/JSON/DataObjectBuilder/MapDataObjectJSONBuilder.h
				src/Core/JSON/DataObjectBuilder/StringDataObjectJSONBuilder.cpp
				src/Core/JSON/DataObjectBuilder/StringDataObjectJSONBuilder.h
				src/Core/JSON/DataObjectBuilder/ArrayDataObjectJSONBuilder.h
				src/Core/JSON/DataObjectBuilder/ArrayDataObjectJSONBuilder.cpp)

SOURCE_GROUP("Core\\JSON\\Parsers" FILES
				src/Core/JSON/Parser/JSONParser.cpp
				src/Core/JSON/Parser/JSONParser.h)

SOURCE_GROUP("Core\\JSON\\Parsers\\Handler" FILES
				src/Core/JSON/Parser/Handler/JSONHandler.h
				src/Core/JSON/Parser/Handler/JSONHandler.cpp)

SOURCE_GROUP("Core\\Application" FILES
				src/Core/Application/CommandLine.h
				src/Core/Application/CommandLine.cpp)

SOURCE_GROUP("Core\\Exceptions" FILES
				src/Core/Exceptions/Exception.h
				src/Core/Exceptions/Exception.cpp)

###################
# Settings        #
###################

SOURCE_GROUP("Settings\\Factories" FILES
				src/Settings/Factories/SettingsRepositoryFactory.h
				src/Settings/Factories/SettingsRepositoryFactory.cpp
				src/Settings/Factories/SettingsDAOFactory.h
				src/Settings/Factories/ConcreteSettingsDAOFactory.h
				src/Settings/Factories/ConcreteSettingsDAOFactory.cpp)

SOURCE_GROUP("Settings\\Repositories" FILES
				src/Settings/Repositories/SettingsRepository.h
				src/Settings/Repositories/ConcreteSettingsRepository.h
				src/Settings/Repositories/ConcreteSettingsRepository.cpp)

SOURCE_GROUP("Settings\\Domain" FILES
				src/Settings/Domain/Settings.h
				src/Settings/Domain/Settings.cpp
				src/Settings/Domain/CommandLineSettings.h
				src/Settings/Domain/CommandLineSettings.cpp
				src/Settings/Domain/CustomFileSettings.h
				src/Settings/Domain/CustomFileSettings.cpp)

SOURCE_GROUP("Settings\\DataAccess\\CommandLine" FILES
				src/Settings/DataAccess/CommandLineArgumentSettingsDAO.h
				src/Settings/DataAccess/ConcreteCommandLineArgumentSettingsDAO.h
				src/Settings/DataAccess/ConcreteCommandLineArgumentSettingsDAO.cpp)

SOURCE_GROUP("Settings\\DataAccess\\CustomFile" FILES
				src/Settings/DataAccess/CustomFileSettingsDAO.h
				src/Settings/DataAccess/ConcreteCustomFileSettingsDAO.h
				src/Settings/DataAccess/ConcreteCustomFileSettingsDAO.cpp)

SOURCE_GROUP("Settings\\Builders" FILES
				src/Settings/Builders/CommandLineSettingsBuilder.h
				src/Settings/Builders/CommandLineSettingsBuilder.cpp
				src/Settings/Builders/CustomFileSettingsBuilder.h
				src/Settings/Builders/CustomFileSettingsBuilder.cpp
				src/Settings/Builders/MergedSettingsBuilder.h
				src/Settings/Builders/MergedSettingsBuilder.cpp)

SOURCE_GROUP("Settings\\Exceptions" FILES
				src/Settings/Exceptions/BadFormatCustomFileSettingsException.h
				src/Settings/Exceptions/BadFormatCustomFileSettingsException.cpp
				src/Settings/Exceptions/BadTypeCustomFileSettingsException.h
				src/Settings/Exceptions/BadTypeCustomFileSettingsException.cpp
				src/Settings/Exceptions/MissingSettingsException.cpp
				src/Settings/Exceptions/MissingSettingsException.h)

#####################
#    Application    #
#####################

SOURCE_GROUP("AppLauncher\\Operations" FILES
				src/AppLauncher/Operations/IOperation.h
				src/AppLauncher/Operations/RestoreOperation.cpp
				src/AppLauncher/Operations/RestoreOperation.h
				src/AppLauncher/Operations/ExecuteOperation.cpp
				src/AppLauncher/Operations/ExecuteOperation.h
				src/AppLauncher/Operations/BackupOperation.cpp
				src/AppLauncher/Operations/BackupOperation.h)

SOURCE_GROUP("AppLauncher\\Domain" FILES
				src/AppLauncher/Domain/FileToBackup.h
				src/AppLauncher/Domain/FileToBackup.cpp
				src/AppLauncher/Domain/BackupFolder.h
				src/AppLauncher/Domain/BackupFolder.cpp)

SOURCE_GROUP("AppLauncher\\Repositories" FILES
				src/AppLauncher/Repositories/FileToBackupRepository.h
				src/AppLauncher/Repositories/FileToBackupRepository.cpp
				src/AppLauncher/Repositories/BackupFolderRepository.h
				src/AppLauncher/Repositories/BackupFolderRepository.cpp)

SOURCE_GROUP("AppLauncher\\Factories" FILES
				src/AppLauncher/Factories/FileToBackupRepositoryFactory.h
				src/AppLauncher/Factories/FileToBackupRepositoryFactory.cpp
				src/AppLauncher/Factories/BackupFolderRepositoryFactory.h
				src/AppLauncher/Factories/BackupFolderRepositoryFactory.cpp)

SOURCE_GROUP("AppLauncher\\Exceptions" FILES
				src/AppLauncher/Exceptions/FileToBackupExceptions.h
				src/AppLauncher/Exceptions/FileToBackupExceptions.cpp
				src/AppLauncher/Exceptions/BackupFolderExceptions.h
				src/AppLauncher/Exceptions/BackupFolderExceptions.cpp)

####################
#    FileSystem    #
####################

SOURCE_GROUP("FileSystem" FILES
				src/FileSystem/Path.cpp
				src/FileSystem/Path.h)

SOURCE_GROUP("FileSystem\\Operations" FILES
				src/FileSystem/Operations/ReadInformationOperation.h
				src/FileSystem/Operations/ReadInformationOperation.cpp
				src/FileSystem/Operations/ReadInformationOperationWindows.cpp
				src/FileSystem/Operations/ReadInformationOperationUnix.cpp
				src/FileSystem/Operations/CopyOperation.cpp
				src/FileSystem/Operations/CopyOperation.h)

SOURCE_GROUP("FileSystem\\Factories" FILES
				src/FileSystem/Factories/PathFactory.h
				src/FileSystem/Factories/PathFactory.cpp)
				
####################
#      Utils      #
####################
SOURCE_GROUP("Utils" FILES
				src/Common/Utils/StringUtils.cpp
				src/Common/Utils/StringUtils.h)

