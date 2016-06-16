#pragma once
#include <string>
#include <vector>

namespace settings { namespace domain {

class Settings
{
public:
	Settings(const std::string& executablPath, const std::string& backupPath, const std::vector<std::string>& filePaths);
	virtual ~Settings();

	std::string getExecutablePath() const;
	std::string getBackupPath() const;
	const std::vector<std::string>& getFilePaths() const;

private:
	std::string _executablePath;
	std::string _backupPath;
	std::vector<std::string> _filePaths;
};

} }