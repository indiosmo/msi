#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/snapshot.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
snapshot::reset()
{
  presence_map_.reset();
}

std::pair<bool, const auction_imbalance&>
snapshot::auction_imbalance() const
{
  return std::pair<bool, const messages::auction_imbalance&>( presence_map_[ix_auction_imbalance], auction_imbalance_ );
}

void
snapshot::set_auction_imbalance( const messages::auction_imbalance& val )
{
  auction_imbalance_ = val;
  presence_map_[ix_auction_imbalance] = true;
}

const std::vector<bid>&
snapshot::bids() const
{
  return bids_;
}

void
snapshot::add_bid( const bid& val )
{
  bids_.push_back( val );
  presence_map_[ix_bid] = true;
}

std::pair<bool, const close&>
snapshot::close() const
{
  return std::pair<bool, const messages::close&>( presence_map_[ix_close], close_ );
}

void
snapshot::set_close( const messages::close& val )
{
  close_ = val;
  presence_map_[ix_close] = true;
}

std::pair<bool, const high&>
snapshot::high() const
{
  return std::pair<bool, const messages::high&>( presence_map_[ix_high], high_ );
}

void
snapshot::set_high( const messages::high& val )
{
  high_ = val;
  presence_map_[ix_high] = true;
}

std::pair<bool, const index&>
snapshot::index() const
{
  return std::pair<bool, const messages::index&>( presence_map_[ix_index], index_ );
}

void
snapshot::set_index( const messages::index& val )
{
  index_ = val;
  presence_map_[ix_index] = true;
}

std::pair<bool, const low&>
snapshot::low() const
{
  return std::pair<bool, const messages::low&>( presence_map_[ix_low], low_ );
}

void
snapshot::set_low( const messages::low& val )
{
  low_ = val;
  presence_map_[ix_low] = true;
}

const std::vector<offer>&
snapshot::offers() const
{
  return offers_;
}

void
snapshot::add_offer( const offer& val )
{
  offers_.push_back( val );
  presence_map_[ix_offer] = true;
}

std::pair<bool, const open&>
snapshot::open() const
{
  return std::pair<bool, const messages::open&>( presence_map_[ix_open], open_ );
}

void
snapshot::set_open( const messages::open& val )
{
  open_ = val;
  presence_map_[ix_open] = true;
}

std::pair<bool, const open_interest&>
snapshot::open_interest() const
{
  return std::pair<bool, const messages::open_interest&>( presence_map_[ix_open_interest], open_interest_ );
}

void
snapshot::set_open_interest( const messages::open_interest& val )
{
  open_interest_ = val;
  presence_map_[ix_open_interest] = true;
}

std::pair<bool, const price_band&>
snapshot::price_band() const
{
  return std::pair<bool, const messages::price_band&>( presence_map_[ix_price_band], price_band_ );
}

void
snapshot::set_price_band( const messages::price_band& val )
{
  price_band_ = val;
  presence_map_[ix_price_band] = true;
}

std::pair<bool, const quantity_band&>
snapshot::quantity_band() const
{
  return std::pair<bool, const messages::quantity_band&>( presence_map_[ix_quantity_band], quantity_band_ );
}

void
snapshot::set_quantity_band( const messages::quantity_band& val )
{
  quantity_band_ = val;
  presence_map_[ix_quantity_band] = true;
}

std::pair<bool, const security_status&>
snapshot::security_status() const
{
  return std::pair<bool, const messages::security_status&>( presence_map_[ix_security_status], security_status_ );
}

void
snapshot::set_security_status( const messages::security_status& val )
{
  security_status_ = val;
  presence_map_[ix_security_status] = true;
}

std::pair<bool, const settlement&>
snapshot::settlement() const
{
  return std::pair<bool, const messages::settlement&>( presence_map_[ix_settlement], settlement_ );
}

void
snapshot::set_settlement( const messages::settlement& val )
{
  settlement_ = val;
  presence_map_[ix_settlement] = true;
}

std::pair<bool, const trade&>
snapshot::trade() const
{
  return std::pair<bool, const messages::trade&>( presence_map_[ix_trade], trade_ );
}

void
snapshot::set_trade( const messages::trade& val )
{
  trade_ = val;
  presence_map_[ix_trade] = true;
}

std::pair<bool, const trade_volume&>
snapshot::trade_volume() const
{
  return std::pair<bool, const messages::trade_volume&>( presence_map_[ix_trade_volume], trade_volume_ );
}

void
snapshot::set_trade_volume( const messages::trade_volume& val )
{
  trade_volume_ = val;
  presence_map_[ix_trade_volume] = true;
}

std::pair<bool, const vwap&>
snapshot::vwap() const
{
  return std::pair<bool, const messages::vwap&>( presence_map_[ix_vwap], vwap_ );
}

void
snapshot::set_vwap( const messages::vwap& val )
{
  vwap_ = val;
  presence_map_[ix_vwap] = true;
}

const std::bitset<snapshot::ix_field_count>&
snapshot::presence_map() const
{
  return presence_map_;
}

void snapshot::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

