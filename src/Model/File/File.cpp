#include "File.h"

File::File(const FilePath & path) : _path(path)
{
}

File::~File()
{
}

FilePath File::path()
{
	return _path;
}
