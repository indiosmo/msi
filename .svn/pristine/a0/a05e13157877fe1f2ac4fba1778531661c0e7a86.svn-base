#ifndef APOENA_MSI_UMDF_MESSAGES_SEQUENCE_RESET_HPP
#define APOENA_MSI_UMDF_MESSAGES_SEQUENCE_RESET_HPP

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

class UMDF_MESSAGES_Export sequence_reset
{
public:

  enum field_index
  {
    ix_MsgType = 0,
    ix_MsgSeqNum,
    ix_SendingTime,
    ix_ApplVerID,
    ix_NewSeqNo,
    ix_field_count
  };

  void reset();

  std::pair<bool, const std::string&> MsgType() const;
  void set_MsgType( const std::string& val );

  std::pair<bool, uint32_t> MsgSeqNum() const;
  void set_MsgSeqNum( uint32_t val );

  std::pair<bool, uint64_t> SendingTime() const;
  void set_SendingTime( uint64_t val );

  std::pair<bool, const std::string&> ApplVerID() const;
  void set_ApplVerID( const std::string& val );

  std::pair<bool, uint32_t> NewSeqNo() const;
  void set_NewSeqNo( uint32_t val );

private:
  std::bitset<ix_field_count> presence_map_;

  std::string MsgType_;
  uint32_t MsgSeqNum_;
  uint64_t SendingTime_;
  std::string ApplVerID_;
  uint32_t NewSeqNo_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_MESSAGES_SEQUENCE_RESET_HPP */

