#ifndef ExecutableLauncherUnix_hpp
#define ExecutableLauncherUnix_hpp

#include <stdio.h>
#include "IExecutableLauncherSpec.h"

class ExecutableLauncherUnix : public IExecutableLauncherSpec {
	
public:
	virtual ~ExecutableLauncherUnix() {};
	
	void start() override;
};

#endif /* ExecutableLauncherUnix_hpp */
