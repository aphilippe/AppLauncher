#pragma once

namespace core { namespace application {

class CommandLine
{
public:
	CommandLine(int argc, char** argv);
	virtual ~CommandLine();

	int getArgc() const;
	char** getArgv() const;

private:
	int _argc;
	char** _argv;
};

} }