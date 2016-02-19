#ifndef UnixPathInformationReader_hpp
#define UnixPathInformationReader_hpp

#include "FileSystem/Operations/IPathInformationReader.h"

namespace clt { namespace filesystem { namespace operations {
	
	class UnixPathInformationReader : public IPathInformationReader
	{
	public:
		UnixPathInformationReader();
		virtual ~UnixPathInformationReader();
		
		// Inherited via IFileInformationReader
		virtual bool exists(const clt::filesystem::entities::Path & path) const override;
		
		virtual bool isDirectory(const clt::filesystem::entities::Path & path) const override;
		
		// Inherited via IFileInformationReader
		virtual std::string getFileExtension(const clt::filesystem::entities::Path & path) const override;
		
		// Inherited via IPathInformationReader
		virtual bool isExecutable(const clt::filesystem::entities::Path & path) const override;
		
	};
	
} } }

#endif /* UnixPathInformationReader_hpp */
