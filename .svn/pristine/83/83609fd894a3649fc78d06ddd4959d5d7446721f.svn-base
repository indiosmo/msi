@echo off

set messages=heartbeat,incremental,news,security_list,security_status,sequence_reset,snapshot
set template=%MSI_ROOT%/libs/umdf/messages/xml

for %%a in ("%messages:,=" "%") do (
  xsltproc --stringparam message_name %%a header.xslt %template%/%%a.xml > %%a.hpp
  xsltproc --stringparam message_name %%a source.xslt %template%/%%a.xml > %%a.cpp
)
@goto end

:end
