#pragma once
#include "RapidJSON/rapidjson.h"
#include "Core/JSON/DataObjectBuilder/RootDataObjectJSONBuilder.h"

namespace core {
	namespace json {
		namespace parser {
			namespace handler {

				class JSONHandler {
				public:
					bool Null(); 
					bool Bool(bool b);
					bool Int(int i);
					bool Uint(unsigned u);
					bool Int64(int64_t i);
					bool Uint64(uint64_t u);
					bool Double(double d);
					bool RawNumber(const char* str, rapidjson::SizeType length, bool copy);
					bool String(const char* str, rapidjson::SizeType length, bool copy);
					bool StartObject();
					bool Key(const char* str, rapidjson::SizeType length, bool copy);
					bool EndObject(rapidjson::SizeType memberCount);
					bool StartArray(); 
					bool EndArray(rapidjson::SizeType elementCount);

					core::DataObject getObject();

				private:
					core::json::builders::RootDataObjectJSONBuilder _rootBuilder;
					core::DataObject _object;
				};

			}
		}
	}
}