#include "CommandLineSettings.h"

using settings::domain::CommandLineSettings;
using std::string;

CommandLineSettings::CommandLineSettings(const string& executablePath)
	: _executablePath(executablePath)
{
}


CommandLineSettings::~CommandLineSettings()
{
}

string CommandLineSettings::getExecutablePath() const
{
	return _executablePath;
}
