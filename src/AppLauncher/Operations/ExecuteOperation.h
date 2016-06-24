#pragma once
#include "AppLauncher/Operations/IOperation.h"

namespace launcher {
	namespace operations {

		class ExecuteOperation : public launcher::IOperation
		{
		public:
			ExecuteOperation();
			virtual ~ExecuteOperation();

			void run() override;
		};

	}
}