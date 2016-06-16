#ifndef CustomFileSettingsBuilder_hpp
#define CustomFileSettingsBuilder_hpp

#include <stdio.h>
#include <vector>
#include "Settings/Domain/CustomFileSettings.h"


namespace settings { namespace builders {

class CustomFileSettingsBuilder {
public:
	settings::domain::CustomFileSettings build();

	void setBackupFolderPath(const std::string& path);
	void setFilePaths(const std::vector<std::string>& paths);

private:
	std::string _backupFolderPath;
	std::vector<std::string> _filePaths;
};

} }
	
#endif /* CustomFileSettingsBuilder_hpp */
