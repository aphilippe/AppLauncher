#include "ApplicationParametersBuilder.h"

using namespace application::parameters;

ApplicationParametersBuilder::ApplicationParametersBuilder()
{
}


ApplicationParametersBuilder::~ApplicationParametersBuilder()
{
}

ApplicationParameters application::parameters::ApplicationParametersBuilder::build() const
{
	return ApplicationParameters(_executablePath);
}

void application::parameters::ApplicationParametersBuilder::setExecutablePath(const std::string & executablePath)
{
	_executablePath = executablePath;
}
