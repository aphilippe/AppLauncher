#pragma once
#include "Settings/DataAccess/CommandLineArgumentSettingsDAO.h"
#include "Core/Application/CommandLine.h"
#include <memory>

namespace settings {
	namespace builders {
		class CommandLineSettingsBuilder;
	}
}

namespace settings { namespace dataaccess {
class ConcreteCommandLineArgumentSettingsDAO : public CommandLineArgumentSettingsDAO
{
public:
	ConcreteCommandLineArgumentSettingsDAO(const core::application::CommandLine& commandLine, std::unique_ptr<settings::builders::CommandLineSettingsBuilder> settingsBuilder);
	virtual ~ConcreteCommandLineArgumentSettingsDAO();

	// Inherited via CommandLineArgumentSettingsDAO
	virtual settings::domain::CommandLineSettings get() override;

private:
	core::application::CommandLine _commandLine;
	std::unique_ptr<settings::builders::CommandLineSettingsBuilder> _settingsBuilder;

		
};

} }