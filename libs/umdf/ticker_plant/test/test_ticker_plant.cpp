#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp>
#define BOOST_TEST_NO_MAIN umdf_ticker_plant_test
#include <boost/test/unit_test.hpp>

#include <functional>
#include <memory>
#include <vector>
#include <iostream>
#include <thread>
#include <boost/asio.hpp>

#include <msi/logging/log.hpp>
#include <msi/logging/console_logger_factory.hpp>

#include <msi/byte_conversion.hpp>
#include <msi/decimal/decimal.hpp>
#include <msi/network/tcp/client.hpp>
#include <msi/network/multicast_sender.hpp>
#include <msi/umdf/receiver/receiver.hpp>
#include <msi/umdf/recovery/null_recovery_service.hpp>
#include <msi/umdf/adapter/adapter.hpp>
#include <msi/umdf/ticker_plant/ticker_plant.hpp>
#include <msi/marketdata/messages/messages.hpp>
#include <msi/marketdata/serialization/serializers.hpp>
#include <msi/marketdata/messages/message_types.hpp>

//QuickFAST includes
#include <Codecs/Encoder.h>
#include <Codecs/DataDestination.h>
#include <Codecs/DataSourceString.h>
#include <Common/Types.h>
#include <Common/WorkingBuffer.h>
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

namespace
{

using namespace apoena::msi;
using namespace QuickFAST;
namespace ph = std::placeholders;

struct handler
{
  void handle_connected( network::tcp::client& )
  {
    connected_ = true;
  }

  void handle_read( const unsigned char* data, std::size_t length )
  {
    service s = static_cast<service>( byte_conversion::be_to_uint32( data ) );
    BOOST_REQUIRE_EQUAL( s, service_marketdata );
    marketdata::messages::message_type m = static_cast<marketdata::messages::message_type>(
        byte_conversion::be_to_uint32( data + message_offset_message_type ) );
    BOOST_REQUIRE_EQUAL( m, marketdata::messages::message_bid );

    bid_serializer_.deserialize( data + message_offset_data, bid_ );
  }

  bool connected_ = false;

  marketdata::serialization::bid_serializer bid_serializer_;
  marketdata::messages::bid bid_;
};

}

BOOST_AUTO_TEST_SUITE( suite_ticker_plant )

