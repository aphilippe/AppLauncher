#include "FileSystem/Factories/EntityFactory.h"

#include "FileSystem/Operations/WindowsPathInformationReader.h"
#include "FileSystem/Operations/ExecutableLauncherWindows.h"

#include "FileSystem/Entities/Validators/WindowsExecutablePathValidator.h"

using namespace clt::filesystem::factories;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::operations;

Path 
EntityFactory::createPath(const std::string & path) const
{
	std::shared_ptr<WindowsPathInformationReader> fileInformationReader = std::make_shared<WindowsPathInformationReader>();
	return Path(path, fileInformationReader);
}

clt::filesystem::entities::Executable clt::filesystem::factories::EntityFactory::createExecutable(const std::string & path) const
{
	Path systemPath = this->createPath(path);
	std::shared_ptr<ExecutableLauncherWindows> launcher = std::make_shared<ExecutableLauncherWindows>();
	validators::WindowsExecutablePathValidator validator;
	return Executable(systemPath, launcher, validator);
}
