#pragma once
#include <string>

namespace userparameter {
	namespace domain {

		class UserParameterFile
		{
		public:
			UserParameterFile(const std::string & path);
			virtual ~UserParameterFile();

			std::string getPath() const;

		private:
			std::string _path;
		};

	}
}