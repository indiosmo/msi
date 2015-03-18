#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/bid.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
bid::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
bid::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
bid::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint32_t>
bid::update_action() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_update_action], update_action_ );
}

void
bid::set_update_action( uint32_t val )
{
  update_action_ = val;
  presence_map_[ix_update_action] = true;
}

std::pair<bool, uint64_t>
bid::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
bid::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, decimal>
bid::entry_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_entry_price], entry_price_ );
}

void
bid::set_entry_price( decimal val )
{
  entry_price_ = val;
  presence_map_[ix_entry_price] = true;
}

std::pair<bool, int64_t>
bid::entry_size() const
{
  return std::pair<bool, int64_t>( presence_map_[ix_entry_size], entry_size_ );
}

void
bid::set_entry_size( int64_t val )
{
  entry_size_ = val;
  presence_map_[ix_entry_size] = true;
}

std::pair<bool, uint32_t>
bid::entry_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_date], entry_date_ );
}

void
bid::set_entry_date( uint32_t val )
{
  entry_date_ = val;
  presence_map_[ix_entry_date] = true;
}

std::pair<bool, uint32_t>
bid::entry_time() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_time], entry_time_ );
}

void
bid::set_entry_time( uint32_t val )
{
  entry_time_ = val;
  presence_map_[ix_entry_time] = true;
}

std::pair<bool, const std::string&>
bid::buyer() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_buyer], buyer_ );
}

void
bid::set_buyer( const std::string& val )
{
  buyer_ = val;
  presence_map_[ix_buyer] = true;
}

std::pair<bool, uint32_t>
bid::position() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_position], position_ );
}

void
bid::set_position( uint32_t val )
{
  position_ = val;
  presence_map_[ix_position] = true;
}

std::pair<bool, const std::string&>
bid::order_id() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_order_id], order_id_ );
}

void
bid::set_order_id( const std::string& val )
{
  order_id_ = val;
  presence_map_[ix_order_id] = true;
}

const std::bitset<bid::ix_field_count>&
bid::presence_map() const
{
  return presence_map_;
}

void bid::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

