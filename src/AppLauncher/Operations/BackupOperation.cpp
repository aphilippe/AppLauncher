#include "BackupOperation.h"

#include <vector>

#include "AppLauncher/Domain/BackupFolder.h"
#include "AppLauncher/Domain/FileToBackup.h"
#include "AppLauncher/Repositories/BackupFolderRepository.h"
#include "AppLauncher/Repositories/FileToBackupRepository.h"

using launcher::operations::BackupOperation;

using std::vector;

using launcher::domain::BackupFolder;
using launcher::domain::FileToBackup;
using launcher::repositories::BackupFolderRepository;
using launcher::repositories::FileToBackupRepository;


BackupOperation::BackupOperation(FileToBackupRepository& fileToBackupRepository, launcher::repositories::BackupFolderRepository& backupFolderRepository)
	: _fileToBackupRepository(fileToBackupRepository), _backupFolderRepository(backupFolderRepository)
{
}


BackupOperation::~BackupOperation()
{
}

void BackupOperation::run()
{
	vector<FileToBackup> files = _fileToBackupRepository.get();
	BackupFolder backupFolder = _backupFolderRepository.get();

	for (FileToBackup& file : files) {
		file.copyTo(backupFolder);
	}
}
