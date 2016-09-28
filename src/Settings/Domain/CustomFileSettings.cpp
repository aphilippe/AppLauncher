#include "CustomFileSettings.h"
#include "Settings/Exceptions/CustomFileSettingsExceptions.h"

using std::string;

using settings::domain::CustomFileSettings;
using settings::domain::FileToBackup;
using settings::exceptions::DuplicateLabelCustomFileSettingsException;

CustomFileSettings::CustomFileSettings(const string& backupFolderPath, const std::vector<FileToBackup>& filePaths, const std::string& executablePath)
    : _backupFolderPath(backupFolderPath), _filePaths(filePaths), _executablePath(executablePath)
{
    this->validateFilePaths();
}


CustomFileSettings::~CustomFileSettings()
{
}

string CustomFileSettings::getBackupFolderPath()
{
	return _backupFolderPath;
}

const std::vector<FileToBackup>& CustomFileSettings::getFilePaths() const
{
    return _filePaths;
}

string CustomFileSettings::getExecutablePath() const
{
    return _executablePath;
}

void CustomFileSettings::validateFilePaths()
{
    for (auto fileIt  = _filePaths.begin(); fileIt != _filePaths.end(); ++fileIt)
    {
        FileToBackup& file = *fileIt;

        auto duplicateIt = find_if(fileIt + 1, _filePaths.end(), [&file] (FileToBackup& f) {
                return file.getLabel() == f.getLabel();
        });

        if (duplicateIt != _filePaths.end())
        {
            throw DuplicateLabelCustomFileSettingsException(duplicateIt->getLabel());
        }
    }
}
