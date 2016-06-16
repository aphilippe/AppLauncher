#include "CustomFileSettings.h"

using std::string;

using settings::domain::CustomFileSettings;

CustomFileSettings::CustomFileSettings(const string& backupFolderPath, const std::vector<std::string>& filePaths)
	: _backupFolderPath(backupFolderPath), _filePaths(filePaths)
{
}


CustomFileSettings::~CustomFileSettings()
{
}

string CustomFileSettings::getBackupFolderPath()
{
	return _backupFolderPath;
}

const std::vector<std::string>& CustomFileSettings::getFilePaths() const
{
	return _filePaths;
}
