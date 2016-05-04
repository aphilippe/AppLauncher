#ifndef JSONParser_hpp
#define JSONParser_hpp

#include <stdio.h>

#include "Core/DataObject.h"
#include "Core/JSON/RootDataObjectJSONBuilder.h"

class JSONParser {
public:
	core::DataObject parse();
	
private:
	RootDataObjectJSONBuilder rootBuilder;
};

#endif /* JSONParser_hpp */
