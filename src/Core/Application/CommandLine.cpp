#include "CommandLine.h"

using core::application::CommandLine;

CommandLine::CommandLine(int argc, char** argv)
	: _argc(argc), _argv(argv)
{
}


CommandLine::~CommandLine()
{
}

int core::application::CommandLine::getArgc() const
{
	return _argc;
}

char ** core::application::CommandLine::getArgv() const
{
	return _argv;
}
