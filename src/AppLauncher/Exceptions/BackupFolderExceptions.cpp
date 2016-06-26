#include "BackupFolderExceptions.h"
#include <sstream>

using launcher::exceptions::BackupFolderInvalidPermissionException;
using launcher::exceptions::BackupFolderNotAFolderException;
using launcher::exceptions::BackupFolderNotFoundException;

using file_system::Path;

BackupFolderInvalidPermissionException::BackupFolderInvalidPermissionException(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << "No read permission" << std::endl;

	this->setMessage(stringStream.str());
}


BackupFolderNotAFolderException::BackupFolderNotAFolderException(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << " : Not a folder" << std::endl;

	this->setMessage(stringStream.str());
}


BackupFolderNotFoundException::BackupFolderNotFoundException(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << " : folder not found." << std::endl;

	this->setMessage(stringStream.str());
}
