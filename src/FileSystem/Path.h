#pragma once
#include <string>
#include <memory>

namespace file_system {
	namespace operations {
		class ReadInformationOperation;
	}
}

namespace file_system {

	class Path
	{
	public:
		Path(const std::string& value, std::shared_ptr<file_system::operations::ReadInformationOperation> readInformationOperation);
		Path(const Path& other);
		virtual ~Path();

		std::string stringValue() const;

		bool exists() const;

		bool isFile() const;
		bool isFolder() const;

		bool canRead() const;
		bool canWrite() const;

	private:
		std::string _value;
		std::shared_ptr<file_system::operations::ReadInformationOperation> _readInformationOperation;
	};

}