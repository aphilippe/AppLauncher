#include <cstdlib>

#include "FileSystem/Entities/Executable.h"
#include "FileSystem/FileSystem.h"
#include "FileSystem/Factories/FileSystemFactory.h"
#include "FileSystem/Entities/UnixExecutablePathValidator.h"
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

	Path path(argv[1]);

	FileSystemFactory factory;
	std::unique_ptr<FileSystem> system = std::move(factory.createFileSystem());

	//TODO: create an executable factory that choose the validator (only pass the path)
	validator::UnixExecutablePathValidator validator;
	
	Executable executable(path, std::move(system), validator);
	executable.execute();
	
	return EXIT_SUCCESS;
}
