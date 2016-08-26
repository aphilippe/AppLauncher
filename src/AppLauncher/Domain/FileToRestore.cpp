#include "FileToRestore.h"
#include "FileSystem/Operations/CopyOperation.h"
#include "AppLauncher/Exceptions/FileToRestoreException.h"

using launcher::domain::FileToRestore;

using file_system::Path;
using file_system::operations::CopyOperation;

using launcher::domain::BackupFolder;

FileToRestore::FileToRestore(const Path& restorePath, const BackupFolder& backupFolder)
	: _restorePath(restorePath), _backupFolder(backupFolder)
{
	Path backupPath = _backupFolder.getPath().addComponent(_restorePath.getFileName());
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
	Path backupPath = _backupFolder.getPath().addComponent(_restorePath.getFileName());
	CopyOperation operation;
	operation.copy(backupPath, _restorePath.getParent());
}
