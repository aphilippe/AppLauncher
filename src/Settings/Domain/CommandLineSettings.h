#pragma once

#include <string>

namespace settings {
	namespace domain {

		class CommandLineSettings
		{
		public:
			CommandLineSettings(const std::string& executablePath, const std::string& customSettingsFilePath);
			virtual ~CommandLineSettings();

			std::string getExecutablePath() const;
			std::string getCustomSettingsFilePath() const;

		private:
			std::string _executablePath;
			std::string _customSettingsFilePath;
		};

	}
}