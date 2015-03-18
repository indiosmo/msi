#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp>
#include <msi/umdf/decoder/quickfast/builder.hpp>

#include <Messages/FieldInt8.h>
#include <Messages/FieldInt16.h>
#include <Messages/FieldInt32.h>
#include <Messages/FieldInt64.h>
#include <Messages/FieldUInt8.h>
#include <Messages/FieldUInt16.h>
#include <Messages/FieldUInt32.h>
#include <Messages/FieldUInt64.h>
#include <Messages/FieldDecimal.h>
#include <Messages/FieldAscii.h>

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

builder::~builder()
{

}

void
builder::add_setter( QuickFAST::field_id_t identity, QuickFAST::ValueType::Type fast_type, std::shared_ptr<setter_base> setter )
{
  setters_[identity][fast_type] = setter;
}

void
builder::setField( QuickFAST::field_id_t identity, QuickFAST::ValueType::Type fast_type, QuickFAST::Messages::FieldCPtr field )
{
  auto field_setters = setters_.find( identity );

  if ( field_setters != setters_.end() )
  {
    auto setter = field_setters->second.find( fast_type );

    if ( setter != field_setters->second.end() )
    {
      setter->second->set( field );
    }
    else
    {
      //TODO log incompatible type for field
    }
  }
  else
  {
    //TODO log invalid field id
  }
}

const std::string&
builder::getApplicationType() const
{
  return applicationType_;
}

const std::string&
builder::getApplicationTypeNs() const
{
  return applicationTypeNs_;
}

void
builder::addValue( const qm::FieldIdentity& identity,
                   QuickFAST::ValueType::Type type,
                   const QuickFAST::int64 value )
{
  setField( identity.id(), type, QuickFAST::Messages::FieldInt64::create( value ) );
}

void
builder::addValue( const qm::FieldIdentity& identity,
                   QuickFAST::ValueType::Type type,
                   const QuickFAST::uint64 value )
{
  setField( identity.id(), type, QuickFAST::Messages::FieldUInt64::create( value ) );
}

void
builder::addValue( const qm::FieldIdentity& identity,
                   QuickFAST::ValueType::Type type,
                   const QuickFAST::int32 value )
{
  setField( identity.id(), type, QuickFAST::Messages::FieldInt32::create( value ) );
}

void
builder::addValue( const qm::FieldIdentity&
                   identity, QuickFAST::ValueType::Type type,
                   const QuickFAST::uint32 value )
{
  setField( identity.id(), type, QuickFAST::Messages::FieldUInt32::create( value ) );
}

void
builder::addValue( const qm::FieldIdentity& identity,
                   QuickFAST::ValueType::Type type,
                   const QuickFAST::int16 value )
{
  setField( identity.id(), type, QuickFAST::Messages::FieldInt16::create( value ) );
}

void
builder::addValue( const qm::FieldIdentity& identity,
                   QuickFAST::ValueType::Type type,
                   const QuickFAST::uint16 value )
{
  setField( identity.id(), type, QuickFAST::Messages::FieldUInt16::create( value ) );
}

void
builder::addValue( const qm::FieldIdentity& identity,
                   QuickFAST::ValueType::Type type,
                   const QuickFAST::int8 value )
{
  setField( identity.id(), type, QuickFAST::Messages::FieldInt8::create( value ) );
}

void
builder::addValue( const qm::FieldIdentity& identity,
                   QuickFAST::ValueType::Type type,
                   const QuickFAST::uchar value )
{
  setField( identity.id(), type, QuickFAST::Messages::FieldUInt8::create( value ) );
}

void
builder::addValue( const qm::FieldIdentity& identity,
                   QuickFAST::ValueType::Type type,
                   const QuickFAST::Decimal& value )
{
  setField( identity.id(), type, QuickFAST::Messages::FieldDecimal::create( value ) );
}

void
builder::addValue( const qm::FieldIdentity& identity,
                   QuickFAST::ValueType::Type type,
                   const unsigned char* value, size_t length )
{
  setField( identity.id(), type, QuickFAST::Messages::FieldAscii::create( value, length ) );
}

qm::ValueMessageBuilder&
builder::startMessage( const std::string& applicationType,
                       const std::string& applicationTypeNamespace,
                       size_t size )
{
  return *this;
}

bool
builder::endMessage( qm::ValueMessageBuilder& messageBuilder )
{
  return true;
}

bool
builder::ignoreMessage( qm::ValueMessageBuilder& messageBuilder )
{
  return true;
}

qm::ValueMessageBuilder&
builder::startSequence( const qm::FieldIdentity& identity,
                        const std::string& applicationType,
                        const std::string& applicationTypeNamespace,
                        size_t fieldCount,
                        const qm::FieldIdentity& lengthIdentity,
                        size_t length )
{
  return *this;
}

void
builder::endSequence( const qm::FieldIdentity& identity,
                      qm::ValueMessageBuilder& sequenceBuilder )
{

}

qm::ValueMessageBuilder&
builder::startSequenceEntry( const std::string& applicationType,
                             const std::string& applicationTypeNamespace,
                             size_t size )
{
  return *this;
}

void
builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{

}

qm::ValueMessageBuilder&
builder::startGroup( const qm::FieldIdentity& identity,
                     const std::string& applicationType,
                     const std::string& applicationTypeNamespace,
                     size_t size )
{
  return *this;
}

void
builder::endGroup( const qm::FieldIdentity& identity,
                   qm::ValueMessageBuilder& groupBuilder )
{

}

bool
builder::wantLog( LogLevel level )
{
  return false;
}

bool
builder::logMessage( LogLevel level, const std::string& message )
{
  return true;
}

bool
builder::reportDecodingError( const std::string& message )
{
  return true;
}

bool
builder::reportCommunicationError( const std::string& message )
{
  return true;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
