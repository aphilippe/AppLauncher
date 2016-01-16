#include "ExecutableLauncher.h"

using namespace filesystem;

ExecutableLauncher::ExecutableLauncher(std::shared_ptr<Executable> executable, std::unique_ptr<IExecutableLauncherSpec> launcherSpec) : _executable(executable)
{
	_launcherSpec = std::move(launcherSpec);
}


ExecutableLauncher::~ExecutableLauncher()
{
}

void ExecutableLauncher::start()
{
	_launcherSpec->start();
}

std::shared_ptr<filesystem::Executable> ExecutableLauncher::getExecutable()
{
	return _executable;
}
