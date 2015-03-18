#ifndef APOENA_MSI_UMDF_DECODER_QUICKFAST_BUILDER_SELECTOR_HPP
#define APOENA_MSI_UMDF_DECODER_QUICKFAST_BUILDER_SELECTOR_HPP

#include <map>
#include <msi/umdf/messages/message_type.hpp>
#include <msi/umdf/messages/field_id.hpp>
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

class UMDF_DECODER_QUICKFAST_Export builder_selector : public builder
{
public:
  builder_selector();
  builder_selector( const builder_selector& ) = delete;
  builder_selector& operator=( const builder_selector& ) = delete;

  virtual ~builder_selector();

  void add_builder( messages::message_type_t message_type, std::shared_ptr<builder> builder );

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

private:
  builder* current_builder_;
  std::map<messages::message_type_t, std::shared_ptr<builder>> builders_;

  //in some templates ApplVerId comes before MessageType, in which case we don't yet
  // have a builder to add the value to. Store the value to be added once a builder
  // is selected.
  struct applverid
  {
    applverid()
      : pending( false ) {}

    bool pending;
    qm::FieldIdentity identity;
    QuickFAST::ValueType::Type type;
    std::string value;
  };

  applverid applverid_;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_DECODER_QUICKFAST_BUILDER_SELECTOR_HPP */

