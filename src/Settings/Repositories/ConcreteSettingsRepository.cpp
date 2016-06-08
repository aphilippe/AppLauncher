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
	if (!_commandLineDAO) {
		_commandLineDAO = _daoFactory->createCommandLineArgumentDAO();
	}

	settings::domain::CommandLineSettings cmdSettings = _commandLineDAO->get();

	_settings = std::make_unique<Settings>(cmdSettings.getExecutablePath());
	return *_settings;
}

const settings::dataaccess::CommandLineArgumentSettingsDAO&
ConcreteSettingsRepository::getCommandLineDAO() {
	
	if (_commandLineDAO == nullptr) {
		_commandLineDAO = _daoFactory->createCommandLineArgumentDAO();
	}
	
	return *_commandLineDAO;
}

const settings::dataaccess::CustomFileSettingsDAO&
ConcreteSettingsRepository::getCustomFileDAO() {
	return *_customDAO;
}