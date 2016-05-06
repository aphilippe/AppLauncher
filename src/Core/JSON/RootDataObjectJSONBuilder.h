
#ifndef RootDataObjectJSONBuilder_hpp
#define RootDataObjectJSONBuilder_hpp

#include <stdio.h>
#include "Core/JSON/IDataObjectJSONBuilder.h"

class RootDataObjectJSONBuilder : public IDataObjectJSONBuilder {
public:
	void addChild(const IDataObjectJSONBuilder& builder) override;
	core::DataObject getObject() const override;
};

#endif /* RootDataObjectJSONBuilder_hpp */
