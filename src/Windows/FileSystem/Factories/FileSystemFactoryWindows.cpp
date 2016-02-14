#include "FileSystem/Factories/FileSystemFactory.h"

#include "FileSystem/Operations/ExecutableLauncherWindows.h"
#include "FileSystem/Operations/WindowsPathInformationReader.h"

using namespace std;
using namespace clt::filesystem::operations;
using namespace clt::filesystem::factories;

std::unique_ptr<clt::filesystem::FileSystem> clt::filesystem::factories::FileSystemFactory::createFileSystem()
{
	unique_ptr<ExecutableLauncherWindows> executableLauncher(new ExecutableLauncherWindows());
	unique_ptr<WindowsPathInformationReader> informationReader(new WindowsPathInformationReader());
	unique_ptr<FileSystem> fileSystem(new FileSystem(move(executableLauncher), move(informationReader)));
	return move(fileSystem);
}