#include "ExecutableLauncherFactory.h"
#include "Business/ExecutableLaunchers/ExecutableLauncherUnix.h"

std::shared_ptr<ExecutableLauncher>
ExecutableLauncherFactory::getLauncher(std::shared_ptr<filesystem::Executable> executable)
{
	IExecutableLauncherSpec* launcherSpec;
	launcherSpec = new ExecutableLauncherUnix();
	
	ExecutableLauncher* launcher = new ExecutableLauncher(executable, std::unique_ptr<IExecutableLauncherSpec>(launcherSpec));
	
	return std::shared_ptr<ExecutableLauncher>(launcher);
}