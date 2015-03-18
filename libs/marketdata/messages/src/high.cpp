#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/high.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
high::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
high::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
high::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint32_t>
high::update_action() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_update_action], update_action_ );
}

void
high::set_update_action( uint32_t val )
{
  update_action_ = val;
  presence_map_[ix_update_action] = true;
}

std::pair<bool, uint64_t>
high::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
high::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, decimal>
high::entry_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_entry_price], entry_price_ );
}

void
high::set_entry_price( decimal val )
{
  entry_price_ = val;
  presence_map_[ix_entry_price] = true;
}

std::pair<bool, int64_t>
high::entry_size() const
{
  return std::pair<bool, int64_t>( presence_map_[ix_entry_size], entry_size_ );
}

void
high::set_entry_size( int64_t val )
{
  entry_size_ = val;
  presence_map_[ix_entry_size] = true;
}

std::pair<bool, uint32_t>
high::entry_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_date], entry_date_ );
}

void
high::set_entry_date( uint32_t val )
{
  entry_date_ = val;
  presence_map_[ix_entry_date] = true;
}

std::pair<bool, uint32_t>
high::entry_time() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_time], entry_time_ );
}

void
high::set_entry_time( uint32_t val )
{
  entry_time_ = val;
  presence_map_[ix_entry_time] = true;
}

const std::bitset<high::ix_field_count>&
high::presence_map() const
{
  return presence_map_;
}

void high::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

