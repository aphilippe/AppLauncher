#pragma once

#include "Core/JSON/DataObjectBuilder/IDataObjectJSONBuilder.h"
#include <string>

namespace core {
	namespace json {
		namespace builders {

			class StringDataObjectJSONBuilder : public IDataObjectJSONBuilder
			{
			public:
				StringDataObjectJSONBuilder(const std::string & value);
				virtual ~StringDataObjectJSONBuilder();

				// Inherited via IDataObjectJSONBuilder
				virtual void addChild(std::unique_ptr<IDataObjectJSONBuilder> builder) override;
				virtual void createObject(std::function<void(core::DataObject)> callback) override;
				virtual void addKey(const std::string & key) override;
			private:
				std::string _value;
			};

		}
	}
}