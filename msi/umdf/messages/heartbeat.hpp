#ifndef APOENA_MSI_UMDF_MESSAGES_HEARTBEAT_HPP
#define APOENA_MSI_UMDF_MESSAGES_HEARTBEAT_HPP

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

class UMDF_MESSAGES_Export heartbeat
{
public:

  enum field_index
  {
    ix_ApplVerID = 0,
    ix_MsgType,
    ix_MsgSeqNum,
    ix_SendingTime,
    ix_PosDupFlag,
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

  std::pair<bool, const std::string&> PosDupFlag() const;
  void set_PosDupFlag( const std::string& val );

private:
  std::bitset<ix_field_count> presence_map_;

  std::string ApplVerID_;
  std::string MsgType_;
  uint32_t MsgSeqNum_;
  uint64_t SendingTime_;
  std::string PosDupFlag_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_MESSAGES_HEARTBEAT_HPP */

