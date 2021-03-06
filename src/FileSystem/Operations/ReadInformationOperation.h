#pragma once

#include "FileSystem/Path.h"

namespace file_system {
	namespace operations {
		
		class ReadInformationOperation {
		public:
			bool exists(const file_system::Path& path)const;

			bool isDirectory(const Path & path) const;
			bool isFile(const Path & path) const;

			bool isExecutable(const Path & path) const;

			bool canRead(const Path& path) const;
			bool canWrite(const Path& path) const;
		};

	}
}