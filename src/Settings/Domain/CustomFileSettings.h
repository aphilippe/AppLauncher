#pragma once

#include <string>

namespace settings { namespace domain {

class CustomFileSettings
{
public:
	CustomFileSettings(const std::string& backupFolderPath);
	virtual ~CustomFileSettings();

	std::string getBackupFolderPath();

private:
	std::string _backupFolderPath;
};

} }