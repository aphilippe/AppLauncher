#ifndef ExecutableLauncherFactory_h
#define ExecutableLauncherFactory_h

#include <stdio.h>
#include <memory>
#include "Business/ExecutableLaunchers/ExecutableLauncher.h"

class ExecutableLauncherFactory {
public:
	std::shared_ptr<ExecutableLauncher> getLauncher(std::shared_ptr<filesystem::Executable> executable);
};

#endif /* ExecutableLauncherFactory_hpp */
