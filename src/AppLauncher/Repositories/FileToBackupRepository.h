#pragma once
#include <vector>

#include "AppLauncher/Domain/FileToBackup.h"

namespace launcher { namespace repositories {

class FileToBackupRepository
{
public:
	FileToBackupRepository();
	virtual ~FileToBackupRepository();

	std::vector<launcher::domain::FileToBackup> get();
};

} }