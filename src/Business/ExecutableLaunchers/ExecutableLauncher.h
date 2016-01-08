#pragma once
#include <memory>
#include "FileSystem/File/Executable.h"
#include "Business/ExecutableLaunchers/IExecutableLauncherSpec.h"

class ExecutableLauncher
{
public:
	ExecutableLauncher(std::shared_ptr<filesystem::Executable> executable, std::unique_ptr<IExecutableLauncherSpec> launcherSpec);
	virtual ~ExecutableLauncher();

	void start();
	std::shared_ptr<filesystem::Executable> getExecutable();

private:
	std::shared_ptr<filesystem::Executable> _executable;
	std::unique_ptr<IExecutableLauncherSpec> _launcherSpec;
};

