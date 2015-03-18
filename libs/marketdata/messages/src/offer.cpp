#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/offer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
offer::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
offer::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
offer::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint32_t>
offer::update_action() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_update_action], update_action_ );
}

void
offer::set_update_action( uint32_t val )
{
  update_action_ = val;
  presence_map_[ix_update_action] = true;
}

std::pair<bool, uint64_t>
offer::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
offer::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, decimal>
offer::entry_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_entry_price], entry_price_ );
}

void
offer::set_entry_price( decimal val )
{
  entry_price_ = val;
  presence_map_[ix_entry_price] = true;
}

std::pair<bool, int64_t>
offer::entry_size() const
{
  return std::pair<bool, int64_t>( presence_map_[ix_entry_size], entry_size_ );
}

void
offer::set_entry_size( int64_t val )
{
  entry_size_ = val;
  presence_map_[ix_entry_size] = true;
}

std::pair<bool, uint32_t>
offer::entry_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_date], entry_date_ );
}

void
offer::set_entry_date( uint32_t val )
{
  entry_date_ = val;
  presence_map_[ix_entry_date] = true;
}

std::pair<bool, uint32_t>
offer::entry_time() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_time], entry_time_ );
}

void
offer::set_entry_time( uint32_t val )
{
  entry_time_ = val;
  presence_map_[ix_entry_time] = true;
}

std::pair<bool, const std::string&>
offer::seller() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_seller], seller_ );
}

void
offer::set_seller( const std::string& val )
{
  seller_ = val;
  presence_map_[ix_seller] = true;
}

std::pair<bool, uint32_t>
offer::position() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_position], position_ );
}

void
offer::set_position( uint32_t val )
{
  position_ = val;
  presence_map_[ix_position] = true;
}

std::pair<bool, const std::string&>
offer::order_id() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_order_id], order_id_ );
}

void
offer::set_order_id( const std::string& val )
{
  order_id_ = val;
  presence_map_[ix_order_id] = true;
}

const std::bitset<offer::ix_field_count>&
offer::presence_map() const
{
  return presence_map_;
}

void offer::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

