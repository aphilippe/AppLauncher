#ifndef IExecutableLauncher_hpp
#define IExecutableLauncher_hpp

#include <stdio.h>

class IExecutableLauncherSpec {
public:
	
	virtual ~IExecutableLauncherSpec() {};
	
	virtual void start() = 0;
};

#endif /* IExecutableLauncher_hpp */
