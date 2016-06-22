#include "MergedSettingsBuilder.h"
#include "Settings/Domain/CommandLineSettings.h"
#include "Settings/Domain/CustomFileSettings.h"

using settings::builders::MergedSettingsBuilder;
using settings::domain::CommandLineSettings;
using settings::domain::CustomFileSettings;
using settings::domain::Settings;

MergedSettingsBuilder::MergedSettingsBuilder()
	:_customFileSettings(nullptr), _commandLineSettings(nullptr)
{
}

MergedSettingsBuilder::~MergedSettingsBuilder()
{
}

void MergedSettingsBuilder::setCommandLineSettings(std::shared_ptr<CommandLineSettings> commandLineSettings)
{
	_commandLineSettings = commandLineSettings;
}

void MergedSettingsBuilder::setCustomFileSettings(std::shared_ptr<CustomFileSettings> customFileSettings)
{
	_customFileSettings = customFileSettings;
}

std::unique_ptr<Settings> MergedSettingsBuilder::build()
{
	std::string executablePath = this->mergeExecutablePath();
	std::string backupPath = this->mergeBackupPath();
	auto filePaths = this->mergeFilePaths();

	return std::make_unique<settings::domain::Settings>(executablePath, backupPath, filePaths);
}

std::string settings::builders::MergedSettingsBuilder::mergeExecutablePath() const
{
	std::string executablePath = _commandLineSettings->getExecutablePath();
	if (executablePath.empty())
	{
		throw "";
	}
	return executablePath;
}

std::string settings::builders::MergedSettingsBuilder::mergeBackupPath() const
{
	std::string backupPath = _customFileSettings->getBackupFolderPath();
	if (backupPath.empty())
	{
		throw "";
	}
	return backupPath;
}

std::vector<std::string> settings::builders::MergedSettingsBuilder::mergeFilePaths() const
{
	auto paths = _customFileSettings->getFilePaths();
	if (paths.size() == 0)
	{
		throw "";
	}
	return paths;
}
