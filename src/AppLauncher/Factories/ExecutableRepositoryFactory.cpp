#include "ExecutableRepositoryFactory.h"

using launcher::factories::ExecutableRepositoryFactory;
using launcher::repositories::ExecutableRepository;

ExecutableRepositoryFactory::ExecutableRepositoryFactory()
{
}


ExecutableRepositoryFactory::~ExecutableRepositoryFactory()
{
}

std::unique_ptr<ExecutableRepository> ExecutableRepositoryFactory::create() const
{
	return std::make_unique<ExecutableRepository>();
}

