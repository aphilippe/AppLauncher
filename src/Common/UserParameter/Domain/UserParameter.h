#pragma once

#include <list>
#include "FileSystem/Entities/Path.h"


namespace userparameter { namespace domain {

class UserParameter
{
public:
	UserParameter(const clt::filesystem::entities::Path& _backupFolderPath, std::list<clt::filesystem::entities::Path> _backupFilePaths);
	virtual ~UserParameter();

private:
	clt::filesystem::entities::Path _backupFolderPath;
	std::list<clt::filesystem::entities::Path> _backupFiles;
};

}}