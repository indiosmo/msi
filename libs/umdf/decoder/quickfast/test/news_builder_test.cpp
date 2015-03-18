#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp>
#define BOOST_TEST_NO_MAIN umdf_quickfast_decoder_test
#include <boost/test/unit_test.hpp>

#include <functional>
#include <Codecs/Encoder.h>
#include <Codecs/Decoder.h>
#include <Codecs/DataDestination.h>
#include <Codecs/DataSourceString.h>
#include <Common/Types.h>
#include <Messages/Message.h>
#include <Messages/FieldIdentity.h>
#include <Messages/FieldInt32.h>
#include <Messages/FieldUInt32.h>
#include <Messages/FieldInt64.h>
#include <Messages/FieldUInt64.h>
#include <Messages/FieldAscii.h>
#include <Messages/FieldByteVector.h>
#include <Messages/FieldDecimal.h>
#include <Messages/FieldGroup.h>
#include <Messages/FieldSequence.h>
#include <Messages/FieldUtf8.h>
#include <Messages/Sequence.h>

#include <msi/decimal/decimal.hpp>
#include <msi/umdf/messages/field_id.hpp>
#include <msi/umdf/decoder/quickfast/builder_selector.hpp>
#include <msi/umdf/messages/news.hpp>
#include <msi/umdf/decoder/quickfast/news_builder.hpp>

namespace
{

using namespace apoena::msi::umdf::decoder::quickfast;
using namespace apoena::msi::umdf::messages;
using namespace QuickFAST;

struct message_container
{
  void on_message( const news& message )
  {
    message_ = message;
  }

  news message_;
};

}

BOOST_AUTO_TEST_SUITE( suite_news_builder )

