#include "CustomFileSettings.h"

using std::string;

using settings::domain::CustomFileSettings;

CustomFileSettings::CustomFileSettings(const string& backupFolderPath)
	: _backupFolderPath(backupFolderPath)
{
}


CustomFileSettings::~CustomFileSettings()
{
}

string CustomFileSettings::getBackupFolderPath()
{
	return _backupFolderPath;
}
