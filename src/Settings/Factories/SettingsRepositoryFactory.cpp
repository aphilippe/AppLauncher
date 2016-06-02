#include "SettingsRepositoryFactory.h"
#include "Settings/Repositories/ConcreteSettingsRepository.h"

using settings::factories::SettingsRepositoryFactory;
using settings::repositories::SettingsRepository;
using settings::repositories::ConcreteSettingsRepository;

SettingsRepositoryFactory::SettingsRepositoryFactory()
{
}


SettingsRepositoryFactory::~SettingsRepositoryFactory()
{
}

std::unique_ptr<SettingsRepository> SettingsRepositoryFactory::createRepository()
{
	return std::make_unique<ConcreteSettingsRepository>(nullptr);
}
