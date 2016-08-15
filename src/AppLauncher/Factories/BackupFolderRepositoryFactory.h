#pragma once

#include <memory>

#include "AppLauncher/Repositories/BackupFolderRepository.h"

namespace launcher { namespace factories {

class BackupFolderRepositoryFactory
{
public:
	BackupFolderRepositoryFactory();
	virtual ~BackupFolderRepositoryFactory();

	std::unique_ptr<launcher::repositories::BackupFolderRepository> create() const;
};

} }