#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/settlement.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
settlement::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
settlement::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
settlement::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint64_t>
settlement::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
settlement::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, decimal>
settlement::entry_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_entry_price], entry_price_ );
}

void
settlement::set_entry_price( decimal val )
{
  entry_price_ = val;
  presence_map_[ix_entry_price] = true;
}

std::pair<bool, const std::string&>
settlement::price_type() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_price_type], price_type_ );
}

void
settlement::set_price_type( const std::string& val )
{
  price_type_ = val;
  presence_map_[ix_price_type] = true;
}

std::pair<bool, uint32_t>
settlement::entry_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_date], entry_date_ );
}

void
settlement::set_entry_date( uint32_t val )
{
  entry_date_ = val;
  presence_map_[ix_entry_date] = true;
}

std::pair<bool, uint32_t>
settlement::entry_time() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_time], entry_time_ );
}

void
settlement::set_entry_time( uint32_t val )
{
  entry_time_ = val;
  presence_map_[ix_entry_time] = true;
}

std::pair<bool, const std::string&>
settlement::settl_flag() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_settl_flag], settl_flag_ );
}

void
settlement::set_settl_flag( const std::string& val )
{
  settl_flag_ = val;
  presence_map_[ix_settl_flag] = true;
}

std::pair<bool, const std::string&>
settlement::settl_price_type() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_settl_price_type], settl_price_type_ );
}

void
settlement::set_settl_price_type( const std::string& val )
{
  settl_price_type_ = val;
  presence_map_[ix_settl_price_type] = true;
}

const std::bitset<settlement::ix_field_count>&
settlement::presence_map() const
{
  return presence_map_;
}

void settlement::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

