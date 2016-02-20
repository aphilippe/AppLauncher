#include "FileSystem/Operations/UnixPathInformationReader.h"

#include <unistd.h>


using namespace clt::filesystem::operations;

UnixPathInformationReader::UnixPathInformationReader()
{
}


UnixPathInformationReader::~UnixPathInformationReader()
{
}

bool clt::filesystem::operations::UnixPathInformationReader::exists(const clt::filesystem::entities::Path & path) const
{
	return access(path.getValue().c_str(), F_OK) == 0;
}

bool clt::filesystem::operations::UnixPathInformationReader::isDirectory(const clt::filesystem::entities::Path & path) const
{
	return false;
}

std::string clt::filesystem::operations::UnixPathInformationReader::getFileExtension(const clt::filesystem::entities::Path & path) const
{
	return std::string();
}

bool clt::filesystem::operations::UnixPathInformationReader::isExecutable(const clt::filesystem::entities::Path & path) const
{
	return false;
}
