#pragma once

#include "AppLauncher/Operations/IOperation.h"

namespace launcher {
	namespace operations {

		class RestoreOperation : public launcher::IOperation
		{
		public:
			RestoreOperation();
			virtual ~RestoreOperation();

			void run() override;
		};
	}
}