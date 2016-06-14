#include "Settings.h"

using settings::domain::Settings;
using std::string;

Settings::Settings(const std::string& executablPath, const string& backupPath)
	: _executablePath(executablPath), _backupPath(backupPath)
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
