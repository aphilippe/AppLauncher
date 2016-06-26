#include "FileToBackup.h"

#include "AppLauncher/Domain/BackupFolder.h"

using launcher::domain::FileToBackup;

using file_system::Path;

using launcher::domain::BackupFolder;

FileToBackup::FileToBackup(const Path& path)
	: _path(path)
{
}


FileToBackup::~FileToBackup()
{
}

void FileToBackup::copyTo(const BackupFolder & folder) const
{
	// TODO
}
