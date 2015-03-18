#ifndef APOENA_MSI_UMDF_DECODER_QUICKFAST_NEWS_BUILDER_HPP
#define APOENA_MSI_UMDF_DECODER_QUICKFAST_NEWS_BUILDER_HPP

#include <functional>
#include <boost/container/flat_map.hpp>
#include <Messages/FieldIdentity.h>
#include <msi/umdf/messages/field_id.hpp>
#include <msi/umdf/messages/news.hpp>
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

class UMDF_DECODER_QUICKFAST_Export news_builder : public builder
{
public:

  class UMDF_DECODER_QUICKFAST_Export relatedsym_builder : public builder
  {
  public:

    relatedsym_builder();

    typedef std::function<void( const messages::news::relatedsym& )> on_message_t;

    void register_on_message_callback( on_message_t callback );

    const messages::news::relatedsym& get_message() const;

    virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

  private:
    on_message_t on_message_;
    messages::news::relatedsym message_;

  };

  class UMDF_DECODER_QUICKFAST_Export routingids_builder : public builder
  {
  public:

    routingids_builder();

    typedef std::function<void( const messages::news::routingids& )> on_message_t;

    void register_on_message_callback( on_message_t callback );

    const messages::news::routingids& get_message() const;

    virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

  private:
    on_message_t on_message_;
    messages::news::routingids message_;

  };

  class UMDF_DECODER_QUICKFAST_Export linesoftext_builder : public builder
  {
  public:

    linesoftext_builder();

    typedef std::function<void( const messages::news::linesoftext& )> on_message_t;

    void register_on_message_callback( on_message_t callback );

    const messages::news::linesoftext& get_message() const;

    virtual void endSequenceEntry( qm::ValueMessageBuilder& entry );

  private:
    on_message_t on_message_;
    messages::news::linesoftext message_;

  };

  news_builder();

  typedef std::function<void( const messages::news& )> on_message_t;

  void register_on_message_callback( on_message_t callback );

  const messages::news& get_message() const;

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
  messages::news message_;
  relatedsym_builder relatedsym_builder_;
  routingids_builder routingids_builder_;
  linesoftext_builder linesoftext_builder_;

  void add_RelatedSym( const messages::news::relatedsym& entry );
  void add_RoutingIds( const messages::news::routingids& entry );
  void add_LinesOfText( const messages::news::linesoftext& entry );
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_DECODER_QUICKFAST_NEWS_BUILDER_HPP */

