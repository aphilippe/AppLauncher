#include "FileToBackup.h"

using settings::domain::FileToBackup;

FileToBackup::FileToBackup(const std::string& path)
    : _path(path)
{

}

FileToBackup::~FileToBackup()
{

}

std::string FileToBackup::getPath() const
{
    return _path;
}
