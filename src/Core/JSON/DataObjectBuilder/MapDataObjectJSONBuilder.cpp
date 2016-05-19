#include "MapDataObjectJSONBuilder.h"

using core::json::builders::MapDataObjectJSONBuilder;

MapDataObjectJSONBuilder::MapDataObjectJSONBuilder()
{
}


MapDataObjectJSONBuilder::~MapDataObjectJSONBuilder()
{
}

void MapDataObjectJSONBuilder::addChild(std::unique_ptr<IDataObjectJSONBuilder> builder)
{
	if (_childBuilder == nullptr) {
		_childBuilder = std::move(builder);
	}
	else {
		_childBuilder->addChild(std::move(builder));
	}
}

void MapDataObjectJSONBuilder::createObject(std::function<void(core::DataObject)> callback)
{
	if (_childBuilder == nullptr) {
		callback(core::DataObject(_map));
	}
	else {
		_childBuilder->createObject([this](core::DataObject object) {
			_map.insert(std::pair<std::string, core::DataObject>(_currentKey, object));
			_childBuilder = nullptr;
		});
	}
}

void MapDataObjectJSONBuilder::addKey(const std::string & key)
{
	_currentKey = key;
}
