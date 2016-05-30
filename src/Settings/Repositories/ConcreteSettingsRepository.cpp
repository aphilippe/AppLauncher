#include "ConcreteSettingsRepository.h"

using settings::repositories::ConcreteSettingsRepository;
using settings::domain::Settings;


ConcreteSettingsRepository::ConcreteSettingsRepository()
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
