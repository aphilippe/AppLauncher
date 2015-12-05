#include "FilePath.h"


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
