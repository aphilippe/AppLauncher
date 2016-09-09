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
    void setFilePaths(const std::vector<settings::domain::FileToBackup>& paths);
    void setExecutablePath(const std::string& path);

private:
	std::string _backupFolderPath;
    std::vector<settings::domain::FileToBackup> _filePaths;
    std::string _executablePath;
};

} }
	
#endif /* CustomFileSettingsBuilder_hpp */
