#pragma once
#include "Application/Parameters/ApplicationParameters.h"

namespace application {
	namespace parameters {

		class ApplicationParametersBuilder
		{
		public:
			ApplicationParametersBuilder();
			virtual ~ApplicationParametersBuilder();

			ApplicationParameters build() const;
			void setExecutablePath(const std::string & executablePath);

		private:
			std::string _executablePath;
		};

	}
}