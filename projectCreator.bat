@echo off

SET cleanParameter=clean
SET cleanAllParamter=cleanAll

SET firstParameter=%1
if %firstParameter% EQU %cleanAllParamter% (
	echo "cleanAll not implemented"
) else if %firstParameter% EQU %cleanParameter% (
	echo "clean not implemented"
) else (
	goto:createProject
)

pause
goto:eof

::--------------------------------------------------------
::-- Function section starts below here
::--------------------------------------------------------

:createProject
SET mypath=%~dp0
set platformsFolder=platforms
set platformName=%*

set folder=%mypath%\%platformsFolder%\%platformName%

if not exist %folder% (mkdir %folder%)

cd %folder%

rem call cmake
cmake.exe %mypath% -G%platformName%

cd %mypath%
goto:eof