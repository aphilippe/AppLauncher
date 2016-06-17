#include "ConcreteCustomFileSettingsDAO.h"
#include "RapidJSON/document.h"
#include "RapidJSON/filereadstream.h"
#include "Settings/Builders/CustomFileSettingsBuilder.h"
#include "Settings/Exceptions/BadFormatCustomFileSettingsException.h"

#include <vector>

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
	FILE* fp = fopen(_filePath.c_str(), "rb");
	char readBuffer[65536];

	rapidjson::FileReadStream fileStream(fp, readBuffer, sizeof(readBuffer));

	Document document;
	document.ParseStream(fileStream);

	if (document.HasParseError()) {
		throw BadFormatCustomFileSettingsException();
	}

	_builder->setBackupFolderPath(document["backupFolder"].GetString());

	if (document.HasMember("backupFiles")) {
		std::vector<string> pathArray;

		auto jsonArray = document["backupFiles"].GetArray();

		for (auto it = jsonArray.Begin(); it != jsonArray.End(); it++) {
			pathArray.push_back(it->GetString());
		}

		_builder->setFilePaths(pathArray);
	}

	fclose(fp);

	return _builder->build();
}
