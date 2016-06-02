#include "SettingsRepositoryFactory.h"
#include "Settings/Repositories/ConcreteSettingsRepository.h"
#include "Settings/Factories/ConcreteSettingsDAOFactory.h"

using settings::factories::SettingsRepositoryFactory;
using settings::repositories::SettingsRepository;
using settings::repositories::ConcreteSettingsRepository;
using settings::factories::ConcreteSettingsDAOFactory;

SettingsRepositoryFactory::SettingsRepositoryFactory()
{
}


SettingsRepositoryFactory::~SettingsRepositoryFactory()
{
}

std::unique_ptr<SettingsRepository> SettingsRepositoryFactory::createRepository()
{
	std::unique_ptr<ConcreteSettingsDAOFactory> settingsDAOFactory = std::make_unique<ConcreteSettingsDAOFactory>();
	return std::make_unique<ConcreteSettingsRepository>(std::move(settingsDAOFactory));
}
