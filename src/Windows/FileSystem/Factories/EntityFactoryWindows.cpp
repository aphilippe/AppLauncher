#include "FileSystem/Factories/EntityFactory.h"

#include "FileSystem/Operations/WindowsFileInformationReader.h"

using namespace clt::filesystem::factories;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::operations;

Path 
EntityFactory::createPath(const std::string & path) const
{
	std::shared_ptr<WindowsFileInformationReader> fileInformationReader = std::make_shared<WindowsFileInformationReader>();
	return Path(path, fileInformationReader);
}