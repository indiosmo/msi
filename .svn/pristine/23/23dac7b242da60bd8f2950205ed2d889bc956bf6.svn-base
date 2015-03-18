#ifndef APOENA_MSI_MARKETDATA_SERIALIZATION_SNAPSHOT_SERIALIZER_HPP
#define APOENA_MSI_MARKETDATA_SERIALIZATION_SNAPSHOT_SERIALIZER_HPP

#include <msi/marketdata/messages/snapshot.hpp>
#include <msi/marketdata/serialization/marketdata_serialization_export.hpp>

#include <msi/marketdata/serialization/auction_imbalance_serializer.hpp>
#include <msi/marketdata/serialization/bid_serializer.hpp>
#include <msi/marketdata/serialization/close_serializer.hpp>
#include <msi/marketdata/serialization/high_serializer.hpp>
#include <msi/marketdata/serialization/index_serializer.hpp>
#include <msi/marketdata/serialization/low_serializer.hpp>
#include <msi/marketdata/serialization/offer_serializer.hpp>
#include <msi/marketdata/serialization/open_serializer.hpp>
#include <msi/marketdata/serialization/open_interest_serializer.hpp>
#include <msi/marketdata/serialization/price_band_serializer.hpp>
#include <msi/marketdata/serialization/quantity_band_serializer.hpp>
#include <msi/marketdata/serialization/security_status_serializer.hpp>
#include <msi/marketdata/serialization/settlement_serializer.hpp>
#include <msi/marketdata/serialization/trade_serializer.hpp>
#include <msi/marketdata/serialization/trade_volume_serializer.hpp>
#include <msi/marketdata/serialization/vwap_serializer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

class MARKETDATA_SERIALIZATION_Export snapshot_serializer
{
public:
  enum offset
  {
    offset_pmap = 0,
    offset_auction_imbalance = offset_pmap + sizeof( uint32_t ),
    offset_bid = offset_auction_imbalance + sizeof( uint32_t ),
    offset_close = offset_bid + sizeof( uint32_t ),
    offset_high = offset_close + sizeof( uint32_t ),
    offset_index = offset_high + sizeof( uint32_t ),
    offset_low = offset_index + sizeof( uint32_t ),
    offset_offer = offset_low + sizeof( uint32_t ),
    offset_open = offset_offer + sizeof( uint32_t ),
    offset_open_interest = offset_open + sizeof( uint32_t ),
    offset_price_band = offset_open_interest + sizeof( uint32_t ),
    offset_quantity_band = offset_price_band + sizeof( uint32_t ),
    offset_security_status = offset_quantity_band + sizeof( uint32_t ),
    offset_settlement = offset_security_status + sizeof( uint32_t ),
    offset_trade = offset_settlement + sizeof( uint32_t ),
    offset_trade_volume = offset_trade + sizeof( uint32_t ),
    offset_vwap = offset_trade_volume + sizeof( uint32_t ),
    offset_variable_fields = offset_vwap + sizeof( uint32_t )
  };

  snapshot_serializer();
  std::pair<const unsigned char*, std::size_t> serialize( const messages::snapshot& msg );
  std::size_t buffer_size() const;
  std::size_t deserialize( const unsigned char* data, messages::snapshot& dst );

private:
  auction_imbalance_serializer auction_imbalance_serializer_;
  bid_serializer bid_serializer_;
  close_serializer close_serializer_;
  high_serializer high_serializer_;
  index_serializer index_serializer_;
  low_serializer low_serializer_;
  offer_serializer offer_serializer_;
  open_serializer open_serializer_;
  open_interest_serializer open_interest_serializer_;
  price_band_serializer price_band_serializer_;
  quantity_band_serializer quantity_band_serializer_;
  security_status_serializer security_status_serializer_;
  settlement_serializer settlement_serializer_;
  trade_serializer trade_serializer_;
  trade_volume_serializer trade_volume_serializer_;
  vwap_serializer vwap_serializer_;

  std::vector<unsigned char> data_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_SERIALIZATION_SNAPSHOT_SERIALIZER_HPP */

