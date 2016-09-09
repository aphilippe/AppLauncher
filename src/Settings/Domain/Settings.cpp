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

const std::vector<std::string>& Settings::getFilePaths() const
{
	// TODO: return FIleToBackup directly
	std::vector<string>* vec = new std::vector<string>();

	for (auto it = _filePaths.begin(); it != _filePaths.end(); it++)
	{
		vec->push_back(it->getPath());
	}
	return *vec;
}