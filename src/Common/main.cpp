#include <cstdlib>
#include <iostream>
#include <memory>

#include "AppLauncher/Operations/RestoreOperation.h"
#include "AppLauncher/Operations/ExecuteOperation.h"
#include "AppLauncher/Operations/BackupOperation.h"

#include "Core/Application/CommandLine.h"

#include "FileSystem/Entities/Executable.h"
#include "FileSystem/Factories/EntityFactory.h"
#include "FileSystem/Entities/Exceptions/InvalidExecutablePathException.h"

#include "Settings/Factories/SettingsRepositoryFactory.h"

using std::unique_ptr;

using launcher::operations::RestoreOperation;
using launcher::operations::ExecuteOperation;
using launcher::operations::BackupOperation;

using core::application::CommandLine;

using namespace clt::filesystem;
using namespace clt::filesystem::factories;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::exceptions;

using settings::factories::SettingsRepositoryFactory;
using settings::repositories::SettingsRepository;
using settings::domain::Settings;

unique_ptr<SettingsRepository> settingsRepository = nullptr;

void initialize(const CommandLine& arguments);
void terminate();

int main(int argc, char* argv[]) {
	initialize(CommandLine(argc, argv));

	try {
		RestoreOperation restoreOperation;
		restoreOperation.run();

		ExecuteOperation executeOperation;
		executeOperation.run();

		BackupOperation backupOperation;
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
}

void terminate() {
	settingsRepository = nullptr;
}