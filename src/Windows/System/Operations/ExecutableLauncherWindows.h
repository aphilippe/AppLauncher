#pragma once
#include "System/Operations/IExecutableLauncher.h"

namespace clt{ namespace system { namespace operations {

	class ExecutableLauncherWindows : public IExecutableLauncher
	{
	public:
		ExecutableLauncherWindows();
		virtual ~ExecutableLauncherWindows();

		virtual void execute(const entities::Path & executable);
	};

} } }