#include "UserParameter.h"

using userparameter::domain::UserParameter;

UserParameter::UserParameter(const clt::filesystem::entities::Path& backupFolderPath, std::list<clt::filesystem::entities::Path> backupFilePaths) :
	_backupFolderPath(backupFiles), _backupFilePaths(backupFilePaths)
{
}


UserParameter::~UserParameter()
{
}
