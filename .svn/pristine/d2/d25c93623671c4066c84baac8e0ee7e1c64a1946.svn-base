#ifndef APOENA_MSI_MARKETDATA_MESSAGES_SECURITY_STATUS_HPP
#define APOENA_MSI_MARKETDATA_MESSAGES_SECURITY_STATUS_HPP

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

class MARKETDATA_MESSAGES_Export security_status
{
public:
  enum field_index
  {
    ix_seqnum = 0,
    ix_security_id,
    ix_security_group,
    ix_group_phase,
    ix_instrument_state,
    ix_open_time,
    ix_trading_event,
    ix_field_count
  };

  void reset();

  std::pair<bool, uint32_t> seqnum() const;
  void set_seqnum( uint32_t val );

  std::pair<bool, uint64_t> security_id() const;
  void set_security_id( uint64_t val );

  std::pair<bool, const std::string&> security_group() const;
  void set_security_group( const std::string& val );

  std::pair<bool, const std::string&> group_phase() const;
  void set_group_phase( const std::string& val );

  std::pair<bool, uint32_t> instrument_state() const;
  void set_instrument_state( uint32_t val );

  std::pair<bool, uint64_t> open_time() const;
  void set_open_time( uint64_t val );

  std::pair<bool, uint32_t> trading_event() const;
  void set_trading_event( uint32_t val );

  const std::bitset<ix_field_count>& presence_map() const;
  void set_presence_map( uint32_t val );

private:

  std::bitset<ix_field_count> presence_map_;

  uint32_t seqnum_;
  uint64_t security_id_;
  std::string security_group_;
  std::string group_phase_;
  uint32_t instrument_state_;
  uint64_t open_time_;
  uint32_t trading_event_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_MESSAGES_SECURITY_STATUS_HPP */

