
#ifndef RootDataObjectJSONBuilder_hpp
#define RootDataObjectJSONBuilder_hpp

#include <stdio.h>
#include "Core/JSON/DataObjectBuilder/IDataObjectJSONBuilder.h"

namespace core {
	namespace json {
		namespace builders {

			class RootDataObjectJSONBuilder : public IDataObjectJSONBuilder {
			public:
				void addChild(std::unique_ptr<IDataObjectJSONBuilder> builder) override;

				// Inherited via IDataObjectJSONBuilder
				virtual void createObject(std::function<void(core::DataObject)> callback) override;
				virtual void addKey(const std::string & key) override;

			private:
				std::unique_ptr<IDataObjectJSONBuilder> _childBuilder;
				core::DataObject _object;

				// Inherited via IDataObjectJSONBuilder

			};

#endif /* RootDataObjectJSONBuilder_hpp */

		}
	}
}