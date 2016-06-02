#pragma once
#include "Settings/Factories/SettingsDAOFactory.h"

namespace settings { namespace factories {

class ConcreteSettingsDAOFactory : public SettingsDAOFactory
{
public:
	ConcreteSettingsDAOFactory();
	virtual ~ConcreteSettingsDAOFactory();

	// Inherited via SettingsDAOFactory
	virtual std::unique_ptr<settings::dataaccess::CommandLineArgumentSettingsDAO> createCommandLineArgumentDAO() override;
};

} }