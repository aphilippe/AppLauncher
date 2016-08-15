#include "BackupFolder.h"

#include "AppLauncher/Domain/BackupFolder.h"
#include "AppLauncher/Exceptions/BackupFolderExceptions.h"

using launcher::domain::BackupFolder;

using file_system::Path;

BackupFolder::BackupFolder(const Path& path)
	: _path(path)
{
	if (!path.exists())
	{
		throw launcher::exceptions::BackupFolderNotFoundException(path);
	}

	if (!_path.isFolder())
	{
		throw launcher::exceptions::BackupFolderNotAFolderException(path);
	}

	if (!_path.canWrite())
	{
		throw launcher::exceptions::BackupFolderInvalidPermissionException(path);
	}
}


BackupFolder::~BackupFolder()
{
}

Path BackupFolder::getPath() const
{
	return _path;
}
