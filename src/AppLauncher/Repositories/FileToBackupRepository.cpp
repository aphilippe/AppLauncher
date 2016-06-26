#include "FileToBackupRepository.h"

#include "Settings/Repositories/SettingsRepository.h"


using launcher::repositories::FileToBackupRepository;

using file_system::Path;

using launcher::domain::FileToBackup;

using settings::domain::Settings;
using settings::repositories::SettingsRepository;

FileToBackupRepository::FileToBackupRepository(SettingsRepository& settingsRepository)
	: _settingsRepository(settingsRepository)
{
}


FileToBackupRepository::~FileToBackupRepository()
{
}

std::vector<FileToBackup>FileToBackupRepository::get()
{
	const Settings& settings = _settingsRepository.get();

	std::vector<FileToBackup> files;
	for (std::string pathString : settings.getFilePaths())
	{
		Path path(pathString);
		FileToBackup newFile(path);
		files.push_back(newFile);
	}

	return files;
}
