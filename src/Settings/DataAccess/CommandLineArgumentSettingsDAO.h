#ifndef CommandLineSettingsDAO_h
#define CommandLineSettingsDAO_h

#include "Settings/Domain/CommandLineSettings.h"


namespace settings { namespace dataaccess {

class CommandLineArgumentSettingsDAO {
	
public:
	virtual settings::domain::CommandLineSettings get() = 0;

};
	
} }

#endif /* CommandLineSettingsDAO_h */
