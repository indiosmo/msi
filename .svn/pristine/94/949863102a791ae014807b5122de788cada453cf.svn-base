#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/security_status.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
security_status::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
security_status::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
security_status::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint64_t>
security_status::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
security_status::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, const std::string&>
security_status::security_group() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_security_group], security_group_ );
}

void
security_status::set_security_group( const std::string& val )
{
  security_group_ = val;
  presence_map_[ix_security_group] = true;
}

std::pair<bool, const std::string&>
security_status::group_phase() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_group_phase], group_phase_ );
}

void
security_status::set_group_phase( const std::string& val )
{
  group_phase_ = val;
  presence_map_[ix_group_phase] = true;
}

std::pair<bool, uint32_t>
security_status::instrument_state() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_instrument_state], instrument_state_ );
}

void
security_status::set_instrument_state( uint32_t val )
{
  instrument_state_ = val;
  presence_map_[ix_instrument_state] = true;
}

std::pair<bool, uint64_t>
security_status::open_time() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_open_time], open_time_ );
}

void
security_status::set_open_time( uint64_t val )
{
  open_time_ = val;
  presence_map_[ix_open_time] = true;
}

std::pair<bool, uint32_t>
security_status::trading_event() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_trading_event], trading_event_ );
}

void
security_status::set_trading_event( uint32_t val )
{
  trading_event_ = val;
  presence_map_[ix_trading_event] = true;
}

const std::bitset<security_status::ix_field_count>&
security_status::presence_map() const
{
  return presence_map_;
}

void security_status::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

