#ifndef APOENA_MSI_UMDF_DECODER_QUICKFAST_BUILDER_HPP
#define APOENA_MSI_UMDF_DECODER_QUICKFAST_BUILDER_HPP

#include <memory>
#include <map>
#include <Common/Types.h>
#include <Messages/ValueMessageBuilder.h>
#include <Messages/Field_fwd.h>
#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_export.hpp>
#include <msi/umdf/decoder/quickfast/setter_base.hpp>

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

namespace qm = QuickFAST::Messages;

class UMDF_DECODER_QUICKFAST_Export builder : public qm::ValueMessageBuilder
{
public:
  virtual ~builder() = 0;

  void add_setter( QuickFAST::field_id_t identity, QuickFAST::ValueType::Type fast_type, std::shared_ptr<setter_base> setter );

  void setField( QuickFAST::field_id_t identity, QuickFAST::ValueType::Type fast_type, qm::FieldCPtr field );

  //implement ValueMessageBuilder
  virtual const std::string& getApplicationType() const;
  virtual const std::string& getApplicationTypeNs() const;

  virtual void addValue( const qm::FieldIdentity& identity,
                         QuickFAST::ValueType::Type type,
                         const QuickFAST::int64 value );

  virtual void addValue( const qm::FieldIdentity& identity,
                         QuickFAST::ValueType::Type type,
                         const QuickFAST::uint64 value );

  virtual void addValue( const qm::FieldIdentity& identity,
                         QuickFAST::ValueType::Type type,
                         const QuickFAST::int32 value );

  virtual void addValue( const qm::FieldIdentity& identity,
                         QuickFAST::ValueType::Type type,
                         const QuickFAST::uint32 value );

  virtual void addValue( const qm::FieldIdentity& identity,
                         QuickFAST::ValueType::Type type,
                         const QuickFAST::int16 value );

  virtual void addValue( const qm::FieldIdentity& identity,
                         QuickFAST::ValueType::Type type,
                         const QuickFAST::uint16 value );

  virtual void addValue( const qm::FieldIdentity& identity,
                         QuickFAST::ValueType::Type type,
                         const QuickFAST::int8 value );

  virtual void addValue( const qm::FieldIdentity& identity,
                         QuickFAST::ValueType::Type type,
                         const QuickFAST::uchar value );

  virtual void addValue( const qm::FieldIdentity& identity,
                         QuickFAST::ValueType::Type type,
                         const QuickFAST::Decimal& value );

  virtual void addValue( const qm::FieldIdentity& identity,
                         QuickFAST::ValueType::Type type,
                         const unsigned char* value, size_t length );

  virtual qm::ValueMessageBuilder& startMessage(
    const std::string& applicationType,
    const std::string& applicationTypeNamespace,
    size_t size );

  virtual bool endMessage( qm::ValueMessageBuilder& messageBuilder );

  virtual bool ignoreMessage( qm::ValueMessageBuilder& messageBuilder );

  virtual qm::ValueMessageBuilder& startSequence(
    const qm::FieldIdentity& identity,
    const std::string& applicationType,
    const std::string& applicationTypeNamespace,
    size_t fieldCount,
    const qm::FieldIdentity& lengthIdentity,
    size_t length );

  virtual void endSequence(
    const qm::FieldIdentity& identity,
    qm::ValueMessageBuilder& sequenceBuilder );

  virtual qm::ValueMessageBuilder& startSequenceEntry(
    const std::string& applicationType,
    const std::string& applicationTypeNamespace,
    size_t size );

  virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

  virtual qm::ValueMessageBuilder& startGroup(
    const qm::FieldIdentity& identity,
    const std::string& applicationType,
    const std::string& applicationTypeNamespace,
    size_t size );

  virtual void endGroup(
    const qm::FieldIdentity& identity,
    qm::ValueMessageBuilder& groupBuilder );

  //Implement Logger
  virtual bool wantLog( LogLevel level );

  virtual bool logMessage( LogLevel level, const std::string& message );

  virtual bool reportDecodingError( const std::string& message );

  virtual bool reportCommunicationError( const std::string& message );


private:
  //a field might have different value types depending on the template version of the message received
  //so we have a setter per ValueType per Field.
  std::map<QuickFAST::field_id_t, std::map<QuickFAST::ValueType::Type, std::shared_ptr<setter_base>>> setters_;

  //implement ValueMessageBuilder
  std::string applicationType_;
  std::string applicationTypeNs_;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_DECODER_QUICKFAST_BUILDER_HPP */

