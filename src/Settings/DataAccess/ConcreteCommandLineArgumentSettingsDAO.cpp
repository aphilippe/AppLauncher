#include "ConcreteCommandLineArgumentSettingsDAO.h"
#include "Settings/Builders/CommandLineSettingsBuilder.h"
#include "Libraries/tclap/CmdLine.h"

using settings::dataaccess::ConcreteCommandLineArgumentSettingsDAO;
using core::application::CommandLine;
using std::move;
using settings::domain::CommandLineSettings;
using std::string;

ConcreteCommandLineArgumentSettingsDAO::ConcreteCommandLineArgumentSettingsDAO(const core::application::CommandLine& commandLine, std::unique_ptr<settings::builders::CommandLineSettingsBuilder> settingsBuilder)
	: _commandLine(commandLine), _settingsBuilder(move(settingsBuilder))
{
}


ConcreteCommandLineArgumentSettingsDAO::~ConcreteCommandLineArgumentSettingsDAO()
{
}

CommandLineSettings ConcreteCommandLineArgumentSettingsDAO::get()
{
	TCLAP::CmdLine parser("Command description", ' ', "0.3.0");

    TCLAP::ValueArg<string> executablePathArg("e", "executable", "The path of the executable to launch", false, "", "string");
	parser.add(executablePathArg);
	
    TCLAP::ValueArg<string> customSettingsFilePathArg("s", "settings", "The path of the Clapp file settings", true, "", "string");
	parser.add(customSettingsFilePathArg);

	parser.parse(_commandLine.getArgc(), _commandLine.getArgv());

	
	_settingsBuilder->setExecutablePath(executablePathArg.getValue());
	_settingsBuilder->setCustomSettingsFilePath(customSettingsFilePathArg.getValue());

	return _settingsBuilder->build();
}
