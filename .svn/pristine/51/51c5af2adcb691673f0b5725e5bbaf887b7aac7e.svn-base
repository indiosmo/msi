#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/open_interest.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
open_interest::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
open_interest::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
open_interest::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint64_t>
open_interest::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
open_interest::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, decimal>
open_interest::entry_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_entry_price], entry_price_ );
}

void
open_interest::set_entry_price( decimal val )
{
  entry_price_ = val;
  presence_map_[ix_entry_price] = true;
}

std::pair<bool, int64_t>
open_interest::entry_size() const
{
  return std::pair<bool, int64_t>( presence_map_[ix_entry_size], entry_size_ );
}

void
open_interest::set_entry_size( int64_t val )
{
  entry_size_ = val;
  presence_map_[ix_entry_size] = true;
}

std::pair<bool, uint32_t>
open_interest::entry_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_date], entry_date_ );
}

void
open_interest::set_entry_date( uint32_t val )
{
  entry_date_ = val;
  presence_map_[ix_entry_date] = true;
}

std::pair<bool, uint32_t>
open_interest::entry_time() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_time], entry_time_ );
}

void
open_interest::set_entry_time( uint32_t val )
{
  entry_time_ = val;
  presence_map_[ix_entry_time] = true;
}

const std::bitset<open_interest::ix_field_count>&
open_interest::presence_map() const
{
  return presence_map_;
}

void open_interest::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

