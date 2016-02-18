#include "WindowsPathInformationReader.h"

#include <Windows.h>
#include "Shlwapi.h"

using namespace clt::filesystem::operations;

WindowsPathInformationReader::WindowsPathInformationReader()
{
}


WindowsPathInformationReader::~WindowsPathInformationReader()
{
}

bool clt::filesystem::operations::WindowsPathInformationReader::exists(const clt::filesystem::entities::Path & path) const
{
	return PathFileExists(path.getValue().c_str());
}

bool clt::filesystem::operations::WindowsPathInformationReader::isDirectory(const clt::filesystem::entities::Path & path) const
{
	return PathIsDirectory(path.getValue().c_str());
}

std::string clt::filesystem::operations::WindowsPathInformationReader::getFileExtension(const clt::filesystem::entities::Path & path) const
{
	return PathFindExtension(path.getValue().c_str());
}
