#include "FileToBackupRepository.h"

using launcher::repositories::FileToBackupRepository;
using launcher::domain::FileToBackup;

FileToBackupRepository::FileToBackupRepository()
{
}


FileToBackupRepository::~FileToBackupRepository()
{
}

std::vector<FileToBackup>FileToBackupRepository::get()
{
	return{FileToBackup(), FileToBackup(), FileToBackup()};
}
