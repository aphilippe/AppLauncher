#pragma once

#include <string>
#include <vector>

namespace settings { namespace domain {

class CustomFileSettings
{
public:
	CustomFileSettings(const std::string& backupFolderPath, const std::vector<std::string>& filePaths);
	virtual ~CustomFileSettings();

	std::string getBackupFolderPath();
	const std::vector<std::string>& getFilePaths() const;
private:
	std::string _backupFolderPath;
	std::vector<std::string> _filePaths;
};

} }