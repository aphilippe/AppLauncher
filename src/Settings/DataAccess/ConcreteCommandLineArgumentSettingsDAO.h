#pragma once
#include "Settings/DataAccess/CommandLineArgumentSettingsDAO.h"

namespace settings { namespace dataaccess {
class ConcreteCommandLineArgumentSettingsDAO : public CommandLineArgumentSettingsDAO
{
public:
	ConcreteCommandLineArgumentSettingsDAO();
	virtual ~ConcreteCommandLineArgumentSettingsDAO();
};

} }