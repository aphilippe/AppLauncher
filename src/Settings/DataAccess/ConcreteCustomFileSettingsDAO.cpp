#include "ConcreteCustomFileSettingsDAO.h"
#include "RapidJSON/document.h"
#include "Settings/Builders/CustomFileSettingsBuilder.h"

using settings::dataaccess::ConcreteCustomFileSettingsDAO;
using settings::domain::CustomFileSettings;

using std::string;

using rapidjson::Document;

ConcreteCustomFileSettingsDAO::ConcreteCustomFileSettingsDAO(const string& filePath, std::unique_ptr<settings::builders::CustomFileSettingsBuilder> builder)
: _filePath(filePath), _builder(std::move(builder))
{
}


ConcreteCustomFileSettingsDAO::~ConcreteCustomFileSettingsDAO()
{
}

CustomFileSettings ConcreteCustomFileSettingsDAO::get()
{
	Document document;
	document.Parse(_filePath.c_str());

	_builder->setBackupFolderPath("plop");
	
	return _builder->build();
}
