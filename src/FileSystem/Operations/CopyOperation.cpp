#include "CopyOperation.h"
#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS
#include <sstream>

using file_system::operations::CopyOperation;
using file_system::Path;

CopyOperation::CopyOperation()
{
}


CopyOperation::~CopyOperation()
{
}

void CopyOperation::copy(const Path& sourceFile, const Path& destinationFolder)
{
	boost::filesystem::path sourceFilePath(sourceFile.stringValue());
	boost::filesystem::path destinationFilePath(destinationFolder.stringValue());

	destinationFilePath /= sourceFilePath.filename();

	boost::filesystem::copy_file(sourceFilePath, destinationFilePath);
}
