#include "UserParameterDTO.h"

using userparameter::dataaccess::UserParameterDTO;

UserParameterDTO::UserParameterDTO()
{
}


UserParameterDTO::~UserParameterDTO()
{
}

void UserParameterDTO::setBackupFolder(const std::string & value)
{
	_backupFolder = value;
}

void UserParameterDTO::addFile(const std::string & value)
{
	_files.push_back(value);
}

std::string UserParameterDTO::getBackupFolder() const
{
	return _backupFolder;
}

const std::vector<std::string> UserParameterDTO::getFiles() const
{
	return _files;
}
