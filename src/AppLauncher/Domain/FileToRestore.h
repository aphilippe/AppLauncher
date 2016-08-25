#pragma once

#include "FileSystem/Path.h"

#include "AppLauncher/Domain/BackupFolder.h"

namespace launcher {
	namespace domain {

		class FileToRestore
		{
		public:
			FileToRestore(const file_system::Path& restorePath, const launcher::domain::BackupFolder& backupFolder);
			virtual ~FileToRestore();

			void restore();

		private:
			file_system::Path _restorePath;
			launcher::domain::BackupFolder _backupFolder;
		};

	}
}