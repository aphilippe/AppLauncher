#pragma once
#include <memory>
#include "FileSystem/File/Executable.h"

class ExecutableLauncher
{
public:
	ExecutableLauncher(std::shared_ptr<filesystem::Executable> executable);
	virtual ~ExecutableLauncher();

	void start();

private:
	std::shared_ptr<filesystem::Executable> _executable;
};

