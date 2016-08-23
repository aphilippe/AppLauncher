#pragma once

#include <memory>

#include "Settings/Repositories/SettingsRepository.h"

#include "AppLauncher/Repositories/BackupFolderRepository.h"
#include "AppLauncher/Repositories/FileToBackupRepository.h"
#include "AppLauncher/Repositories/ExecutableRepository.h"

extern std::unique_ptr<settings::repositories::SettingsRepository> settingsRepository;

extern std::unique_ptr<launcher::repositories::FileToBackupRepository> fileToBackupRepository;
extern std::unique_ptr<launcher::repositories::BackupFolderRepository> backupFolderRepository;
extern std::unique_ptr<launcher::repositories::ExecutableRepository> executableRepository;