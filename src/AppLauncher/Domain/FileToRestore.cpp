#include "FileToRestore.h"
#include "FileSystem/Operations/CopyOperation.h"
#include "AppLauncher/Exceptions/FileToRestoreException.h"

using launcher::domain::FileToRestore;

using file_system::Path;
using file_system::operations::CopyOperation;

using launcher::domain::BackupFolder;

FileToRestore::FileToRestore(const Path& restorePath, const BackupFolder& backupFolder, const std::string& label)
	: _restorePath(restorePath), _backupFolder(backupFolder), _label(label)
{
	if (label.empty())
	{
		throw launcher::exceptions::FileToRestoreLabelNotfoundException(restorePath);
	}

	Path backupPath = _backupFolder.getPath().addComponent(_label);
	if (!backupPath.exists())
	{
		throw launcher::exceptions::FileToRestoreNotNotfoundException(backupPath);
	}

	if (!backupPath.isFile())
	{
		throw launcher::exceptions::FileToRestoreNotAFileException(backupPath);
	}

	if (!backupPath.canRead())
	{
		throw launcher::exceptions::FileToRestoreInvalidPermissionException(backupPath);
	}
}


FileToRestore::~FileToRestore()
{
}

void FileToRestore::restore()
{
	Path backupPath = _backupFolder.getPath().addComponent(_label);
	CopyOperation operation;
	operation.copy(backupPath, _restorePath);
}
