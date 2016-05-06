#ifndef IDataObjectJSONBuilder_h
#define IDataObjectJSONBuilder_h

#include "Core/DataObject.h"

class IDataObjectJSONBuilder {
public:
	virtual ~IDataObjectJSONBuilder(){}
	virtual void addChild(const IDataObjectJSONBuilder& builder) = 0;
	virtual core::DataObject getObject() const = 0;
};


#endif /* IDataObjectJSONBuilder_h */
