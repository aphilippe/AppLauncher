#include "FileToRestoreRepository.h"

using launcher::repositories::FileToRestoreRepository;

using launcher::domain::FileToRestore;

FileToRestoreRepository::FileToRestoreRepository()
{
}


FileToRestoreRepository::~FileToRestoreRepository()
{
}

std::vector<FileToRestore> FileToRestoreRepository::get()
{
	return std::vector<launcher::domain::FileToRestore>();
}
