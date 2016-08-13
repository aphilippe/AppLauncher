#include "CopyOperation.h"
#include <boost/filesystem.hpp>
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

	destinationFilePath.append(sourceFilePath.filename().c_str());

	boost::filesystem::copy_file(sourceFilePath, destinationFilePath);
}
