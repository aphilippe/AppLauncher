#include "FileToRestore.h"
#include "FileSystem/Operations/CopyOperation.h"

using launcher::domain::FileToRestore;

using file_system::Path;
using file_system::operations::CopyOperation;

using launcher::domain::BackupFolder;

FileToRestore::FileToRestore(const Path& restorePath, const BackupFolder& backupFolder)
	: _restorePath(restorePath), _backupFolder(backupFolder)
{
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
