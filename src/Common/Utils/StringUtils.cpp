#include "StringUtils.h"

using namespace std;
using namespace clt::utils;


void StringUtils::replaceAll(std::string & source, const std::string & find, const std::string & replace)
{
	for (string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
	{
		source.replace(i, find.length(), replace);
		i += replace.length();
	}
}
