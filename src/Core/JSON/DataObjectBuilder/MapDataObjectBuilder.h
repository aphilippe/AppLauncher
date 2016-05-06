#pragma once
#include "IDataObjectJSONBuilder.h"
#include <string>
#include <memory>
#include <map>

class MapDataObjectBuilder : public IDataObjectJSONBuilder
{
public:
	MapDataObjectBuilder();
	virtual ~MapDataObjectBuilder();

	// Inherited via IDataObjectJSONBuilder
	virtual void addChild(std::unique_ptr<IDataObjectJSONBuilder> builder) override;
	virtual core::DataObject getObject() const override;

private:
	std::unique_ptr<IDataObjectJSONBuilder> _childBuilder;
	std::string _currentKey;
	std::map<std::string, core::DataObject> _map;

	// Inherited via IDataObjectJSONBuilder
	virtual void createObject(std::function<void(core::DataObject)> callback) override;

	// Inherited via IDataObjectJSONBuilder
	virtual void addKey(const std::string & key) override;
};

