#include <cstdlib>

#include "FileSystem/Entities/Executable.h"
#include "FileSystem/FileSystem.h"
#include "FileSystem/Operations/ExecutableLauncherWindows.h"
#include <memory>

using namespace clt::filesystem;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::operations;

int main() {
	// TODO: use argument to set the path
	Path path("...");

	// TODO: create a factory that return an executable with only the Path
	std::unique_ptr<IExecutableLauncher> launcher(new ExecutableLauncherWindows());
	std::unique_ptr<FileSystem> system(new FileSystem(std::move(launcher)));
	Executable executable(path, std::move(system));
	
	executable.execute();
	
	return EXIT_SUCCESS;
}


