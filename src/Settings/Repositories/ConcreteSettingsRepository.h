#pragma once
#include <memory>
#include "Settings/Repositories/SettingsRepository.h"
#include "Settings/Factories/SettingsDAOFactory.h"

namespace settings { namespace dataaccess {
	class CommandLineArgumentSettingsDAO;
	class CustomSettingsDAO;
} }


namespace settings { namespace repositories {

class ConcreteSettingsRepository : public SettingsRepository
{
public:
	ConcreteSettingsRepository(std::unique_ptr<settings::factories::SettingsDAOFactory> daoFactory);
	virtual ~ConcreteSettingsRepository();

	// Inherited via SettingsRepository
	virtual const settings::domain::Settings & get() override;

private:
	std::unique_ptr<settings::domain::Settings> _settings;
	
	std::unique_ptr<settings::factories::SettingsDAOFactory> _daoFactory;
	
	std::unique_ptr<settings::dataaccess::CommandLineArgumentSettingsDAO> _commandLineDAO;
	std::unique_ptr<settings::dataaccess::CustomFileSettingsDAO> _customDAO;
	
	const settings::dataaccess::CommandLineArgumentSettingsDAO& getCommandLineDAO();
	const settings::dataaccess::CustomFileSettingsDAO& getCustomFileDAO();
};

} }