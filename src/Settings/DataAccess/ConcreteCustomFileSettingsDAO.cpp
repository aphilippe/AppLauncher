#include "ConcreteCustomFileSettingsDAO.h"

using settings::dataaccess::ConcreteCustomFileSettingsDAO;
using settings::domain::CustomFileSettings;

ConcreteCustomFileSettingsDAO::ConcreteCustomFileSettingsDAO()
{
}


ConcreteCustomFileSettingsDAO::~ConcreteCustomFileSettingsDAO()
{
}

settings::domain::CustomFileSettings settings::dataaccess::ConcreteCustomFileSettingsDAO::get()
{
	return CustomFileSettings("path");
}
