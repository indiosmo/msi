@echo off
set template=%1

if "%1" == "" goto usage

set messages=auction_imbalance,bid,close,high,index,low,offer,open,open_interest,price_band,quantity_band,security_definition,security_status,settlement,trade,trade_volume,vwap,snapshot

for %%a in ("%messages:,=" "%") do (
  xsltproc --stringparam message_name %%a header.xslt %template% > %%a_serializer.hpp
  xsltproc --stringparam message_name %%a source.xslt %template% > %%a_serializer.cpp
)

@goto end

:usage
@echo "generate_serializers.bat <template file>"
@goto end

:end
