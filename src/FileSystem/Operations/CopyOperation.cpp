#include "CopyOperation.h"
#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS
#include <sstream>
#include "FileSystem/Exceptions/CopyOperationExceptions.h"

using file_system::operations::CopyOperation;
using file_system::Path;
using file_system::exceptions::CopyOperationSourceNotAFileException;
using file_system::exceptions::CopyOperationDestinationNotAFolderException;

CopyOperation::CopyOperation()
{
}


CopyOperation::~CopyOperation()
{
}

void CopyOperation::copy(const Path& sourceFile, const Path& destinationPath)
{
	if (!sourceFile.isFile())
	{
		throw CopyOperationSourceNotAFileException(sourceFile);
	}

    boost::filesystem::path sourceFilePath(sourceFile.stringValue());
    boost::filesystem::path destinationFilePath(destinationPath.stringValue());

    if (destinationPath.isFolder())
	{
        destinationFilePath /= sourceFilePath.filename();
	}

	boost::filesystem::copy_file(sourceFilePath, destinationFilePath, boost::filesystem::copy_option::overwrite_if_exists);
}
