#pragma once
#include <memory>

#include "AppLauncher/Repositories/FileToBackupRepository.h"

namespace launcher { namespace factories {

class FileToBackupRepositoryFactory
{
public:
	FileToBackupRepositoryFactory();
	virtual ~FileToBackupRepositoryFactory();

	std::unique_ptr<launcher::repositories::FileToBackupRepository> create() const;
};

} }