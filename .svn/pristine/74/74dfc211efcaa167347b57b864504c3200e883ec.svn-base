@echo off

set messages=heartbeat,incremental,news,security_list,security_status,sequence_reset,snapshot
set template=%MSI_ROOT%/libs/umdf/messages/xml

for %%a in ("%messages:,=" "%") do (
  xsltproc --stringparam message_name %%a builder_test.xslt %template%/%%a_templates.xml > %%a_builder_test.cpp
)
@goto end

:end
