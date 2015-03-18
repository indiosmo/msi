#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/trade_volume.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
trade_volume::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
trade_volume::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
trade_volume::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint64_t>
trade_volume::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
trade_volume::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, decimal>
trade_volume::financial_volume() const
{
  return std::pair<bool, decimal>( presence_map_[ix_financial_volume], financial_volume_ );
}

void
trade_volume::set_financial_volume( decimal val )
{
  financial_volume_ = val;
  presence_map_[ix_financial_volume] = true;
}

std::pair<bool, uint32_t>
trade_volume::number_of_trades() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_number_of_trades], number_of_trades_ );
}

void
trade_volume::set_number_of_trades( uint32_t val )
{
  number_of_trades_ = val;
  presence_map_[ix_number_of_trades] = true;
}

std::pair<bool, uint64_t>
trade_volume::quantity_volume() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_quantity_volume], quantity_volume_ );
}

void
trade_volume::set_quantity_volume( uint64_t val )
{
  quantity_volume_ = val;
  presence_map_[ix_quantity_volume] = true;
}

std::pair<bool, uint32_t>
trade_volume::entry_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_date], entry_date_ );
}

void
trade_volume::set_entry_date( uint32_t val )
{
  entry_date_ = val;
  presence_map_[ix_entry_date] = true;
}

std::pair<bool, uint32_t>
trade_volume::entry_time() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_time], entry_time_ );
}

void
trade_volume::set_entry_time( uint32_t val )
{
  entry_time_ = val;
  presence_map_[ix_entry_time] = true;
}

std::pair<bool, const std::string&>
trade_volume::currency() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_currency], currency_ );
}

void
trade_volume::set_currency( const std::string& val )
{
  currency_ = val;
  presence_map_[ix_currency] = true;
}

const std::bitset<trade_volume::ix_field_count>&
trade_volume::presence_map() const
{
  return presence_map_;
}

void trade_volume::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

