#include "FileSystem/Factories/EntityFactory.h"

#include "FileSystem/Operations/UnixPathInformationReader.h"
#include "FileSystem/Operations/ExecutableLauncherUnix.h"

#include "FileSystem/Entities/Validators/UnixExecutablePathValidator.h"

using namespace clt::filesystem::factories;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::operations;

Path
EntityFactory::createPath(const std::string & path) const
{
	std::shared_ptr<UnixPathInformationReader> fileInformationReader = std::make_shared<UnixPathInformationReader>();
	return Path(path, fileInformationReader);
}

clt::filesystem::entities::Executable clt::filesystem::factories::EntityFactory::createExecutable(const std::string & path) const
{
	Path systemPath = this->createPath(path);
	std::shared_ptr<ExecutableLauncherUnix> launcher = std::make_shared<ExecutableLauncherUnix>();
	validators::UnixExecutablePathValidator validator;
	return Executable(systemPath, launcher, validator);
}
