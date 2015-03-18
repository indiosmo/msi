#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp>
#include <memory>
#include <Common/Types.h>
#include <Messages/Field.h>
#include <msi/umdf/common/typedefs.hpp>
#include <msi/decimal/decimal.hpp>
#include <msi/umdf/messages/field_id.hpp>
#include <msi/umdf/decoder/quickfast/setter_t.hpp>
#include <msi/umdf/decoder/quickfast/security_status_builder.hpp>

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

security_status_builder::security_status_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::ApplVerID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_status::set_ApplVerID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MsgType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_status::set_MsgType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MsgSeqNum, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_status::set_MsgSeqNum, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SendingTime, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::security_status::set_SendingTime, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityGroup, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_status::set_SecurityGroup, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::Symbol, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_status::set_Symbol, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityID, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::security_status::set_SecurityID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityIDSource, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_status::set_SecurityIDSource, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityExchange, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_status::set_SecurityExchange, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradingSessionSubID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_status::set_TradingSessionSubID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityTradingStatus, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_status::set_SecurityTradingStatus, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradingSessionID, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_status::set_TradingSessionID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradSesOpenTime, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::security_status::set_TradSesOpenTime, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::TransactTime, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::security_status::set_TransactTime, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradeDate, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_status::set_TradeDate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityTradingEvent, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_status::set_SecurityTradingEvent, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

}

void
security_status_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::security_status&
security_status_builder::get_message() const
{
  return message_;
}

bool
security_status_builder::endMessage( qm::ValueMessageBuilder& messageBuilder )
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
