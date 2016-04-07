#include "ApplicationParametersReader.h"

#include <string>
#include "tclap/CmdLine.h"

using namespace application::parameters;

void ApplicationParametersReader::start(int argc, char* argv[]) const {
	TCLAP::CmdLine cmd("Command description", ' ', "0.2");
	
	TCLAP::ValueArg<std::string> executableArg("e", "executable", "The path of the executable to launch", true, "", "string");
	TCLAP::ValueArg<std::string> filePathArg("f", "file", "The path of clapp file", true, "", "string");
	
	cmd.add(executableArg);
	cmd.add(filePathArg);
	
	cmd.parse(argc, argv);
	
	std::string executablePath = executableArg.getValue();
	if (!executablePath.empty()) {
		_onExecutablePath(executablePath);
	}
	
	std::string filePath = filePathArg.getValue();
	if (!filePath.empty()) {
		_onBackupParametersFilePath(filePath);
	}
	
}


void ApplicationParametersReader::setOnExecutablePath(std::function<void (const std::string&)> func) {
	_onExecutablePath = func;
}


void ApplicationParametersReader::setOnBackupParametersFilePath(std::function<void (const std::string &)> func) {
	_onBackupParametersFilePath = func;
}