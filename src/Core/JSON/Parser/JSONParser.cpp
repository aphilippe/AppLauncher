#include "JSONParser.h"
#include "RapidJSON/reader.h"
#include "rapidjson/filereadstream.h"
#include "Core/JSON/Parser/Handler/JSONHandler.h"
#include <cstdio>

#include <iostream>
using namespace std;

using core::parsers::JSONParser;
using rapidjson::Reader;
using core::json::parser::handler::JSONHandler;
using rapidjson::FileReadStream;


JSONParser::JSONParser()
{
}


JSONParser::~JSONParser()
{
}

core::DataObject JSONParser::parse(FILE* file)
{
	Reader reader;
	JSONHandler handler;
	char readBuffer[65536];
	FileReadStream stream(file, readBuffer, sizeof(readBuffer));
	reader.Parse(stream, handler);

	return handler.getObject();
}
