#pragma once
#include <string>

namespace file_system {

	class Path
	{
	public:
		Path(const std::string& value);
		virtual ~Path();

		std::string stringValue();

	private:
		std::string _value;
	};

}