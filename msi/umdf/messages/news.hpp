#ifndef APOENA_MSI_UMDF_MESSAGES_NEWS_HPP
#define APOENA_MSI_UMDF_MESSAGES_NEWS_HPP

#include <bitset>
#include <utility>
#include <vector>
#include <msi/decimal/decimal.hpp>
#include <msi/umdf/messages/umdf_messages_export.hpp>
#include <msi/umdf/common/typedefs.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

class UMDF_MESSAGES_Export news
{
public:

  class UMDF_MESSAGES_Export relatedsym
  {
  public:

    enum field_index
    {
      ix_SecurityID = 0,
      ix_SecurityIDSource,
      ix_SecurityExchange,
      ix_field_count
    };

    void reset();

    std::pair<bool, uint64_t> SecurityID() const;
    void set_SecurityID( uint64_t val );

    std::pair<bool, uint32_t> SecurityIDSource() const;
    void set_SecurityIDSource( uint32_t val );

    std::pair<bool, const std::string&> SecurityExchange() const;
    void set_SecurityExchange( const std::string& val );

  private:
    std::bitset<ix_field_count> presence_map_;

    uint64_t SecurityID_;
    uint32_t SecurityIDSource_;
    std::string SecurityExchange_;

  };

  class UMDF_MESSAGES_Export routingids
  {
  public:

    enum field_index
    {
      ix_RoutingType = 0,
      ix_RoutingID,
      ix_field_count
    };

    void reset();

    std::pair<bool, uint32_t> RoutingType() const;
    void set_RoutingType( uint32_t val );

    std::pair<bool, const std::string&> RoutingID() const;
    void set_RoutingID( const std::string& val );

  private:
    std::bitset<ix_field_count> presence_map_;

    uint32_t RoutingType_;
    std::string RoutingID_;

  };

  class UMDF_MESSAGES_Export linesoftext
  {
  public:

    enum field_index
    {
      ix_Text = 0,
      ix_EncodedTextLen,
      ix_EncodedText,
      ix_field_count
    };

    void reset();

    std::pair<bool, const std::string&> Text() const;
    void set_Text( const std::string& val );

    std::pair<bool, uint32_t> EncodedTextLen() const;
    void set_EncodedTextLen( uint32_t val );

    std::pair<bool, const std::string&> EncodedText() const;
    void set_EncodedText( const std::string& val );

  private:
    std::bitset<ix_field_count> presence_map_;

    std::string Text_;
    uint32_t EncodedTextLen_;
    std::string EncodedText_;

  };

  enum field_index
  {
    ix_ApplVerID = 0,
    ix_MsgType,
    ix_MsgSeqNum,
    ix_SendingTime,
    ix_OrigTime,
    ix_NewsSource,
    ix_NewsID,
    ix_LanguageCode,
    ix_Headline,
    ix_URLLink,
    ix_EncodedHeadlineLen,
    ix_EncodedHeadline,
    ix_RelatedSym,
    ix_RoutingIds,
    ix_LinesOfText,
    ix_field_count
  };

  void reset();

  std::pair<bool, const std::string&> ApplVerID() const;
  void set_ApplVerID( const std::string& val );

  std::pair<bool, const std::string&> MsgType() const;
  void set_MsgType( const std::string& val );

  std::pair<bool, uint32_t> MsgSeqNum() const;
  void set_MsgSeqNum( uint32_t val );

  std::pair<bool, uint64_t> SendingTime() const;
  void set_SendingTime( uint64_t val );

  std::pair<bool, uint64_t> OrigTime() const;
  void set_OrigTime( uint64_t val );

  std::pair<bool, const std::string&> NewsSource() const;
  void set_NewsSource( const std::string& val );

  std::pair<bool, const std::string&> NewsID() const;
  void set_NewsID( const std::string& val );

  std::pair<bool, const std::string&> LanguageCode() const;
  void set_LanguageCode( const std::string& val );

  std::pair<bool, const std::string&> Headline() const;
  void set_Headline( const std::string& val );

  std::pair<bool, const std::string&> URLLink() const;
  void set_URLLink( const std::string& val );

  std::pair<bool, uint32_t> EncodedHeadlineLen() const;
  void set_EncodedHeadlineLen( uint32_t val );

  std::pair<bool, const std::string&> EncodedHeadline() const;
  void set_EncodedHeadline( const std::string& val );

  const std::vector<relatedsym>& RelatedSym() const;
  void add_RelatedSym( const relatedsym& val );

  const std::vector<routingids>& RoutingIds() const;
  void add_RoutingIds( const routingids& val );

  const std::vector<linesoftext>& LinesOfText() const;
  void add_LinesOfText( const linesoftext& val );

private:
  std::bitset<ix_field_count> presence_map_;

  std::string ApplVerID_;
  std::string MsgType_;
  uint32_t MsgSeqNum_;
  uint64_t SendingTime_;
  uint64_t OrigTime_;
  std::string NewsSource_;
  std::string NewsID_;
  std::string LanguageCode_;
  std::string Headline_;
  std::string URLLink_;
  uint32_t EncodedHeadlineLen_;
  std::string EncodedHeadline_;
  std::vector<relatedsym> RelatedSym_;
  std::vector<routingids> RoutingIds_;
  std::vector<linesoftext> LinesOfText_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_MESSAGES_NEWS_HPP */

