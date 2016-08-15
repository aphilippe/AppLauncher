#include "BackupFolderRepositoryFactory.h"

#include "Repositories.h"

using launcher::factories::BackupFolderRepositoryFactory;

using std::unique_ptr;

using launcher::repositories::BackupFolderRepository;

BackupFolderRepositoryFactory::BackupFolderRepositoryFactory()
{
}


BackupFolderRepositoryFactory::~BackupFolderRepositoryFactory()
{
}

unique_ptr<BackupFolderRepository> BackupFolderRepositoryFactory::create() const
{
	return std::make_unique<BackupFolderRepository>(*settingsRepository);
}
