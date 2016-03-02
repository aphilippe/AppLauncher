#include "ApplicationParameters.h"

using namespace application::parameters;

ApplicationParameters::ApplicationParameters(const std::string & executablePath) : _executablePath(executablePath)
{
}


ApplicationParameters::~ApplicationParameters()
{
}

std::string application::parameters::ApplicationParameters::getExecutablePath()
{
	return _executablePath;
}
