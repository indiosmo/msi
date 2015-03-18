#ifndef APOENA_MSI_MARKETDATA_MESSAGES_TRADE_HPP
#define APOENA_MSI_MARKETDATA_MESSAGES_TRADE_HPP

#include <bitset>
#include <utility>
#include <vector>
#include <map>
#include <msi/decimal/decimal.hpp>
#include <msi/marketdata/messages/marketdata_messages_export.hpp>
#include <msi/marketdata/messages/field_values.hpp>


namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

class MARKETDATA_MESSAGES_Export trade
{
public:
  enum field_index
  {
    ix_seqnum = 0,
    ix_update_action,
    ix_security_id,
    ix_entry_price,
    ix_entry_size,
    ix_entry_date,
    ix_entry_time,
    ix_tick_direction,
    ix_buyer,
    ix_seller,
    ix_variation,
    ix_quantity_volume,
    ix_trade_id,
    ix_trade_condition,
    ix_field_count
  };

  void reset();

  std::pair<bool, uint32_t> seqnum() const;
  void set_seqnum( uint32_t val );

  std::pair<bool, uint32_t> update_action() const;
  void set_update_action( uint32_t val );

  std::pair<bool, uint64_t> security_id() const;
  void set_security_id( uint64_t val );

  std::pair<bool, decimal> entry_price() const;
  void set_entry_price( decimal val );

  std::pair<bool, int64_t> entry_size() const;
  void set_entry_size( int64_t val );

  std::pair<bool, uint32_t> entry_date() const;
  void set_entry_date( uint32_t val );

  std::pair<bool, uint32_t> entry_time() const;
  void set_entry_time( uint32_t val );

  std::pair<bool, uint32_t> tick_direction() const;
  void set_tick_direction( uint32_t val );

  std::pair<bool, const std::string&> buyer() const;
  void set_buyer( const std::string& val );

  std::pair<bool, const std::string&> seller() const;
  void set_seller( const std::string& val );

  std::pair<bool, decimal> variation() const;
  void set_variation( decimal val );

  std::pair<bool, uint64_t> quantity_volume() const;
  void set_quantity_volume( uint64_t val );

  std::pair<bool, const std::string&> trade_id() const;
  void set_trade_id( const std::string& val );

  bool trade_condition_opening_price() const;
  bool trade_condition_crossed() const;
  bool trade_condition_last_trade_at_price() const;
  bool trade_condition_imbalance_more_buyers() const;
  bool trade_condition_imbalance_more_sellers() const;
  bool trade_condition_exchange_last() const;
  bool trade_condition_multi_asset_trade() const;
  bool trade_condition_leg_trade() const;
  bool trade_condition_marketplace_entered_trade() const;
  std::pair<bool, uint32_t> trade_condition() const;
  void set_trade_condition( const std::bitset<trade_condition_field_count>& val );
  void set_trade_condition( const std::string& val );
  const std::bitset<ix_field_count>& presence_map() const;
  void set_presence_map( uint32_t val );

private:

  std::bitset<ix_field_count> presence_map_;

  uint32_t seqnum_;
  uint32_t update_action_;
  uint64_t security_id_;
  decimal entry_price_;
  int64_t entry_size_;
  uint32_t entry_date_;
  uint32_t entry_time_;
  uint32_t tick_direction_;
  std::string buyer_;
  std::string seller_;
  decimal variation_;
  uint64_t quantity_volume_;
  std::string trade_id_;
  std::bitset<trade_condition_field_count> trade_condition_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_MESSAGES_TRADE_HPP */

