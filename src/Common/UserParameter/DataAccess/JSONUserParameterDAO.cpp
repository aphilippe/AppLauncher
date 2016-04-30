#include "JSONUserParameterDAO.h"
#include "Core/Parsers/JSONParser.h"

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
	core::parsers::JSONParser parser;


	return parser.parse();
}
