#include <cstdlib>

#include "FileSystem/Entities/Executable.h"
#include "FileSystem/FileSystem.h"
#include "FileSystem/Factories/FileSystemFactory.h"
#include <memory>

using namespace clt::filesystem;
using namespace clt::filesystem::factories;
using namespace clt::filesystem::entities;

int main() {
	// TODO: use argument to set the path
	Path path("...");

	FileSystemFactory factory;
	std::unique_ptr<FileSystem> system(factory.createFileSystem());

	Executable executable(path, std::move(system));
	executable.execute();
	
	return EXIT_SUCCESS;
}
