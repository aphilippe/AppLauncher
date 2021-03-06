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
	FileToBackup(const file_system::Path& path, const std::string& label);
	virtual ~FileToBackup();

	file_system::Path getPath() const;
	std::string getLabel() const;

	void copyTo(const launcher::domain::BackupFolder& folder) const;

private:
	file_system::Path _path;
	std::string _label;
};

} }