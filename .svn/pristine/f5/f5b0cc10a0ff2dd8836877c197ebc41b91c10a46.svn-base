@echo off
set TEMPLATE=%1

if "%1" == "" goto usage

xsltproc field_id_xml.xslt %TEMPLATE% > field_id.xml
xsltproc field_id_hpp.xslt field_id.xml > field_id.hpp
xsltproc field_id_cpp.xslt field_id.xml > field_id.cpp
del field_id.xml
@goto end

:usage
@echo "generate_field_ids.bat <template file>"
@goto end

:end

