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
	TCLAP::CmdLine parser("Command description", ' ', "0.2");

	TCLAP::ValueArg<string> executablePathArg("e", "executable", "The path of the executable to launch", true, "", "string");

	parser.add(executablePathArg);

	parser.parse(_commandLine.getArgc(), _commandLine.getArgv());

	string executablePath = executablePathArg.getValue();
	if (!executablePath.empty()) {
		_settingsBuilder->setExecutablePath(executablePath);
	}

	return _settingsBuilder->build();
}
