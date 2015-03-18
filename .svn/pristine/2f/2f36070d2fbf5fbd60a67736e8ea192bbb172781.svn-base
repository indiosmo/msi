#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/auction_imbalance.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
auction_imbalance::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
auction_imbalance::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
auction_imbalance::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, uint32_t>
auction_imbalance::update_action() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_update_action], update_action_ );
}

void
auction_imbalance::set_update_action( uint32_t val )
{
  update_action_ = val;
  presence_map_[ix_update_action] = true;
}

std::pair<bool, uint64_t>
auction_imbalance::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
auction_imbalance::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, int64_t>
auction_imbalance::entry_size() const
{
  return std::pair<bool, int64_t>( presence_map_[ix_entry_size], entry_size_ );
}

void
auction_imbalance::set_entry_size( int64_t val )
{
  entry_size_ = val;
  presence_map_[ix_entry_size] = true;
}

std::pair<bool, uint32_t>
auction_imbalance::entry_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_date], entry_date_ );
}

void
auction_imbalance::set_entry_date( uint32_t val )
{
  entry_date_ = val;
  presence_map_[ix_entry_date] = true;
}

std::pair<bool, uint32_t>
auction_imbalance::entry_time() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_entry_time], entry_time_ );
}

void
auction_imbalance::set_entry_time( uint32_t val )
{
  entry_time_ = val;
  presence_map_[ix_entry_time] = true;
}

bool
auction_imbalance::trade_condition_opening_price() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_opening_price] )
  {
    return true;
  }

  return false;
}

bool
auction_imbalance::trade_condition_crossed() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_crossed] )
  {
    return true;
  }

  return false;
}

bool
auction_imbalance::trade_condition_last_trade_at_price() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_last_trade_at_price] )
  {
    return true;
  }

  return false;
}

bool
auction_imbalance::trade_condition_imbalance_more_buyers() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_imbalance_more_buyers] )
  {
    return true;
  }

  return false;
}

bool
auction_imbalance::trade_condition_imbalance_more_sellers() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_imbalance_more_sellers] )
  {
    return true;
  }

  return false;
}

bool
auction_imbalance::trade_condition_exchange_last() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_exchange_last] )
  {
    return true;
  }

  return false;
}

bool
auction_imbalance::trade_condition_multi_asset_trade() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_multi_asset_trade] )
  {
    return true;
  }

  return false;
}

bool
auction_imbalance::trade_condition_leg_trade() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_leg_trade] )
  {
    return true;
  }

  return false;
}

bool
auction_imbalance::trade_condition_marketplace_entered_trade() const
{
  if ( presence_map_[ix_trade_condition] && trade_condition_[ix_trade_condition_marketplace_entered_trade] )
  {
    return true;
  }

  return false;
}

std::pair< bool, uint32_t>
auction_imbalance::trade_condition() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_trade_condition], trade_condition_.to_ulong() );
}

void
auction_imbalance::set_trade_condition( const std::bitset<trade_condition_field_count>& val )
{
  trade_condition_ = val;
  presence_map_[ix_trade_condition] = true;
}

void
auction_imbalance::set_trade_condition( const std::string& val )
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

const std::bitset<auction_imbalance::ix_field_count>&
auction_imbalance::presence_map() const
{
  return presence_map_;
}

void auction_imbalance::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

