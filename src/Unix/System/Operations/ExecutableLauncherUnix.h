#ifndef ExecutableLauncherUnix_hpp
#define ExecutableLauncherUnix_hpp

#include <stdio.h>
#include "System/Operations/IExecutableLauncher.h"

namespace clt { namespace system { namespace operations {

class ExecutableLauncherUnix : public IExecutableLauncher {
	
public:
	virtual ~ExecutableLauncherUnix() {};
	
	void execute() override;
};

} } }

#endif /* ExecutableLauncherUnix_hpp */
