#include "Exception.h"

using core::Exception;
using std::string;

Exception::Exception()
{
}


Exception::~Exception()
{
}

char const * core::Exception::what() const
{
	return _message.c_str();
}

void Exception::setMessage(const string & message)
{
	_message = message;
}
