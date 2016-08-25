#include <cstdlib>
#include <iostream>
#include <memory>

#include "AppLauncher/Factories/BackupFolderRepositoryFactory.h"
#include "AppLauncher/Factories/FileToBackupRepositoryFactory.h"
#include "AppLauncher/Factories/FileToRestoreRepositoryFactory.h"
#include "AppLauncher/Factories/ExecutableRepositoryFactory.h"
#include "AppLauncher/Operations/RestoreOperation.h"
#include "AppLauncher/Operations/ExecuteOperation.h"
#include "AppLauncher/Operations/BackupOperation.h"

#include "Core/Application/CommandLine.h"

#include "Settings/Factories/SettingsRepositoryFactory.h"

using std::unique_ptr;

using launcher::factories::BackupFolderRepositoryFactory;
using launcher::factories::FileToBackupRepositoryFactory;
using launcher::factories::FileToRestoreRepositoryFactory;
using launcher::factories::ExecutableRepositoryFactory;
using launcher::operations::RestoreOperation;
using launcher::operations::ExecuteOperation;
using launcher::operations::BackupOperation;
using launcher::repositories::FileToBackupRepository;
using launcher::repositories::FileToRestoreRepository;
using launcher::repositories::BackupFolderRepository;
using launcher::repositories::ExecutableRepository;

using core::application::CommandLine;

using settings::factories::SettingsRepositoryFactory;
using settings::repositories::SettingsRepository;


unique_ptr<SettingsRepository> settingsRepository = nullptr;
unique_ptr<FileToBackupRepository> fileToBackupRepository = nullptr;
unique_ptr<BackupFolderRepository> backupFolderRepository = nullptr;
unique_ptr<ExecutableRepository> executableRepository = nullptr;
std::unique_ptr<FileToRestoreRepository> fileToRestoreRepository = nullptr;


void initialize(const CommandLine& arguments);
void terminate();

int main(int argc, char* argv[]) {
	initialize(CommandLine(argc, argv));

	try {
		RestoreOperation restoreOperation(*fileToRestoreRepository, *backupFolderRepository);
		restoreOperation.run();

		ExecuteOperation executeOperation(*executableRepository);
		executeOperation.run();

		BackupOperation backupOperation(*fileToBackupRepository, *backupFolderRepository);
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

	BackupFolderRepositoryFactory backupFolderRepositoryFactory;
	backupFolderRepository = backupFolderRepositoryFactory.create();

	ExecutableRepositoryFactory executableRepositoryFactory;
	executableRepository = executableRepositoryFactory.create();

	FileToRestoreRepositoryFactory fileToRestoreRepositoryFactory;
	fileToRestoreRepository = fileToRestoreRepositoryFactory.create();
}

void terminate() {
	backupFolderRepository = nullptr;
	fileToBackupRepository = nullptr;
	settingsRepository = nullptr;
}