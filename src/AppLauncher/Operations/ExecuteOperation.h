#pragma once
#include "AppLauncher/Operations/IOperation.h"

namespace launcher {
	namespace repositories {
		class ExecutableRepository;
	}
}

namespace launcher {
	namespace operations {

		class ExecuteOperation : public launcher::IOperation
		{
		public:
			ExecuteOperation(launcher::repositories::ExecutableRepository& executableRepository);
			virtual ~ExecuteOperation();

			void run() override;

		private:
			launcher::repositories::ExecutableRepository& _executableRepository;
		};

	}
}