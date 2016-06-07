#include "ConcreteSettingsDAOFactory.h"
#include "Settings/DataAccess/ConcreteCommandLineArgumentSettingsDAO.h"

using std::unique_ptr;
using std::make_unique;
using settings::factories::ConcreteSettingsDAOFactory;
using settings::dataaccess::CommandLineArgumentSettingsDAO;
using settings::dataaccess::ConcreteCommandLineArgumentSettingsDAO;
using core::application::CommandLine;

ConcreteSettingsDAOFactory::ConcreteSettingsDAOFactory(const CommandLine& commandLine) 
	: _commandLine(commandLine)
{
}


ConcreteSettingsDAOFactory::~ConcreteSettingsDAOFactory()
{
}

unique_ptr<CommandLineArgumentSettingsDAO> ConcreteSettingsDAOFactory::createCommandLineArgumentDAO()
{
	return make_unique<ConcreteCommandLineArgumentSettingsDAO>(_commandLine);
}
