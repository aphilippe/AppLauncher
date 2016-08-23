#pragma once

#include <memory>

#include "AppLauncher/Repositories/ExecutableRepository.h"

namespace launcher {
	namespace factories {

		class ExecutableRepositoryFactory
		{
		public:
			ExecutableRepositoryFactory();
			virtual ~ExecutableRepositoryFactory();

			std::unique_ptr<launcher::repositories::ExecutableRepository> create() const;
		};

	}
}
