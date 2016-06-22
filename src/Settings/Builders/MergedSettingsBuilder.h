#pragma once
#include <memory>

#include "Settings/Domain//Settings.h"

namespace settings {
	namespace domain {
		class CommandLineSettings;
		class CustomFileSettings;
	}
}

namespace settings { namespace builders {

class MergedSettingsBuilder
{
public:
	MergedSettingsBuilder();
	virtual ~MergedSettingsBuilder();

	void setCommandLineSettings(std::shared_ptr<settings::domain::CommandLineSettings> commandLineSettings);
	void setCustomFileSettings(std::shared_ptr<settings::domain::CustomFileSettings> customFileSettings);

	std::unique_ptr<settings::domain::Settings> build();

private:
	std::shared_ptr<settings::domain::CommandLineSettings> _commandLineSettings;
	std::shared_ptr<settings::domain::CustomFileSettings> _customFileSettings;

	std::string mergeExecutablePath() const;
	std::string mergeBackupPath() const;
	std::vector<std::string> mergeFilePaths() const;
};

} }