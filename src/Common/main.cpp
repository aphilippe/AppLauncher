#include <cstdlib>
#include <iostream>
#include <memory>

#include "AppLauncher/Operations/RestoreOperation.h"
#include "AppLauncher/Operations/ExecuteOperation.h"
#include "AppLauncher/Operations/BackupOperation.h"
#include "AppLauncher/Factories/FileToBackupRepositoryFactory.h"

#include "Core/Application/CommandLine.h"

#include "Settings/Factories/SettingsRepositoryFactory.h"

using std::unique_ptr;

using launcher::factories::FileToBackupRepositoryFactory;
using launcher::operations::RestoreOperation;
using launcher::operations::ExecuteOperation;
using launcher::operations::BackupOperation;
using launcher::repositories::FileToBackupRepository;

using core::application::CommandLine;

using settings::factories::SettingsRepositoryFactory;
using settings::repositories::SettingsRepository;
using settings::domain::Settings;

unique_ptr<SettingsRepository> settingsRepository = nullptr;
unique_ptr<FileToBackupRepository> fileToBackupRepository = nullptr;

void initialize(const CommandLine& arguments);
void terminate();

int main(int argc, char* argv[]) {
	initialize(CommandLine(argc, argv));

	try {
		RestoreOperation restoreOperation;
		restoreOperation.run();

		ExecuteOperation executeOperation;
		executeOperation.run();

		BackupOperation backupOperation(*fileToBackupRepository);
		backupOperation.run();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	terminate();
	
	return EXIT_SUCCESS;
}

void initialize(const CommandLine& arguments) {
	SettingsRepositoryFactory settingsRepositoryFactory;
	settingsRepository = settingsRepositoryFactory.createRepository(arguments);

	FileToBackupRepositoryFactory fileToBackupRepositoryFactory;
	fileToBackupRepository = fileToBackupRepositoryFactory.create();
}

void terminate() {
	settingsRepository = nullptr;
	fileToBackupRepository = nullptr;
}