#include <cstdlib>

#include "FileSystem/Entities/Executable.h"
#include "FileSystem/Factories/EntityFactory.h"
#include "FileSystem/Entities/Exceptions/InvalidExecutablePathException.h"
#include <memory>
#include <iostream>

#include "Settings/Factories/SettingsRepositoryFactory.h"
#include "Core/Application/CommandLine.h"

using namespace clt::filesystem;
using namespace clt::filesystem::factories;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::exceptions;

using settings::factories::SettingsRepositoryFactory;
using settings::repositories::SettingsRepository;
using settings::domain::Settings;
using std::unique_ptr;

using core::application::CommandLine;


int main(int argc, char* argv[]) {
	
	try {
		CommandLine cmdLine(argc, argv);
		SettingsRepositoryFactory settingsRepositoryFactory;
		unique_ptr<SettingsRepository> settingsRepository = settingsRepositoryFactory.createRepository(cmdLine);
		const Settings settings = settingsRepository->get();
	}
	catch (std::exception e)
	{
		printf(e.what());
	}
	// To be uncomment after refactoring
	/*EntityFactory entityFactory;
	
	try
	{
		Executable executable = entityFactory.createExecutable(settings.getExecutablePath());
		executable.execute();
	}
	catch (InvalidExecutablePathException exception) {
		std::cout << "Invalid executable path : " << std::endl << "\t - " << exception.getDescription() << std::endl;
	}*/

	
	
	return EXIT_SUCCESS;
}
