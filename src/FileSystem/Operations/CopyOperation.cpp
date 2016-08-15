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

void CopyOperation::copy(const Path& sourceFile, const Path& destinationFolder)
{
	if (!sourceFile.isFile())
	{
		throw CopyOperationSourceNotAFileException(sourceFile);
	}

	if (!destinationFolder.isFolder())
	{
		throw CopyOperationDestinationNotAFolderException(destinationFolder);
	}

	boost::filesystem::path sourceFilePath(sourceFile.stringValue());
	boost::filesystem::path destinationFilePath(destinationFolder.stringValue());

	destinationFilePath /= sourceFilePath.filename();

	boost::filesystem::copy_file(sourceFilePath, destinationFilePath);
}
