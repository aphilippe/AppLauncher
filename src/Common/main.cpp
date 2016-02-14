#include <cstdlib>


#include "FileSystem/Entities/Executable.h"
#include "FileSystem/Factories/EntityFactory.h"
#include <memory>

using namespace clt::filesystem;
using namespace clt::filesystem::factories;
using namespace clt::filesystem::entities;

int main(int argc, char* argv[]) {
	if (argc < 2)
	{
		printf("not enough argument, need the path of your executable");
		return EXIT_FAILURE;
	}
	EntityFactory entityFactory;
	
	Executable executable = entityFactory.createExecutable(argv[1]);
	executable.execute();
	
	return EXIT_SUCCESS;
}
