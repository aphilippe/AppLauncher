#include "RestoreOperation.h"
#include <vector>

#include "AppLauncher/Domain/BackupFolder.h"
#include "AppLauncher/Repositories/FileToRestoreRepository.h"
#include "AppLauncher/Repositories/BackupFolderRepository.h"

using launcher::operations::RestoreOperation;
using launcher::repositories::FileToRestoreRepository;
using launcher::domain::FileToRestore;
using launcher::repositories::BackupFolderRepository;
using launcher::domain::BackupFolder;

RestoreOperation::RestoreOperation(FileToRestoreRepository& fileToRestoreRepository, BackupFolderRepository& backupFolderRepository)
	: _fileToRestoreRepository(fileToRestoreRepository), _backupFolderRepository(backupFolderRepository)
{
}


RestoreOperation::~RestoreOperation()
{
}

void RestoreOperation::run()
{
	BackupFolder backupFolder = _backupFolderRepository.get();
	std::vector<FileToRestore> files = _fileToRestoreRepository.get();

	for (FileToRestore& file : files)
	{
		file.restore(backupFolder);
	}
}
