#pragma once
#include "AppLauncher/Operations/IOperation.h"

namespace launcher {
	namespace repositories {
		class FileToBackupRepository;
		class BackupFolderRepository;
	}
}

namespace launcher { namespace operations {

class BackupOperation : public launcher::IOperation
{
public:
	BackupOperation(launcher::repositories::FileToBackupRepository& fileToBackupRepository, launcher::repositories::BackupFolderRepository& backupFolderRepository);
	virtual ~BackupOperation();

	void run() override;

private:
	launcher::repositories::FileToBackupRepository& _fileToBackupRepository;
	launcher::repositories::BackupFolderRepository& _backupFolderRepository;
};

} }