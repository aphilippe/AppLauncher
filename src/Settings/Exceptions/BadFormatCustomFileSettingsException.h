#pragma once
#include <exception>


class BadFormatCustomFileSettingsException : public std::exception
{
public:
	BadFormatCustomFileSettingsException();
	virtual ~BadFormatCustomFileSettingsException();

};

