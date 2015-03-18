#ifndef APOENA_MSI_MARKETDATA_MESSAGES_SETTLEMENT_HPP
#define APOENA_MSI_MARKETDATA_MESSAGES_SETTLEMENT_HPP

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

class MARKETDATA_MESSAGES_Export settlement
{
public:
  enum field_index
  {
    ix_seqnum = 0,
    ix_security_id,
    ix_entry_price,
    ix_price_type,
    ix_entry_date,
    ix_entry_time,
    ix_settl_flag,
    ix_settl_price_type,
    ix_field_count
  };

  void reset();

  std::pair<bool, uint32_t> seqnum() const;
  void set_seqnum( uint32_t val );

  std::pair<bool, uint64_t> security_id() const;
  void set_security_id( uint64_t val );

  std::pair<bool, decimal> entry_price() const;
  void set_entry_price( decimal val );

  std::pair<bool, const std::string&> price_type() const;
  void set_price_type( const std::string& val );

  std::pair<bool, uint32_t> entry_date() const;
  void set_entry_date( uint32_t val );

  std::pair<bool, uint32_t> entry_time() const;
  void set_entry_time( uint32_t val );

  std::pair<bool, const std::string&> settl_flag() const;
  void set_settl_flag( const std::string& val );

  std::pair<bool, const std::string&> settl_price_type() const;
  void set_settl_price_type( const std::string& val );

  const std::bitset<ix_field_count>& presence_map() const;
  void set_presence_map( uint32_t val );

private:

  std::bitset<ix_field_count> presence_map_;

  uint32_t seqnum_;
  uint64_t security_id_;
  decimal entry_price_;
  std::string price_type_;
  uint32_t entry_date_;
  uint32_t entry_time_;
  std::string settl_flag_;
  std::string settl_price_type_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_MESSAGES_SETTLEMENT_HPP */

