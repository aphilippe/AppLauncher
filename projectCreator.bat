@echo off

SET cleanParameter=clean
SET cleanAllParamter=cleanAll
SET mypath=%~dp0
set platformsFolder=projects

SET firstParameter=%1
if %firstParameter% EQU %cleanAllParamter% (
	goto:cleanAll
) else if %firstParameter% EQU %cleanParameter% (
	goto:clean
) else (
	goto:createProject
)

pause
goto:eof

::--------------------------------------------------------
::-- Function section starts below here
::--------------------------------------------------------

:createProject

set platformName=%*

set folder=%mypath%\%platformsFolder%\%platformName%

if not exist %folder% (mkdir %folder%)

cd %folder%

rem call cmake
cmake.exe %mypath% -G%platformName%

cd %mypath%
goto:eof

:cleanAll
RMDIR /S /Q "%mypath%\%platformsFolder%"
goto:eof

:clean
set platformName=%2
set folder=%mypath%\%platformsFolder%\%platformName%
if not exist %folder% (goto:eof)

RMDIR /S /Q %folder%
goto:eof