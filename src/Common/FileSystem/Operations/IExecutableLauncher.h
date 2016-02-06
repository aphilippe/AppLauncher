#ifndef IExecutableLauncher_hpp
#define IExecutableLauncher_hpp

#include <stdio.h>
#include "FileSystem/Entities/Path.h"

namespace clt { namespace filesystem { namespace operations {

class IExecutableLauncher {
public:
	IExecutableLauncher() {};
	virtual ~IExecutableLauncher() {};
	
	virtual void execute(const entities::Path & executable) = 0;
};
	
} } }

#endif /* IExecutableLauncher_hpp */
