#include "FileToRestoreRepository.h"

#include "Settings/Repositories/SettingsRepository.h"
#include "Core/Exceptions/Exception.h"
#include "FileSystem/Factories/PathFactory.h"
#include "AppLauncher/Domain/BackupFolder.h"

#include <iostream>

using launcher::repositories::FileToRestoreRepository;

using file_system::Path;
using file_system::factories::PathFactory;

using launcher::domain::BackupFolder;
using launcher::domain::FileToRestore;

using settings::domain::Settings;
using settings::repositories::SettingsRepository;

FileToRestoreRepository::FileToRestoreRepository(SettingsRepository& settingsRepository)
	: _settingsRepository(settingsRepository)
{
}


FileToRestoreRepository::~FileToRestoreRepository()
{
}

std::vector<FileToRestore> FileToRestoreRepository::get(const BackupFolder& backupFolder)
{
	const Settings& settings = _settingsRepository.get();

	std::vector<FileToRestore> files;
	PathFactory pathFactory;
	for (settings::domain::FileToBackup pathString : settings.getFilePaths())
	{
		try
		{
			Path path = pathFactory.createPath(pathString.getPath());
			FileToRestore newFile(path, backupFolder);
			files.push_back(newFile);
		}
		catch (core::Exception exception)
		{
			std::cout << "Can not restore file" << std::endl
				<< "\t - " << exception.what() << std::endl;
		}
	}

	return files;
}
