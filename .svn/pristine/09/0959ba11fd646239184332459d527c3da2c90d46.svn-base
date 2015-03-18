#ifndef APOENA_MSI_MARKETDATA_COMMON_DECODER_HPP
#define APOENA_MSI_MARKETDATA_COMMON_DECODER_HPP

#include <functional>
#include <memory>
#include <msi/marketdata/common/marketdata_common_export.hpp>
#include <msi/marketdata/messages/messages.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{

class MARKETDATA_COMMON_Export decoder
{
public:
  virtual ~decoder() = 0;

  typedef std::function<void ( const messages::auction_imbalance& )> on_auction_imbalance_t;
  typedef std::function<void ( const messages::bid& )> on_bid_t;
  typedef std::function<void ( const messages::close& )> on_close_t;
  typedef std::function<void ( const messages::high& )> on_high_t;
  typedef std::function<void ( const messages::index& )> on_index_t;
  typedef std::function<void ( const messages::low& )> on_low_t;
  typedef std::function<void ( const messages::offer& )> on_offer_t;
  typedef std::function<void ( const messages::open& )> on_open_t;
  typedef std::function<void ( const messages::open_interest& )> on_open_interest_t;
  typedef std::function<void ( const messages::price_band& )> on_price_band_t;
  typedef std::function<void ( const messages::quantity_band& )> on_quantity_band_t;
  typedef std::function<void ( const messages::security_definition& )> on_security_definition_t;
  typedef std::function<void ( const messages::security_status& )> on_security_status_t;
  typedef std::function<void ( const messages::settlement& )> on_settlement_t;
  typedef std::function<void ( const messages::trade& )> on_trade_t;
  typedef std::function<void ( const messages::trade_volume& )> on_trade_volume_t;
  typedef std::function<void ( const messages::vwap& )> on_vwap_t;

  void register_on_auction_imbalance_callback( on_auction_imbalance_t callback );
  void register_on_bid_callback( on_bid_t callback );
  void register_on_close_callback( on_close_t callback );
  void register_on_high_callback( on_high_t callback );
  void register_on_index_callback( on_index_t callback );
  void register_on_low_callback( on_low_t callback );
  void register_on_offer_callback( on_offer_t callback );
  void register_on_open_callback( on_open_t callback );
  void register_on_open_interest_callback( on_open_interest_t callback );
  void register_on_price_band_callback( on_price_band_t callback );
  void register_on_quantity_band_callback( on_quantity_band_t callback );
  void register_on_security_definition_callback( on_security_definition_t callback );
  void register_on_security_status_callback( on_security_status_t callback );
  void register_on_settlement_callback( on_settlement_t callback );
  void register_on_trade_callback( on_trade_t callback );
  void register_on_trade_volume_callback( on_trade_volume_t callback );
  void register_on_vwap_callback( on_vwap_t callback );

  virtual void decode( const unsigned char* data, std::size_t length ) = 0;

protected:
  on_auction_imbalance_t on_auction_imbalance_;
  on_bid_t on_bid_;
  on_close_t on_close_;
  on_high_t on_high_;
  on_index_t on_index_;
  on_low_t on_low_;
  on_offer_t on_offer_;
  on_open_t on_open_;
  on_open_interest_t on_open_interest_;
  on_price_band_t on_price_band_;
  on_quantity_band_t on_quantity_band_;
  on_security_definition_t on_security_definition_;
  on_security_status_t on_security_status_;
  on_settlement_t on_settlement_;
  on_trade_t on_trade_;
  on_trade_volume_t on_trade_volume_;
  on_vwap_t on_vwap_;
};

typedef std::shared_ptr<marketdata::decoder> decoder_ptr;

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_COMMON_DECODER_HPP */

