#include "Path.h"
#include "FileSystem\Operations\ReadInformationOperation.h"

using file_system::Path;

using file_system::operations::ReadInformationOperation;

using std::string;

Path::Path(const std::string& value, std::shared_ptr<ReadInformationOperation> readInformationOperation)
	: _value(value), _readInformationOperation(std::move(readInformationOperation))
{
}


Path::Path(const Path& otherPath)
	:_value(otherPath._value), _readInformationOperation(otherPath._readInformationOperation)
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
	return _readInformationOperation->exists(*this);
}

bool Path::isFile() const
{
	return _readInformationOperation->isFile(*this);
}

bool Path::isFolder() const
{
	return  _readInformationOperation->isDirectory(*this);
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