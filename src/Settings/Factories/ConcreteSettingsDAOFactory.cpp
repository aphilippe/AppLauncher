#include "ConcreteSettingsDAOFactory.h"
#include "Settings/DataAccess/ConcreteCommandLineArgumentSettingsDAO.h"
#include "Settings/Builders/CommandLineSettingsBuilder.h"

using std::unique_ptr;
using std::make_unique;
using settings::factories::ConcreteSettingsDAOFactory;
using settings::dataaccess::CommandLineArgumentSettingsDAO;
using settings::dataaccess::ConcreteCommandLineArgumentSettingsDAO;
using core::application::CommandLine;
using settings::builders::CommandLineSettingsBuilder;

ConcreteSettingsDAOFactory::ConcreteSettingsDAOFactory(const CommandLine& commandLine) 
	: _commandLine(commandLine)
{
}


ConcreteSettingsDAOFactory::~ConcreteSettingsDAOFactory()
{
}

unique_ptr<CommandLineArgumentSettingsDAO> ConcreteSettingsDAOFactory::createCommandLineArgumentDAO()
{
	unique_ptr<CommandLineSettingsBuilder> commandLineSettingsBuilder = make_unique<CommandLineSettingsBuilder>();
	return make_unique<ConcreteCommandLineArgumentSettingsDAO>(_commandLine, std::move(commandLineSettingsBuilder));
}
