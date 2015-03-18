#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp>
#include <memory>
#include <Common/Types.h>
#include <Messages/Field.h>
#include <msi/umdf/common/typedefs.hpp>
#include <msi/decimal/decimal.hpp>
#include <msi/umdf/messages/field_id.hpp>
#include <msi/umdf/decoder/quickfast/setter_t.hpp>
#include <msi/umdf/decoder/quickfast/sequence_reset_builder.hpp>

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

sequence_reset_builder::sequence_reset_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::MsgType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::sequence_reset::set_MsgType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MsgSeqNum, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::sequence_reset::set_MsgSeqNum, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SendingTime, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::sequence_reset::set_SendingTime, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::ApplVerID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::sequence_reset::set_ApplVerID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::NewSeqNo, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::sequence_reset::set_NewSeqNo, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

}

void
sequence_reset_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::sequence_reset&
sequence_reset_builder::get_message() const
{
  return message_;
}

bool
sequence_reset_builder::endMessage( qm::ValueMessageBuilder& messageBuilder )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();

  return true;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
