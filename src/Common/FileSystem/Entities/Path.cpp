#include "Path.h"
#include "Utils/StringUtils.h"
#include "FileSystem/Operations/IPathInformationReader.h"

using namespace std;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::operations;

static const string UNIVERSAL_SEPARATOR = "/";
static const string NOT_ACCEPTABLE_SEPARATOR = "\\";

Path::Path(const std::string & value, std::shared_ptr<clt::filesystem::operations::IPathInformationReader> fileInformationReader) : _value(value), _informationReader(fileInformationReader)
{
	// in the app we are only working with "/" separator
	clt::utils::StringUtils::replaceAll(_value, NOT_ACCEPTABLE_SEPARATOR, UNIVERSAL_SEPARATOR);
}

Path::~Path()
{
}


string
Path::getValue() const
{
	return _value;
}

Path clt::filesystem::entities::Path::getParent() const
{
	size_t lastSeparatorPosition = _value.find_last_of(UNIVERSAL_SEPARATOR);
	string parentValue = _value.substr(0, lastSeparatorPosition);
	return Path(parentValue, nullptr);
}

bool clt::filesystem::entities::Path::exists() const
{
	return _informationReader->exists(*this);
}

bool clt::filesystem::entities::Path::isDirectory() const
{
	return _informationReader->isDirectory(*this);
}

bool clt::filesystem::entities::Path::isExecutable() const
{
	return _informationReader->isExecutable(*this);
}

std::string clt::filesystem::entities::Path::getFileExtension() const
{
	return _informationReader->getFileExtension(*this);
}
