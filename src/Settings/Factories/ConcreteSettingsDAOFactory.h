#pragma once
#include "Settings/Factories/SettingsDAOFactory.h"
#include "Core/Application/CommandLine.h"

namespace settings { namespace factories {

class ConcreteSettingsDAOFactory : public SettingsDAOFactory
{
public:
	ConcreteSettingsDAOFactory(const core::application::CommandLine& commandLine);
	virtual ~ConcreteSettingsDAOFactory();

	// Inherited via SettingsDAOFactory
	virtual std::unique_ptr<settings::dataaccess::CommandLineArgumentSettingsDAO> createCommandLineArgumentDAO() override;
	virtual std::unique_ptr<settings::dataaccess::CustomFileSettingsDAO> createCustomFileSettingsDAO(const std::string& customFileSettingsPath) override;

private:
	core::application::CommandLine _commandLine;

	
};

} }