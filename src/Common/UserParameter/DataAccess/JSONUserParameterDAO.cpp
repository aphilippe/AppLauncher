#include "JSONUserParameterDAO.h"
#include "Core/JSON/Parser/JSONParser.h"

#include <map>
#include <string>
#include <vector>
#include <cstdio>

using userparameter::dataaccess::JSONUserParameterDAO;
using namespace std;

JSONUserParameterDAO::JSONUserParameterDAO()
{
}


JSONUserParameterDAO::~JSONUserParameterDAO()
{
}

core::DataObject userparameter::dataaccess::JSONUserParameterDAO::get(const std::string& path)
{
	FILE* file = fopen(path.c_str(), "rb");
	core::parsers::JSONParser parser;


	return parser.parse(file);
}
