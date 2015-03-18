#include <msi/msi_pch.hpp>
#include <msi/umdf/ticker_plant/ticker_plant.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace ticker_plant
{

namespace ph = std::placeholders;
namespace mm = marketdata::messages;
namespace ms = marketdata::serialization;

ticker_plant::ticker_plant( boost::asio::io_service& io_service,
                            const std::string& address,
                            const std::string& port,
                            marketdata::receiver_ptr receiver,
                            marketdata::decoder_ptr decoder )
  : receiver_( receiver )
  , decoder_( decoder )
  , tcp_server_( io_service, address, port )
{
  init();
}

void
ticker_plant::run()
{
  receiver_->run();
  tcp_server_.run();
}

void
ticker_plant::stop()
{
  receiver_->stop();
  tcp_server_.stop();
}

void
ticker_plant::init()
{
  receiver_->register_on_receive_callback( std::bind(
        &marketdata::decoder::decode, decoder_, ph::_1,
        ph::_2 ) );

  tcp_server_.register_on_connection_callback( std::bind(
        &ticker_plant::handle_connection, this, ph::_1 ) );

  decoder_->register_on_auction_imbalance_callback(
    std::bind( &ticker_plant::handle_message<mm::auction_imbalance, ms::auction_imbalance_serializer>,
               this, ph::_1, mm::message_auction_imbalance, auction_imbalance_serializer_ ) );

  decoder_->register_on_bid_callback(
    std::bind( &ticker_plant::handle_message<mm::bid, ms::bid_serializer>,
               this, ph::_1, mm::message_bid, bid_serializer_ ) );

  decoder_->register_on_close_callback(
    std::bind( &ticker_plant::handle_message<mm::close, ms::close_serializer>,
               this, ph::_1, mm::message_close, close_serializer_ ) );

  decoder_->register_on_high_callback(
    std::bind( &ticker_plant::handle_message<mm::high, ms::high_serializer>,
               this, ph::_1, mm::message_high, high_serializer_ ) );

  decoder_->register_on_index_callback(
    std::bind( &ticker_plant::handle_message<mm::index, ms::index_serializer>,
               this, ph::_1, mm::message_index, index_serializer_ ) );

  decoder_->register_on_low_callback(
    std::bind( &ticker_plant::handle_message<mm::low, ms::low_serializer>,
               this, ph::_1, mm::message_low, low_serializer_ ) );

  decoder_->register_on_offer_callback(
    std::bind( &ticker_plant::handle_message<mm::offer, ms::offer_serializer>,
               this, ph::_1, mm::message_offer, offer_serializer_ ) );

  decoder_->register_on_open_callback(
    std::bind( &ticker_plant::handle_message<mm::open, ms::open_serializer>,
               this, ph::_1, mm::message_open, open_serializer_ ) );

  decoder_->register_on_open_interest_callback(
    std::bind( &ticker_plant::handle_message<mm::open_interest, ms::open_interest_serializer>,
               this, ph::_1, mm::message_open_interest, open_interest_serializer_ ) );

  decoder_->register_on_price_band_callback(
    std::bind( &ticker_plant::handle_message<mm::price_band, ms::price_band_serializer>,
               this, ph::_1, mm::message_price_band, price_band_serializer_ ) );

  decoder_->register_on_quantity_band_callback(
    std::bind( &ticker_plant::handle_message<mm::quantity_band, ms::quantity_band_serializer>,
               this, ph::_1, mm::message_quantity_band, quantity_band_serializer_ ) );

  decoder_->register_on_security_definition_callback(
    std::bind( &ticker_plant::handle_message<mm::security_definition, ms::security_definition_serializer>,
               this, ph::_1, mm::message_security_definition, security_definition_serializer_ ) );

  decoder_->register_on_security_status_callback(
    std::bind( &ticker_plant::handle_message<mm::security_status, ms::security_status_serializer>,
               this, ph::_1, mm::message_security_status, security_status_serializer_ ) );

  decoder_->register_on_settlement_callback(
    std::bind( &ticker_plant::handle_message<mm::settlement, ms::settlement_serializer>,
               this, ph::_1, mm::message_settlement, settlement_serializer_ ) );

  decoder_->register_on_trade_callback(
    std::bind( &ticker_plant::handle_message<mm::trade, ms::trade_serializer>,
               this, ph::_1, mm::message_trade, trade_serializer_ ) );

  decoder_->register_on_trade_volume_callback(
    std::bind( &ticker_plant::handle_message<mm::trade_volume, ms::trade_volume_serializer>,
               this, ph::_1, mm::message_trade_volume, trade_volume_serializer_ ) );

  decoder_->register_on_vwap_callback(
    std::bind( &ticker_plant::handle_message<mm::vwap, ms::vwap_serializer>,
               this, ph::_1, mm::message_vwap, vwap_serializer_ ) );
}

void ticker_plant::handle_connection( network::tcp::connection_ptr connection )
{
  subscribers_.insert( connection );

  connection->register_on_disconnect_callback(
    std::bind( &ticker_plant::handle_disconnection, this, connection ) );
}

void ticker_plant::handle_disconnection( network::tcp::connection_ptr connection )
{
  subscribers_.erase( connection );
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

