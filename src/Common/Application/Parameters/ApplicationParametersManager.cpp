#include "ApplicationParametersManager.h"

using namespace application::parameters;

ApplicationParametersManager::ApplicationParametersManager(std::unique_ptr<ApplicationParametersBuilder> builder, std::unique_ptr<ApplicationParametersReader> reader)
{
	_builder = std::move(builder);
	_reader = std::move(reader);
	
	_reader->setOnExecutablePath([this] (const std::string& executablePath) {_builder->setExecutablePath(executablePath);});
	_reader->setOnBackupParametersFilePath([this] (const std::string& path) {_builder->setBackupParametersFilePath(path);});
}


ApplicationParametersManager::~ApplicationParametersManager()
{
}

void application::parameters::ApplicationParametersManager::start(int argc, char * argv[])
{
	_reader->start(argc, argv);

	_parameters = std::make_unique<ApplicationParameters>(_builder->build());
}

ApplicationParameters & application::parameters::ApplicationParametersManager::getParameters() const
{
	return *_parameters;
}
