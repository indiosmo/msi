#ifndef APOENA_MSI_UMDF_MESSAGES_SECURITY_STATUS_HPP
#define APOENA_MSI_UMDF_MESSAGES_SECURITY_STATUS_HPP

#include <bitset>
#include <utility>
#include <vector>
#include <msi/decimal/decimal.hpp>
#include <msi/umdf/messages/umdf_messages_export.hpp>
#include <msi/umdf/common/typedefs.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

class UMDF_MESSAGES_Export security_status
{
public:

  enum field_index
  {
    ix_ApplVerID = 0,
    ix_MsgType,
    ix_MsgSeqNum,
    ix_SendingTime,
    ix_SecurityGroup,
    ix_Symbol,
    ix_SecurityID,
    ix_SecurityIDSource,
    ix_SecurityExchange,
    ix_TradingSessionSubID,
    ix_SecurityTradingStatus,
    ix_TradingSessionID,
    ix_TradSesOpenTime,
    ix_TransactTime,
    ix_TradeDate,
    ix_SecurityTradingEvent,
    ix_field_count
  };

  void reset();

  std::pair<bool, const std::string&> ApplVerID() const;
  void set_ApplVerID( const std::string& val );

  std::pair<bool, const std::string&> MsgType() const;
  void set_MsgType( const std::string& val );

  std::pair<bool, uint32_t> MsgSeqNum() const;
  void set_MsgSeqNum( uint32_t val );

  std::pair<bool, uint64_t> SendingTime() const;
  void set_SendingTime( uint64_t val );

  std::pair<bool, const std::string&> SecurityGroup() const;
  void set_SecurityGroup( const std::string& val );

  std::pair<bool, const std::string&> Symbol() const;
  void set_Symbol( const std::string& val );

  std::pair<bool, uint64_t> SecurityID() const;
  void set_SecurityID( uint64_t val );

  std::pair<bool, uint32_t> SecurityIDSource() const;
  void set_SecurityIDSource( uint32_t val );

  std::pair<bool, const std::string&> SecurityExchange() const;
  void set_SecurityExchange( const std::string& val );

  std::pair<bool, const std::string&> TradingSessionSubID() const;
  void set_TradingSessionSubID( const std::string& val );

  std::pair<bool, uint32_t> SecurityTradingStatus() const;
  void set_SecurityTradingStatus( uint32_t val );

  std::pair<bool, uint32_t> TradingSessionID() const;
  void set_TradingSessionID( uint32_t val );

  std::pair<bool, uint64_t> TradSesOpenTime() const;
  void set_TradSesOpenTime( uint64_t val );

  std::pair<bool, uint64_t> TransactTime() const;
  void set_TransactTime( uint64_t val );

  std::pair<bool, uint32_t> TradeDate() const;
  void set_TradeDate( uint32_t val );

  std::pair<bool, uint32_t> SecurityTradingEvent() const;
  void set_SecurityTradingEvent( uint32_t val );

private:
  std::bitset<ix_field_count> presence_map_;

  std::string ApplVerID_;
  std::string MsgType_;
  uint32_t MsgSeqNum_;
  uint64_t SendingTime_;
  std::string SecurityGroup_;
  std::string Symbol_;
  uint64_t SecurityID_;
  uint32_t SecurityIDSource_;
  std::string SecurityExchange_;
  std::string TradingSessionSubID_;
  uint32_t SecurityTradingStatus_;
  uint32_t TradingSessionID_;
  uint64_t TradSesOpenTime_;
  uint64_t TransactTime_;
  uint32_t TradeDate_;
  uint32_t SecurityTradingEvent_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_MESSAGES_SECURITY_STATUS_HPP */

