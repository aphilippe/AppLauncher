#include "CommandLineSettingsBuilder.h"

using settings::builders::CommandLineSettingsBuilder;
using settings::domain::CommandLineSettings;

using std::string;

CommandLineSettingsBuilder::CommandLineSettingsBuilder()
{
}


CommandLineSettingsBuilder::~CommandLineSettingsBuilder()
{
}

settings::domain::CommandLineSettings settings::builders::CommandLineSettingsBuilder::build()
{
	return CommandLineSettings(_executablePath);
}

void CommandLineSettingsBuilder::setExecutablePath(const string & executablePath)
{
	_executablePath = executablePath;
}
