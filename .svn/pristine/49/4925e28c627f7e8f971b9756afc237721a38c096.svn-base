#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp>
#include <memory>
#include <Common/Types.h>
#include <Messages/Field.h>
#include <msi/umdf/common/typedefs.hpp>
#include <msi/decimal/decimal.hpp>
#include <msi/umdf/messages/field_id.hpp>
#include <msi/umdf/decoder/quickfast/setter_t.hpp>
#include <msi/umdf/decoder/quickfast/news_builder.hpp>

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

news_builder::relatedsym_builder::relatedsym_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::SecurityID, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::news::relatedsym::set_SecurityID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityIDSource, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::news::relatedsym::set_SecurityIDSource, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityExchange, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::relatedsym::set_SecurityExchange, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

}

void
news_builder::relatedsym_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::news::relatedsym&
news_builder::relatedsym_builder::get_message() const
{
  return message_;
}

void
news_builder::relatedsym_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

news_builder::routingids_builder::routingids_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::RoutingType, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::news::routingids::set_RoutingType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::RoutingID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::routingids::set_RoutingID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

}

void
news_builder::routingids_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::news::routingids&
news_builder::routingids_builder::get_message() const
{
  return message_;
}

void
news_builder::routingids_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

news_builder::linesoftext_builder::linesoftext_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::Text, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::linesoftext::set_Text, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::EncodedTextLen, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::news::linesoftext::set_EncodedTextLen, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::EncodedText, q::ValueType::UTF8,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::linesoftext::set_EncodedText, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::EncodedText, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::linesoftext::set_EncodedText, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

}

void
news_builder::linesoftext_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::news::linesoftext&
news_builder::linesoftext_builder::get_message() const
{
  return message_;
}

void
news_builder::linesoftext_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

news_builder::news_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;

  builders_[m::field_id::NoRelatedSym] = &relatedsym_builder_;
  builders_[m::field_id::NoRoutingIDs] = &routingids_builder_;
  builders_[m::field_id::NoLinesOfText] = &linesoftext_builder_;
  add_setter( m::field_id::ApplVerID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::set_ApplVerID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MsgType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::set_MsgType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MsgSeqNum, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::news::set_MsgSeqNum, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SendingTime, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::news::set_SendingTime, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::OrigTime, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::news::set_OrigTime, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::NewsSource, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::set_NewsSource, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::NewsID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::set_NewsID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::LanguageCode, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::set_LanguageCode, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::Headline, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::set_Headline, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::URLLink, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::set_URLLink, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::EncodedHeadlineLen, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::news::set_EncodedHeadlineLen, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::EncodedHeadline, q::ValueType::UTF8,
              std::make_shared<setter<std::string>>(
                std::bind( &m::news::set_EncodedHeadline, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  static_cast<news_builder::relatedsym_builder*>
  ( builders_[m::field_id::NoRelatedSym] )->register_on_message_callback( std::bind (
        &news_builder::add_RelatedSym, this, p::_1 ) );

  static_cast<news_builder::routingids_builder*>
  ( builders_[m::field_id::NoRoutingIDs] )->register_on_message_callback( std::bind (
        &news_builder::add_RoutingIds, this, p::_1 ) );

  static_cast<news_builder::linesoftext_builder*>
  ( builders_[m::field_id::NoLinesOfText] )->register_on_message_callback( std::bind (
        &news_builder::add_LinesOfText, this, p::_1 ) );

}

void
news_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::news&
news_builder::get_message() const
{
  return message_;
}

qm::ValueMessageBuilder&
news_builder::startSequence( const qm::FieldIdentity& identity,
                             const std::string& applicationType,
                             const std::string& applicationTypeNamespace,
                             size_t fieldCount,
                             const qm::FieldIdentity& lengthIdentity,
                             size_t length )
{
  auto builder = builders_.find( lengthIdentity.id() );

  if ( builder != builders_.end() )
  {
    return *( builder->second );
  }
  else
  {
    std::stringstream ss;
    ss << "Unsupported sequence " << lengthIdentity.getLocalName() << "[" << lengthIdentity.id() << "]";
    throw std::runtime_error( ss.str() );
  }
}

bool
news_builder::endMessage( qm::ValueMessageBuilder& messageBuilder )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();

  return true;
}

void
news_builder::add_RelatedSym( const messages::news::relatedsym& entry )
{
  message_.add_RelatedSym( entry );
}

void
news_builder::add_RoutingIds( const messages::news::routingids& entry )
{
  message_.add_RoutingIds( entry );
}

void
news_builder::add_LinesOfText( const messages::news::linesoftext& entry )
{
  message_.add_LinesOfText( entry );
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
