#include "BackupOperation.h"

#include <vector>

#include "AppLauncher/Domain/BackupFolder.h"
#include "AppLauncher/Domain/FileToBackup.h"

using std::vector;

using launcher::domain::BackupFolder;
using launcher::domain::FileToBackup;
using launcher::operations::BackupOperation;

BackupOperation::BackupOperation()
{
}


BackupOperation::~BackupOperation()
{
}

void BackupOperation::run()
{
	vector<FileToBackup> files;
	BackupFolder backupFolder;

	for (FileToBackup& file : files) {
		file.copyTo(backupFolder);
	}
}
