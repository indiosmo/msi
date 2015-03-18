#ifndef APOENA_MSI_UMDF_DECODER_QUICKFAST_HEARTBEAT_BUILDER_HPP
#define APOENA_MSI_UMDF_DECODER_QUICKFAST_HEARTBEAT_BUILDER_HPP

#include <functional>
#include <Messages/FieldIdentity.h>
#include <msi/umdf/messages/field_id.hpp>
#include <msi/umdf/messages/heartbeat.hpp>
#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_export.hpp>
#include <msi/umdf/decoder/quickfast/builder.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace decoder
{
namespace quickfast
{

class UMDF_DECODER_QUICKFAST_Export heartbeat_builder : public builder
{
public:

  heartbeat_builder();

  typedef std::function<void( const messages::heartbeat& )> on_message_t;

  void register_on_message_callback( on_message_t callback );

  const messages::heartbeat& get_message() const;

  virtual bool endMessage( qm::ValueMessageBuilder& messageBuilder );

private:
  on_message_t on_message_;
  messages::heartbeat message_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_DECODER_QUICKFAST_HEARTBEAT_BUILDER_HPP */

