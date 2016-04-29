#include "UserParameter.h"

using userparameter::domain::UserParameter;

UserParameter::UserParameter(const std::string& backupFolderPath, const std::vector<std::string>& backupFilePaths) :
	_backupFolderPath(backupFolderPath), _backupFiles(backupFilePaths)
{
}


UserParameter::~UserParameter()
{
}
