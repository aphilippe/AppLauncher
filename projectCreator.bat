rem echo off

SET mypath=%~dp0
set platformsFolder=platforms
set platformName="Visual Studio 14"

set folder=%mypath%\%platformsFolder%\%platformName%

if not exist %folder% (mkdir %folder%)

cd %platformsFolder%

rem call cmake
cmake.exe .. -G%platformName%

cd %mypath%

pause