#include "ApplicationParametersManager.h"

using namespace application::parameters;

ApplicationParametersManager::ApplicationParametersManager(std::unique_ptr<ApplicationParametersBuilder> builder, std::unique_ptr<ApplicationParametersReader> reader)
{
	_builder = std::move(builder);
	_reader = std::move(reader);
	
	_reader->setOnExecutablePath([this] (const std::string& executablePath) {_builder->setExecutablePath(executablePath);});
}


ApplicationParametersManager::~ApplicationParametersManager()
{
}

void application::parameters::ApplicationParametersManager::start(char * argv[])
{
	_reader->start(argv);

	_parameters = std::make_unique<ApplicationParameters>(_builder->build());
}

ApplicationParameters & application::parameters::ApplicationParametersManager::getParameters() const
{
	return *_parameters;
}
