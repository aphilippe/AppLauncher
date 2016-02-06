#pragma once
#include <string>
namespace clt { namespace utils {
	class StringUtils
	{
	public:
		static void replaceAll(std::string & stringToModify, const std::string & stringToFind, const std::string & replacingString);
	};

} }