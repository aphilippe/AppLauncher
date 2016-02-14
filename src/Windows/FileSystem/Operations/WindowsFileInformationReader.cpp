#include "WindowsFileInformationReader.h"

#include <Windows.h>
#include "Shlwapi.h"

using namespace clt::filesystem::operations;

WindowsFileInformationReader::WindowsFileInformationReader()
{
}


WindowsFileInformationReader::~WindowsFileInformationReader()
{
}

bool clt::filesystem::operations::WindowsFileInformationReader::exists(const clt::filesystem::entities::Path & path) const
{
	return PathFileExists(path.getValue().c_str());
}

bool clt::filesystem::operations::WindowsFileInformationReader::isDirectory(const clt::filesystem::entities::Path & path) const
{
	return PathIsDirectory(path.getValue().c_str());
}

std::string clt::filesystem::operations::WindowsFileInformationReader::getFileExtension(const clt::filesystem::entities::Path & path) const
{
	return PathFindExtension(path.getValue().c_str());
}
