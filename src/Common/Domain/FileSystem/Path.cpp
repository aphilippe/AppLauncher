#include "Path.h"

using namespace std;
using namespace filesystem;

Path::Path(const string & value) : _value(value) {}

string
Path::getValue() const
{
	return _value;
}