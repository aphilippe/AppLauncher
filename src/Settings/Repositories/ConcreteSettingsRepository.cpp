#include "ConcreteSettingsRepository.h"
#include "Settings/Domain/CommandLineSettings.h"
#include "Settings/Domain/CustomFileSettings.h"

using std::move;

using settings::repositories::ConcreteSettingsRepository;
using settings::domain::Settings;
using settings::domain::CommandLineSettings;
using settings::domain::CustomFileSettings;


ConcreteSettingsRepository::ConcreteSettingsRepository(std::unique_ptr<settings::factories::SettingsDAOFactory> daoFactory)
: _daoFactory(move(daoFactory)), _commandLineDAO(nullptr), _customDAO(nullptr)
{
	
}


ConcreteSettingsRepository::~ConcreteSettingsRepository()
{
}

const Settings& ConcreteSettingsRepository::get()
{
	CommandLineSettings cmdSettings = this->getCommandLineDAO().get();
	CustomFileSettings customSettings = this->getCustomFileDAO().get();

	_settings = std::make_unique<Settings>(cmdSettings.getExecutablePath(), customSettings.getBackupFolderPath());
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
ConcreteSettingsRepository::getCustomFileDAO() {
	if (_customDAO == nullptr) {
		_customDAO = _daoFactory->createCustomFileSettingsDAO();
	}
	return *_customDAO;
}