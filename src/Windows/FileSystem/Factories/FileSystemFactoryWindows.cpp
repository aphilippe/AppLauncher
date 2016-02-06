#include "FileSystem/Factories/FileSystemFactory.h"

#include "FileSystem/Operations/ExecutableLauncherWindows.h"

using namespace clt::filesystem::operations;
using namespace clt::filesystem::factories;

clt::filesystem::FileSystem * clt::filesystem::factories::FileSystemFactory::newFileSystem()
{
	std::unique_ptr<ExecutableLauncherWindows> executableLauncher(new ExecutableLauncherWindows());

	return new FileSystem(std::move(executableLauncher));
}