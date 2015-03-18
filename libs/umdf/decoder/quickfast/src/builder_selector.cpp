#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp>
#include <msi/umdf/decoder/quickfast/builder_selector.hpp>

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

builder_selector::builder_selector()
{

}

builder_selector::~builder_selector()
{

}

void
builder_selector::add_builder( messages::message_type_t message_type,
                               std::shared_ptr<builder> builder )
{
  builders_[message_type] = builder;
}

qm::ValueMessageBuilder&
builder_selector::startMessage( const std::string& applicationType,
                                const std::string& applicationTypeNamespace,
                                size_t size )
{
  applverid_.pending = false;
  current_builder_ = nullptr;

  return *this;
}

bool
builder_selector::endMessage( qm::ValueMessageBuilder& messageBuilder )
{
  if ( current_builder_ )
  {
    return current_builder_->endMessage( messageBuilder );
  }
  else
  {
    return true;
  }
}

bool
builder_selector::ignoreMessage( qm::ValueMessageBuilder& messageBuilder )
{
  if ( current_builder_ )
  {
    return current_builder_->ignoreMessage( messageBuilder );
  }
  else
  {
    return true;
  }
}

qm::ValueMessageBuilder&
builder_selector::startSequence( const qm::FieldIdentity& identity,
                                 const std::string& applicationType,
                                 const std::string& applicationTypeNamespace,
                                 size_t fieldCount,
                                 const qm::FieldIdentity& lengthIdentity,
                                 size_t length )
{
  if ( current_builder_ )
  {
    return current_builder_->startSequence( identity, applicationType,
                                            applicationTypeNamespace, fieldCount, lengthIdentity, length );
  }
  else
  {
    return *this;
  }
}

void
builder_selector::endSequence( const qm::FieldIdentity& identity,
                               qm::ValueMessageBuilder& sequenceBuilder )
{
  if ( current_builder_ )
  {
    current_builder_->endSequence( identity, sequenceBuilder );
  }
}

qm::ValueMessageBuilder&
builder_selector::startSequenceEntry( const std::string& applicationType,
                                      const std::string& applicationTypeNamespace,
                                      size_t size )
{
  if ( current_builder_ )
  {
    return current_builder_->startSequenceEntry( applicationType, applicationTypeNamespace, size );
  }
  else
  {
    return *this;
  }
}

void
builder_selector::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( current_builder_ )
  {
    current_builder_->endSequenceEntry( entry );
  }
}

void
builder_selector::addValue( const qm::FieldIdentity& identity,
                            QuickFAST::ValueType::Type type,
                            const QuickFAST::int64 value )
{
  if ( current_builder_ )
  {
    current_builder_->addValue( identity, type, value );
  }
}

void
builder_selector::addValue( const qm::FieldIdentity& identity,
                            QuickFAST::ValueType::Type type,
                            const QuickFAST::uint64 value )
{
  if ( current_builder_ )
  {
    current_builder_->addValue( identity, type, value );
  }
}

void
builder_selector::addValue( const qm::FieldIdentity& identity,
                            QuickFAST::ValueType::Type type,
                            const QuickFAST::int32 value )
{
  if ( current_builder_ )
  {
    current_builder_->addValue( identity, type, value );
  }
}

void
builder_selector::addValue( const qm::FieldIdentity& identity,
                            QuickFAST::ValueType::Type type,
                            const QuickFAST::uint32 value )
{
  if ( current_builder_ )
  {
    current_builder_->addValue( identity, type, value );
  }
}

void
builder_selector::addValue( const qm::FieldIdentity& identity,
                            QuickFAST::ValueType::Type type,
                            const QuickFAST::int16 value )
{
  if ( current_builder_ )
  {
    current_builder_->addValue( identity, type, value );
  }
}

void
builder_selector::addValue( const qm::FieldIdentity& identity,
                            QuickFAST::ValueType::Type type,
                            const QuickFAST::uint16 value )
{
  if ( current_builder_ )
  {
    current_builder_->addValue( identity, type, value );
  }
}

void
builder_selector::addValue( const qm::FieldIdentity& identity,
                            QuickFAST::ValueType::Type type,
                            const QuickFAST::int8 value )
{
  if ( current_builder_ )
  {
    current_builder_->addValue( identity, type, value );
  }
}

void
builder_selector::addValue( const qm::FieldIdentity& identity,
                            QuickFAST::ValueType::Type type,
                            const QuickFAST::uchar value )
{
  if ( current_builder_ )
  {
    current_builder_->addValue( identity, type, value );
  }
}

void
builder_selector::addValue( const qm::FieldIdentity& identity,
                            QuickFAST::ValueType::Type type,
                            const QuickFAST::Decimal& value )
{
  if ( current_builder_ )
  {
    current_builder_->addValue( identity, type, value );
  }
}

void
builder_selector::addValue( const qm::FieldIdentity& identity,
                            QuickFAST::ValueType::Type type,
                            const unsigned char* value,
                            size_t length )
{
  if ( identity.id() == messages::field_id::ApplVerID && current_builder_ == nullptr )
  {
    applverid_.pending = true;
    applverid_.identity = identity;
    applverid_.type = type;
    applverid_.value = std::string( reinterpret_cast<const char*>( value ), length );
  }

  if ( identity.id() == messages::field_id::MsgType )
  {
    auto builder = builders_.find( messages::message_type_t( reinterpret_cast<const char*>( value ), length ) );

    if ( builder != builders_.end() )
    {
      current_builder_ = builder->second.get();

      if ( applverid_.pending )
      {
        current_builder_->addValue(
          applverid_.identity,
          applverid_.type,
          reinterpret_cast<const unsigned char*>( applverid_.value.c_str() ),
          applverid_.value.length() );
      }
    }
  }

  if ( current_builder_ )
  {
    current_builder_->addValue( identity, type, value, length );
  }
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace


