
#include "ReadInformationOperation.h"
#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS

using file_system::operations::ReadInformationOperation;

using file_system::Path;

bool ReadInformationOperation::exists(const Path & path) const
{
	return boost::filesystem::exists(path.stringValue());
}

bool ReadInformationOperation::isDirectory(const Path & path) const
{
	return boost::filesystem::is_directory(path.stringValue());
}

bool ReadInformationOperation::isFile(const Path & path) const
{
	return boost::filesystem::is_regular(path.stringValue());
}

bool ReadInformationOperation::canRead(const Path& path) const {
	
	boost::filesystem::file_status status = boost::filesystem::status(path.stringValue());
	return status.permissions() & boost::filesystem::owner_read;
}

bool ReadInformationOperation::canWrite(const Path& path) const {
	
	boost::filesystem::file_status status = boost::filesystem::status(path.stringValue());
	return status.permissions() & boost::filesystem::owner_write;
}