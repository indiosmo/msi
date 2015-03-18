#ifndef APOENA_MSI_MARKETDATA_MESSAGES_TRADE_VOLUME_HPP
#define APOENA_MSI_MARKETDATA_MESSAGES_TRADE_VOLUME_HPP

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

class MARKETDATA_MESSAGES_Export trade_volume
{
public:
  enum field_index
  {
    ix_seqnum = 0,
    ix_security_id,
    ix_financial_volume,
    ix_number_of_trades,
    ix_quantity_volume,
    ix_entry_date,
    ix_entry_time,
    ix_currency,
    ix_field_count
  };

  void reset();

  std::pair<bool, uint32_t> seqnum() const;
  void set_seqnum( uint32_t val );

  std::pair<bool, uint64_t> security_id() const;
  void set_security_id( uint64_t val );

  std::pair<bool, decimal> financial_volume() const;
  void set_financial_volume( decimal val );

  std::pair<bool, uint32_t> number_of_trades() const;
  void set_number_of_trades( uint32_t val );

  std::pair<bool, uint64_t> quantity_volume() const;
  void set_quantity_volume( uint64_t val );

  std::pair<bool, uint32_t> entry_date() const;
  void set_entry_date( uint32_t val );

  std::pair<bool, uint32_t> entry_time() const;
  void set_entry_time( uint32_t val );

  std::pair<bool, const std::string&> currency() const;
  void set_currency( const std::string& val );

  const std::bitset<ix_field_count>& presence_map() const;
  void set_presence_map( uint32_t val );

private:

  std::bitset<ix_field_count> presence_map_;

  uint32_t seqnum_;
  uint64_t security_id_;
  decimal financial_volume_;
  uint32_t number_of_trades_;
  uint64_t quantity_volume_;
  uint32_t entry_date_;
  uint32_t entry_time_;
  std::string currency_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_MESSAGES_TRADE_VOLUME_HPP */

