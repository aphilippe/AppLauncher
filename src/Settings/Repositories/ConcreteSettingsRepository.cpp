#include "ConcreteSettingsRepository.h"

using std::move;

using settings::repositories::ConcreteSettingsRepository;
using settings::domain::Settings;


ConcreteSettingsRepository::ConcreteSettingsRepository(std::unique_ptr<settings::factories::SettingsDAOFactory> daoFactory)
: _daoFactory(move(daoFactory)), _commandLineDAO(nullptr), _customDAO(nullptr)
{
	_settings = std::make_unique<Settings>("executablePath");
}


ConcreteSettingsRepository::~ConcreteSettingsRepository()
{
}

const Settings& ConcreteSettingsRepository::get()
{
	return *_settings;
}

const settings::dataaccess::CommandLineArgumentSettingsDAO&
ConcreteSettingsRepository::getCommandLineDAO() {
	
	if (_commandLineDAO == nullptr) {
		_commandLineDAO = _daoFactory->createCommandLineArgumentDAO();
	}
	
	return *_commandLineDAO;
}

const settings::dataaccess::CustomSettingsDAO&
ConcreteSettingsRepository::getCustomDAO() {
	return *_customDAO;
}