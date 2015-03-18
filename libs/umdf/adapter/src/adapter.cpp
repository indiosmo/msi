#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp>
#include <msi/umdf/adapter/adapter.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace adapter
{

const std::string adapter::stream_electronic = "E";
const std::string adapter::stream_all = "A";

const std::string adapter::type_bid = "0";
const std::string adapter::type_offer = "1";
const std::string adapter::type_trade = "2";
const std::string adapter::type_index = "3";
const std::string adapter::type_open = "4";
const std::string adapter::type_close = "5";
const std::string adapter::type_settlement = "6";
const std::string adapter::type_high = "7";
const std::string adapter::type_low = "8";
const std::string adapter::type_vwap = "9";
const std::string adapter::type_auction_imbalance = "A";
const std::string adapter::type_trade_volume = "B";
const std::string adapter::type_open_interest = "C";
const std::string adapter::type_empty_book = "J";
const std::string adapter::type_security_status = "c";
const std::string adapter::type_price_band = "g";
const std::string adapter::type_quantity_band = "h";


adapter::adapter( const std::string& template_path )
  : decoder_( template_path )
{
  decoder_.register_on_incremental_callback(
    std::bind( &adapter::on_incremental, this, std::placeholders::_1 ) );

  decoder_.register_on_security_status_callback(
    std::bind( &adapter::on_security_status, this, std::placeholders::_1 ) );

  incremental_convert_map_[type_bid] = std::bind( &adapter::convert_incremental_bid, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_offer] = std::bind( &adapter::convert_incremental_offer, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_trade] = std::bind( &adapter::convert_incremental_trade, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_index] = std::bind( &adapter::convert_incremental_index, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_open] = std::bind( &adapter::convert_incremental_open, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_close] = std::bind( &adapter::convert_incremental_close, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_settlement] = std::bind( &adapter::convert_incremental_settlement, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_high] = std::bind( &adapter::convert_incremental_high, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_low] = std::bind( &adapter::convert_incremental_low, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_vwap] = std::bind( &adapter::convert_incremental_vwap, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_auction_imbalance] = std::bind( &adapter::convert_incremental_auction_imbalance, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_trade_volume] = std::bind( &adapter::convert_incremental_trade_volume, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_open_interest] = std::bind( &adapter::convert_incremental_open_interest, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_empty_book] = std::bind( &adapter::convert_incremental_empty_book, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_price_band] = std::bind( &adapter::convert_incremental_price_band, this, ph::_1, ph::_2 );
  incremental_convert_map_[type_quantity_band] = std::bind( &adapter::convert_incremental_quantity_band, this, ph::_1, ph::_2 );
}

void adapter::decode( const unsigned char* data, std::size_t length )
{
  decoder_.decode( data, length );
}

void adapter::on_security_status( const messages::security_status& msg )
{
  security_status_.reset();

  security_status_.set_seqnum( msg.MsgSeqNum().second );

  if ( msg.SecurityID().first )
  {
    security_status_.set_security_id( msg.SecurityID().second );
  }

  if ( msg.SecurityGroup().first )
  {
    security_status_.set_security_group( msg.SecurityGroup().second );
  }

  if ( msg.TradingSessionSubID().first )
  {
    security_status_.set_group_phase( msg.TradingSessionSubID().second );
  }

  if ( msg.SecurityTradingStatus().first )
  {
    security_status_.set_instrument_state( msg.SecurityTradingStatus().second );
  }

  if ( msg.TradSesOpenTime().first )
  {
    security_status_.set_open_time( msg.TradSesOpenTime().second );
  }

  if ( msg.SecurityTradingEvent().first )
  {
    security_status_.set_trading_event( msg.SecurityTradingEvent().second );
  }

  if ( on_security_status_ )
  {
    on_security_status_( security_status_ );
  }
}

void adapter::on_incremental( const messages::incremental& msg )
{
  for ( auto entry : msg.MDEntries() )
  {
    auto stream_id = entry.MDStreamID();

    if ( !stream_id.first
         || stream_id.second == stream_electronic
         || stream_id.second == stream_all )
    {
      auto f = incremental_convert_map_.find( entry.MDEntryType().second );

      if ( f != incremental_convert_map_.end() )
      {
        f->second( msg.MsgSeqNum().second, entry );
      }
    }
  }
}

void adapter::convert_incremental_auction_imbalance( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  auction_imbalance_.reset();

  auction_imbalance_.set_seqnum( seqnum );
  auction_imbalance_.set_update_action( entry.MDUpdateAction().second );
  auction_imbalance_.set_security_id( entry.SecurityID().second );
  auction_imbalance_.set_entry_date( entry.MDEntryDate().second );
  auction_imbalance_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.TradeCondition().first )
  {
    auction_imbalance_.set_trade_condition( entry.TradeCondition().second );
  }

  if ( entry.MDEntrySize().first )
  {
    auction_imbalance_.set_entry_size( entry.MDEntrySize().second );
  }

  if ( on_auction_imbalance_ )
  {
    on_auction_imbalance_( auction_imbalance_ );
  }
}

