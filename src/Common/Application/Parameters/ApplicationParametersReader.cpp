#include "ApplicationParametersReader.h"

#include <string>

using namespace application::parameters;

void ApplicationParametersReader::start(char* argv[]) const {
	_onExecutablePath(argv[1]);
}


void ApplicationParametersReader::setOnExecutablePath(std::function<void (const std::string&)> func) {
	_onExecutablePath = func;
}