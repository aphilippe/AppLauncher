#include "FileSystem.h"

using namespace clt::filesystem;

clt::filesystem::FileSystem::FileSystem(std::unique_ptr<operations::IExecutableLauncher> executableLauncher, std::unique_ptr<operations::IPathInformationReader> fileInformationReader)
{
	_executableLauncher = std::move(executableLauncher);
	_fileInformationReader = std::move(fileInformationReader);
}


clt::filesystem::FileSystem::~FileSystem()
{
}

void clt::filesystem::FileSystem::execute(const clt::filesystem::entities::Path & path) const
{
	_executableLauncher->execute(path);
}

bool clt::filesystem::FileSystem::pathExists(const clt::filesystem::entities::Path & path) const
{
	return _fileInformationReader->exists(path);
}

bool clt::filesystem::FileSystem::pathIsDirectory(const clt::filesystem::entities::Path & path) const
{
	return _fileInformationReader->isDirectory(path);
}