void adapter::convert_incremental_bid( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  bid_.reset();

  bid_.set_seqnum( seqnum );
  bid_.set_update_action( entry.MDUpdateAction().second );
  bid_.set_security_id( entry.SecurityID().second );
  bid_.set_entry_date( entry.MDEntryDate().second );
  bid_.set_entry_time( entry.MDEntryTime().second );
  bid_.set_position( entry.MDEntryPositionNo().second );

  if ( entry.MDEntryPx().first )
  {
    bid_.set_entry_price( entry.MDEntryPx().second );
  }

  if ( entry.MDEntrySize().first )
  {
    bid_.set_entry_size( entry.MDEntrySize().second );
  }

  if ( entry.MDEntryBuyer().first )
  {
    bid_.set_buyer( entry.MDEntryBuyer().second );
  }

  if ( entry.OrderID().first )
  {
    bid_.set_order_id( entry.OrderID().second );
  }

  if ( on_bid_ )
  {
    on_bid_( bid_ );
  }
}

void adapter::convert_incremental_close( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  close_.reset();

  close_.set_seqnum( seqnum );
  close_.set_security_id( entry.SecurityID().second );
  close_.set_entry_date( entry.MDEntryDate().second );
  close_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.MDEntryPx().first )
  {
    close_.set_entry_price( entry.MDEntryPx().second );
  }

  if ( entry.LastTradeDate().first )
  {
    close_.set_last_trade_date( entry.LastTradeDate().second );
  }

  if ( entry.PriceAdjustmentMethod().first )
  {
    close_.set_price_adjust_method( entry.PriceAdjustmentMethod().second );
  }

  if ( entry.OpenCloseSettlFlag().first )
  {
    close_.set_settl_flag( std::to_string( entry.OpenCloseSettlFlag().second ) );
  }

  if ( on_close_ )
  {
    on_close_( close_ );
  }
}

void adapter::convert_incremental_high( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  high_.reset();

  high_.set_seqnum( seqnum );
  high_.set_update_action( entry.MDUpdateAction().second );
  high_.set_security_id( entry.SecurityID().second );
  high_.set_entry_date( entry.MDEntryDate().second );
  high_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.MDEntryPx().first )
  {
    high_.set_entry_price( entry.MDEntryPx().second );
  }

  if ( entry.MDEntrySize().first )
  {
    high_.set_entry_size( entry.MDEntrySize().second );
  }

  if ( on_high_ )
  {
    on_high_( high_ );
  }
}

void adapter::convert_incremental_index( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  index_.reset();

  index_.set_seqnum( seqnum );
  index_.set_update_action( entry.MDUpdateAction().second );
  index_.set_security_id( entry.SecurityID().second );
  index_.set_entry_date( entry.MDEntryDate().second );
  index_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.MDEntryPx().first )
  {
    index_.set_entry_price( entry.MDEntryPx().second );
  }

  if ( entry.TickDirection().first )
  {
    index_.set_tick_direction( std::stoul( entry.TickDirection().second ) );
  }

  if ( on_index_ )
  {
    on_index_( index_ );
  }
}

void adapter::convert_incremental_low( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  low_.reset();

  low_.set_seqnum( seqnum );
  low_.set_update_action( entry.MDUpdateAction().second );
  low_.set_security_id( entry.SecurityID().second );
  low_.set_entry_date( entry.MDEntryDate().second );
  low_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.MDEntryPx().first )
  {
    low_.set_entry_price( entry.MDEntryPx().second );
  }

  if ( entry.MDEntrySize().first )
  {
    low_.set_entry_size( entry.MDEntrySize().second );
  }

  if ( on_low_ )
  {
    on_low_( low_ );
  }
}

