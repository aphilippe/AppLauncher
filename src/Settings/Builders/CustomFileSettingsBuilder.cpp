#include "CustomFileSettingsBuilder.h"

using settings::builders::CustomFileSettingsBuilder;
using settings::domain::CustomFileSettings;

using std::string;

CustomFileSettings CustomFileSettingsBuilder::build()
{
	return settings::domain::CustomFileSettings(_backupFolderPath);
}

void CustomFileSettingsBuilder::setBackupFolderPath(const string & path)
{
	_backupFolderPath = path;
}
