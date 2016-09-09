#include "FileToBackup.h"

using settings::domain::FileToBackup;

FileToBackup::FileToBackup(const std::string& path, const std::string& label)
    : _path(path), _label(label)
{

}

FileToBackup::~FileToBackup()
{

}

std::string FileToBackup::getPath() const
{
    return _path;
}

std::string FileToBackup::getLabel() const
{
	return _label;
}
