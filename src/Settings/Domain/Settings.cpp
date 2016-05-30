#include "Settings.h"

using settings::domain::Settings;

Settings::Settings(const std::string& executablPath)
	: _executablePath(executablPath)
{
}


Settings::~Settings()
{
}

std::string settings::domain::Settings::getExecutablePath() const
{
	return _executablePath;
}
