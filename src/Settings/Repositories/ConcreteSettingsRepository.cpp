#include "ConcreteSettingsRepository.h"
#include "Settings/Domain/CommandLineSettings.h"

using std::move;

using settings::repositories::ConcreteSettingsRepository;
using settings::domain::Settings;


ConcreteSettingsRepository::ConcreteSettingsRepository(std::unique_ptr<settings::factories::SettingsDAOFactory> daoFactory)
: _daoFactory(move(daoFactory)), _commandLineDAO(nullptr), _customDAO(nullptr)
{
	
}


ConcreteSettingsRepository::~ConcreteSettingsRepository()
{
}

const Settings& ConcreteSettingsRepository::get()
{
	settings::domain::CommandLineSettings cmdSettings = this->getCommandLineDAO().get();

	_settings = std::make_unique<Settings>(cmdSettings.getExecutablePath());
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