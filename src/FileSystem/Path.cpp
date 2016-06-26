#include "Path.h"

using file_system::Path;

using std::string;

Path::Path(const std::string& value) 
	: _value(value)
{
}


Path::~Path()
{
}

string Path::stringValue() const
{
	return _value;
}

bool Path::exists() const
{
	// TODO
	return false;
}

bool Path::isFile() const
{
	// TODO
	return true;
}

bool Path::isFolder() const
{
	// TODO
	return  true;
}

bool Path::canRead() const
{
	// TODO
	return true;
}

bool Path::canWrite() const
{
	// TODO
	return true;
}