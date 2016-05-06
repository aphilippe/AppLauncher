#include "RootDataObjectJSONBuilder.h"

void RootDataObjectJSONBuilder::addChild(std::unique_ptr<IDataObjectJSONBuilder> builder) {
	if (_childBuilder == nullptr) {
		_childBuilder = std::move(builder);
	}
	else {
		_childBuilder->addChild(std::move(builder));
	}
}


core::DataObject RootDataObjectJSONBuilder::getObject() const {
	return core::DataObject();
}

void RootDataObjectJSONBuilder::createObject(std::function<void(core::DataObject)> callback)
{
	if (_childBuilder != nullptr) {
		_childBuilder->createObject([this,callback](core::DataObject object) {
			callback(object);
		});
	}
	
}

void RootDataObjectJSONBuilder::addKey(const std::string & key)
{
	_childBuilder->addKey(key);
}
