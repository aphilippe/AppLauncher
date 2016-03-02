#include <cstdlib>

#include "Application/Parameters/ApplicationParameters.h"
#include "FileSystem/Entities/Executable.h"
#include "FileSystem/Factories/EntityFactory.h"
#include "FileSystem/Entities/Exceptions/InvalidExecutablePathException.h"
#include <memory>
#include <iostream>

using namespace clt::filesystem;
using namespace clt::filesystem::factories;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::exceptions;
using namespace application::parameters;

int main(int argc, char* argv[]) {
	
	if (argc < 2)
	{
		// TODO: real arguments management
		printf("not enough argument, need the path of your executable");
		return EXIT_FAILURE;
	}

	ApplicationParameters parameters(argv[1]);
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
