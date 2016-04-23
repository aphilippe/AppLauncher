#pragma once

namespace userparameter {
	namespace dataaccess {
		class UserParameterDTO;
		class IUserParameterDAO {
		public:
			virtual ~IUserParameterDAO(){};

			virtual std::unique_ptr<UserParameterDTO> get()=0;
		};
	}
}