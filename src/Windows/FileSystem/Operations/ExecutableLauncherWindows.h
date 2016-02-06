#pragma once
#include "FileSystem/Operations/IExecutableLauncher.h"

namespace clt{ namespace filesystem { namespace operations {

	class ExecutableLauncherWindows : public IExecutableLauncher
	{
	public:
		ExecutableLauncherWindows();
		virtual ~ExecutableLauncherWindows();

		virtual void execute(const entities::Path & executable);
	};

} } }