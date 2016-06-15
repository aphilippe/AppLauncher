#ifndef CustomFileSettingsBuilder_hpp
#define CustomFileSettingsBuilder_hpp

#include <stdio.h>
#include "Settings/Domain/CustomFileSettings.h"


namespace settings { namespace builders {

class CustomFileSettingsBuilder {
public:
	settings::domain::CustomFileSettings build();
};

} }
	
#endif /* CustomFileSettingsBuilder_hpp */
