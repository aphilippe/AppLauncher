#pragma once
#include "AppLauncher/Operations/IOperation.h"

namespace launcher { namespace operations {

class BackupOperation : public launcher::IOperation
{
public:
	BackupOperation();
	virtual ~BackupOperation();

	void run() override;
};

} }