#ifndef APOENA_MSI_MARKETDATA_MESSAGES_QUANTITY_BAND_HPP
#define APOENA_MSI_MARKETDATA_MESSAGES_QUANTITY_BAND_HPP

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

class MARKETDATA_MESSAGES_Export quantity_band
{
public:
  enum field_index
  {
    ix_seqnum = 0,
    ix_security_id,
    ix_low_limit_price,
    ix_high_limit_price,
    ix_trading_reference_price,
    ix_price_band_midpoint_price_type,
    ix_avg_daily_traded_qty,
    ix_max_trade_vol,
    ix_entry_date,
    ix_entry_time,
    ix_field_count
  };

  void reset();

  std::pair<bool, uint32_t> seqnum() const;
  void set_seqnum( uint32_t val );

  std::pair<bool, uint64_t> security_id() const;
  void set_security_id( uint64_t val );

  std::pair<bool, decimal> low_limit_price() const;
  void set_low_limit_price( decimal val );

  std::pair<bool, decimal> high_limit_price() const;
  void set_high_limit_price( decimal val );

  std::pair<bool, decimal> trading_reference_price() const;
  void set_trading_reference_price( decimal val );

  std::pair<bool, uint32_t> price_band_midpoint_price_type() const;
  void set_price_band_midpoint_price_type( uint32_t val );

  std::pair<bool, uint64_t> avg_daily_traded_qty() const;
  void set_avg_daily_traded_qty( uint64_t val );

  std::pair<bool, uint64_t> max_trade_vol() const;
  void set_max_trade_vol( uint64_t val );

  std::pair<bool, uint32_t> entry_date() const;
  void set_entry_date( uint32_t val );

  std::pair<bool, uint32_t> entry_time() const;
  void set_entry_time( uint32_t val );

  const std::bitset<ix_field_count>& presence_map() const;
  void set_presence_map( uint32_t val );

private:

  std::bitset<ix_field_count> presence_map_;

  uint32_t seqnum_;
  uint64_t security_id_;
  decimal low_limit_price_;
  decimal high_limit_price_;
  decimal trading_reference_price_;
  uint32_t price_band_midpoint_price_type_;
  uint64_t avg_daily_traded_qty_;
  uint64_t max_trade_vol_;
  uint32_t entry_date_;
  uint32_t entry_time_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_MESSAGES_QUANTITY_BAND_HPP */

