#pragma once

#include "Core/DataObject.h"
#include <string>

namespace userparameter {
	namespace dataaccess {
		class IUserParameterDAO {
		public:
			virtual ~IUserParameterDAO(){};

			virtual core::DataObject get(const std::string& path)=0;
		};
	}
}