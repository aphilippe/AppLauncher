#include "FolderPath.h"

using namespace filesystem;

filesystem::FolderPath::FolderPath(const std::string & value) : _value(value)
{
}

FolderPath::~FolderPath()
{
}

std::string FolderPath::value()
{
	return _value;
}
