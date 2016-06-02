
#ifndef SettingsDAOFactory_hpp
#define SettingsDAOFactory_hpp

#include <stdio.h>
#include "Settings/DataAccess/CommandLineArgumentSettingsDAO.h"
#include "Settings/DataAccess/CustomSettingsDAO.h"

namespace settings { namespace factories {

class SettingsDAOFactory {
public:
	virtual ~SettingsDAOFactory() {}
	virtual std::unique_ptr<settings::dataaccess::CommandLineArgumentSettingsDAO> createCommandLineArgumentDAO() = 0;
};

} }

#endif /* SettingsDAOFactory_hpp */
