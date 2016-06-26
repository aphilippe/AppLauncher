#pragma once
#include <string>

namespace file_system {

	class Path
	{
	public:
		Path(const std::string& value);
		virtual ~Path();

		std::string stringValue() const;

		bool exists() const;

		bool isFile() const;
		bool isFolder() const;

		bool canRead() const;
		bool canWrite() const;

	private:
		std::string _value;
	};

}