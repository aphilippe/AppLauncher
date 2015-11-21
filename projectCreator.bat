echo off

set platformsFolder=platforms
set platformName=Visual

set folder=%platformsFolder%\%platformName%

if not exist %folder% (mkdir %folder%)