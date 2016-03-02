#include "ApplicationParametersManager.h"

using namespace application::parameters;

ApplicationParametersManager::ApplicationParametersManager(std::unique_ptr<ApplicationParametersBuilder> builder)
{
	_builder = std::move(builder);
}


ApplicationParametersManager::~ApplicationParametersManager()
{
}

void application::parameters::ApplicationParametersManager::start(char * argv[])
{
	_builder->setExecutablePath(argv[1]);

	_parameters = std::make_unique<ApplicationParameters>(_builder->build());
}

ApplicationParameters & application::parameters::ApplicationParametersManager::getParameters() const
{
	return *_parameters;
}
