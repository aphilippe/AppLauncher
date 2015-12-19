#include "Executable.h"
using namespace filesystem;

filesystem::Executable::Executable(const FilePath & path) : File(path)
{
}

Executable::~Executable()
{
}
