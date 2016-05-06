#include "JSONParser.h"


core::DataObject JSONParser::parse() {
	return rootBuilder.getObject();
}