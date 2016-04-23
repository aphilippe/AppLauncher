#include "UserParameter.h"

using userparameter::domain::UserParameter;

UserParameter::UserParameter(const clt::filesystem::entities::Path& backupFolderPath, const std::list<clt::filesystem::entities::Path>& backupFilePaths) :
	_backupFolderPath(backupFolderPath)
{
	//TODO fill backupFilePaths
}


UserParameter::~UserParameter()
{
}
