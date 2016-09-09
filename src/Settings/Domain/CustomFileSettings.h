#pragma once

#include <string>
#include <vector>
#include "Settings/Domain/FileToBackup.h"

namespace settings { namespace domain {

class CustomFileSettings
{
public:
    CustomFileSettings(const std::string& backupFolderPath, const std::vector<settings::domain::FileToBackup>& filePaths, const std::string& executablePath);
	virtual ~CustomFileSettings();

	std::string getBackupFolderPath();
	const std::vector<std::string>& getFilePaths() const;
    std::string getExecutablePath() const;
private:
	std::string _backupFolderPath;
    std::vector<settings::domain::FileToBackup> _filePaths;
    std::string _executablePath;
};

} }
