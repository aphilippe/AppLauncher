#pragma once

#include "FileSystem/Path.h"

namespace launcher { namespace domain {

class BackupFolder
{
public:
	BackupFolder(const file_system::Path& path);
	virtual ~BackupFolder();

private:
	file_system::Path _path;
};

} }