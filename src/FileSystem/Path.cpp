#include "Path.h"
#include "FileSystem/Operations/ReadInformationOperation.h"

#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS

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
	return  _readInformationOperation->canRead(*this);
}

bool Path::canWrite() const
{
	return _readInformationOperation->canWrite(*this);
}

Path Path::getParent() const
{
	return Path(boost::filesystem::path(_value).parent_path().string(), _readInformationOperation);
}