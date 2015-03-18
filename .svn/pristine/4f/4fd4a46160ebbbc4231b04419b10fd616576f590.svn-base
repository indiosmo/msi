#ifndef APOENA_MSI_UMDF_ADAPTER_ADAPTER_HPP
#define APOENA_MSI_UMDF_ADAPTER_ADAPTER_HPP

#include <msi/marketdata/common/decoder.hpp>
#include <msi/umdf/decoder/quickfast/decoder.hpp>
#include <msi/umdf/adapter/umdf_adapter_export.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace adapter
{

namespace ph = std::placeholders;

class UMDF_ADAPTER_Export adapter : public marketdata::decoder
{
public:
  explicit adapter( const std::string& template_path );

  virtual void decode( const unsigned char* data, std::size_t length );

private:
  static const std::string stream_electronic;
  static const std::string stream_all;

  static const std::string type_bid;
  static const std::string type_offer;
  static const std::string type_trade;
  static const std::string type_index;
  static const std::string type_open;
  static const std::string type_close;
  static const std::string type_settlement;
  static const std::string type_high;
  static const std::string type_low;
  static const std::string type_vwap;
  static const std::string type_auction_imbalance;
  static const std::string type_trade_volume;
  static const std::string type_open_interest;
  static const std::string type_empty_book;
  static const std::string type_security_status;
  static const std::string type_price_band;
  static const std::string type_quantity_band;

  typedef std::function<void( uint32_t, const messages::incremental::mdentries& )> incremental_convert_t;
  std::map<std::string, incremental_convert_t> incremental_convert_map_;

  void on_security_status( const messages::security_status& msg );

  void on_incremental( const messages::incremental& msg );

  void convert_incremental_auction_imbalance( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_bid( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_close( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_high( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_index( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_low( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_offer( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_open( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_open_interest( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_empty_book( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_price_band( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_quantity_band( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_settlement( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_trade( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_trade_volume( uint32_t seqnum, const messages::incremental::mdentries& entry );

  void convert_incremental_vwap( uint32_t seqnum, const messages::incremental::mdentries& entry );

  umdf::decoder::quickfast::decoder decoder_;

  marketdata::messages::auction_imbalance auction_imbalance_;
  marketdata::messages::bid bid_;
  marketdata::messages::close close_;
  marketdata::messages::high high_;
  marketdata::messages::index index_;
  marketdata::messages::low low_;
  marketdata::messages::offer offer_;
  marketdata::messages::open open_;
  marketdata::messages::open_interest open_interest_;
  marketdata::messages::price_band price_band_;
  marketdata::messages::quantity_band quantity_band_;
  marketdata::messages::settlement settlement_;
  marketdata::messages::trade trade_;
  marketdata::messages::trade_volume trade_volume_;
  marketdata::messages::vwap vwap_;
  marketdata::messages::security_status security_status_;
};

} // end of namespace
} // end of namespace
} // end of namespace
} // end of namespace

#endif /* APOENA_MSI_UMDF_ADAPTER_ADAPTER_HPP */