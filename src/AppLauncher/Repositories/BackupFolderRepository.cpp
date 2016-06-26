#include "BackupFolderRepository.h"

#include "Settings/Repositories/SettingsRepository.h"


using launcher::repositories::BackupFolderRepository;

using file_system::Path;

using launcher::domain::BackupFolder;

using settings::domain::Settings;
using settings::repositories::SettingsRepository;

BackupFolderRepository::BackupFolderRepository(SettingsRepository& settingsRepository)
	: _settingsRepository(settingsRepository)
{
}


BackupFolderRepository::~BackupFolderRepository()
{
}

BackupFolder BackupFolderRepository::get()
{
	const Settings& settings = _settingsRepository.get();
	std::string folderPathString = settings.getBackupPath();
	Path path(folderPathString);


	return BackupFolder(path);
}
