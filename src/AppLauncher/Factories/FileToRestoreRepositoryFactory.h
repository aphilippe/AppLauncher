#pragma once
#include <memory>

#include "AppLauncher/Repositories/FileToRestoreRepository.h"

namespace launcher {
	namespace factories {

		class FileToRestoreRepositoryFactory
		{
		public:
			FileToRestoreRepositoryFactory();
			virtual ~FileToRestoreRepositoryFactory();

			std::unique_ptr<launcher::repositories::FileToRestoreRepository> create() const;
		};

	}
}