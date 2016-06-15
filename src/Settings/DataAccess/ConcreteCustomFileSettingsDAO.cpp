#include "ConcreteCustomFileSettingsDAO.h"

using settings::dataaccess::ConcreteCustomFileSettingsDAO;
using settings::domain::CustomFileSettings;

using std::string;

ConcreteCustomFileSettingsDAO::ConcreteCustomFileSettingsDAO(const string& filePath)
: _filePath(filePath)
{
}


ConcreteCustomFileSettingsDAO::~ConcreteCustomFileSettingsDAO()
{
}

settings::domain::CustomFileSettings settings::dataaccess::ConcreteCustomFileSettingsDAO::get()
{
	return CustomFileSettings("path");
}
