#include "Settings.h"

using settings::domain::Settings;
using settings::domain::FileToBackup;
using std::string;

Settings::Settings(const string& executablPath, const string& backupPath, const std::vector<FileToBackup>& filePaths)
	: _executablePath(executablPath), _backupPath(backupPath), _filePaths(filePaths)
{
}


Settings::~Settings()
{
}

string Settings::getExecutablePath() const
{
	return _executablePath;
}

string Settings::getBackupPath() const
{
	return _backupPath;
}

const std::vector<FileToBackup>& Settings::getFilePaths() const
{
	return _filePaths;
}