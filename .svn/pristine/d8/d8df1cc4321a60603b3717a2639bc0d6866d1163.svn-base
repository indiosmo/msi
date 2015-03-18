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
#include <msi/umdf/messages/security_status.hpp>
#include <msi/umdf/decoder/quickfast/security_status_builder.hpp>

namespace
{

using namespace apoena::msi::umdf::decoder::quickfast;
using namespace apoena::msi::umdf::messages;
using namespace QuickFAST;

struct message_container
{
  void on_message( const security_status& message )
  {
    message_ = message;
  }

  security_status message_;
};

}

BOOST_AUTO_TEST_SUITE( suite_security_status_builder )

BOOST_AUTO_TEST_CASE( test_builder_142 )
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
  id securitygroup_id( "SecurityGroup" );
  id securityid_id( "SecurityID" );
  id securityidsource_id( "SecurityIDSource" );
  id securityexchange_id( "SecurityExchange" );
  id tradingsessionsubid_id( "TradingSessionSubID" );
  id securitytradingstatus_id( "SecurityTradingStatus" );
  id tradingsessionid_id( "TradingSessionID" );
  id tradsesopentime_id( "TradSesOpenTime" );
  id transacttime_id( "TransactTime" );
  id tradedate_id( "TradeDate" );
  id securitytradingevent_id( "SecurityTradingEvent" );

  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( msgtype_id, Messages::FieldAscii::create( "f" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldUInt64::create( 52 ) );
  msg.addField( securitygroup_id, Messages::FieldAscii::create( "1151" ) );
  msg.addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  msg.addField( securityidsource_id, Messages::FieldUInt32::create( 8 ) );
  msg.addField( securityexchange_id, Messages::FieldAscii::create( "207" ) );
  msg.addField( tradingsessionsubid_id, Messages::FieldAscii::create( "625" ) );
  msg.addField( securitytradingstatus_id, Messages::FieldUInt32::create( 326 ) );
  msg.addField( tradingsessionid_id, Messages::FieldUInt32::create( 336 ) );
  msg.addField( tradsesopentime_id, Messages::FieldUInt64::create( 342 ) );
  msg.addField( transacttime_id, Messages::FieldUInt64::create( 60 ) );
  msg.addField( tradedate_id, Messages::FieldUInt32::create( 75 ) );
  msg.addField( securitytradingevent_id, Messages::FieldUInt32::create( 1174 ) );

  encoder.encodeMessage( destination, 142, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<security_status_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "f", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  security_status& m = container.message_;

  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "f" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, 52 );
  BOOST_CHECK( m.SecurityGroup().first );
  BOOST_CHECK_EQUAL( m.SecurityGroup().second, "1151" );
  BOOST_CHECK( m.SecurityID().first );
  BOOST_CHECK_EQUAL( m.SecurityID().second, 48 );
  BOOST_CHECK( m.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( m.SecurityIDSource().second, 8 );
  BOOST_CHECK( m.SecurityExchange().first );
  BOOST_CHECK_EQUAL( m.SecurityExchange().second, "207" );
  BOOST_CHECK( m.TradingSessionSubID().first );
  BOOST_CHECK_EQUAL( m.TradingSessionSubID().second, "625" );
  BOOST_CHECK( m.SecurityTradingStatus().first );
  BOOST_CHECK_EQUAL( m.SecurityTradingStatus().second, 326 );
  BOOST_CHECK( m.TradingSessionID().first );
  BOOST_CHECK_EQUAL( m.TradingSessionID().second, 336 );
  BOOST_CHECK( m.TradSesOpenTime().first );
  BOOST_CHECK_EQUAL( m.TradSesOpenTime().second, 342 );
  BOOST_CHECK( m.TransactTime().first );
  BOOST_CHECK_EQUAL( m.TransactTime().second, 60 );
  BOOST_CHECK( m.TradeDate().first );
  BOOST_CHECK_EQUAL( m.TradeDate().second, 75 );
  BOOST_CHECK( m.SecurityTradingEvent().first );
  BOOST_CHECK_EQUAL( m.SecurityTradingEvent().second, 1174 );

}

BOOST_AUTO_TEST_CASE( test_builder_134 )
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
  id securitygroup_id( "SecurityGroup" );
  id symbol_id( "Symbol" );
  id securityid_id( "SecurityID" );
  id securityidsource_id( "SecurityIDSource" );
  id securityexchange_id( "SecurityExchange" );
  id tradingsessionsubid_id( "TradingSessionSubID" );
  id securitytradingstatus_id( "SecurityTradingStatus" );
  id tradingsessionid_id( "TradingSessionID" );
  id tradsesopentime_id( "TradSesOpenTime" );
  id transacttime_id( "TransactTime" );
  id tradedate_id( "TradeDate" );
  id securitytradingevent_id( "SecurityTradingEvent" );

  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( messagetype_id, Messages::FieldAscii::create( "f" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldUInt64::create( 52 ) );
  msg.addField( securitygroup_id, Messages::FieldAscii::create( "1151" ) );
  msg.addField( symbol_id, Messages::FieldAscii::create( "55" ) );
  msg.addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  msg.addField( securityidsource_id, Messages::FieldUInt32::create( 8 ) );
  msg.addField( securityexchange_id, Messages::FieldAscii::create( "207" ) );
  msg.addField( tradingsessionsubid_id, Messages::FieldAscii::create( "625" ) );
  msg.addField( securitytradingstatus_id, Messages::FieldUInt32::create( 326 ) );
  msg.addField( tradingsessionid_id, Messages::FieldUInt32::create( 336 ) );
  msg.addField( tradsesopentime_id, Messages::FieldUInt64::create( 342 ) );
  msg.addField( transacttime_id, Messages::FieldUInt64::create( 60 ) );
  msg.addField( tradedate_id, Messages::FieldUInt32::create( 75 ) );
  msg.addField( securitytradingevent_id, Messages::FieldUInt32::create( 1174 ) );

  encoder.encodeMessage( destination, 134, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<security_status_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "f", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  security_status& m = container.message_;

  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "f" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, 52 );
  BOOST_CHECK( m.SecurityGroup().first );
  BOOST_CHECK_EQUAL( m.SecurityGroup().second, "1151" );
  BOOST_CHECK( m.Symbol().first );
  BOOST_CHECK_EQUAL( m.Symbol().second, "55" );
  BOOST_CHECK( m.SecurityID().first );
  BOOST_CHECK_EQUAL( m.SecurityID().second, 48 );
  BOOST_CHECK( m.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( m.SecurityIDSource().second, 8 );
  BOOST_CHECK( m.SecurityExchange().first );
  BOOST_CHECK_EQUAL( m.SecurityExchange().second, "207" );
  BOOST_CHECK( m.TradingSessionSubID().first );
  BOOST_CHECK_EQUAL( m.TradingSessionSubID().second, "625" );
  BOOST_CHECK( m.SecurityTradingStatus().first );
  BOOST_CHECK_EQUAL( m.SecurityTradingStatus().second, 326 );
  BOOST_CHECK( m.TradingSessionID().first );
  BOOST_CHECK_EQUAL( m.TradingSessionID().second, 336 );
  BOOST_CHECK( m.TradSesOpenTime().first );
  BOOST_CHECK_EQUAL( m.TradSesOpenTime().second, 342 );
  BOOST_CHECK( m.TransactTime().first );
  BOOST_CHECK_EQUAL( m.TransactTime().second, 60 );
  BOOST_CHECK( m.TradeDate().first );
  BOOST_CHECK_EQUAL( m.TradeDate().second, 75 );
  BOOST_CHECK( m.SecurityTradingEvent().first );
  BOOST_CHECK_EQUAL( m.SecurityTradingEvent().second, 1174 );

}

BOOST_AUTO_TEST_CASE( test_builder_125 )
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
  id tradedate_id( "TradeDate" );
  id securitygroup_id( "SecurityGroup" );
  id symbol_id( "Symbol" );
  id securityid_id( "SecurityID" );
  id securityidsource_id( "SecurityIDSource" );
  id securityexchange_id( "SecurityExchange" );
  id tradingsessionsubid_id( "TradingSessionSubID" );
  id securitytradingstatus_id( "SecurityTradingStatus" );
  id tradsesopentime_id( "TradSesOpenTime" );
  id transacttime_id( "TransactTime" );
  id securitytradingevent_id( "SecurityTradingEvent" );

  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( messagetype_id, Messages::FieldAscii::create( "f" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldUInt64::create( 52 ) );
  msg.addField( tradedate_id, Messages::FieldUInt32::create( 75 ) );
  msg.addField( securitygroup_id, Messages::FieldAscii::create( "1151" ) );
  msg.addField( symbol_id, Messages::FieldAscii::create( "55" ) );
  msg.addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  msg.addField( securityidsource_id, Messages::FieldUInt32::create( 8 ) );
  msg.addField( securityexchange_id, Messages::FieldAscii::create( "207" ) );
  msg.addField( tradingsessionsubid_id, Messages::FieldAscii::create( "625" ) );
  msg.addField( securitytradingstatus_id, Messages::FieldUInt32::create( 326 ) );
  msg.addField( tradsesopentime_id, Messages::FieldUInt64::create( 342 ) );
  msg.addField( transacttime_id, Messages::FieldUInt64::create( 60 ) );
  msg.addField( securitytradingevent_id, Messages::FieldUInt32::create( 1174 ) );

  encoder.encodeMessage( destination, 125, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<security_status_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "f", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  security_status& m = container.message_;

  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "f" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, 52 );
  BOOST_CHECK( m.TradeDate().first );
  BOOST_CHECK_EQUAL( m.TradeDate().second, 75 );
  BOOST_CHECK( m.SecurityGroup().first );
  BOOST_CHECK_EQUAL( m.SecurityGroup().second, "1151" );
  BOOST_CHECK( m.Symbol().first );
  BOOST_CHECK_EQUAL( m.Symbol().second, "55" );
  BOOST_CHECK( m.SecurityID().first );
  BOOST_CHECK_EQUAL( m.SecurityID().second, 48 );
  BOOST_CHECK( m.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( m.SecurityIDSource().second, 8 );
  BOOST_CHECK( m.SecurityExchange().first );
  BOOST_CHECK_EQUAL( m.SecurityExchange().second, "207" );
  BOOST_CHECK( m.TradingSessionSubID().first );
  BOOST_CHECK_EQUAL( m.TradingSessionSubID().second, "625" );
  BOOST_CHECK( m.SecurityTradingStatus().first );
  BOOST_CHECK_EQUAL( m.SecurityTradingStatus().second, 326 );
  BOOST_CHECK( m.TradSesOpenTime().first );
  BOOST_CHECK_EQUAL( m.TradSesOpenTime().second, 342 );
  BOOST_CHECK( m.TransactTime().first );
  BOOST_CHECK_EQUAL( m.TransactTime().second, 60 );
  BOOST_CHECK( m.SecurityTradingEvent().first );
  BOOST_CHECK_EQUAL( m.SecurityTradingEvent().second, 1174 );

}


BOOST_AUTO_TEST_SUITE_END()
