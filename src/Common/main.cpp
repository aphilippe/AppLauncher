#include <cstdlib>

#include "System/Entities/Executable.h"
#include "System/Operations/ExecutableLauncherWindows.h"
#include <memory>

using namespace clt::system::entities;
using namespace clt::system::operations;

int main() {
	// TODO: use argument to set the path
	Path path("path to executable");
	// TODO: create a factory that return an executable with only the Path
	std::unique_ptr<IExecutableLauncher> launcher(new ExecutableLauncherWindows());
	Executable executable(path, std::move(launcher));
	
	executable.execute();
	
	return EXIT_SUCCESS;
}


