@echo off

if "%MSI_ROOT%"=="" (
  echo Project root not set!
  exit /B
)

if not exist "%MSI_ROOT%" (
  echo Invalid project directory %MSI_ROOT%
  exit /B
)

if not exist "%MSI_ROOT%/etc/astyle.conf" (
  echo Config file not found
  exit /B
)

if not exist "%MSI_ROOT%/etc/astyle-clean.bat" (
  echo Clean script not found
  exit /B
)

call astyle --options=%MSI_ROOT%/etc/astyle.conf --recursive %MSI_ROOT%/libs/*.cpp
call astyle --options=%MSI_ROOT%/etc/astyle.conf --recursive %MSI_ROOT%/libs/*.hpp 
call astyle --options=%MSI_ROOT%/etc/astyle.conf --recursive %MSI_ROOT%/msi/*.cpp
call astyle --options=%MSI_ROOT%/etc/astyle.conf --recursive %MSI_ROOT%/msi/*.hpp

call %MSI_ROOT%/etc/astyle-clean.bat libs
call %MSI_ROOT%/etc/astyle-clean.bat msi

for /F "usebackq delims==" %%i in (`head -1 %MSI_ROOT%/ChangeLog`) do @set MSG="%%i"
call svn commit %MSI_ROOT% -m %MSG%
call svnsync --sync-username msisync --sync-password msisync --non-interactive sync %SVN_MIRROR_URL%
call svn up %MSI_ROOT%

