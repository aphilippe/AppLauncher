#include "CustomFileSettingsBuilder.h"

using settings::builders::CustomFileSettingsBuilder;
using settings::domain::CustomFileSettings;
using settings::domain::FileToBackup;

using std::string;

CustomFileSettings CustomFileSettingsBuilder::build()
{
    return settings::domain::CustomFileSettings(_backupFolderPath, _filePaths, _executablePath);
}

void CustomFileSettingsBuilder::setBackupFolderPath(const string & path)
{
	_backupFolderPath = path;
}

void CustomFileSettingsBuilder::setFilePaths(const std::vector<FileToBackup>& paths)
{
	_filePaths = paths;
}

void CustomFileSettingsBuilder::setExecutablePath(const string& path)
{
    _executablePath = path;
}