BOOST_AUTO_TEST_CASE( test_builder_143 )
{
  std::string xml( std::getenv( "MSI_ROOT" ) );
  xml += "/resources/templates-PUMA.xml";
  std::ifstream template_file( xml, std::ifstream::binary );

  BOOST_REQUIRE( template_file.good() ) ;

  Codecs::XMLTemplateParser parser;
  Codecs::TemplateRegistryPtr template_registry = parser.parse( template_file );

  Codecs::Encoder encoder( template_registry );
  Codecs::DataDestination destination;

  typedef Messages::FieldIdentity id;

  Messages::Message msg( template_registry->maxFieldCount() );

  id applverid_id( "ApplVerID" );
  id msgtype_id( "MsgType" );
  id msgseqnum_id( "MsgSeqNum" );
  id sendingtime_id( "SendingTime" );
  id origtime_id( "OrigTime" );
  id newssource_id( "NewsSource" );
  id newsid_id( "NewsID" );
  id languagecode_id( "LanguageCode" );
  id headline_id( "Headline" );
  id urllink_id( "URLLink" );
  id encodedheadlinelen_id( "EncodedHeadlineLen" );
  id encodedheadline_id( "EncodedHeadline" );
  id relatedsym_id( "RelatedSym" );
  id linesoftext_id( "LinesOfText" );
  id norelatedsym_id( "NoRelatedSym" );
  id securityid_id( "SecurityID" );
  id securityidsource_id( "SecurityIDSource" );
  id securityexchange_id( "SecurityExchange" );
  id nolinesoftext_id( "NoLinesOfText" );
  id text_id( "Text" );
  id encodedtextlen_id( "EncodedTextLen" );
  id encodedtext_id( "EncodedText" );

  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( msgtype_id, Messages::FieldAscii::create( "B" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldUInt64::create( 52 ) );
  msg.addField( origtime_id, Messages::FieldUInt64::create( 42 ) );
  msg.addField( newssource_id, Messages::FieldAscii::create( "6940" ) );
  msg.addField( newsid_id, Messages::FieldAscii::create( "1472" ) );
  msg.addField( languagecode_id, Messages::FieldAscii::create( "1474" ) );
  msg.addField( headline_id, Messages::FieldAscii::create( "148" ) );
  msg.addField( urllink_id, Messages::FieldAscii::create( "149" ) );
  msg.addField( encodedheadlinelen_id, Messages::FieldUInt32::create( 358 ) );
  msg.addField( encodedheadline_id, Messages::FieldAscii::create( "359" ) );

  Messages::SequencePtr RelatedSym_seq( new Messages::Sequence( relatedsym_id, 1 ) );
  Messages::FieldSetPtr RelatedSym( new Messages::FieldSet( 3 ) );

  RelatedSym->addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  RelatedSym->addField( securityidsource_id, Messages::FieldUInt32::create( 8 ) );
  RelatedSym->addField( securityexchange_id, Messages::FieldAscii::create( "207" ) );

  RelatedSym_seq->addEntry( RelatedSym );

  Messages::SequencePtr LinesOfText_seq( new Messages::Sequence( linesoftext_id, 1 ) );
  Messages::FieldSetPtr LinesOfText( new Messages::FieldSet( 3 ) );

  LinesOfText->addField( text_id, Messages::FieldAscii::create( "58" ) );
  LinesOfText->addField( encodedtextlen_id, Messages::FieldUInt32::create( 354 ) );
  LinesOfText->addField( encodedtext_id, Messages::FieldAscii::create( "355" ) );

  LinesOfText_seq->addEntry( LinesOfText );

  msg.addField( relatedsym_id, Messages::FieldSequence::create( RelatedSym_seq ) );

  msg.addField( linesoftext_id, Messages::FieldSequence::create( LinesOfText_seq ) );

  encoder.encodeMessage( destination, 143, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<news_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "B", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  news& m = container.message_;

  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "B" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, 52 );
  BOOST_CHECK( m.OrigTime().first );
  BOOST_CHECK_EQUAL( m.OrigTime().second, 42 );
  BOOST_CHECK( m.NewsSource().first );
  BOOST_CHECK_EQUAL( m.NewsSource().second, "6940" );
  BOOST_CHECK( m.NewsID().first );
  BOOST_CHECK_EQUAL( m.NewsID().second, "1472" );
  BOOST_CHECK( m.LanguageCode().first );
  BOOST_CHECK_EQUAL( m.LanguageCode().second, "1474" );
  BOOST_CHECK( m.Headline().first );
  BOOST_CHECK_EQUAL( m.Headline().second, "148" );
  BOOST_CHECK( m.URLLink().first );
  BOOST_CHECK_EQUAL( m.URLLink().second, "149" );
  BOOST_CHECK( m.EncodedHeadlineLen().first );
  BOOST_CHECK_EQUAL( m.EncodedHeadlineLen().second, 358 );
  BOOST_CHECK( m.EncodedHeadline().first );
  BOOST_CHECK_EQUAL( m.EncodedHeadline().second, "359" );

  BOOST_REQUIRE_EQUAL( m.RelatedSym().size(), 1 );
  const news::relatedsym& RelatedSym_msg = m.RelatedSym()[0];

  BOOST_CHECK( RelatedSym_msg.SecurityID().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityID().second, 48 );
  BOOST_CHECK( RelatedSym_msg.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityIDSource().second, 8 );
  BOOST_CHECK( RelatedSym_msg.SecurityExchange().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityExchange().second, "207" );

  BOOST_REQUIRE_EQUAL( m.LinesOfText().size(), 1 );
  const news::linesoftext& LinesOfText_msg = m.LinesOfText()[0];

  BOOST_CHECK( LinesOfText_msg.Text().first );
  BOOST_CHECK_EQUAL( LinesOfText_msg.Text().second, "58" );
  BOOST_CHECK( LinesOfText_msg.EncodedTextLen().first );
  BOOST_CHECK_EQUAL( LinesOfText_msg.EncodedTextLen().second, 354 );
  BOOST_CHECK( LinesOfText_msg.EncodedText().first );
  BOOST_CHECK_EQUAL( LinesOfText_msg.EncodedText().second, "355" );

}

BOOST_AUTO_TEST_CASE( test_builder_137 )
{
  std::string xml( std::getenv( "MSI_ROOT" ) );
  xml += "/resources/templates-PUMA.xml";
  std::ifstream template_file( xml, std::ifstream::binary );

  BOOST_REQUIRE( template_file.good() ) ;

  Codecs::XMLTemplateParser parser;
  Codecs::TemplateRegistryPtr template_registry = parser.parse( template_file );

  Codecs::Encoder encoder( template_registry );
  Codecs::DataDestination destination;

  typedef Messages::FieldIdentity id;

  Messages::Message msg( template_registry->maxFieldCount() );

  id applverid_id( "ApplVerID" );
  id messagetype_id( "MessageType" );
  id msgseqnum_id( "MsgSeqNum" );
  id sendingtime_id( "SendingTime" );
  id origtime_id( "OrigTime" );
  id newssource_id( "NewsSource" );
  id newsid_id( "NewsID" );
  id languagecode_id( "LanguageCode" );
  id headline_id( "Headline" );
  id urllink_id( "URLLink" );
  id encodedheadlinelen_id( "EncodedHeadlineLen" );
  id encodedheadline_id( "EncodedHeadline" );
  id relatedsym_id( "RelatedSym" );
  id linesoftext_id( "LinesOfText" );
  id norelatedsym_id( "NoRelatedSym" );
  id securityid_id( "SecurityID" );
  id securityidsource_id( "SecurityIDSource" );
  id securityexchange_id( "SecurityExchange" );
  id nolinesoftext_id( "NoLinesOfText" );
  id text_id( "Text" );
  id encodedtextlen_id( "EncodedTextLen" );
  id encodedtext_id( "EncodedText" );

  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( messagetype_id, Messages::FieldAscii::create( "B" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldUInt64::create( 52 ) );
  msg.addField( origtime_id, Messages::FieldUInt64::create( 42 ) );
  msg.addField( newssource_id, Messages::FieldAscii::create( "6940" ) );
  msg.addField( newsid_id, Messages::FieldAscii::create( "1472" ) );
  msg.addField( languagecode_id, Messages::FieldAscii::create( "1474" ) );
  msg.addField( headline_id, Messages::FieldAscii::create( "148" ) );
  msg.addField( urllink_id, Messages::FieldAscii::create( "149" ) );
  msg.addField( encodedheadlinelen_id, Messages::FieldUInt32::create( 358 ) );
  msg.addField( encodedheadline_id, Messages::FieldAscii::create( "359" ) );

  Messages::SequencePtr RelatedSym_seq( new Messages::Sequence( relatedsym_id, 1 ) );
  Messages::FieldSetPtr RelatedSym( new Messages::FieldSet( 3 ) );

  RelatedSym->addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  RelatedSym->addField( securityidsource_id, Messages::FieldUInt32::create( 8 ) );
  RelatedSym->addField( securityexchange_id, Messages::FieldAscii::create( "207" ) );

  RelatedSym_seq->addEntry( RelatedSym );

  Messages::SequencePtr LinesOfText_seq( new Messages::Sequence( linesoftext_id, 1 ) );
  Messages::FieldSetPtr LinesOfText( new Messages::FieldSet( 3 ) );

  LinesOfText->addField( text_id, Messages::FieldAscii::create( "58" ) );
  LinesOfText->addField( encodedtextlen_id, Messages::FieldUInt32::create( 354 ) );
  LinesOfText->addField( encodedtext_id, Messages::FieldAscii::create( "355" ) );

  LinesOfText_seq->addEntry( LinesOfText );

  msg.addField( relatedsym_id, Messages::FieldSequence::create( RelatedSym_seq ) );

  msg.addField( linesoftext_id, Messages::FieldSequence::create( LinesOfText_seq ) );

  encoder.encodeMessage( destination, 137, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<news_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "B", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  news& m = container.message_;

  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "B" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, 52 );
  BOOST_CHECK( m.OrigTime().first );
  BOOST_CHECK_EQUAL( m.OrigTime().second, 42 );
  BOOST_CHECK( m.NewsSource().first );
  BOOST_CHECK_EQUAL( m.NewsSource().second, "6940" );
  BOOST_CHECK( m.NewsID().first );
  BOOST_CHECK_EQUAL( m.NewsID().second, "1472" );
  BOOST_CHECK( m.LanguageCode().first );
  BOOST_CHECK_EQUAL( m.LanguageCode().second, "1474" );
  BOOST_CHECK( m.Headline().first );
  BOOST_CHECK_EQUAL( m.Headline().second, "148" );
  BOOST_CHECK( m.URLLink().first );
  BOOST_CHECK_EQUAL( m.URLLink().second, "149" );
  BOOST_CHECK( m.EncodedHeadlineLen().first );
  BOOST_CHECK_EQUAL( m.EncodedHeadlineLen().second, 358 );
  BOOST_CHECK( m.EncodedHeadline().first );
  BOOST_CHECK_EQUAL( m.EncodedHeadline().second, "359" );

  BOOST_REQUIRE_EQUAL( m.RelatedSym().size(), 1 );
  const news::relatedsym& RelatedSym_msg = m.RelatedSym()[0];

  BOOST_CHECK( RelatedSym_msg.SecurityID().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityID().second, 48 );
  BOOST_CHECK( RelatedSym_msg.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityIDSource().second, 8 );
  BOOST_CHECK( RelatedSym_msg.SecurityExchange().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityExchange().second, "207" );

  BOOST_REQUIRE_EQUAL( m.LinesOfText().size(), 1 );
  const news::linesoftext& LinesOfText_msg = m.LinesOfText()[0];

  BOOST_CHECK( LinesOfText_msg.Text().first );
  BOOST_CHECK_EQUAL( LinesOfText_msg.Text().second, "58" );
  BOOST_CHECK( LinesOfText_msg.EncodedTextLen().first );
  BOOST_CHECK_EQUAL( LinesOfText_msg.EncodedTextLen().second, 354 );
  BOOST_CHECK( LinesOfText_msg.EncodedText().first );
  BOOST_CHECK_EQUAL( LinesOfText_msg.EncodedText().second, "355" );

}

BOOST_AUTO_TEST_CASE( test_builder_120 )
{
  std::string xml( std::getenv( "MSI_ROOT" ) );
  xml += "/resources/templates-PUMA.xml";
  std::ifstream template_file( xml, std::ifstream::binary );

  BOOST_REQUIRE( template_file.good() ) ;

  Codecs::XMLTemplateParser parser;
  Codecs::TemplateRegistryPtr template_registry = parser.parse( template_file );

  Codecs::Encoder encoder( template_registry );
  Codecs::DataDestination destination;

  typedef Messages::FieldIdentity id;

  Messages::Message msg( template_registry->maxFieldCount() );

  id applverid_id( "ApplVerID" );
  id messagetype_id( "MessageType" );
  id msgseqnum_id( "MsgSeqNum" );
  id sendingtime_id( "SendingTime" );
  id origtime_id( "OrigTime" );
  id newssource_id( "NewsSource" );
  id languagecode_id( "LanguageCode" );
  id headline_id( "Headline" );
  id urllink_id( "URLLink" );
  id relatedsym_id( "RelatedSym" );
  id routingids_id( "RoutingIds" );
  id linesoftext_id( "LinesOfText" );
  id norelatedsym_id( "NoRelatedSym" );
  id securityid_id( "SecurityID" );
  id securityidsource_id( "SecurityIDSource" );
  id securityexchange_id( "SecurityExchange" );
  id noroutingids_id( "NoRoutingIDs" );
  id routingtype_id( "RoutingType" );
  id routingid_id( "RoutingID" );
  id nolinesoftext_id( "NoLinesOfText" );
  id text_id( "text" );
  id encodedtextlen_id( "EncodedTextLen" );
  id encodedtext_id( "EncodedText" );

  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( messagetype_id, Messages::FieldAscii::create( "B" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldUInt64::create( 52 ) );
  msg.addField( origtime_id, Messages::FieldUInt64::create( 42 ) );
  msg.addField( newssource_id, Messages::FieldAscii::create( "6940" ) );
  msg.addField( languagecode_id, Messages::FieldAscii::create( "1474" ) );
  msg.addField( headline_id, Messages::FieldAscii::create( "148" ) );
  msg.addField( urllink_id, Messages::FieldAscii::create( "149" ) );

  Messages::SequencePtr RelatedSym_seq( new Messages::Sequence( relatedsym_id, 1 ) );
  Messages::FieldSetPtr RelatedSym( new Messages::FieldSet( 3 ) );

  RelatedSym->addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  RelatedSym->addField( securityidsource_id, Messages::FieldUInt32::create( 8 ) );
  RelatedSym->addField( securityexchange_id, Messages::FieldAscii::create( "207" ) );

  RelatedSym_seq->addEntry( RelatedSym );

  Messages::SequencePtr RoutingIds_seq( new Messages::Sequence( routingids_id, 1 ) );
  Messages::FieldSetPtr RoutingIds( new Messages::FieldSet( 2 ) );

  RoutingIds->addField( routingtype_id, Messages::FieldUInt32::create( 216 ) );
  RoutingIds->addField( routingid_id, Messages::FieldAscii::create( "217" ) );

  RoutingIds_seq->addEntry( RoutingIds );

  Messages::SequencePtr LinesOfText_seq( new Messages::Sequence( linesoftext_id, 1 ) );
  Messages::FieldSetPtr LinesOfText( new Messages::FieldSet( 3 ) );

  LinesOfText->addField( text_id, Messages::FieldAscii::create( "58" ) );
  LinesOfText->addField( encodedtextlen_id, Messages::FieldUInt32::create( 354 ) );
  LinesOfText->addField( encodedtext_id, Messages::FieldAscii::create( "355" ) );

  LinesOfText_seq->addEntry( LinesOfText );

  msg.addField( relatedsym_id, Messages::FieldSequence::create( RelatedSym_seq ) );

  msg.addField( routingids_id, Messages::FieldSequence::create( RoutingIds_seq ) );

  msg.addField( linesoftext_id, Messages::FieldSequence::create( LinesOfText_seq ) );

  encoder.encodeMessage( destination, 120, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<news_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "B", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  news& m = container.message_;

  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "B" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, 52 );
  BOOST_CHECK( m.OrigTime().first );
  BOOST_CHECK_EQUAL( m.OrigTime().second, 42 );
  BOOST_CHECK( m.NewsSource().first );
  BOOST_CHECK_EQUAL( m.NewsSource().second, "6940" );
  BOOST_CHECK( m.LanguageCode().first );
  BOOST_CHECK_EQUAL( m.LanguageCode().second, "1474" );
  BOOST_CHECK( m.Headline().first );
  BOOST_CHECK_EQUAL( m.Headline().second, "148" );
  BOOST_CHECK( m.URLLink().first );
  BOOST_CHECK_EQUAL( m.URLLink().second, "149" );

  BOOST_REQUIRE_EQUAL( m.RelatedSym().size(), 1 );
  const news::relatedsym& RelatedSym_msg = m.RelatedSym()[0];

  BOOST_CHECK( RelatedSym_msg.SecurityID().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityID().second, 48 );
  BOOST_CHECK( RelatedSym_msg.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityIDSource().second, 8 );
  BOOST_CHECK( RelatedSym_msg.SecurityExchange().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityExchange().second, "207" );

  BOOST_REQUIRE_EQUAL( m.RoutingIds().size(), 1 );
  const news::routingids& RoutingIds_msg = m.RoutingIds()[0];

  BOOST_CHECK( RoutingIds_msg.RoutingType().first );
  BOOST_CHECK_EQUAL( RoutingIds_msg.RoutingType().second, 216 );
  BOOST_CHECK( RoutingIds_msg.RoutingID().first );
  BOOST_CHECK_EQUAL( RoutingIds_msg.RoutingID().second, "217" );

  BOOST_REQUIRE_EQUAL( m.LinesOfText().size(), 1 );
  const news::linesoftext& LinesOfText_msg = m.LinesOfText()[0];

  BOOST_CHECK( LinesOfText_msg.Text().first );
  BOOST_CHECK_EQUAL( LinesOfText_msg.Text().second, "58" );
  BOOST_CHECK( LinesOfText_msg.EncodedTextLen().first );
  BOOST_CHECK_EQUAL( LinesOfText_msg.EncodedTextLen().second, 354 );
  BOOST_CHECK( LinesOfText_msg.EncodedText().first );
  BOOST_CHECK_EQUAL( LinesOfText_msg.EncodedText().second, "355" );

}


BOOST_AUTO_TEST_SUITE_END()
