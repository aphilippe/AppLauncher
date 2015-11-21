echo off

SET mypath=%~dp0
set platformsFolder=platforms
set platformName=%1

set folder=%mypath%\%platformsFolder%\%platformName%

if not exist %folder% (mkdir %folder%)

cd %folder%

rem call cmake
cmake.exe %mypath% -G%platformName%

cd %mypath%

pause