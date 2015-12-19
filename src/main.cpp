#include <cstdlib>

#include "FileSystem/File/Executable.h"
#include "Business/ExecutableLauncher.h"

using namespace filesystem;

int main() {
	FilePath path(FolderPath(""));
	std::shared_ptr<filesystem::Executable> executable = std::make_shared<filesystem::Executable>(path);

	ExecutableLauncher launcher(executable);
	launcher.start();

	return EXIT_SUCCESS;
}


