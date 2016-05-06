#include "MapDataObjectBuilder.h"



MapDataObjectBuilder::MapDataObjectBuilder()
{
}


MapDataObjectBuilder::~MapDataObjectBuilder()
{
}

void MapDataObjectBuilder::addChild(std::unique_ptr<IDataObjectJSONBuilder> builder)
{
	if (_childBuilder == nullptr) {
		_childBuilder = std::move(builder);
	}
	else {
		_childBuilder->addChild(std::move(builder));
	}
}

core::DataObject MapDataObjectBuilder::getObject() const
{
	return core::DataObject();
}

void MapDataObjectBuilder::createObject(std::function<void(core::DataObject)> callback)
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

void MapDataObjectBuilder::addKey(const std::string & key)
{
	_currentKey = key;
}
