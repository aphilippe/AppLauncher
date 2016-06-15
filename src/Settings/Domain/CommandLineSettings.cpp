#include "CommandLineSettings.h"

using settings::domain::CommandLineSettings;
using std::string;

CommandLineSettings::CommandLineSettings(const string& executablePath, const string& customSettingsFilePath)
	: _executablePath(executablePath), _customSettingsFilePath(customSettingsFilePath)
{
}


CommandLineSettings::~CommandLineSettings()
{
}

string CommandLineSettings::getExecutablePath() const
{
	return _executablePath;
}

string CommandLineSettings::getCustomSettingsFilePath() const
{
	return _customSettingsFilePath;
}