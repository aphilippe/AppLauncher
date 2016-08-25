#pragma once
#include <vector>

#include "AppLauncher/Domain/FileToRestore.h"

namespace launcher { namespace repositories {

class FileToRestoreRepository
{
public:
	FileToRestoreRepository();
	virtual ~FileToRestoreRepository();

	std::vector<launcher::domain::FileToRestore> get();
};

} }