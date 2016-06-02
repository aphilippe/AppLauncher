#include "ConcreteSettingsDAOFactory.h"
#include "Settings/DataAccess/ConcreteCommandLineArgumentSettingsDAO.h"

using std::unique_ptr;
using std::make_unique;
using settings::factories::ConcreteSettingsDAOFactory;
using settings::dataaccess::CommandLineArgumentSettingsDAO;
using settings::dataaccess::ConcreteCommandLineArgumentSettingsDAO;

ConcreteSettingsDAOFactory::ConcreteSettingsDAOFactory()
{
}


ConcreteSettingsDAOFactory::~ConcreteSettingsDAOFactory()
{
}

unique_ptr<CommandLineArgumentSettingsDAO> ConcreteSettingsDAOFactory::createCommandLineArgumentDAO()
{
	return make_unique<ConcreteCommandLineArgumentSettingsDAO>();
}
