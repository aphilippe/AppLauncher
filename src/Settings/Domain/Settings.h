#pragma once
#include <string>
#include <vector>
#include "Settings/Domain/FileToBackup.h"

namespace settings { namespace domain {

class Settings
{
public:
	Settings(const std::string& executablPath, const std::string& backupPath, const std::vector<settings::domain::FileToBackup>& filePaths);
	virtual ~Settings();

	std::string getExecutablePath() const;
	std::string getBackupPath() const;
	const std::vector<std::string>& getFilePaths() const;

private:
	std::string _executablePath;
	std::string _backupPath;
	std::vector<settings::domain::FileToBackup> _filePaths;
};

} }