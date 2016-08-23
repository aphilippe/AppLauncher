#include "ExecuteOperation.h"
#include "AppLauncher/Repositories/ExecutableRepository.h"

using launcher::operations::ExecuteOperation;
using launcher::repositories::ExecutableRepository;
using launcher::domain::Executable;

ExecuteOperation::ExecuteOperation(ExecutableRepository& executableRepository)
	: _executableRepository(executableRepository)
{
}


ExecuteOperation::~ExecuteOperation()
{
}

void ExecuteOperation::run()
{
	Executable executable = _executableRepository.get();
	executable.execute();
}
