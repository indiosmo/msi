#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/price_band.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
price_band::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
price_band::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
price_band::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint64_t>
price_band::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
price_band::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, const std::string&>
price_band::price_band_type() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_price_band_type], price_band_type_ );
}

void
price_band::set_price_band_type( const std::string& val )
{
  price_band_type_ = val;
  presence_map_[ix_price_band_type] = true;
}

std::pair<bool, uint32_t>
price_band::price_limit_type() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_price_limit_type], price_limit_type_ );
}

void
price_band::set_price_limit_type( uint32_t val )
{
  price_limit_type_ = val;
  presence_map_[ix_price_limit_type] = true;
}

std::pair<bool, decimal>
price_band::low_limit_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_low_limit_price], low_limit_price_ );
}

void
price_band::set_low_limit_price( decimal val )
{
  low_limit_price_ = val;
  presence_map_[ix_low_limit_price] = true;
}

std::pair<bool, decimal>
price_band::high_limit_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_high_limit_price], high_limit_price_ );
}

void
price_band::set_high_limit_price( decimal val )
{
  high_limit_price_ = val;
  presence_map_[ix_high_limit_price] = true;
}

std::pair<bool, decimal>
price_band::trading_reference_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_trading_reference_price], trading_reference_price_ );
}

void
price_band::set_trading_reference_price( decimal val )
{
  trading_reference_price_ = val;
  presence_map_[ix_trading_reference_price] = true;
}

std::pair<bool, uint32_t>
price_band::price_band_midpoint_price_type() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_price_band_midpoint_price_type], price_band_midpoint_price_type_ );
}

void
price_band::set_price_band_midpoint_price_type( uint32_t val )
{
  price_band_midpoint_price_type_ = val;
  presence_map_[ix_price_band_midpoint_price_type] = true;
}

std::pair<bool, uint32_t>
price_band::entry_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_date], entry_date_ );
}

void
price_band::set_entry_date( uint32_t val )
{
  entry_date_ = val;
  presence_map_[ix_entry_date] = true;
}

std::pair<bool, uint32_t>
price_band::entry_time() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_time], entry_time_ );
}

void
price_band::set_entry_time( uint32_t val )
{
  entry_time_ = val;
  presence_map_[ix_entry_time] = true;
}

const std::bitset<price_band::ix_field_count>&
price_band::presence_map() const
{
  return presence_map_;
}

void price_band::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

