#pragma once

#include "AppLauncher/Domain/Executable.h"

namespace launcher { namespace repositories {

class ExecutableRepository
{
public:
	ExecutableRepository();
	virtual ~ExecutableRepository();

	launcher::domain::Executable get();
};

} }