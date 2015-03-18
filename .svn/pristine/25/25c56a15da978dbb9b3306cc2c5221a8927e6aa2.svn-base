#ifndef APOENA_MSI_UMDF_TICKER_PLANT_TICKER_PLANT_HPP
#define APOENA_MSI_UMDF_TICKER_PLANT_TICKER_PLANT_HPP

#include <functional>
#include <memory>
#include <unordered_set>
#include <boost/asio.hpp>
#include <msi/services.hpp>
#include <msi/marketdata/common/receiver.hpp>
#include <msi/marketdata/common/decoder.hpp>
#include <msi/marketdata/messages/message_types.hpp>
#include <msi/marketdata/serialization/serializers.hpp>
#include <msi/network/tcp/server.hpp>
#include <msi/umdf/ticker_plant/umdf_ticker_plant_export.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace ticker_plant
{

class UMDF_TICKER_PLANT_Export ticker_plant
{
public:
  ticker_plant( boost::asio::io_service& io_service,
                const std::string& address,
                const std::string& port,
                marketdata::receiver_ptr receiver,
                marketdata::decoder_ptr decoder );

  void run();

  void stop();

private:
  void init();

  void handle_disconnection( network::tcp::connection_ptr connection );
  void handle_connection( network::tcp::connection_ptr connection );

  template<typename MESSAGE_T, typename SERIALIZER_T>
  void handle_message( const MESSAGE_T& msg,
                       marketdata::messages::message_type type,
                       SERIALIZER_T& serializer )
  {
    if ( subscribers_.size() == 0 )
    {
      return;
    }

    std::pair<const unsigned char*, size_t> serialized =
      serializer.serialize( msg );

    for ( auto connection : subscribers_ )
    {
      connection->write( service_marketdata, type, serialized.first, serialized.second );
    }
  }

  marketdata::receiver_ptr receiver_;
  marketdata::decoder_ptr decoder_;
  network::tcp::server tcp_server_;
  std::unordered_set<network::tcp::connection_ptr > subscribers_;

  marketdata::serialization::auction_imbalance_serializer auction_imbalance_serializer_;
  marketdata::serialization::bid_serializer bid_serializer_;
  marketdata::serialization::close_serializer close_serializer_;
  marketdata::serialization::high_serializer high_serializer_;
  marketdata::serialization::index_serializer index_serializer_;
  marketdata::serialization::low_serializer low_serializer_;
  marketdata::serialization::offer_serializer offer_serializer_;
  marketdata::serialization::open_serializer open_serializer_;
  marketdata::serialization::open_interest_serializer open_interest_serializer_;
  marketdata::serialization::price_band_serializer price_band_serializer_;
  marketdata::serialization::quantity_band_serializer quantity_band_serializer_;
  marketdata::serialization::security_definition_serializer security_definition_serializer_;
  marketdata::serialization::security_status_serializer security_status_serializer_;
  marketdata::serialization::settlement_serializer settlement_serializer_;
  marketdata::serialization::trade_serializer trade_serializer_;
  marketdata::serialization::trade_volume_serializer trade_volume_serializer_;
  marketdata::serialization::vwap_serializer vwap_serializer_;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_TICKER_PLANT_TICKER_PLANT_HPP */

