#pragma once

#include <memory>
#include "Core/DataObject.h"

namespace userparameter {
	namespace domain {
		class UserParameter;
	}
}

namespace userparameter { namespace factories {

class UserParameterFactory
{
public:
	UserParameterFactory();
	virtual ~UserParameterFactory();

	std::unique_ptr<userparameter::domain::UserParameter> createUserParameter(const core::DataObject& data);
};

} }