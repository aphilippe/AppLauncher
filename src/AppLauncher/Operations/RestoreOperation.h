#pragma once

#include "AppLauncher/Operations/IOperation.h"

namespace launcher {
	namespace repositories {
		class FileToRestoreRepository;
		class BackupFolderRepository;
	}
}

namespace launcher {
	namespace operations {

		class RestoreOperation : public launcher::IOperation
		{
		public:
			RestoreOperation(launcher::repositories::FileToRestoreRepository& fileToRestoreRepository, launcher::repositories::BackupFolderRepository& backupFolderRepository);
			virtual ~RestoreOperation();

			void run() override;

		private:
			launcher::repositories::FileToRestoreRepository& _fileToRestoreRepository;
			launcher::repositories::BackupFolderRepository& _backupFolderRepository;
		};
	}
}