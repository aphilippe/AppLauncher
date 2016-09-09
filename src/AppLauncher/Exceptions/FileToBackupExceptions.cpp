#include "FileToBackupExceptions.h"
#include <sstream>

using launcher::exceptions::FileToBackupInvalidPathException;
using launcher::exceptions::FileToBackupInvalidPermissionException;
using launcher::exceptions::FileToBackupNotAFileException;
using launcher::exceptions::FileToBackupNotNotfoundException;
using launcher::exceptions::FileToBackupEmptyLabelExcetion;

using file_system::Path;

FileToBackupInvalidPathException::FileToBackupInvalidPathException(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << " : Not a valid path" << std::endl;

	this->setMessage(stringStream.str());
}


FileToBackupInvalidPermissionException::FileToBackupInvalidPermissionException(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << "No read permission" << std::endl;

	this->setMessage(stringStream.str());
}


FileToBackupNotAFileException::FileToBackupNotAFileException(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << " : Not a file" << std::endl;

	this->setMessage(stringStream.str());
}


FileToBackupNotNotfoundException::FileToBackupNotNotfoundException(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << " : file not found." << std::endl;

	this->setMessage(stringStream.str());
}

FileToBackupEmptyLabelExcetion::FileToBackupEmptyLabelExcetion(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << " : no label found." << std::endl;

	this->setMessage(stringStream.str());
}
