#include "ApplicationParameters.h"

using namespace application::parameters;

ApplicationParameters::ApplicationParameters(const std::string & executablePath, const std::string & backupParametersFilePath)
: _executablePath(executablePath), _backupParametersFilePath(backupParametersFilePath)
{
}


ApplicationParameters::~ApplicationParameters()
{
}

std::string application::parameters::ApplicationParameters::getExecutablePath()
{
	return _executablePath;
}

std::string application::parameters::ApplicationParameters::getBackupParametersFilePath() {
	return _backupParametersFilePath;
}