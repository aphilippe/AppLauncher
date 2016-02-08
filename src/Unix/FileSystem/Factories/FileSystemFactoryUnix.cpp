#include <stdio.h>
#include "FileSystem/Factories/FileSystemFactory.h"

#include "FilesYstem/Operations/ExecutableLauncherUnix.h"

using namespace std;
using namespace clt::filesystem;
using namespace clt::filesystem::operations;
using namespace clt::filesystem::factories;

std::unique_ptr<FileSystem>
FileSystemFactory::createFileSystem()
{
	unique_ptr<ExecutableLauncherUnix> executableLauncher(new ExecutableLauncherUnix());
	unique_ptr<FileSystem> fileSystem(new FileSystem(move(executableLauncher)));
	return move(fileSystem);
}
