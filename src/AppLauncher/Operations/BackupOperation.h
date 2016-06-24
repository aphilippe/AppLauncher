#pragma once
#include "AppLauncher/Operations/IOperation.h"

namespace launcher {
	namespace repositories {
		class FileToBackupRepository;
	}
}

namespace launcher { namespace operations {

class BackupOperation : public launcher::IOperation
{
public:
	BackupOperation(launcher::repositories::FileToBackupRepository& fileToBackupRepository);
	virtual ~BackupOperation();

	void run() override;

private:
	launcher::repositories::FileToBackupRepository& _fileToBackupRepository;
};

} }