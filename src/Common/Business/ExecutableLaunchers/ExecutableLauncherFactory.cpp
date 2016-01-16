#include "ExecutableLauncherFactory.h"
#include "Business/ExecutableLaunchers/ExecutableLauncherUnix.h"

std::shared_ptr<ExecutableLauncher>
ExecutableLauncherFactory::getLauncher(std::shared_ptr<filesystem::Executable> executable)
{
	return nullptr;
}