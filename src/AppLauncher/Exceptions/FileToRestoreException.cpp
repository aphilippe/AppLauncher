#include "FileToRestoreException.h"

#include <sstream>

using launcher::exceptions::FileToRestoreInvalidPathException;
using launcher::exceptions::FileToRestoreInvalidPermissionException;
using launcher::exceptions::FileToRestoreNotAFileException;
using launcher::exceptions::FileToRestoreNotNotfoundException;
using launcher::exceptions::FileToRestoreLabelNotfoundException;

using file_system::Path;

FileToRestoreInvalidPathException::FileToRestoreInvalidPathException(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << " : Not a valid path" << std::endl;

	this->setMessage(stringStream.str());
}


FileToRestoreInvalidPermissionException::FileToRestoreInvalidPermissionException(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << "No read permission" << std::endl;

	this->setMessage(stringStream.str());
}


FileToRestoreNotAFileException::FileToRestoreNotAFileException(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << " : Not a file" << std::endl;

	this->setMessage(stringStream.str());
}


FileToRestoreNotNotfoundException::FileToRestoreNotNotfoundException(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << " : file not found." << std::endl;

	this->setMessage(stringStream.str());
}

FileToRestoreLabelNotfoundException::FileToRestoreLabelNotfoundException(const Path& path)
{
	std::ostringstream stringStream;

	stringStream << path.stringValue() << " : label not found." << std::endl;

	this->setMessage(stringStream.str());
}

