#include "ExecutableRepository.h"

#include "Settings/Repositories/SettingsRepository.h"
#include "FileSystem/Factories/PathFactory.h"

using launcher::repositories::ExecutableRepository;
using launcher::domain::Executable;

using file_system::Path;
using file_system::factories::PathFactory;

using settings::domain::Settings;
using settings::repositories::SettingsRepository;

ExecutableRepository::ExecutableRepository(SettingsRepository& settingsRepository)
	: _settingsRepository(settingsRepository)
{
}


ExecutableRepository::~ExecutableRepository()
{
}

Executable ExecutableRepository::get()
{
	const Settings& settings = _settingsRepository.get();
	std::string executablePathString = settings.getExecutablePath();
	PathFactory pathFactory;
	Path path = pathFactory.createPath(executablePathString);


	return Executable(path);
}
