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

const std::vector<std::string>& CustomFileSettings::getFilePaths() const
{
    // TODO: remove this quiclky (memory leak) and return directly vector of FileToBackup
    std::vector<std::string>* vec = new std::vector<std::string>();
    for(auto it = _filePaths.begin(); it != _filePaths.end(); ++it)
    {
        vec->push_back(it->getPath());
    }
    return *vec;
}

string CustomFileSettings::getExecutablePath() const
{
    return _executablePath;
}
