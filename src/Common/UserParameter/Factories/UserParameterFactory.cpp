#include "UserParameterFactory.h"
#include "UserParameter/Domain/UserParameter.h"
#include <string>
#include <vector>
#include <map>

using userparameter::factories::UserParameterFactory;
using userparameter::domain::UserParameter;
using std::make_unique;
using std::map;
using std::string;
using std::vector;

UserParameterFactory::UserParameterFactory()
{
}


UserParameterFactory::~UserParameterFactory()
{
}

std::unique_ptr<UserParameter> UserParameterFactory::createUserParameter(const core::DataObject & data)
{
	map<string, core::DataObject> dataMap = data.get<map<string, core::DataObject>>();

	string backupFolder = dataMap["backupFolder"].get<string>();

	vector<core::DataObject> backupFilesData = dataMap["backupFiles"].get<vector<core::DataObject>>();
	vector<string> backupFiles;
	
	for (core::DataObject& fileData : backupFilesData) {
		string backupFilePath = fileData.get<string>();
		backupFiles.push_back(backupFilePath);
	}

	return make_unique<UserParameter>(backupFolder, backupFiles);
}
