#include "ConcreteSettingsDAOFactory.h"
#include "Settings/DataAccess/ConcreteCommandLineArgumentSettingsDAO.h"
#include "Settings/Builders/CommandLineSettingsBuilder.h"
#include "Settings/DataAccess/ConcreteCustomFileSettingsDAO.h"
#include "Settings/Builders/CustomFileSettingsBuilder.h"

using std::unique_ptr;
using std::make_unique;
using std::string;
using settings::factories::ConcreteSettingsDAOFactory;
using settings::dataaccess::CommandLineArgumentSettingsDAO;
using settings::dataaccess::ConcreteCommandLineArgumentSettingsDAO;
using core::application::CommandLine;
using settings::builders::CommandLineSettingsBuilder;
using settings::dataaccess::CustomFileSettingsDAO;
using settings::dataaccess::ConcreteCustomFileSettingsDAO;
using settings::builders::CustomFileSettingsBuilder;

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

unique_ptr<CustomFileSettingsDAO> ConcreteSettingsDAOFactory::createCustomFileSettingsDAO(const string& customFileSettingsPath)
{
	unique_ptr<CustomFileSettingsBuilder> builder = make_unique<CustomFileSettingsBuilder>();
	return make_unique<ConcreteCustomFileSettingsDAO>(customFileSettingsPath, std::move(builder));
}
