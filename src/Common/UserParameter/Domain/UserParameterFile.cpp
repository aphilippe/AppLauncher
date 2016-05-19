#include "UserParameterFile.h"

using userparameter::domain::UserParameterFile;
using std::string;

UserParameterFile::UserParameterFile(const string & path) 
	: _path(path)
{
}


UserParameterFile::~UserParameterFile()
{
}

std::string userparameter::domain::UserParameterFile::getPath() const
{
	return _path;
}
