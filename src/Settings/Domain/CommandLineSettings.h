#pragma once

#include <string>

namespace settings {
	namespace domain {

		class CommandLineSettings
		{
		public:
			CommandLineSettings(const std::string& executablePath);
			virtual ~CommandLineSettings();

			std::string getExecutablePath() const;

		private:
			std::string _executablePath;
		};

	}
}