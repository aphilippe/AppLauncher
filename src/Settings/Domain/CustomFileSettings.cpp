#include "CustomFileSettings.h"

using std::string;

using settings::domain::CustomFileSettings;
using settings::domain::FileToBackup;

CustomFileSettings::CustomFileSettings(const string& backupFolderPath, const std::vector<FileToBackup>& filePaths, const std::string& executablePath)
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

const std::vector<FileToBackup>& CustomFileSettings::getFilePaths() const
{
    return _filePaths;
}

string CustomFileSettings::getExecutablePath() const
{
    return _executablePath;
}
