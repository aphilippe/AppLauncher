#pragma once

namespace launcher { namespace domain {

class Executable
{
public:
	Executable();
	virtual ~Executable();

	void execute();
};

} }