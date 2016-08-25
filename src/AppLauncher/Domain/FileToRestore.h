#pragma once

#include "FileSystem/Path.h"

namespace launcher {
	namespace domain {
		class BackupFolder;
	}
}

namespace launcher {
	namespace domain {

		class FileToRestore
		{
		public:
			FileToRestore(const file_system::Path& restorePath);
			virtual ~FileToRestore();

			void restore(const launcher::domain::BackupFolder& backupFolder);

		private:
			file_system::Path _restorePath;
		};

	}
}