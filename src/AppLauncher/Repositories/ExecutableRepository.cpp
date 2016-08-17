#include "ExecutableRepository.h"

using launcher::repositories::ExecutableRepository;
using launcher::domain::Executable;

ExecutableRepository::ExecutableRepository()
{
}


ExecutableRepository::~ExecutableRepository()
{
}

Executable ExecutableRepository::get()
{
	return launcher::domain::Executable();
}
