#pragma once

#include "AppLauncher/Domain/BackupFolder.h"

namespace launcher { namespace repositories {

class BackupFolderRepository
{
public:
	BackupFolderRepository();
	virtual ~BackupFolderRepository();

	launcher::domain::BackupFolder get();
};

} }