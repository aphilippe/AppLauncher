#pragma once
#include "FileSystem/Path.h"

namespace file_system {
	namespace operations {

		class CopyOperation
		{
		public:
			CopyOperation();
			virtual ~CopyOperation();

            void copy(const file_system::Path& sourceFile, const file_system::Path& destinationPath);
		};

	}
}
