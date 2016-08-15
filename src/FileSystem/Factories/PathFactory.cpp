#include "PathFactory.h"
#include "FileSystem/Operations/ReadInformationOperation.h"

using file_system::factories::PathFactory;

using file_system::Path;
using file_system::operations::ReadInformationOperation;

PathFactory::PathFactory()
{
}


PathFactory::~PathFactory()
{
}

Path PathFactory::createPath(const std::string & pathString)
{
	return Path(pathString, std::make_shared<ReadInformationOperation>());
}
