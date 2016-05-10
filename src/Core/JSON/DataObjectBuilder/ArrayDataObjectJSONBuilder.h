#pragma once
#include "Core/JSON/DataObjectBuilder/IDataObjectJSONBuilder.h"
#include <vector>

class ArrayDataObjectJSONBuilder : public IDataObjectJSONBuilder
{
public:
	ArrayDataObjectJSONBuilder();
	virtual ~ArrayDataObjectJSONBuilder();

	// Inherited via IDataObjectJSONBuilder
	virtual void addChild(std::unique_ptr<IDataObjectJSONBuilder> builder) override;
	virtual core::DataObject getObject() const override;
	virtual void createObject(std::function<void(core::DataObject)> callback) override;
	virtual void addKey(const std::string & key) override;

private:
	std::unique_ptr<IDataObjectJSONBuilder> _childBuilder;
	std::string _currentKey;
	std::vector<core::DataObject> _vector;
};

