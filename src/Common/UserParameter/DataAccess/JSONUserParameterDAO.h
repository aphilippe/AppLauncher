#pragma once

#include "UserParameter/DataAccess/IUserParameterDAO.h"

namespace userparameter {
	namespace dataaccess {

		class JSONUserParameterDAO : public IUserParameterDAO
		{
		public:
			JSONUserParameterDAO();
			virtual ~JSONUserParameterDAO();

			// Inherited via IUserParameterDAO
			virtual std::unique_ptr<core::DataObject> get() override;
		};

	}
}

