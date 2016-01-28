#include <cstdlib>

#include "Domain/FileSystem/Executable.h"

using namespace filesystem;

int main() {
	Path path("");
	Executable executable(path);
	
	
	executable.execute();
	
	return EXIT_SUCCESS;
}


