#include "CopyOperationExceptions.h"

#include <sstream>

using file_system::exceptions::CopyOperationSourceNotAFileException;
using file_system::exceptions::CopyOperationDestinationNotAFolderException;
using file_system::Path;

CopyOperationSourceNotAFileException::CopyOperationSourceNotAFileException(const Path& path)
{
	std::stringstream stream;
	stream << path.stringValue() << " as source for copy operation invalid (must be a file)" << std::endl;

	this->setMessage(stream.str());
}

CopyOperationDestinationNotAFolderException::CopyOperationDestinationNotAFolderException(const Path& path)
{
	std::stringstream stream;
	stream << path.stringValue() << " as destination for copy operation invalid (must be a folder)" << std::endl;

	this->setMessage(stream.str());
}