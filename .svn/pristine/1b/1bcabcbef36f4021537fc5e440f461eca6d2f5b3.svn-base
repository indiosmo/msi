#ifndef APOENA_MSI_UMDF_DECODER_QUICKFAST_SECURITY_LIST_BUILDER_HPP
#define APOENA_MSI_UMDF_DECODER_QUICKFAST_SECURITY_LIST_BUILDER_HPP

#include <functional>
#include <boost/container/flat_map.hpp>
#include <Messages/FieldIdentity.h>
#include <msi/umdf/messages/field_id.hpp>
#include <msi/umdf/messages/security_list.hpp>
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

class UMDF_DECODER_QUICKFAST_Export security_list_builder : public builder
{
public:

  class UMDF_DECODER_QUICKFAST_Export relatedsym_builder : public builder
  {
  public:

    class UMDF_DECODER_QUICKFAST_Export applids_builder : public builder
    {
    public:

      class UMDF_DECODER_QUICKFAST_Export feedtypes_builder : public builder
      {
      public:

        feedtypes_builder();

        typedef std::function<void( const messages::security_list::relatedsym::applids::feedtypes& )> on_message_t;

        void register_on_message_callback( on_message_t callback );

        const messages::security_list::relatedsym::applids::feedtypes& get_message() const;

        virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

      private:
        on_message_t on_message_;
        messages::security_list::relatedsym::applids::feedtypes message_;

      };

      applids_builder();

      typedef std::function<void( const messages::security_list::relatedsym::applids& )> on_message_t;

      void register_on_message_callback( on_message_t callback );

      const messages::security_list::relatedsym::applids& get_message() const;

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
      messages::security_list::relatedsym::applids message_;
      feedtypes_builder feedtypes_builder_;

      void add_FeedTypes( const messages::security_list::relatedsym::applids::feedtypes& entry );
    };

    class UMDF_DECODER_QUICKFAST_Export securityaltids_builder : public builder
    {
    public:

      securityaltids_builder();

      typedef std::function<void( const messages::security_list::relatedsym::securityaltids& )> on_message_t;

      void register_on_message_callback( on_message_t callback );

      const messages::security_list::relatedsym::securityaltids& get_message() const;

      virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

    private:
      on_message_t on_message_;
      messages::security_list::relatedsym::securityaltids message_;

    };

    class UMDF_DECODER_QUICKFAST_Export underlyings_builder : public builder
    {
    public:

      underlyings_builder();

      typedef std::function<void( const messages::security_list::relatedsym::underlyings& )> on_message_t;

      void register_on_message_callback( on_message_t callback );

      const messages::security_list::relatedsym::underlyings& get_message() const;

      virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

    private:
      on_message_t on_message_;
      messages::security_list::relatedsym::underlyings message_;

    };

    class UMDF_DECODER_QUICKFAST_Export instrattrib_builder : public builder
    {
    public:

      instrattrib_builder();

      typedef std::function<void( const messages::security_list::relatedsym::instrattrib& )> on_message_t;

      void register_on_message_callback( on_message_t callback );

      const messages::security_list::relatedsym::instrattrib& get_message() const;

      virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

    private:
      on_message_t on_message_;
      messages::security_list::relatedsym::instrattrib message_;

    };

    class UMDF_DECODER_QUICKFAST_Export tickrules_builder : public builder
    {
    public:

      tickrules_builder();

      typedef std::function<void( const messages::security_list::relatedsym::tickrules& )> on_message_t;

      void register_on_message_callback( on_message_t callback );

      const messages::security_list::relatedsym::tickrules& get_message() const;

      virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

    private:
      on_message_t on_message_;
      messages::security_list::relatedsym::tickrules message_;

    };

    class UMDF_DECODER_QUICKFAST_Export legs_builder : public builder
    {
    public:

      legs_builder();

      typedef std::function<void( const messages::security_list::relatedsym::legs& )> on_message_t;

      void register_on_message_callback( on_message_t callback );

      const messages::security_list::relatedsym::legs& get_message() const;

      virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

    private:
      on_message_t on_message_;
      messages::security_list::relatedsym::legs message_;

    };

    class UMDF_DECODER_QUICKFAST_Export lots_builder : public builder
    {
    public:

      lots_builder();

      typedef std::function<void( const messages::security_list::relatedsym::lots& )> on_message_t;

      void register_on_message_callback( on_message_t callback );

      const messages::security_list::relatedsym::lots& get_message() const;

      virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

    private:
      on_message_t on_message_;
      messages::security_list::relatedsym::lots message_;

    };

    relatedsym_builder();

    typedef std::function<void( const messages::security_list::relatedsym& )> on_message_t;

    void register_on_message_callback( on_message_t callback );

    const messages::security_list::relatedsym& get_message() const;

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
    messages::security_list::relatedsym message_;
    applids_builder applids_builder_;
    securityaltids_builder securityaltids_builder_;
    underlyings_builder underlyings_builder_;
    instrattrib_builder instrattrib_builder_;
    tickrules_builder tickrules_builder_;
    legs_builder legs_builder_;
    lots_builder lots_builder_;

    void add_ApplIDs( const messages::security_list::relatedsym::applids& entry );
    void add_SecurityAltIDs( const messages::security_list::relatedsym::securityaltids& entry );
    void add_Underlyings( const messages::security_list::relatedsym::underlyings& entry );
    void add_InstrAttrib( const messages::security_list::relatedsym::instrattrib& entry );
    void add_TickRules( const messages::security_list::relatedsym::tickrules& entry );
    void add_Legs( const messages::security_list::relatedsym::legs& entry );
    void add_Lots( const messages::security_list::relatedsym::lots& entry );
  };

  security_list_builder();

  typedef std::function<void( const messages::security_list& )> on_message_t;

  void register_on_message_callback( on_message_t callback );

  const messages::security_list& get_message() const;

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
  messages::security_list message_;
  relatedsym_builder relatedsym_builder_;

  void add_RelatedSym( const messages::security_list::relatedsym& entry );
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_DECODER_QUICKFAST_SECURITY_LIST_BUILDER_HPP */

