#pragma once

#include "Core/DataObject.h"

namespace userparameter {
	namespace dataaccess {
		class IUserParameterDAO {
		public:
			virtual ~IUserParameterDAO(){};

			virtual core::DataObject get()=0;
		};
	}
}