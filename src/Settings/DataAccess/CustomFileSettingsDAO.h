#ifndef CustomSettingsDAO_h
#define CustomSettingsDAO_h

#include "Settings/Domain/CustomFileSettings.h"

namespace settings { namespace dataaccess {

class CustomFileSettingsDAO {
public:
	virtual ~CustomFileSettingsDAO() {}

	virtual settings::domain::CustomFileSettings get() = 0;
};

} }

#endif /* CustomSettingsDAO_h */