BOOST_AUTO_TEST_CASE( test_ticker_plant )
{
  using namespace apoena::msi::logging;

  std::shared_ptr<console_logger_factory> factory( new console_logger_factory( Info ) );

  log::register_factory( factory );

  //instantiate receiver to receive from the source
  boost::asio::io_service io_service_plant;

  auto recovery = std::make_shared<umdf::recovery::null_recovery_service>();

  auto receiver = std::make_shared<umdf::receiver::receiver>(
                    io_service_plant, "test", umdf::receiver::channel_type_cyclic, recovery );
  receiver->add_multicast_group( "233.0.0.1", 21001, 1420 );

  //instantiate umdf adapter decoder
  std::string xml( std::getenv( "MSI_ROOT" ) );
  xml += "/resources/templates-PUMA.xml";
  auto adapter = std::make_shared<umdf::adapter::adapter>( xml );
  receiver->register_on_receive_callback( std::bind(
      &umdf::adapter::adapter::decode, adapter.get(), ph::_1, ph::_2 ) );

  //instantiate ticker plant
  umdf::ticker_plant::ticker_plant plant(
    io_service_plant, "127.0.0.1", "21000", receiver, adapter );

  plant.run();

  //run ticker plant on a thread;
  std::thread io_thread_plant( boost::bind( &boost::asio::io_service::run, &io_service_plant ) );

  std::chrono::milliseconds wait( 500 );
  std::this_thread::sleep_for( wait );

  //instantiate tcp client
  boost::asio::io_service io_service_client;
  network::tcp::client client( io_service_client, "127.0.0.1", "21000" );

  handler h;

  client.register_on_connected_callback( std::bind(
      &handler::handle_connected, &h, ph::_1 ) );

  client.register_on_read_callback( std::bind(
                                      &handler::handle_read, &h, ph::_1, ph::_2 ) );

  client.connect();

  std::thread io_thread_client( boost::bind( &boost::asio::io_service::run, &io_service_client ) );

  std::this_thread::sleep_for( wait );

  //instantiate multicast source
  boost::asio::io_service io_service_source;
  auto io_work_source = std::make_unique<boost::asio::io_service::work>( io_service_source );

  network::multicast_sender source( "233.0.0.1", 21001, io_service_source );

  std::thread io_thread_source( boost::bind( &boost::asio::io_service::run, &io_service_source ) );

  //send packets from source
  std::ifstream template_file( xml, std::ifstream::binary );

  BOOST_REQUIRE( template_file.good() );

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
  id tradedate_id( "TradeDate" );
  id mdentries_id( "MDEntries" );
  id nomdentries_id( "NoMDEntries" );
  id mdupdateaction_id( "MDUpdateAction" );
  id mdentrytype_id( "MDEntryType" );
  id securityidsource_id( "SecurityIDSource" );
  id securityexchange_id( "SecurityExchange" );
  id securityid_id( "SecurityID" );
  id rptseq_id( "RptSeq" );
  id quotecondition_id( "QuoteCondition" );
  id mdentrypx_id( "MDEntryPx" );
  id mdentryinterestrate_id( "MDEntryInterestRate" );
  id numberoforders_id( "NumberOfOrders" );
  id pricetype_id( "PriceType" );
  id mdentrytime_id( "MDEntryTime" );
  id mdentrysize_id( "MDEntrySize" );
  id mdentrydate_id( "MDEntryDate" );
  id mdinsertdate_id( "MDInsertDate" );
  id mdinserttime_id( "MDInsertTime" );
  id mdstreamid_id( "MDStreamID" );
  id currency_id( "Currency" );
  id netchgprevday_id( "NetChgPrevDay" );
  id sellerdays_id( "SellerDays" );
  id tradevolume_id( "TradeVolume" );
  id tickdirection_id( "TickDirection" );
  id tradecondition_id( "TradeCondition" );
  id tradingsessionid_id( "TradingSessionID" );
  id openclosesettlflag_id( "OpenCloseSettlFlag" );
  id orderid_id( "OrderID" );
  id tradeid_id( "TradeID" );
  id mdentrybuyer_id( "MDEntryBuyer" );
  id mdentryseller_id( "MDEntrySeller" );
  id mdentrypositionno_id( "MDEntryPositionNo" );
  id settpricetype_id( "SettPriceType" );
  id lasttradedate_id( "LastTradeDate" );
  id priceadjustmentmethod_id( "PriceAdjustmentMethod" );
  id pricebandtype_id( "PriceBandType" );
  id pricelimittype_id( "PriceLimitType" );
  id lowlimitprice_id( "LowLimitPrice" );
  id highlimitprice_id( "HighLimitPrice" );
  id tradingreferenceprice_id( "TradingReferencePrice" );
  id pricebandmidpointpricetype_id( "PriceBandMidpointPriceType" );
  id avgdailytradedqty_id( "AvgDailyTradedQty" );
  id expiredate_id( "ExpireDate" );
  id earlytermination_id( "EarlyTermination" );
  id maxtradevol_id( "MaxTradeVol" );
  id underlyings_id( "Underlyings" );
  id indexseq_id( "IndexSeq" );
  id nounderlyings_id( "NoUnderlyings" );
  id underlyingsecurityid_id( "UnderlyingSecurityID" );
  id underlyingsecurityidsource_id( "UnderlyingSecurityIDSource" );
  id underlyingsecurityexchange_id( "UnderlyingSecurityExchange" );
  id underlyingpx_id( "UnderlyingPx" );
  id underlyingpxtype_id( "UnderlyingPxType" );

  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( msgtype_id, Messages::FieldAscii::create( "X" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldUInt64::create( 52 ) );
  msg.addField( tradedate_id, Messages::FieldUInt32::create( 75 ) );

  Messages::SequencePtr MDEntries_seq( new Messages::Sequence( mdentries_id, 1 ) );
  Messages::FieldSetPtr MDEntries( new Messages::FieldSet( 45 ) );

  MDEntries->addField( mdupdateaction_id, Messages::FieldUInt32::create( 279 ) );
  MDEntries->addField( securityidsource_id, Messages::FieldUInt32::create( 8 ) );
  MDEntries->addField( securityexchange_id, Messages::FieldAscii::create( "BVMF" ) );
  MDEntries->addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  MDEntries->addField( rptseq_id, Messages::FieldUInt32::create( 83 ) );
  MDEntries->addField( quotecondition_id, Messages::FieldAscii::create( "276" ) );
  MDEntries->addField( mdentrypx_id, Messages::FieldDecimal::create( 270, 0 ) );
  MDEntries->addField( mdentryinterestrate_id, Messages::FieldDecimal::create( 37014, 0 ) );
  MDEntries->addField( numberoforders_id, Messages::FieldUInt32::create( 346 ) );
  MDEntries->addField( pricetype_id, Messages::FieldAscii::create( "423" ) );
  MDEntries->addField( mdentrytime_id, Messages::FieldUInt32::create( 273 ) );
  MDEntries->addField( mdentrysize_id, Messages::FieldInt64::create( 271 ) );
  MDEntries->addField( mdentrydate_id, Messages::FieldUInt32::create( 272 ) );
  MDEntries->addField( mdinsertdate_id, Messages::FieldUInt32::create( 37016 ) );
  MDEntries->addField( mdinserttime_id, Messages::FieldUInt32::create( 37017 ) );
  MDEntries->addField( currency_id, Messages::FieldAscii::create( "15" ) );
  MDEntries->addField( netchgprevday_id, Messages::FieldDecimal::create( 451, 0 ) );
  MDEntries->addField( sellerdays_id, Messages::FieldUInt32::create( 287 ) );
  MDEntries->addField( tradevolume_id, Messages::FieldUInt64::create( 1020 ) );
  MDEntries->addField( tickdirection_id, Messages::FieldAscii::create( "274" ) );
  MDEntries->addField( tradecondition_id, Messages::FieldAscii::create( "277" ) );
  MDEntries->addField( tradingsessionid_id, Messages::FieldUInt32::create( 336 ) );
  MDEntries->addField( openclosesettlflag_id, Messages::FieldUInt32::create( 286 ) );
  MDEntries->addField( orderid_id, Messages::FieldAscii::create( "37" ) );
  MDEntries->addField( tradeid_id, Messages::FieldAscii::create( "1003" ) );
  MDEntries->addField( mdentrybuyer_id, Messages::FieldAscii::create( "288" ) );
  MDEntries->addField( mdentryseller_id, Messages::FieldAscii::create( "289" ) );
  MDEntries->addField( mdentrypositionno_id, Messages::FieldUInt32::create( 290 ) );
  MDEntries->addField( settpricetype_id, Messages::FieldUInt32::create( 731 ) );
  MDEntries->addField( lasttradedate_id, Messages::FieldUInt32::create( 9325 ) );
  MDEntries->addField( priceadjustmentmethod_id, Messages::FieldUInt32::create( 37013 ) );
  MDEntries->addField( pricebandtype_id, Messages::FieldAscii::create( "6939" ) );
  MDEntries->addField( pricelimittype_id, Messages::FieldUInt32::create( 1306 ) );
  MDEntries->addField( lowlimitprice_id, Messages::FieldDecimal::create( 1148, 0 ) );
  MDEntries->addField( highlimitprice_id, Messages::FieldDecimal::create( 1149, 0 ) );
  MDEntries->addField( tradingreferenceprice_id, Messages::FieldDecimal::create( 1150, 0 ) );
  MDEntries->addField( pricebandmidpointpricetype_id, Messages::FieldUInt32::create( 37008 ) );
  MDEntries->addField( avgdailytradedqty_id, Messages::FieldUInt64::create( 37003 ) );
  MDEntries->addField( expiredate_id, Messages::FieldUInt64::create( 432 ) );
  MDEntries->addField( earlytermination_id, Messages::FieldUInt64::create( 37019 ) );
  MDEntries->addField( maxtradevol_id, Messages::FieldUInt64::create( 1140 ) );
  MDEntries->addField( indexseq_id, Messages::FieldUInt64::create( 37100 ) );

  Messages::SequencePtr Underlyings_seq( new Messages::Sequence( underlyings_id, 1 ) );
  Messages::FieldSetPtr Underlyings( new Messages::FieldSet( 5 ) );

  Underlyings->addField( underlyingsecurityid_id, Messages::FieldUInt64::create( 309 ) );
  Underlyings->addField( underlyingsecurityidsource_id, Messages::FieldUInt32::create( 8 ) );
  Underlyings->addField( underlyingsecurityexchange_id, Messages::FieldAscii::create( "BVMF" ) );
  Underlyings->addField( underlyingpx_id, Messages::FieldDecimal::create( 810, 0 ) );
  Underlyings->addField( underlyingpxtype_id, Messages::FieldUInt32::create( 37018 ) );

  Underlyings_seq->addEntry( Underlyings );

  MDEntries->addField( underlyings_id, Messages::FieldSequence::create( Underlyings_seq ) );

  std::set<std::string> types = { "0", /* "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "c", "g", "h" */};

  for ( auto type : types )
  {
    MDEntries->addField( mdentrytype_id, Messages::FieldAscii::create( "0" ) );
    MDEntries_seq->addEntry( MDEntries );
  }

  msg.addField( mdentries_id, Messages::FieldSequence::create( MDEntries_seq ) );

  encoder.encodeMessage( destination, 145, msg );
  WorkingBuffer fast_buffer;
  destination.toWorkingBuffer( fast_buffer );

  std::vector<unsigned char> write_buffer( 10 + fast_buffer.size() );
  byte_conversion::uint32_to_be( write_buffer.data(), 1 );
  byte_conversion::uint16_to_be( write_buffer.data()+4, 1 );
  byte_conversion::uint16_to_be( write_buffer.data()+6, 1 );
  byte_conversion::uint16_to_be( write_buffer.data()+8, fast_buffer.size() );
  std::copy( fast_buffer.begin(), fast_buffer.end(), write_buffer.begin() + 10 );

  source.send( write_buffer.data(), write_buffer.size() );

  std::this_thread::sleep_for( wait );

  BOOST_CHECK( h.bid_.seqnum().first );
  BOOST_CHECK_EQUAL( h.bid_.seqnum().second, 34 );
  BOOST_CHECK( h.bid_.update_action().first );
  BOOST_CHECK_EQUAL( h.bid_.update_action().second, 279 );
  BOOST_CHECK( h.bid_.security_id().first );
  BOOST_CHECK_EQUAL( h.bid_.security_id().second, 48 );
  BOOST_CHECK( h.bid_.entry_price().first );
  BOOST_CHECK_EQUAL( h.bid_.entry_price().second, decimal( 270, 0 ) );
  BOOST_CHECK( h.bid_.entry_size().first );
  BOOST_CHECK_EQUAL( h.bid_.entry_size().second, 271 );
  BOOST_CHECK( h.bid_.entry_date().first );
  BOOST_CHECK_EQUAL( h.bid_.entry_date().second, 272 );
  BOOST_CHECK( h.bid_.entry_time().first );
  BOOST_CHECK_EQUAL( h.bid_.entry_time().second, 273 );
  BOOST_CHECK( h.bid_.buyer().first );
  BOOST_CHECK_EQUAL( h.bid_.buyer().second, "288" );
  BOOST_CHECK( h.bid_.position().first );
  BOOST_CHECK_EQUAL( h.bid_.position().second, 290 );
  BOOST_CHECK( h.bid_.order_id().first );
  BOOST_CHECK_EQUAL( h.bid_.order_id().second, "37" );

  std::this_thread::sleep_for( wait );

  io_work_source.reset();
  client.disconnect();
  plant.stop();
  io_thread_source.join();
  io_thread_client.join();
  io_thread_plant.join();
}

BOOST_AUTO_TEST_SUITE_END()
