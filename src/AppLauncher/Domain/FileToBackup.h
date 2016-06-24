#pragma once

namespace launcher {
	namespace domain {
		class BackupFolder;
	}
}

namespace launcher { namespace domain {
class FileToBackup
{
public:
	FileToBackup();
	virtual ~FileToBackup();

	void copyTo(const launcher::domain::BackupFolder& folder) const;
};

} }