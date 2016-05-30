#pragma once
#include <memory>
#include "Settings/Repositories/SettingsRepository.h"

namespace settings { namespace repositories {

class ConcreteSettingsRepository : public SettingsRepository
{
public:
	ConcreteSettingsRepository();
	virtual ~ConcreteSettingsRepository();

	// Inherited via SettingsRepository
	virtual const settings::domain::Settings & get() override;

private:
	std::unique_ptr<settings::domain::Settings> _settings;
};

} }