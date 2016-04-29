#pragma once

#include <vector>
#include <string>

namespace userparameter { namespace domain {

class UserParameter
{
public:
	UserParameter(const std::string& backupFolderPath, const std::vector<std::string>& backupFilePaths);
	virtual ~UserParameter();

private:
	std::string _backupFolderPath;
	std::vector<std::string> _backupFiles;
};

}}