#include "FilePath.h"

using namespace filesystem;

FilePath::FilePath(FolderPath folderPath) : _folderPath(folderPath)
{
}

FilePath::~FilePath()
{
}

std::string FilePath::value()
{
	return _folderPath.value();
}
