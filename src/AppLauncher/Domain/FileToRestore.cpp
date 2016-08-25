#include "FileToRestore.h"

#include "AppLauncher/Domain/BackupFolder.h"

using launcher::domain::FileToRestore;

using file_system::Path;

using launcher::domain::BackupFolder;

FileToRestore::FileToRestore(const Path& restorePath)
	: _restorePath(restorePath)
{
}


FileToRestore::~FileToRestore()
{
}

void FileToRestore::restore(const BackupFolder & backupFolder)
{
}
