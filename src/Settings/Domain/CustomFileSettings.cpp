#include "CustomFileSettings.h"

using std::string;

using settings::domain::CustomFileSettings;

CustomFileSettings::CustomFileSettings(const string& backupFolderPath, const std::vector<std::string>& filePaths, const std::string& executablePath)
    : _backupFolderPath(backupFolderPath), _filePaths(filePaths), _executablePath(executablePath)
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

string CustomFileSettings::getExecutablePath() const
{
    return _executablePath;
}
