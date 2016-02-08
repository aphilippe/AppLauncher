#ifndef ExecutableLauncherUnix_hpp
#define ExecutableLauncherUnix_hpp

#include <stdio.h>
#include "FileSystem/Operations/IExecutableLauncher.h"

namespace clt { namespace filesystem { namespace operations {

class ExecutableLauncherUnix : public IExecutableLauncher {
	
public:
	virtual ~ExecutableLauncherUnix() {};
	
	void execute(const entities::Path & executable) override;
};

} } }

#endif /* ExecutableLauncherUnix_hpp */
