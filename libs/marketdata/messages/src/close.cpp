#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/close.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
close::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
close::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
close::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint64_t>
close::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
close::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, decimal>
close::entry_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_entry_price], entry_price_ );
}

void
close::set_entry_price( decimal val )
{
  entry_price_ = val;
  presence_map_[ix_entry_price] = true;
}

std::pair<bool, uint32_t>
close::last_trade_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_last_trade_date], last_trade_date_ );
}

void
close::set_last_trade_date( uint32_t val )
{
  last_trade_date_ = val;
  presence_map_[ix_last_trade_date] = true;
}

std::pair<bool, uint32_t>
close::price_adjust_method() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_price_adjust_method], price_adjust_method_ );
}

void
close::set_price_adjust_method( uint32_t val )
{
  price_adjust_method_ = val;
  presence_map_[ix_price_adjust_method] = true;
}

std::pair<bool, uint32_t>
close::entry_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_date], entry_date_ );
}

void
close::set_entry_date( uint32_t val )
{
  entry_date_ = val;
  presence_map_[ix_entry_date] = true;
}

std::pair<bool, uint32_t>
close::entry_time() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_time], entry_time_ );
}

void
close::set_entry_time( uint32_t val )
{
  entry_time_ = val;
  presence_map_[ix_entry_time] = true;
}

std::pair<bool, const std::string&>
close::settl_flag() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_settl_flag], settl_flag_ );
}

void
close::set_settl_flag( const std::string& val )
{
  settl_flag_ = val;
  presence_map_[ix_settl_flag] = true;
}

const std::bitset<close::ix_field_count>&
close::presence_map() const
{
  return presence_map_;
}

void close::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

