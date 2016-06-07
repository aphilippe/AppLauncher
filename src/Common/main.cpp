#include <cstdlib>

#include "Application/Parameters/ApplicationParameters.h"
#include "Application/Parameters/ApplicationParametersBuilder.h"
#include "Application/Parameters/ApplicationParametersManager.h"
#include "Application/Parameters/ApplicationParametersReader.h"
#include "FileSystem/Entities/Executable.h"
#include "FileSystem/Factories/EntityFactory.h"
#include "FileSystem/Entities/Exceptions/InvalidExecutablePathException.h"
#include <memory>
#include <iostream>
#include "UserParameter/Repositories/UserParameterRepository.h"
#include "UserParameter/DataAccess/JSONUserParameterDAO.h"
#include "UserParameter/Domain/UserParameter.h"
#include "UserParameter/Domain/UserParameterFile.h"

#include "Settings/Factories/SettingsRepositoryFactory.h"
#include "Core/Application/CommandLine.h"

using namespace clt::filesystem;
using namespace clt::filesystem::factories;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::exceptions;
using namespace application::parameters;

using settings::factories::SettingsRepositoryFactory;
using settings::repositories::SettingsRepository;
using settings::domain::Settings;
using std::unique_ptr;

using core::application::CommandLine;


int main(int argc, char* argv[]) {
	// to be removed with refactoring
	//ApplicationParametersManager parametersManager(std::make_unique<ApplicationParametersBuilder>(), std::make_unique<ApplicationParametersReader>());
	//parametersManager.start(cmdLine._argc, cmdLine._argv);
	//ApplicationParameters parameters = parametersManager.getParameters();

	//userparameter::domain::UserParameterFile userParameterFile(parameters.getBackupParametersFilePath());
	//userparameter::repositories::UserParameterRepository userParameterRepository(std::move(std::make_unique<userparameter::dataaccess::JSONUserParameterDAO>()));
	//userParameterRepository.getUserParameter(userParameterFile);
	
	CommandLine cmdLine(argc, argv);
	SettingsRepositoryFactory settingsRepositoryFactory;
	unique_ptr<SettingsRepository> settingsRepository = settingsRepositoryFactory.createRepository(cmdLine);
	const Settings settings = settingsRepository->get();

	// To be uncomment after refactoring
	EntityFactory entityFactory;
	
	try
	{
		Executable executable = entityFactory.createExecutable(settings.getExecutablePath());
		executable.execute();
	}
	catch (InvalidExecutablePathException exception) {
		std::cout << "Invalid executable path : " << std::endl << "\t - " << exception.getDescription() << std::endl;
	}
	
	return EXIT_SUCCESS;
}
