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

CommandLineSettings CommandLineSettingsBuilder::build()
{
	return CommandLineSettings(_executablePath, _customSettingsFilePath);
}

void CommandLineSettingsBuilder::setExecutablePath(const string & executablePath)
{
	_executablePath = executablePath;
}

void CommandLineSettingsBuilder::setCustomSettingsFilePath(const std::string& path)
{
	_customSettingsFilePath = path;
}