void adapter::convert_incremental_offer( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  offer_.reset();

  offer_.set_seqnum( seqnum );
  offer_.set_update_action( entry.MDUpdateAction().second );
  offer_.set_security_id( entry.SecurityID().second );
  offer_.set_entry_date( entry.MDEntryDate().second );
  offer_.set_entry_time( entry.MDEntryTime().second );
  offer_.set_position( entry.MDEntryPositionNo().second );

  if ( entry.MDEntryPx().first )
  {
    offer_.set_entry_price( entry.MDEntryPx().second );
  }

  if ( entry.MDEntrySize().first )
  {
    offer_.set_entry_size( entry.MDEntrySize().second );
  }

  if ( entry.MDEntrySeller().first )
  {
    offer_.set_seller( entry.MDEntrySeller().second );
  }

  if ( entry.OrderID().first )
  {
    offer_.set_order_id( entry.OrderID().second );
  }

  if ( on_offer_ )
  {
    on_offer_( offer_ );
  }
}

void adapter::convert_incremental_open( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  open_.reset();

  open_.set_seqnum( seqnum );
  open_.set_update_action( entry.MDUpdateAction().second );
  open_.set_security_id( entry.SecurityID().second );
  open_.set_entry_date( entry.MDEntryDate().second );
  open_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.MDEntryPx().first )
  {
    open_.set_entry_price( entry.MDEntryPx().second );
  }

  if ( entry.MDEntrySize().first )
  {
    open_.set_entry_size( entry.MDEntrySize().second );
  }

  if ( entry.OpenCloseSettlFlag().first )
  {
    open_.set_settl_flag( std::to_string( entry.OpenCloseSettlFlag().second ) );
  }

  if ( entry.NetChgPrevDay().first )
  {
    open_.set_variation( entry.NetChgPrevDay().second );
  }

  if ( on_open_ )
  {
    on_open_( open_ );
  }
}

void adapter::convert_incremental_open_interest( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  open_interest_.reset();

  open_interest_.set_seqnum( seqnum );
  open_interest_.set_security_id( entry.SecurityID().second );
  open_interest_.set_entry_date( entry.MDEntryDate().second );
  open_interest_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.MDEntryPx().first )
  {
    open_interest_.set_entry_price( entry.MDEntryPx().second );
  }

  if ( entry.MDEntrySize().first )
  {
    open_interest_.set_entry_size( entry.MDEntrySize().second );
  }

  if ( on_open_interest_ )
  {
    on_open_interest_( open_interest_ );
  }
}

void adapter::convert_incremental_empty_book( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  //TODO
}

void adapter::convert_incremental_price_band( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  price_band_.reset();

  price_band_.set_seqnum( seqnum );
  price_band_.set_security_id( entry.SecurityID().second );
  price_band_.set_entry_date( entry.MDEntryDate().second );
  price_band_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.PriceBandType().first )
  {
    price_band_.set_price_band_type( entry.PriceBandType().second );
  }

  if ( entry.PriceLimitType().first )
  {
    price_band_.set_price_limit_type( entry.PriceLimitType().second );
  }

  if ( entry.LowLimitPrice().first )
  {
    price_band_.set_low_limit_price( entry.LowLimitPrice().second );
  }

  if ( entry.HighLimitPrice().first )
  {
    price_band_.set_high_limit_price( entry.HighLimitPrice().second );
  }

  if ( entry.TradingReferencePrice().first )
  {
    price_band_.set_trading_reference_price( entry.TradingReferencePrice().second );
  }

  if ( entry.PriceBandMidpointPriceType().first )
  {
    price_band_.set_price_band_midpoint_price_type( entry.PriceBandMidpointPriceType().second );
  }

  if ( on_price_band_ )
  {
    on_price_band_( price_band_ );
  }
}

void adapter::convert_incremental_quantity_band( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  quantity_band_.reset();

  quantity_band_.set_seqnum( seqnum );
  quantity_band_.set_security_id( entry.SecurityID().second );
  quantity_band_.set_entry_date( entry.MDEntryDate().second );
  quantity_band_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.LowLimitPrice().first )
  {
    quantity_band_.set_low_limit_price( entry.LowLimitPrice().second );
  }

  if ( entry.HighLimitPrice().first )
  {
    quantity_band_.set_high_limit_price( entry.HighLimitPrice().second );
  }

  if ( entry.TradingReferencePrice().first )
  {
    quantity_band_.set_trading_reference_price( entry.TradingReferencePrice().second );
  }

  if ( entry.PriceBandMidpointPriceType().first )
  {
    quantity_band_.set_price_band_midpoint_price_type( entry.PriceBandMidpointPriceType().second );
  }

  if ( entry.AvgDailyTradedQty().first )
  {
    quantity_band_.set_avg_daily_traded_qty( entry.AvgDailyTradedQty().second );
  }

  if ( entry.MaxTradeVol().first )
  {
    quantity_band_.set_max_trade_vol( entry.MaxTradeVol().second );
  }

  if ( on_quantity_band_ )
  {
    on_quantity_band_( quantity_band_ );
  }
}

