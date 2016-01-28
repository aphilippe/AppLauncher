#include "Executable.h"
using namespace filesystem;

filesystem::Executable::Executable(const Path & path) : _path(path)
{
}

Executable::~Executable()
{
}


void
Executable::execute() {
	
}