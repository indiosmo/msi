@echo off
set TEMPLATE=%1

if "%1" == "" goto usage

xsltproc field_values.xslt %TEMPLATE% > field_values.hpp

@goto end

:usage
@echo "generate_field_values.bat <template file>"
@goto end

:end
