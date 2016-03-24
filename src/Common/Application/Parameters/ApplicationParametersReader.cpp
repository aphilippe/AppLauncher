#include "ApplicationParametersReader.h"

#include <string>

#if WIN32
#include "Libraries/WinGetOpt/wingetopt.h"
#else
#include <unistd.h>
#endif

using namespace application::parameters;

void ApplicationParametersReader::start(int argc, char* argv[]) const {
	char c;
	while ((c = getopt(argc, argv, "f:e:")) != -1) {
		switch (c)
		{
			case 'e':
				_onExecutablePath(optarg);
				break;
			case 'f':
				_onBackupParametersFilePath(optarg);
				break;
			default:
				break;
		}
	}
}


void ApplicationParametersReader::setOnExecutablePath(std::function<void (const std::string&)> func) {
	_onExecutablePath = func;
}


void ApplicationParametersReader::setOnBackupParametersFilePath(std::function<void (const std::string &)> func) {
	_onBackupParametersFilePath = func;
}