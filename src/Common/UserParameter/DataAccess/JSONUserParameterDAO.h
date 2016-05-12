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
			virtual core::DataObject get(const std::string& path) override;
		};

	}
}

