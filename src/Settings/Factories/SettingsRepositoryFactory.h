#pragma once
#include <memory>
#include "Settings/Repositories/SettingsRepository.h"

namespace settings { namespace factories {

class SettingsRepositoryFactory
{
public:
	SettingsRepositoryFactory();
	virtual ~SettingsRepositoryFactory();
	std::unique_ptr<settings::repositories::SettingsRepository> createRepository();
};

} }