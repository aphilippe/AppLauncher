#pragma once

#include "AppLauncher/Domain/Executable.h"

namespace settings {
	namespace repositories {
		class SettingsRepository;
	}
}


namespace launcher { namespace repositories {

class ExecutableRepository
{
public:
	ExecutableRepository(settings::repositories::SettingsRepository& settingsRepository);
	virtual ~ExecutableRepository();

	launcher::domain::Executable get();

private:
	settings::repositories::SettingsRepository& _settingsRepository;
};

} }