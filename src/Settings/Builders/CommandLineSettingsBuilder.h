#pragma once

#include "Settings/Domain/CommandLineSettings.h"

namespace settings { namespace builders {
class CommandLineSettingsBuilder
{
public:
	CommandLineSettingsBuilder();
	virtual ~CommandLineSettingsBuilder();

	settings::domain::CommandLineSettings build();

	void setExecutablePath(const std::string& executablePath);

private:
	std::string _executablePath;
};

} }
