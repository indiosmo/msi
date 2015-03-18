@echo off
set TEMPLATE=%1

if "%1" == "" goto usage

set messages=auction_imbalance,bid,close,high,index,low,offer,open,open_interest,price_band,quantity_band,security_definition,security_status,settlement,trade,trade_volume,vwap,snapshot

for %%a in ("%messages:,=" "%") do (
  xsltproc --stringparam message_name %%a header.xslt %TEMPLATE% > %%a.hpp
  xsltproc --stringparam message_name %%a source.xslt %TEMPLATE% > %%a.cpp
)

@goto end

:usage
@echo "generate_messages.bat <template file>"
@goto end

:end
