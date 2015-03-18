@echo off
set TEMPLATE=%1

if "%1" == "" goto usage

xsltproc message_types.xslt %TEMPLATE% > message_types.hpp

@goto end

:usage
@echo "generate_message_types.bat <template file>"
@goto end

:end
