#include "BackupFolder.h"

#include "AppLauncher/Domain/BackupFolder.h"

using launcher::domain::BackupFolder;

using file_system::Path;

BackupFolder::BackupFolder(const Path& path)
	: _path(path)
{
}


BackupFolder::~BackupFolder()
{
}
