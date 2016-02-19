#include "FileSystem/Operations/UnixPathInformationReader.h"


using namespace clt::filesystem::operations;

UnixPathInformationReader::UnixPathInformationReader()
{
}


UnixPathInformationReader::~UnixPathInformationReader()
{
}

bool clt::filesystem::operations::UnixPathInformationReader::exists(const clt::filesystem::entities::Path & path) const
{
	return false;
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
