#include "FileToBackup.h"

#include "AppLauncher/Domain/BackupFolder.h"
#include "AppLauncher/Exceptions/FileToBackupExceptions.h"
#include "FileSystem/Operations/CopyOperation.h"

using launcher::domain::FileToBackup;

using file_system::Path;
using file_system::operations::CopyOperation;

using launcher::domain::BackupFolder;

FileToBackup::FileToBackup(const Path& path, const std::string& label)
	: _path(path), _label(label)
{
	if (!_path.exists())
	{
		throw launcher::exceptions::FileToBackupNotNotfoundException(path);
	}

	if (!_path.isFile())
	{
		throw launcher::exceptions::FileToBackupNotAFileException(path);
	}

	if (!_path.canRead())
	{
		throw launcher::exceptions::FileToBackupInvalidPermissionException(path);
	}

	if (_label.empty())
	{
		throw launcher::exceptions::FileToBackupEmptyLabelExcetion(path);
	}
}


FileToBackup::~FileToBackup()
{
}

file_system::Path launcher::domain::FileToBackup::getPath() const
{
	return _path;
}

std::string launcher::domain::FileToBackup::getLabel() const
{
	return _label;
}

void FileToBackup::copyTo(const BackupFolder & folder) const
{
	CopyOperation operation;
	operation.copy(this->getPath(), folder.getPath().addComponent(this->getLabel()));
}
