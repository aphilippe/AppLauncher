#include <cstdlib>


#include "FileSystem/Entities/Executable.h"
#include "FileSystem/Factories/EntityFactory.h"
#include "FileSystem/Entities/Exceptions/InvalidExecutablePathException.h"
#include <memory>
#include <iostream>

using namespace clt::filesystem;
using namespace clt::filesystem::factories;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::exceptions;

int main(int argc, char* argv[]) {
	if (argc < 2)
	{
		printf("not enough argument, need the path of your executable");
		return EXIT_FAILURE;
	}
	EntityFactory entityFactory;
	
	try
	{

		Executable executable = entityFactory.createExecutable(argv[1]);
		executable.execute();
	}
	catch (InvalidExecutablePathException exception) {
		std::cout << exception.getDescription() << std::endl;
	}
	
	return EXIT_SUCCESS;
}
