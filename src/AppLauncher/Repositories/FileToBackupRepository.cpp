#include "FileToBackupRepository.h"

#include "Settings/Repositories/SettingsRepository.h"
#include "Core/Exceptions/Exception.h"
#include "FileSystem/Factories/PathFactory.h"

#include <iostream>


using launcher::repositories::FileToBackupRepository;

using file_system::Path;
using file_system::factories::PathFactory;

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
	PathFactory pathFactory;
	for (std::string pathString : settings.getFilePaths())
	{
		try
		{

			Path path = pathFactory.createPath(pathString);
			FileToBackup newFile(path);
			files.push_back(newFile);
		}
		catch (core::Exception exception)
		{
			std::cout << "Can not backup file" << std::endl
				<< "\t - " << exception.what() << std::endl;
		}
	}

	return files;
}
