#include "Path.h"

using namespace std;
using namespace clt::system::entities;

Path::Path(const string & value) : _value(value) {}

string
Path::getValue() const
{
	return _value;
}