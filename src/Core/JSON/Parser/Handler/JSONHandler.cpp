#include "Core/JSON/Parser/Handler/JSONHandler.h"
#include <iostream>
#include "RapidJSON/rapidjson.h"
#include "Core/JSON/DataObjectBuilder/MapDataObjectJSONBuilder.h"
#include "Core/JSON/DataObjectBuilder/StringDataObjectJSONBuilder.h"
#include "Core/JSON/DataObjectBuilder/ArrayDataObjectJSONBuilder.h"

using core::json::parser::handler::JSONHandler;
using std::cout;
using std::endl;
using rapidjson::SizeType;


bool JSONHandler::Null() 
{
	cout << "Null()" << endl; return true; 
}

bool JSONHandler::Bool(bool b)
{
	cout << "Bool(" << b << ")" << endl; return true;
}

bool JSONHandler::Int(int i) 
{
	cout << "Int(" << i << ")" << endl; return true;
}

bool JSONHandler::Uint(unsigned u) 
{
	cout << "Uint(" << u << ")" << endl; return true; 
}

bool JSONHandler::Int64(int64_t i) 
{
	cout << "Int64(" << i << ")" << endl; return true; 
}

bool JSONHandler::Uint64(uint64_t u) 
{
	cout << "Uint64(" << u << ")" << endl; return true; 
}

bool JSONHandler::Double(double d)
{
	cout << "Double(" << d << ")" << endl; return true; 
}

bool JSONHandler::RawNumber(const char* str, SizeType length, bool copy) 
{
	cout << "Number(" << str << ", " << length << ", " << copy << ")" << endl;
	return true;
}

bool JSONHandler::String(const char* str, SizeType length, bool copy)
{
	_rootBuilder.addChild(std::make_unique<StringDataObjectJSONBuilder>(std::string(str)));
	_rootBuilder.createObject([](DataObject object) {});
	return true;
}

bool JSONHandler::StartObject() 
{

	_rootBuilder.addChild(std::make_unique<MapDataObjectJSONBuilder>());
	
	return true; 
}

bool JSONHandler::Key(const char* str, SizeType length, bool copy) 
{
	_rootBuilder.addKey(std::string(str));
	return true;
}

bool JSONHandler::EndObject(SizeType memberCount) 
{
	_rootBuilder.createObject([this](core::DataObject object) {
		_object = object;
	});
	return true; 
}

bool JSONHandler::StartArray()
{
	_rootBuilder.addChild(std::make_unique<ArrayDataObjectJSONBuilder>());
	return true; 
}

bool JSONHandler::EndArray(SizeType elementCount)
{
	_rootBuilder.createObject([this](core::DataObject object) {
		_object = object;
	});
	return true; 
}

core::DataObject JSONHandler::getObject()
{
	return _object;
}


