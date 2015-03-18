#ifndef APOENA_MSI_UMDF_MESSAGES_MESSAGE_TYPE_HPP
#define APOENA_MSI_UMDF_MESSAGES_MESSAGE_TYPE_HPP

#include <string>
#include <msi/umdf/messages/umdf_messages_export.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

typedef std::string message_type_t;

class UMDF_MESSAGES_Export message_type
{
public:
  static const std::string sequence_reset;
  static const std::string heartbeat;
  static const std::string security_list;
  static const std::string incremental;
  static const std::string snapshot;
  static const std::string security_status;
  static const std::string news;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_MESSAGES_MESSAGE_TYPE_HPP */


