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

string Path::stringValue()
{
	return _value;
}
