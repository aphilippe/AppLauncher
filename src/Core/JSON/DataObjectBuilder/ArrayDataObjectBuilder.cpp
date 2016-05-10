#include "ArrayDataObjectBuilder.h"



ArrayDataObjectBuilder::ArrayDataObjectBuilder()
{
}


ArrayDataObjectBuilder::~ArrayDataObjectBuilder()
{
}

void ArrayDataObjectBuilder::addChild(std::unique_ptr<IDataObjectJSONBuilder> builder)
{
	if (_childBuilder == nullptr) {
		_childBuilder = std::move(builder);
	}
	else {
		_childBuilder->addChild(std::move(builder));
	}
}

core::DataObject ArrayDataObjectBuilder::getObject() const
{
	return core::DataObject();
}

void ArrayDataObjectBuilder::createObject(std::function<void(core::DataObject)> callback)
{
	if (_childBuilder == nullptr) {
		callback(core::DataObject(_vector));
	}
	else {
		_childBuilder->createObject([this](core::DataObject object) {
			_vector.push_back(object);
			_childBuilder = nullptr;
		});
	}
}

void ArrayDataObjectBuilder::addKey(const std::string & key)
{
}
