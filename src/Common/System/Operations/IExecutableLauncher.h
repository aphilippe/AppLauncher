#ifndef IExecutableLauncher_hpp
#define IExecutableLauncher_hpp

#include <stdio.h>

namespace clt { namespace system { namespace operations {

class IExecutableLauncher {
public:
	
	virtual ~IExecutableLauncher() {};
	
	virtual void execute() = 0;
};
	
} } }

#endif /* IExecutableLauncher_hpp */
