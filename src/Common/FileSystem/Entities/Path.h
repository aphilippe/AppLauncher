#ifndef Path_hpp
#define Path_hpp

#include <stdio.h>
#include <string>
#include <memory>

namespace clt { namespace filesystem {
	namespace operations {
		class IFileInformationReader;
	}
	namespace entities {
	
		class Path {
		public:
			Path(const std::string & value, std::shared_ptr<clt::filesystem::operations::IFileInformationReader> fileInformationReader);
			virtual ~Path();
			std::string getValue() const;

			Path getParent() const;

			bool exists() const;
			bool isDirectory() const;
			std::string getFileExtension() const;
	
		private:
			std::string _value;
			std::shared_ptr<clt::filesystem::operations::IFileInformationReader> _informationReader;
		};

} } }
#endif /* Path_hpp */
