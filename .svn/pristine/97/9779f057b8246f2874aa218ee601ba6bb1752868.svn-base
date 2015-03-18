#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/trade.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
trade::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
trade::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
trade::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint32_t>
trade::update_action() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_update_action], update_action_ );
}

void
trade::set_update_action( uint32_t val )
{
  update_action_ = val;
  presence_map_[ix_update_action] = true;
}

std::pair<bool, uint64_t>
trade::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
trade::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, decimal>
trade::entry_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_entry_price], entry_price_ );
}

void
trade::set_entry_price( decimal val )
{
  entry_price_ = val;
  presence_map_[ix_entry_price] = true;
}

std::pair<bool, int64_t>
trade::entry_size() const
{
  return std::pair<bool, int64_t>( presence_map_[ix_entry_size], entry_size_ );
}

void
trade::set_entry_size( int64_t val )
{
  entry_size_ = val;
  presence_map_[ix_entry_size] = true;
}

std::pair<bool, uint32_t>
trade::entry_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_date], entry_date_ );
}

void
trade::set_entry_date( uint32_t val )
{
  entry_date_ = val;
  presence_map_[ix_entry_date] = true;
}

std::pair<bool, uint32_t>
trade::entry_time() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_time], entry_time_ );
}

void
trade::set_entry_time( uint32_t val )
{
  entry_time_ = val;
  presence_map_[ix_entry_time] = true;
}

std::pair<bool, uint32_t>
trade::tick_direction() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_tick_direction], tick_direction_ );
}

void
trade::set_tick_direction( uint32_t val )
{
  tick_direction_ = val;
  presence_map_[ix_tick_direction] = true;
}

std::pair<bool, const std::string&>
trade::buyer() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_buyer], buyer_ );
}

void
trade::set_buyer( const std::string& val )
{
  buyer_ = val;
  presence_map_[ix_buyer] = true;
}

std::pair<bool, const std::string&>
trade::seller() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_seller], seller_ );
}

void
trade::set_seller( const std::string& val )
{
  seller_ = val;
  presence_map_[ix_seller] = true;
}

std::pair<bool, decimal>
trade::variation() const
{
  return std::pair<bool, decimal>( presence_map_[ix_variation], variation_ );
}

void
trade::set_variation( decimal val )
{
  variation_ = val;
  presence_map_[ix_variation] = true;
}

std::pair<bool, uint64_t>
trade::quantity_volume() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_quantity_volume], quantity_volume_ );
}

void
trade::set_quantity_volume( uint64_t val )
{
  quantity_volume_ = val;
  presence_map_[ix_quantity_volume] = true;
}

std::pair<bool, const std::string&>
trade::trade_id() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_trade_id], trade_id_ );
}

void
trade::set_trade_id( const std::string& val )
{
  trade_id_ = val;
  presence_map_[ix_trade_id] = true;
}

bool
trade::trade_condition_opening_price() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_opening_price] )
  {
    return true;
  }

  return false;
}

bool
trade::trade_condition_crossed() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_crossed] )
  {
    return true;
  }

  return false;
}

bool
trade::trade_condition_last_trade_at_price() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_last_trade_at_price] )
  {
    return true;
  }

  return false;
}

bool
trade::trade_condition_imbalance_more_buyers() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_imbalance_more_buyers] )
  {
    return true;
  }

  return false;
}

bool
trade::trade_condition_imbalance_more_sellers() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_imbalance_more_sellers] )
  {
    return true;
  }

  return false;
}

bool
trade::trade_condition_exchange_last() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_exchange_last] )
  {
    return true;
  }

  return false;
}

bool
trade::trade_condition_multi_asset_trade() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_multi_asset_trade] )
  {
    return true;
  }

  return false;
}

bool
trade::trade_condition_leg_trade() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_leg_trade] )
  {
    return true;
  }

  return false;
}

bool
trade::trade_condition_marketplace_entered_trade() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_marketplace_entered_trade] )
  {
    return true;
  }

  return false;
}

std::pair< bool, uint32_t>
trade::trade_condition() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_trade_condition], trade_condition_.to_ulong() );
}

void
trade::set_trade_condition( const std::bitset<trade_condition_field_count>& val )
{
  trade_condition_ = val;
  presence_map_[ix_trade_condition] = true;
}

void
trade::set_trade_condition( const std::string& val )
{
  boost::char_separator<char> separator( " " );
  boost::tokenizer<boost::char_separator<char>> tokenizer( val, separator );

  if ( tokenizer.begin() != tokenizer.end() )
  {
    presence_map_[ix_trade_condition] = true;

    for ( auto field : tokenizer )
    {
      auto index = trade_condition_value_index_map.find( field.c_str() );

      if ( index != trade_condition_value_index_map.end() )
      {
        trade_condition_.set( index->second );
      }
    }
  }
}

const std::bitset<trade::ix_field_count>&
trade::presence_map() const
{
  return presence_map_;
}

void trade::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

