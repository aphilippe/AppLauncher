
#ifndef SettingsDAOFactory_hpp
#define SettingsDAOFactory_hpp

#include <memory>
#include "Settings/DataAccess/CommandLineArgumentSettingsDAO.h"
#include "Settings/DataAccess/CustomFileSettingsDAO.h"

namespace settings { namespace factories {

class SettingsDAOFactory {
public:
	virtual ~SettingsDAOFactory() {}
	virtual std::unique_ptr<settings::dataaccess::CommandLineArgumentSettingsDAO> createCommandLineArgumentDAO() = 0;
	virtual std::unique_ptr<settings::dataaccess::CustomFileSettingsDAO> createCustomFileSettingsDAO() = 0;
};

} }

#endif /* SettingsDAOFactory_hpp */
