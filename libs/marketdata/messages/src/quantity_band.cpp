#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/quantity_band.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
quantity_band::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
quantity_band::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
quantity_band::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint64_t>
quantity_band::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
quantity_band::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, decimal>
quantity_band::low_limit_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_low_limit_price], low_limit_price_ );
}

void
quantity_band::set_low_limit_price( decimal val )
{
  low_limit_price_ = val;
  presence_map_[ix_low_limit_price] = true;
}

std::pair<bool, decimal>
quantity_band::high_limit_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_high_limit_price], high_limit_price_ );
}

void
quantity_band::set_high_limit_price( decimal val )
{
  high_limit_price_ = val;
  presence_map_[ix_high_limit_price] = true;
}

std::pair<bool, decimal>
quantity_band::trading_reference_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_trading_reference_price], trading_reference_price_ );
}

void
quantity_band::set_trading_reference_price( decimal val )
{
  trading_reference_price_ = val;
  presence_map_[ix_trading_reference_price] = true;
}

std::pair<bool, uint32_t>
quantity_band::price_band_midpoint_price_type() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_price_band_midpoint_price_type], price_band_midpoint_price_type_ );
}

void
quantity_band::set_price_band_midpoint_price_type( uint32_t val )
{
  price_band_midpoint_price_type_ = val;
  presence_map_[ix_price_band_midpoint_price_type] = true;
}

std::pair<bool, uint64_t>
quantity_band::avg_daily_traded_qty() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_avg_daily_traded_qty], avg_daily_traded_qty_ );
}

void
quantity_band::set_avg_daily_traded_qty( uint64_t val )
{
  avg_daily_traded_qty_ = val;
  presence_map_[ix_avg_daily_traded_qty] = true;
}

std::pair<bool, uint64_t>
quantity_band::max_trade_vol() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_max_trade_vol], max_trade_vol_ );
}

void
quantity_band::set_max_trade_vol( uint64_t val )
{
  max_trade_vol_ = val;
  presence_map_[ix_max_trade_vol] = true;
}

std::pair<bool, uint32_t>
quantity_band::entry_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_date], entry_date_ );
}

void
quantity_band::set_entry_date( uint32_t val )
{
  entry_date_ = val;
  presence_map_[ix_entry_date] = true;
}

std::pair<bool, uint32_t>
quantity_band::entry_time() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_time], entry_time_ );
}

void
quantity_band::set_entry_time( uint32_t val )
{
  entry_time_ = val;
  presence_map_[ix_entry_time] = true;
}

const std::bitset<quantity_band::ix_field_count>&
quantity_band::presence_map() const
{
  return presence_map_;
}

void quantity_band::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

