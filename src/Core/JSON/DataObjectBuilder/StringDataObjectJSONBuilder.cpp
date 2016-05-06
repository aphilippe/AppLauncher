#include "StringDataObjectJSONBuilder.h"



StringDataObjectJSONBuilder::StringDataObjectJSONBuilder(const std::string & value) : _value(value)
{
}


StringDataObjectJSONBuilder::~StringDataObjectJSONBuilder()
{
}

void StringDataObjectJSONBuilder::addChild(std::unique_ptr<IDataObjectJSONBuilder> builder)
{
	// do nothing
}

core::DataObject StringDataObjectJSONBuilder::getObject() const
{
	return core::DataObject();
}

void StringDataObjectJSONBuilder::createObject(std::function<void(core::DataObject)> callback)
{
	callback(core::DataObject(_value));
}

void StringDataObjectJSONBuilder::addKey(const std::string & key)
{
	// do nothing
}
