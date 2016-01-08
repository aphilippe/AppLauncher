#include <cstdlib>

#include "FileSystem/File/Executable.h"
#include "Business/ExecutableLaunchers/ExecutableLauncherFactory.h"

using namespace filesystem;

int main() {
	FilePath path(FolderPath(""));
	std::shared_ptr<filesystem::Executable> executable = std::make_shared<filesystem::Executable>(path);

	ExecutableLauncherFactory launcherFactory;
	
	auto launcher = launcherFactory.getLauncher(executable);
	launcher->start();
	
	return EXIT_SUCCESS;
}


