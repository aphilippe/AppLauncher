#pragma once

#include "AppLauncher/Domain/BackupFolder.h"

namespace settings {
	namespace repositories {
		class SettingsRepository;
	}
}

namespace launcher { namespace repositories {

class BackupFolderRepository
{
public:
	BackupFolderRepository(settings::repositories::SettingsRepository& settingsRepository);
	virtual ~BackupFolderRepository();

	launcher::domain::BackupFolder get();

private:
	settings::repositories::SettingsRepository& _settingsRepository;
};

} }