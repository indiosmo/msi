#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/index.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
index::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
index::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
index::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint32_t>
index::update_action() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_update_action], update_action_ );
}

void
index::set_update_action( uint32_t val )
{
  update_action_ = val;
  presence_map_[ix_update_action] = true;
}

std::pair<bool, uint64_t>
index::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
index::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, decimal>
index::entry_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_entry_price], entry_price_ );
}

void
index::set_entry_price( decimal val )
{
  entry_price_ = val;
  presence_map_[ix_entry_price] = true;
}

std::pair<bool, uint32_t>
index::entry_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_date], entry_date_ );
}

void
index::set_entry_date( uint32_t val )
{
  entry_date_ = val;
  presence_map_[ix_entry_date] = true;
}

std::pair<bool, uint32_t>
index::entry_time() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_time], entry_time_ );
}

void
index::set_entry_time( uint32_t val )
{
  entry_time_ = val;
  presence_map_[ix_entry_time] = true;
}

std::pair<bool, uint32_t>
index::tick_direction() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_tick_direction], tick_direction_ );
}

void
index::set_tick_direction( uint32_t val )
{
  tick_direction_ = val;
  presence_map_[ix_tick_direction] = true;
}

const std::bitset<index::ix_field_count>&
index::presence_map() const
{
  return presence_map_;
}

void index::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

