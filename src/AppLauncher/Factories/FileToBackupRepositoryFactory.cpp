#include "FileToBackupRepositoryFactory.h"

#include "Repositories.h"

using launcher::factories::FileToBackupRepositoryFactory;

using launcher::repositories::FileToBackupRepository;

FileToBackupRepositoryFactory::FileToBackupRepositoryFactory()
{
}


FileToBackupRepositoryFactory::~FileToBackupRepositoryFactory()
{
}

std::unique_ptr<FileToBackupRepository> FileToBackupRepositoryFactory::create() const
{
	return std::make_unique<FileToBackupRepository>(*settingsRepository);
}
