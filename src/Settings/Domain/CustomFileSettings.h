#pragma once

#include <string>
#include <vector>

namespace settings { namespace domain {

class CustomFileSettings
{
public:
    CustomFileSettings(const std::string& backupFolderPath, const std::vector<std::string>& filePaths, const std::string& executablePath);
	virtual ~CustomFileSettings();

	std::string getBackupFolderPath();
	const std::vector<std::string>& getFilePaths() const;
    std::string getExecutablePath() const;
private:
	std::string _backupFolderPath;
	std::vector<std::string> _filePaths;
    std::string _executablePath;
};

} }
