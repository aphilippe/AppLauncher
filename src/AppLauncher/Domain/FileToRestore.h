#pragma once

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
			FileToRestore();
			virtual ~FileToRestore();

			void restore(const launcher::domain::BackupFolder& backupFolder);
		};

	}
}