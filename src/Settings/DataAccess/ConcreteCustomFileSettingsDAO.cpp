#include "ConcreteCustomFileSettingsDAO.h"
#include "RapidJSON/document.h"
#include "RapidJSON/filereadstream.h"
#include "RapidJSON/error/en.h"
#include "Settings/Builders/CustomFileSettingsBuilder.h"
#include "Settings/Exceptions/BadFormatCustomFileSettingsException.h"
#include "Settings/Exceptions/BadTypeCustomFileSettingsException.h"

#include <vector>

using settings::dataaccess::ConcreteCustomFileSettingsDAO;
using settings::domain::CustomFileSettings;
using settings::exceptions::BadFormatCustomFileSettingsException;
using settings::exceptions::BadTypeCustomFileSettingsException;

using std::string;

using rapidjson::Document;
using rapidjson::GetParseError_En;

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
		throw BadFormatCustomFileSettingsException(_filePath, GetParseError_En(document.GetParseError()));
	}

	if (document.HasMember("backupFolder"))
	{
		if (!document["backupFolder"].IsString())
		{
			throw BadTypeCustomFileSettingsException(_filePath, "backupFolder", "string");
		}

		_builder->setBackupFolderPath(document["backupFolder"].GetString());
	}

	if (document.HasMember("backupFiles")) {
		if (!document["backupFiles"].IsArray())
		{
			throw BadTypeCustomFileSettingsException(_filePath, "backupFiles", "array");
		}

		std::vector<string> pathArray;

		auto jsonArray = document["backupFiles"].GetArray();

		for (auto it = jsonArray.Begin(); it != jsonArray.End(); it++) {
			if (!it->IsString())
			{
				throw BadTypeCustomFileSettingsException(_filePath, "backupFiles.object", "string");
			}

			pathArray.push_back(it->GetString());
		}

		_builder->setFilePaths(pathArray);
	}

	fclose(fp);

	return _builder->build();
}
