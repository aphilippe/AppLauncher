#include "Settings.h"

using settings::domain::Settings;
using std::string;

Settings::Settings(const string& executablPath, const string& backupPath, const std::vector<std::string>& filePaths)
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

const std::vector<std::string>& Settings::getFilePaths() const
{
	return _filePaths;
}