void adapter::convert_incremental_settlement( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  settlement_.reset();

  settlement_.set_seqnum( seqnum );
  settlement_.set_security_id( entry.SecurityID().second );
  settlement_.set_entry_date( entry.MDEntryDate().second );
  settlement_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.MDEntryPx().first )
  {
    settlement_.set_entry_price( entry.MDEntryPx().second );
  }

  if ( entry.PriceType().first )
  {
    settlement_.set_price_type( entry.PriceType().second );
  }

  if ( entry.OpenCloseSettlFlag().first )
  {
    settlement_.set_settl_flag( std::to_string( entry.OpenCloseSettlFlag().second ) );
  }

  if ( entry.SettPriceType().first )
  {
    settlement_.set_settl_price_type( std::to_string( entry.SettPriceType().second ) );
  }

  if ( on_settlement_ )
  {
    on_settlement_( settlement_ );
  }
}

void adapter::convert_incremental_trade( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  trade_.reset();

  trade_.set_seqnum( seqnum );
  trade_.set_update_action( entry.MDUpdateAction().second );
  trade_.set_security_id( entry.SecurityID().second );
  trade_.set_entry_date( entry.MDEntryDate().second );
  trade_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.MDEntryPx().first )
  {
    trade_.set_entry_price( entry.MDEntryPx().second );
  }

  if ( entry.MDEntrySize().first )
  {
    trade_.set_entry_size( entry.MDEntrySize().second );
  }

  if ( entry.TickDirection().first )
  {
    trade_.set_tick_direction( std::stoul( entry.TickDirection().second ) );
  }

  if ( entry.MDEntryBuyer().first )
  {
    trade_.set_buyer( entry.MDEntryBuyer().second );
  }

  if ( entry.MDEntrySeller().first )
  {
    trade_.set_seller( entry.MDEntrySeller().second );
  }

  if ( entry.NetChgPrevDay().first )
  {
    trade_.set_variation( entry.NetChgPrevDay().second );
  }

  if ( entry.TradeVolume().first )
  {
    trade_.set_quantity_volume( entry.TradeVolume().second );
  }

  if ( entry.TradeID().first )
  {
    trade_.set_trade_id( entry.TradeID().second );
  }

  if ( entry.TradeCondition().first )
  {
    trade_.set_trade_condition( entry.TradeCondition().second );
  }

  if ( on_trade_ )
  {
    on_trade_( trade_ );
  }
}

void adapter::convert_incremental_trade_volume( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  trade_volume_.reset();

  trade_volume_.set_seqnum( seqnum );
  trade_volume_.set_security_id( entry.SecurityID().second );
  trade_volume_.set_entry_date( entry.MDEntryDate().second );
  trade_volume_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.MDEntryPx().first )
  {
    trade_volume_.set_financial_volume( entry.MDEntryPx().second );
  }

  if ( entry.MDEntrySize().first )
  {
    trade_volume_.set_number_of_trades( entry.MDEntrySize().second );
  }

  if ( entry.TradeVolume().first )
  {
    trade_volume_.set_quantity_volume( entry.TradeVolume().second );
  }

  if ( entry.Currency().first )
  {
    trade_volume_.set_currency( entry.Currency().second );
  }

  if ( on_trade_volume_ )
  {
    on_trade_volume_( trade_volume_ );
  }
}

void adapter::convert_incremental_vwap( uint32_t seqnum, const messages::incremental::mdentries& entry )
{
  vwap_.reset();

  vwap_.set_seqnum( seqnum );
  vwap_.set_update_action( entry.MDUpdateAction().second );
  vwap_.set_security_id( entry.SecurityID().second );
  vwap_.set_entry_date( entry.MDEntryDate().second );
  vwap_.set_entry_time( entry.MDEntryTime().second );

  if ( entry.MDEntryPx().first )
  {
    vwap_.set_entry_price( entry.MDEntryPx().second );
  }

  if ( entry.MDEntrySize().first )
  {
    vwap_.set_entry_size( entry.MDEntrySize().second );
  }

  if ( on_vwap_ )
  {
    on_vwap_( vwap_ );
  }
}

} // end of namespace
} // end of namespace
} // end of namespace
} // end of namespace


