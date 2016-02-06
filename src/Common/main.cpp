#include <cstdlib>

#include "FileSystem/Entities/Executable.h"
#include "FileSystem/FileSystem.h"
#include "FileSystem/Factories/FileSystemFactory.h"
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

	// TODO: use argument to set the path
	Path path(argv[1]);

	FileSystemFactory factory;
	std::unique_ptr<FileSystem> system(factory.newFileSystem());

	Executable executable(path, std::move(system));
	executable.execute();
	
	return EXIT_SUCCESS;
}
