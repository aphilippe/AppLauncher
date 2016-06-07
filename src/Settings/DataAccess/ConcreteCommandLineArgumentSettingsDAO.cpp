#include "ConcreteCommandLineArgumentSettingsDAO.h"

using settings::dataaccess::ConcreteCommandLineArgumentSettingsDAO;
using core::application::CommandLine;

ConcreteCommandLineArgumentSettingsDAO::ConcreteCommandLineArgumentSettingsDAO(const core::application::CommandLine& commandLine)
	: _commandLine(commandLine)
{
}


ConcreteCommandLineArgumentSettingsDAO::~ConcreteCommandLineArgumentSettingsDAO()
{
}
