@echo off
set messages=heartbeat,incremental,news,security_list,security_status,sequence_reset,snapshot
set template=%MSI_ROOT%/libs/umdf/messages/xml

for %%a in ("%messages:,=" "%") do (
  xsltproc --stringparam message_name %%a builder_hpp.xslt %template%/%%a.xml > %%a_builder.hpp
  xsltproc --stringparam message_name %%a builder_cpp.xslt %template%/%%a.xml > %%a_builder.cpp
)
@goto end

:end
