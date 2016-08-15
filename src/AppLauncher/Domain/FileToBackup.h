#pragma once

#include "FileSystem/Path.h"

namespace launcher {
	namespace domain {
		class BackupFolder;
	}
}

namespace launcher { namespace domain {
class FileToBackup
{
public:
	FileToBackup(const file_system::Path& path);
	virtual ~FileToBackup();

	file_system::Path getPath() const;

	void copyTo(const launcher::domain::BackupFolder& folder) const;

private:
	file_system::Path _path;
};

} }