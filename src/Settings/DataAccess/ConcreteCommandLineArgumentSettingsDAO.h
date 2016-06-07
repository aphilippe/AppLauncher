#pragma once
#include "Settings/DataAccess/CommandLineArgumentSettingsDAO.h"
#include "Core/Application/CommandLine.h"

namespace settings { namespace dataaccess {
class ConcreteCommandLineArgumentSettingsDAO : public CommandLineArgumentSettingsDAO
{
public:
	ConcreteCommandLineArgumentSettingsDAO(const core::application::CommandLine& commandLine);
	virtual ~ConcreteCommandLineArgumentSettingsDAO();

private:
	core::application::CommandLine _commandLine;
};

} }