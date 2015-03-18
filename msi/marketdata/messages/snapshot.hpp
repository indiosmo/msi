#ifndef APOENA_MSI_MARKETDATA_MESSAGES_SNAPSHOT_HPP
#define APOENA_MSI_MARKETDATA_MESSAGES_SNAPSHOT_HPP

#include <bitset>
#include <utility>
#include <vector>
#include <map>
#include <msi/decimal/decimal.hpp>
#include <msi/marketdata/messages/marketdata_messages_export.hpp>
#include <msi/marketdata/messages/field_values.hpp>

#include <msi/marketdata/messages/auction_imbalance.hpp>
#include <msi/marketdata/messages/close.hpp>
#include <msi/marketdata/messages/high.hpp>
#include <msi/marketdata/messages/index.hpp>
#include <msi/marketdata/messages/low.hpp>
#include <msi/marketdata/messages/open.hpp>
#include <msi/marketdata/messages/open_interest.hpp>
#include <msi/marketdata/messages/price_band.hpp>
#include <msi/marketdata/messages/quantity_band.hpp>
#include <msi/marketdata/messages/security_status.hpp>
#include <msi/marketdata/messages/settlement.hpp>
#include <msi/marketdata/messages/trade.hpp>
#include <msi/marketdata/messages/trade_volume.hpp>
#include <msi/marketdata/messages/vwap.hpp>
#include <msi/marketdata/messages/bid.hpp>
#include <msi/marketdata/messages/offer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

class MARKETDATA_MESSAGES_Export snapshot
{
public:
  enum field_index
  {
    ix_auction_imbalance = 0,
    ix_bid,
    ix_close,
    ix_high,
    ix_index,
    ix_low,
    ix_offer,
    ix_open,
    ix_open_interest,
    ix_price_band,
    ix_quantity_band,
    ix_security_status,
    ix_settlement,
    ix_trade,
    ix_trade_volume,
    ix_vwap,
    ix_field_count
  };

  void reset();

  std::pair<bool, const auction_imbalance&> auction_imbalance() const;
  void set_auction_imbalance( const messages::auction_imbalance& val );

  const std::vector<bid>& bids() const;
  void add_bid( const bid& val );

  std::pair<bool, const close&> close() const;
  void set_close( const messages::close& val );

  std::pair<bool, const high&> high() const;
  void set_high( const messages::high& val );

  std::pair<bool, const index&> index() const;
  void set_index( const messages::index& val );

  std::pair<bool, const low&> low() const;
  void set_low( const messages::low& val );

  const std::vector<offer>& offers() const;
  void add_offer( const offer& val );

  std::pair<bool, const open&> open() const;
  void set_open( const messages::open& val );

  std::pair<bool, const open_interest&> open_interest() const;
  void set_open_interest( const messages::open_interest& val );

  std::pair<bool, const price_band&> price_band() const;
  void set_price_band( const messages::price_band& val );

  std::pair<bool, const quantity_band&> quantity_band() const;
  void set_quantity_band( const messages::quantity_band& val );

  std::pair<bool, const security_status&> security_status() const;
  void set_security_status( const messages::security_status& val );

  std::pair<bool, const settlement&> settlement() const;
  void set_settlement( const messages::settlement& val );

  std::pair<bool, const trade&> trade() const;
  void set_trade( const messages::trade& val );

  std::pair<bool, const trade_volume&> trade_volume() const;
  void set_trade_volume( const messages::trade_volume& val );

  std::pair<bool, const vwap&> vwap() const;
  void set_vwap( const messages::vwap& val );

  const std::bitset<ix_field_count>& presence_map() const;
  void set_presence_map( uint32_t val );

private:

  std::bitset<ix_field_count> presence_map_;

  messages::auction_imbalance auction_imbalance_;
  std::vector<bid> bids_;
  messages::close close_;
  messages::high high_;
  messages::index index_;
  messages::low low_;
  std::vector<offer> offers_;
  messages::open open_;
  messages::open_interest open_interest_;
  messages::price_band price_band_;
  messages::quantity_band quantity_band_;
  messages::security_status security_status_;
  messages::settlement settlement_;
  messages::trade trade_;
  messages::trade_volume trade_volume_;
  messages::vwap vwap_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_MESSAGES_SNAPSHOT_HPP */

