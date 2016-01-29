#include <cstdlib>

#include "System/Entities/Executable.h"
#include "System/Operations/ExecutableLauncherUnix.h"

using namespace clt::system::entities;
using namespace clt::system::operations;

int main() {
	Path path("");
	std::unique_ptr<IExecutableLauncher> launcher(new ExecutableLauncherUnix());
	Executable executable(path, std::move(launcher));
	
	
	executable.execute();
	
	return EXIT_SUCCESS;
}


