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

using namespace clt::filesystem;
using namespace clt::filesystem::factories;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::exceptions;
using namespace application::parameters;


int main(int argc, char* argv[]) {
	userparameter::repositories::UserParameterRepository userParameterRepository(std::move(std::make_unique<userparameter::dataaccess::JSONUserParameterDAO>()));
	userParameterRepository.getUserParameter();

	ApplicationParametersManager parametersManager(std::make_unique<ApplicationParametersBuilder>(), std::make_unique<ApplicationParametersReader>());
	parametersManager.start(argc, argv);
	ApplicationParameters parameters = parametersManager.getParameters();

	EntityFactory entityFactory;
	
	try
	{
		Executable executable = entityFactory.createExecutable(parameters.getExecutablePath());
		executable.execute();
	}
	catch (InvalidExecutablePathException exception) {
		std::cout << "Invalid executable path : " << std::endl << "\t - " << exception.getDescription() << std::endl;
	}
	
	return EXIT_SUCCESS;
}
