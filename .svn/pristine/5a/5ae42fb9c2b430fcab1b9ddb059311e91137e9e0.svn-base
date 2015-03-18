#ifndef APOENA_MSI_UMDF_DECODER_QUICKFAST_INCREMENTAL_BUILDER_HPP
#define APOENA_MSI_UMDF_DECODER_QUICKFAST_INCREMENTAL_BUILDER_HPP

#include <functional>
#include <boost/container/flat_map.hpp>
#include <Messages/FieldIdentity.h>
#include <msi/umdf/messages/field_id.hpp>
#include <msi/umdf/messages/incremental.hpp>
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

class UMDF_DECODER_QUICKFAST_Export incremental_builder : public builder
{
public:

  class UMDF_DECODER_QUICKFAST_Export mdentries_builder : public builder
  {
  public:

    class UMDF_DECODER_QUICKFAST_Export underlyings_builder : public builder
    {
    public:

      underlyings_builder();

      typedef std::function<void( const messages::incremental::mdentries::underlyings& )> on_message_t;

      void register_on_message_callback( on_message_t callback );

      const messages::incremental::mdentries::underlyings& get_message() const;

      virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

    private:
      on_message_t on_message_;
      messages::incremental::mdentries::underlyings message_;

    };

    mdentries_builder();

    typedef std::function<void( const messages::incremental::mdentries& )> on_message_t;

    void register_on_message_callback( on_message_t callback );

    const messages::incremental::mdentries& get_message() const;

    virtual qm::ValueMessageBuilder& startSequence(
      const qm::FieldIdentity& identity,
      const std::string& applicationType,
      const std::string& applicationTypeNamespace,
      size_t fieldCount,
      const qm::FieldIdentity& lengthIdentity,
      size_t length );

    virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

  private:
    boost::container::flat_map<messages::field_id_t, builder*> builders_;
    on_message_t on_message_;
    messages::incremental::mdentries message_;
    underlyings_builder underlyings_builder_;

    void add_Underlyings( const messages::incremental::mdentries::underlyings& entry );
  };

  incremental_builder();

  typedef std::function<void( const messages::incremental& )> on_message_t;

  void register_on_message_callback( on_message_t callback );

  const messages::incremental& get_message() const;

  virtual qm::ValueMessageBuilder& startSequence(
    const qm::FieldIdentity& identity,
    const std::string& applicationType,
    const std::string& applicationTypeNamespace,
    size_t fieldCount,
    const qm::FieldIdentity& lengthIdentity,
    size_t length );

  virtual bool endMessage( qm::ValueMessageBuilder& messageBuilder );

private:
  boost::container::flat_map<messages::field_id_t, builder*> builders_;
  on_message_t on_message_;
  messages::incremental message_;
  mdentries_builder mdentries_builder_;

  void add_MDEntries( const messages::incremental::mdentries& entry );
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_DECODER_QUICKFAST_INCREMENTAL_BUILDER_HPP */

