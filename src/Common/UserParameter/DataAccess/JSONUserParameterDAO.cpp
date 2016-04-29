#include "JSONUserParameterDAO.h"

#include <map>
#include <string>
#include <vector>

using userparameter::dataaccess::JSONUserParameterDAO;
using namespace std;

JSONUserParameterDAO::JSONUserParameterDAO()
{
}


JSONUserParameterDAO::~JSONUserParameterDAO()
{
}

core::DataObject userparameter::dataaccess::JSONUserParameterDAO::get()
{
	map<string, core::DataObject> json;
	json["backupFolder"] = core::DataObject(string("plop backupFolder"));

	vector<core::DataObject> fileList;
	for (int i = 0; i < 4; ++i) {
		fileList.push_back(core::DataObject(string("plip")));
	}

	json["backupFiles"] = core::DataObject(fileList);

	return core::DataObject(json);
}
