#include "FileSystem.h"

clt::filesystem::FileSystem::FileSystem(std::unique_ptr<operations::IExecutableLauncher> executableLauncher)
{
	_executableLauncher = std::move(executableLauncher);
}

clt::filesystem::FileSystem::~FileSystem()
{
}

void clt::filesystem::FileSystem::execute(const clt::filesystem::entities::Path & path)
{
	_executableLauncher->execute(path);
}
