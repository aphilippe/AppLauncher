#pragma once

#include "Settings/Domain/Settings.h"

namespace settings { namespace repositories {

class SettingsRepository
{
public:
	virtual ~SettingsRepository() {}

	virtual const settings::domain::Settings& get() = 0;
};

} }