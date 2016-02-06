#include "Path.h"
#include "Utils/StringUtils.h"

using namespace std;
using namespace clt::system::entities;

static const string UNIVERSAL_SEPARATOR = "/";
static const string NOT_ACCEPTABLE_SEPARATOR = "\\";

Path::Path(const string & value) : _value(value)
{
	// in the app we are only working with "/" separator
	clt::utils::StringUtils::replaceAll(_value, NOT_ACCEPTABLE_SEPARATOR, UNIVERSAL_SEPARATOR);
}

string
Path::getValue() const
{
	return _value;
}

Path clt::system::entities::Path::getParent() const
{
	size_t lastSeparatorPosition = _value.find_last_of(UNIVERSAL_SEPARATOR);
	string parentValue = _value.substr(0, lastSeparatorPosition);
	return Path(parentValue);
}
