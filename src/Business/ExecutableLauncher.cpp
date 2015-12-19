#include "ExecutableLauncher.h"

using namespace filesystem;

ExecutableLauncher::ExecutableLauncher(std::shared_ptr<Executable> executable) : _executable(executable)
{
}


ExecutableLauncher::~ExecutableLauncher()
{
}

void ExecutableLauncher::start()
{
}
