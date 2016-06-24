#include "BackupFolderRepository.h"

using launcher::repositories::BackupFolderRepository;

using launcher::domain::BackupFolder;

BackupFolderRepository::BackupFolderRepository()
{
}


BackupFolderRepository::~BackupFolderRepository()
{
}

BackupFolder BackupFolderRepository::get()
{
	return BackupFolder();
}
