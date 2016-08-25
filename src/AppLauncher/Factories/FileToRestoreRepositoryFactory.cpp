#include "FileToRestoreRepositoryFactory.h"

#include "Repositories.h"

using launcher::factories::FileToRestoreRepositoryFactory;
using launcher::repositories::FileToRestoreRepository;

FileToRestoreRepositoryFactory::FileToRestoreRepositoryFactory()
{
}


FileToRestoreRepositoryFactory::~FileToRestoreRepositoryFactory()
{
}

std::unique_ptr<FileToRestoreRepository> FileToRestoreRepositoryFactory::create() const
{
	return std::make_unique<FileToRestoreRepository>();
}
