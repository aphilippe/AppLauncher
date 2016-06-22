#include "ConcreteSettingsRepository.h"
#include "Settings/Domain/CommandLineSettings.h"
#include "Settings/Domain/CustomFileSettings.h"
#include "Settings/Builders/MergedSettingsBuilder.h"

using std::move;
using std::string;

using settings::repositories::ConcreteSettingsRepository;
using settings::domain::Settings;
using settings::domain::CommandLineSettings;
using settings::domain::CustomFileSettings;
using settings::builders::MergedSettingsBuilder;


ConcreteSettingsRepository::ConcreteSettingsRepository(std::unique_ptr<settings::factories::SettingsDAOFactory> daoFactory)
: _daoFactory(move(daoFactory)), _commandLineDAO(nullptr), _customDAO(nullptr)
{
	
}


ConcreteSettingsRepository::~ConcreteSettingsRepository()
{
}

const Settings& ConcreteSettingsRepository::get()
{
	std::shared_ptr<CommandLineSettings> cmdSettings = std::make_shared<CommandLineSettings>(this->getCommandLineDAO().get());
	std::shared_ptr<CustomFileSettings> customSettings = std::make_shared<CustomFileSettings>(this->getCustomFileDAO(cmdSettings->getCustomSettingsFilePath()).get());

	MergedSettingsBuilder builder;
	builder.setCommandLineSettings(cmdSettings);
	builder.setCustomFileSettings(customSettings);

	_settings = builder.build();
	return *_settings;
}

settings::dataaccess::CommandLineArgumentSettingsDAO&
ConcreteSettingsRepository::getCommandLineDAO() {
	
	if (_commandLineDAO == nullptr) {
		_commandLineDAO = _daoFactory->createCommandLineArgumentDAO();
	}
	
	return *_commandLineDAO;
}

settings::dataaccess::CustomFileSettingsDAO&
ConcreteSettingsRepository::getCustomFileDAO(const string& path) {
	if (_customDAO == nullptr) {
		_customDAO = _daoFactory->createCustomFileSettingsDAO(path);
	}
	return *_customDAO;
}