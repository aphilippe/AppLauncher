#pragma once
#include <vector>

#include "AppLauncher/Domain/FileToBackup.h"

namespace settings {
	namespace repositories {
		class SettingsRepository;
	}
}

namespace launcher { namespace repositories {

class FileToBackupRepository
{
public:
	FileToBackupRepository(settings::repositories::SettingsRepository& settingsRepository);
	virtual ~FileToBackupRepository();

	std::vector<launcher::domain::FileToBackup> get();

private:
	settings::repositories::SettingsRepository& _settingsRepository;
};

} }