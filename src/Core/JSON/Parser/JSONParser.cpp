#include "JSONParser.h"
#include "RapidJSON/reader.h"
#include "Core/JSON/Parser/Handler/JSONHandler.h"

#include <iostream>
using namespace std;

using core::parsers::JSONParser;
using rapidjson::Reader;
using core::json::parser::handler::JSONHandler;
using rapidjson::StringStream;


JSONParser::JSONParser()
{
}


JSONParser::~JSONParser()
{
}

core::DataObject core::parsers::JSONParser::parse()
{
	const char json[] = " { \"backupFolder\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] } ";

	Reader reader;
	JSONHandler handler;
	StringStream ss(json);
	reader.Parse(ss, handler);

	return handler.getObject();
}
