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
#include <msi/umdf/messages/incremental.hpp>
#include <msi/umdf/decoder/quickfast/incremental_builder.hpp>

namespace
{

using namespace apoena::msi::umdf::decoder::quickfast;
using namespace apoena::msi::umdf::messages;
using namespace QuickFAST;

struct message_container
{
  void on_message( const incremental& message )
  {
    message_ = message;
  }

  incremental message_;
};

}

BOOST_AUTO_TEST_SUITE( suite_incremental_builder )

BOOST_AUTO_TEST_CASE( test_builder_145_performance )
{
  std::string xml( std::getenv( "MSI_ROOT" ) );
  xml += "/resources/templates-PUMA.xml";
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
  MDEntries->addField( mdentrytype_id, Messages::FieldAscii::create( "269" ) );
  MDEntries->addField( securityidsource_id, Messages::FieldUInt32::create( 8 ) );
  MDEntries->addField( securityexchange_id, Messages::FieldAscii::create( "BVMF" ) );
  MDEntries->addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  MDEntries->addField( rptseq_id, Messages::FieldUInt32::create( 83 ) );
  MDEntries->addField( mdentrytime_id, Messages::FieldUInt32::create( 273 ) );
  MDEntries->addField( mdentrysize_id, Messages::FieldInt64::create( 271 ) );
  MDEntries->addField( mdentrydate_id, Messages::FieldUInt32::create( 272 ) );
  MDEntries->addField( mdinsertdate_id, Messages::FieldUInt32::create( 37016 ) );
  MDEntries->addField( mdinserttime_id, Messages::FieldUInt32::create( 37017 ) );
  MDEntries->addField( mdstreamid_id, Messages::FieldAscii::create( "1500" ) );
  MDEntries->addField( orderid_id, Messages::FieldAscii::create( "37" ) );
  MDEntries->addField( mdentrybuyer_id, Messages::FieldAscii::create( "288" ) );
  MDEntries->addField( mdentrypositionno_id, Messages::FieldUInt32::create( 290 ) );

  //   MDEntries->addField(quotecondition_id, Messages::FieldAscii::create("276"));
  //   MDEntries->addField(mdentrypx_id, Messages::FieldDecimal::create(270, 0));
  //   MDEntries->addField(mdentryinterestrate_id, Messages::FieldDecimal::create(37014, 0));
  //   MDEntries->addField(numberoforders_id, Messages::FieldUInt32::create(346));
  //   MDEntries->addField(pricetype_id, Messages::FieldAscii::create("423"));
  //   MDEntries->addField(currency_id, Messages::FieldAscii::create("15"));
  //   MDEntries->addField(netchgprevday_id, Messages::FieldDecimal::create(451, 0));
  //   MDEntries->addField(sellerdays_id, Messages::FieldUInt32::create(287));
  //   MDEntries->addField(tradevolume_id, Messages::FieldUInt64::create(1020));
  //   MDEntries->addField(tickdirection_id, Messages::FieldAscii::create("274"));
  //   MDEntries->addField(tradecondition_id, Messages::FieldAscii::create("277"));
  //   MDEntries->addField(tradingsessionid_id, Messages::FieldUInt32::create(336));
  //   MDEntries->addField(openclosesettlflag_id, Messages::FieldUInt32::create(286));
  //   MDEntries->addField(tradeid_id, Messages::FieldAscii::create("1003"));
  //   MDEntries->addField(mdentryseller_id, Messages::FieldAscii::create("289"));
  //   MDEntries->addField(settpricetype_id, Messages::FieldUInt32::create(731));
  //   MDEntries->addField(lasttradedate_id, Messages::FieldUInt32::create(9325));
  //   MDEntries->addField(priceadjustmentmethod_id, Messages::FieldUInt32::create(37013));
  //   MDEntries->addField(pricebandtype_id, Messages::FieldAscii::create("6939"));
  //   MDEntries->addField(pricelimittype_id, Messages::FieldUInt32::create(1306));
  //   MDEntries->addField(lowlimitprice_id, Messages::FieldDecimal::create(1148, 0));
  //   MDEntries->addField(highlimitprice_id, Messages::FieldDecimal::create(1149, 0));
  //   MDEntries->addField(tradingreferenceprice_id, Messages::FieldDecimal::create(1150, 0));
  //   MDEntries->addField(pricebandmidpointpricetype_id, Messages::FieldUInt32::create(37008));
  //   MDEntries->addField(avgdailytradedqty_id, Messages::FieldUInt64::create(37003));
  //   MDEntries->addField(expiredate_id, Messages::FieldUInt64::create(432));
  //   MDEntries->addField(earlytermination_id, Messages::FieldUInt64::create(37019));
  //   MDEntries->addField(maxtradevol_id, Messages::FieldUInt64::create(1140));
  //   MDEntries->addField(indexseq_id, Messages::FieldUInt64::create(37100));

  //   Messages::SequencePtr Underlyings_seq(new Messages::Sequence(underlyings_id, 1));
  //   Messages::FieldSetPtr Underlyings(new Messages::FieldSet(5));
  //
  //   Underlyings->addField(underlyingsecurityid_id, Messages::FieldUInt64::create(309));
  //   Underlyings->addField(underlyingsecurityidsource_id, Messages::FieldUInt32::create(8));
  //   Underlyings->addField(underlyingsecurityexchange_id, Messages::FieldAscii::create("BVMF"));
  //   Underlyings->addField(underlyingpx_id, Messages::FieldDecimal::create(810, 0));
  //   Underlyings->addField(underlyingpxtype_id, Messages::FieldUInt32::create(37018));
  //
  //   Underlyings_seq->addEntry(Underlyings);
  //
  //   MDEntries->addField(underlyings_id, Messages::FieldSequence::create(Underlyings_seq));

  MDEntries_seq->addEntry( MDEntries );

  msg.addField( mdentries_id, Messages::FieldSequence::create( MDEntries_seq ) );

  encoder.encodeMessage( destination, 145, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<incremental_builder>();

  uint32_t seqnum = 0;
  int received = 0;

  builder->register_on_message_callback( std::bind(
      [&received, &seqnum]( const incremental& msg )
  {
    ++received;
    seqnum = msg.MsgSeqNum().second;
  },
  std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "X", builder );

  uint32_t messages = 100 * 1000;

  LARGE_INTEGER li, start, end;
  QueryPerformanceFrequency( &li );
  double freq = double( li.QuadPart );

  uint64_t total = 0;

  for ( uint32_t i = 1; i <= messages; ++i )
  {
    Codecs::DataSourceString source( fast_string );
    decoder.reset();

    QueryPerformanceCounter( &start );

    decoder.decodeMessage( source, selector );

    QueryPerformanceCounter( &end );
    total += end.QuadPart - start.QuadPart;
  }

  double time = double( total ) / freq;
  double mps = messages / time;
  std::cout << messages << " messages in " << time << "s. " << std::endl;
  std::cout << mps << " messages/s" << std::endl;
  std::cout << time * 1000.0 * 1000.0 / messages << "us/msg" << std::endl;

  BOOST_REQUIRE_EQUAL( received, messages );
  BOOST_REQUIRE_EQUAL( seqnum, 34 );
}


BOOST_AUTO_TEST_CASE( test_builder_81 )
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
  id MsgType_id( "MsgType" );
  id msgseqnum_id( "MsgSeqNum" );
  id sendingtime_id( "SendingTime" );
  id posdupflag_id( "PosDupFlag" );
  id mdentries_id( "MDEntries" );
  id nomdentries_id( "NoMDEntries" );
  id mdupdateaction_id( "MDUpdateAction" );
  id mdpricelevel_id( "MDPriceLevel" );
  id mdentrytype_id( "MDEntryType" );
  id securityidsource_id( "SecurityIDSource" );
  id securityid_id( "SecurityID" );
  id rptseq_id( "RptSeq" );
  id mdentrypx_id( "MDEntryPx" );
  id mdentrytime_id( "MDEntryTime" );
  id mdentrysize_id( "MDEntrySize" );
  id quotecondition_id( "QuoteCondition" );
  id numberoforders_id( "NumberOfOrders" );
  id tradingsessionid_id( "TradingSessionID" );

  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( MsgType_id, Messages::FieldAscii::create( "X" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldUInt64::create( 52 ) );
  msg.addField( posdupflag_id, Messages::FieldAscii::create( "43" ) );

  Messages::SequencePtr MDEntries_seq( new Messages::Sequence( mdentries_id, 1 ) );
  Messages::FieldSetPtr MDEntries( new Messages::FieldSet( 12 ) );

  MDEntries->addField( mdupdateaction_id, Messages::FieldUInt32::create( 279 ) );
  MDEntries->addField( mdpricelevel_id, Messages::FieldUInt32::create( 1023 ) );
  MDEntries->addField( mdentrytype_id, Messages::FieldAscii::create( "269" ) );
  MDEntries->addField( securityidsource_id, Messages::FieldUInt32::create( 8 ) );
  MDEntries->addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  MDEntries->addField( rptseq_id, Messages::FieldUInt32::create( 83 ) );
  MDEntries->addField( mdentrypx_id, Messages::FieldDecimal::create( 270, 0 ) );
  MDEntries->addField( mdentrytime_id, Messages::FieldUInt32::create( 273 ) );
  MDEntries->addField( mdentrysize_id, Messages::FieldInt32::create( 271 ) );
  MDEntries->addField( quotecondition_id, Messages::FieldAscii::create( "276" ) );
  MDEntries->addField( numberoforders_id, Messages::FieldUInt32::create( 346 ) );
  MDEntries->addField( tradingsessionid_id, Messages::FieldAscii::create( "336" ) );

  MDEntries_seq->addEntry( MDEntries );

  msg.addField( mdentries_id, Messages::FieldSequence::create( MDEntries_seq ) );

  encoder.encodeMessage( destination, 81, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<incremental_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "X", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  incremental& m = container.message_;

  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "X" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, 52 );
  BOOST_CHECK( m.PosDupFlag().first );
  BOOST_CHECK_EQUAL( m.PosDupFlag().second, "43" );

  BOOST_REQUIRE_EQUAL( m.MDEntries().size(), 1 );
  const incremental::mdentries& MDEntries_msg = m.MDEntries()[0];

  BOOST_CHECK( MDEntries_msg.MDUpdateAction().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDUpdateAction().second, 279 );
  BOOST_CHECK( MDEntries_msg.MDPriceLevel().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDPriceLevel().second, 1023 );
  BOOST_CHECK( MDEntries_msg.MDEntryType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryType().second, "269" );
  BOOST_CHECK( MDEntries_msg.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityIDSource().second, 8 );
  BOOST_CHECK( MDEntries_msg.SecurityID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityID().second, 48 );
  BOOST_CHECK( MDEntries_msg.RptSeq().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.RptSeq().second, 83 );
  BOOST_CHECK( MDEntries_msg.MDEntryPx().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryPx().second, apoena::msi::decimal( 270, 0 ) );
  BOOST_CHECK( MDEntries_msg.MDEntryTime().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryTime().second, 273 );
  BOOST_CHECK( MDEntries_msg.MDEntrySize().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntrySize().second, 271 );
  BOOST_CHECK( MDEntries_msg.QuoteCondition().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.QuoteCondition().second, "276" );
  BOOST_CHECK( MDEntries_msg.NumberOfOrders().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.NumberOfOrders().second, 346 );
  BOOST_CHECK( MDEntries_msg.TradingSessionID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradingSessionID().second, 336 );

}

BOOST_AUTO_TEST_CASE( test_builder_145 )
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
  MDEntries->addField( mdentrytype_id, Messages::FieldAscii::create( "269" ) );
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
  MDEntries->addField( mdstreamid_id, Messages::FieldAscii::create( "1500" ) );
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

  MDEntries_seq->addEntry( MDEntries );

  msg.addField( mdentries_id, Messages::FieldSequence::create( MDEntries_seq ) );

  encoder.encodeMessage( destination, 145, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<incremental_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "X", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  incremental& m = container.message_;

  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "X" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, 52 );
  BOOST_CHECK( m.TradeDate().first );
  BOOST_CHECK_EQUAL( m.TradeDate().second, 75 );

  BOOST_REQUIRE_EQUAL( m.MDEntries().size(), 1 );
  const incremental::mdentries& MDEntries_msg = m.MDEntries()[0];

  BOOST_CHECK( MDEntries_msg.MDUpdateAction().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDUpdateAction().second, 279 );
  BOOST_CHECK( MDEntries_msg.MDEntryType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryType().second, "269" );
  BOOST_CHECK( MDEntries_msg.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityIDSource().second, 8 );
  BOOST_CHECK( MDEntries_msg.SecurityExchange().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityExchange().second, "BVMF" );
  BOOST_CHECK( MDEntries_msg.SecurityID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityID().second, 48 );
  BOOST_CHECK( MDEntries_msg.RptSeq().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.RptSeq().second, 83 );
  BOOST_CHECK( MDEntries_msg.QuoteCondition().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.QuoteCondition().second, "276" );
  BOOST_CHECK( MDEntries_msg.MDEntryPx().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryPx().second, apoena::msi::decimal( 270, 0 ) );
  BOOST_CHECK( MDEntries_msg.MDEntryInterestRate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryInterestRate().second, apoena::msi::decimal( 37014, 0 ) );
  BOOST_CHECK( MDEntries_msg.NumberOfOrders().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.NumberOfOrders().second, 346 );
  BOOST_CHECK( MDEntries_msg.PriceType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceType().second, "423" );
  BOOST_CHECK( MDEntries_msg.MDEntryTime().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryTime().second, 273 );
  BOOST_CHECK( MDEntries_msg.MDEntrySize().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntrySize().second, 271 );
  BOOST_CHECK( MDEntries_msg.MDEntryDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryDate().second, 272 );
  BOOST_CHECK( MDEntries_msg.MDInsertDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDInsertDate().second, 37016 );
  BOOST_CHECK( MDEntries_msg.MDInsertTime().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDInsertTime().second, 37017 );
  BOOST_CHECK( MDEntries_msg.MDStreamID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDStreamID().second, "1500" );
  BOOST_CHECK( MDEntries_msg.Currency().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.Currency().second, "15" );
  BOOST_CHECK( MDEntries_msg.NetChgPrevDay().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.NetChgPrevDay().second, apoena::msi::decimal( 451, 0 ) );
  BOOST_CHECK( MDEntries_msg.SellerDays().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SellerDays().second, 287 );
  BOOST_CHECK( MDEntries_msg.TradeVolume().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradeVolume().second, 1020 );
  BOOST_CHECK( MDEntries_msg.TickDirection().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TickDirection().second, "274" );
  BOOST_CHECK( MDEntries_msg.TradeCondition().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradeCondition().second, "277" );
  BOOST_CHECK( MDEntries_msg.TradingSessionID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradingSessionID().second, 336 );
  BOOST_CHECK( MDEntries_msg.OpenCloseSettlFlag().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.OpenCloseSettlFlag().second, 286 );
  BOOST_CHECK( MDEntries_msg.OrderID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.OrderID().second, "37" );
  BOOST_CHECK( MDEntries_msg.TradeID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradeID().second, "1003" );
  BOOST_CHECK( MDEntries_msg.MDEntryBuyer().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryBuyer().second, "288" );
  BOOST_CHECK( MDEntries_msg.MDEntrySeller().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntrySeller().second, "289" );
  BOOST_CHECK( MDEntries_msg.MDEntryPositionNo().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryPositionNo().second, 290 );
  BOOST_CHECK( MDEntries_msg.SettPriceType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SettPriceType().second, 731 );
  BOOST_CHECK( MDEntries_msg.LastTradeDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.LastTradeDate().second, 9325 );
  BOOST_CHECK( MDEntries_msg.PriceAdjustmentMethod().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceAdjustmentMethod().second, 37013 );
  BOOST_CHECK( MDEntries_msg.PriceBandType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceBandType().second, "6939" );
  BOOST_CHECK( MDEntries_msg.PriceLimitType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceLimitType().second, 1306 );
  BOOST_CHECK( MDEntries_msg.LowLimitPrice().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.LowLimitPrice().second, apoena::msi::decimal( 1148, 0 ) );
  BOOST_CHECK( MDEntries_msg.HighLimitPrice().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.HighLimitPrice().second, apoena::msi::decimal( 1149, 0 ) );
  BOOST_CHECK( MDEntries_msg.TradingReferencePrice().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradingReferencePrice().second, apoena::msi::decimal( 1150, 0 ) );
  BOOST_CHECK( MDEntries_msg.PriceBandMidpointPriceType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceBandMidpointPriceType().second, 37008 );
  BOOST_CHECK( MDEntries_msg.AvgDailyTradedQty().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.AvgDailyTradedQty().second, 37003 );
  BOOST_CHECK( MDEntries_msg.ExpireDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.ExpireDate().second, 432 );
  BOOST_CHECK( MDEntries_msg.EarlyTermination().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.EarlyTermination().second, 37019 );
  BOOST_CHECK( MDEntries_msg.MaxTradeVol().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MaxTradeVol().second, 1140 );
  BOOST_CHECK( MDEntries_msg.IndexSeq().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.IndexSeq().second, 37100 );

  BOOST_REQUIRE_EQUAL( MDEntries_msg.Underlyings().size(), 1 );
  const incremental::mdentries::underlyings& Underlyings_msg = MDEntries_msg.Underlyings()[0];

  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityID().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityID().second, 309 );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityIDSource().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityIDSource().second, 8 );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityExchange().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityExchange().second, "BVMF" );
  BOOST_CHECK( Underlyings_msg.UnderlyingPx().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingPx().second, apoena::msi::decimal( 810, 0 ) );
  BOOST_CHECK( Underlyings_msg.UnderlyingPxType().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingPxType().second, 37018 );

}

BOOST_AUTO_TEST_CASE( test_builder_138 )
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
  MDEntries->addField( mdentrytype_id, Messages::FieldAscii::create( "269" ) );
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
  MDEntries->addField( mdstreamid_id, Messages::FieldAscii::create( "1500" ) );
  MDEntries->addField( currency_id, Messages::FieldAscii::create( "15" ) );
  MDEntries->addField( netchgprevday_id, Messages::FieldDecimal::create( 451, 0 ) );
  MDEntries->addField( sellerdays_id, Messages::FieldUInt32::create( 287 ) );
  MDEntries->addField( tradevolume_id, Messages::FieldUInt64::create( 1020 ) );
  MDEntries->addField( tickdirection_id, Messages::FieldAscii::create( "274" ) );
  MDEntries->addField( tradecondition_id, Messages::FieldAscii::create( "277" ) );
  MDEntries->addField( tradingsessionid_id, Messages::FieldUInt32::create( 336 ) );
  MDEntries->addField( openclosesettlflag_id, Messages::FieldAscii::create( "286" ) );
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

  MDEntries_seq->addEntry( MDEntries );

  msg.addField( mdentries_id, Messages::FieldSequence::create( MDEntries_seq ) );

  encoder.encodeMessage( destination, 138, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<incremental_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "X", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  incremental& m = container.message_;

  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "X" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, 52 );
  BOOST_CHECK( m.TradeDate().first );
  BOOST_CHECK_EQUAL( m.TradeDate().second, 75 );

  BOOST_REQUIRE_EQUAL( m.MDEntries().size(), 1 );
  const incremental::mdentries& MDEntries_msg = m.MDEntries()[0];

  BOOST_CHECK( MDEntries_msg.MDUpdateAction().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDUpdateAction().second, 279 );
  BOOST_CHECK( MDEntries_msg.MDEntryType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryType().second, "269" );
  BOOST_CHECK( MDEntries_msg.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityIDSource().second, 8 );
  BOOST_CHECK( MDEntries_msg.SecurityExchange().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityExchange().second, "BVMF" );
  BOOST_CHECK( MDEntries_msg.SecurityID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityID().second, 48 );
  BOOST_CHECK( MDEntries_msg.RptSeq().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.RptSeq().second, 83 );
  BOOST_CHECK( MDEntries_msg.QuoteCondition().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.QuoteCondition().second, "276" );
  BOOST_CHECK( MDEntries_msg.MDEntryPx().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryPx().second, apoena::msi::decimal( 270, 0 ) );
  BOOST_CHECK( MDEntries_msg.MDEntryInterestRate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryInterestRate().second, apoena::msi::decimal( 37014, 0 ) );
  BOOST_CHECK( MDEntries_msg.NumberOfOrders().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.NumberOfOrders().second, 346 );
  BOOST_CHECK( MDEntries_msg.PriceType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceType().second, "423" );
  BOOST_CHECK( MDEntries_msg.MDEntryTime().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryTime().second, 273 );
  BOOST_CHECK( MDEntries_msg.MDEntrySize().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntrySize().second, 271 );
  BOOST_CHECK( MDEntries_msg.MDEntryDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryDate().second, 272 );
  BOOST_CHECK( MDEntries_msg.MDInsertDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDInsertDate().second, 37016 );
  BOOST_CHECK( MDEntries_msg.MDInsertTime().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDInsertTime().second, 37017 );
  BOOST_CHECK( MDEntries_msg.MDStreamID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDStreamID().second, "1500" );
  BOOST_CHECK( MDEntries_msg.Currency().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.Currency().second, "15" );
  BOOST_CHECK( MDEntries_msg.NetChgPrevDay().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.NetChgPrevDay().second, apoena::msi::decimal( 451, 0 ) );
  BOOST_CHECK( MDEntries_msg.SellerDays().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SellerDays().second, 287 );
  BOOST_CHECK( MDEntries_msg.TradeVolume().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradeVolume().second, 1020 );
  BOOST_CHECK( MDEntries_msg.TickDirection().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TickDirection().second, "274" );
  BOOST_CHECK( MDEntries_msg.TradeCondition().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradeCondition().second, "277" );
  BOOST_CHECK( MDEntries_msg.TradingSessionID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradingSessionID().second, 336 );
  BOOST_CHECK( MDEntries_msg.OpenCloseSettlFlag().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.OpenCloseSettlFlag().second, 286 );
  BOOST_CHECK( MDEntries_msg.OrderID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.OrderID().second, "37" );
  BOOST_CHECK( MDEntries_msg.TradeID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradeID().second, "1003" );
  BOOST_CHECK( MDEntries_msg.MDEntryBuyer().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryBuyer().second, "288" );
  BOOST_CHECK( MDEntries_msg.MDEntrySeller().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntrySeller().second, "289" );
  BOOST_CHECK( MDEntries_msg.MDEntryPositionNo().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryPositionNo().second, 290 );
  BOOST_CHECK( MDEntries_msg.SettPriceType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SettPriceType().second, 731 );
  BOOST_CHECK( MDEntries_msg.LastTradeDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.LastTradeDate().second, 9325 );
  BOOST_CHECK( MDEntries_msg.PriceAdjustmentMethod().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceAdjustmentMethod().second, 37013 );
  BOOST_CHECK( MDEntries_msg.PriceBandType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceBandType().second, "6939" );
  BOOST_CHECK( MDEntries_msg.PriceLimitType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceLimitType().second, 1306 );
  BOOST_CHECK( MDEntries_msg.LowLimitPrice().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.LowLimitPrice().second, apoena::msi::decimal( 1148, 0 ) );
  BOOST_CHECK( MDEntries_msg.HighLimitPrice().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.HighLimitPrice().second, apoena::msi::decimal( 1149, 0 ) );
  BOOST_CHECK( MDEntries_msg.TradingReferencePrice().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradingReferencePrice().second, apoena::msi::decimal( 1150, 0 ) );
  BOOST_CHECK( MDEntries_msg.PriceBandMidpointPriceType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceBandMidpointPriceType().second, 37008 );
  BOOST_CHECK( MDEntries_msg.AvgDailyTradedQty().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.AvgDailyTradedQty().second, 37003 );
  BOOST_CHECK( MDEntries_msg.ExpireDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.ExpireDate().second, 432 );
  BOOST_CHECK( MDEntries_msg.EarlyTermination().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.EarlyTermination().second, 37019 );
  BOOST_CHECK( MDEntries_msg.MaxTradeVol().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MaxTradeVol().second, 1140 );
  BOOST_CHECK( MDEntries_msg.IndexSeq().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.IndexSeq().second, 37100 );

  BOOST_REQUIRE_EQUAL( MDEntries_msg.Underlyings().size(), 1 );
  const incremental::mdentries::underlyings& Underlyings_msg = MDEntries_msg.Underlyings()[0];

  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityID().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityID().second, 309 );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityIDSource().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityIDSource().second, 8 );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityExchange().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityExchange().second, "BVMF" );
  BOOST_CHECK( Underlyings_msg.UnderlyingPx().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingPx().second, apoena::msi::decimal( 810, 0 ) );
  BOOST_CHECK( Underlyings_msg.UnderlyingPxType().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingPxType().second, 37018 );

}

BOOST_AUTO_TEST_CASE( test_builder_123 )
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
  id MsgType_id( "MsgType" );
  id msgseqnum_id( "MsgSeqNum" );
  id sendingtime_id( "SendingTime" );
  id tradedate_id( "TradeDate" );
  id mdentries_id( "MDEntries" );
  id nomdentries_id( "NoMDEntries" );
  id mdupdateaction_id( "MDUpdateAction" );
  id mdpricelevel_id( "MDPriceLevel" );
  id mdentrytype_id( "MDEntryType" );
  id symbol_id( "Symbol" );
  id securityidsource_id( "SecurityIDSource" );
  id securityexchange_id( "SecurityExchange" );
  id securityid_id( "SecurityID" );
  id rptseq_id( "RptSeq" );
  id quotecondition_id( "QuoteCondition" );
  id mdentrypx_id( "MDEntryPx" );
  id numberoforders_id( "NumberOfOrders" );
  id pricetype_id( "PriceType" );
  id mdentrytime_id( "MDEntryTime" );
  id mdentrysize_id( "MDEntrySize" );
  id mdentrydate_id( "MDEntryDate" );
  id mdinsertdate_id( "MDInsertDate" );
  id mdinserttime_id( "MDInsertTime" );
  id mdstreamid_id( "MDStreamID" );
  id currency_id( "Currency" );
  id tradingsessionid_id( "TradingSessionID" );
  id netchgprevday_id( "NetChgPrevDay" );
  id sellerdays_id( "SellerDays" );
  id tradevolume_id( "TradeVolume" );
  id tickdirection_id( "TickDirection" );
  id tradecondition_id( "TradeCondition" );
  id openclosesettleflag_id( "OpenCloseSettleFlag" );
  id orderid_id( "OrderID" );
  id tradeid_id( "TradeID" );
  id mdentrybuyer_id( "MDEntryBuyer" );
  id mdentryseller_id( "MDEntrySeller" );
  id mdentrypositionno_id( "MDEntryPositionNo" );
  id settltype_id( "SettlType" );
  id settldate_id( "SettlDate" );
  id settlepricetype_id( "SettlePriceType" );
  id pricebandtype_id( "PriceBandType" );
  id pricelimittype_id( "PriceLimitType" );
  id lowlimitprice_id( "LowLimitPrice" );
  id highlimitprice_id( "HighLimitPrice" );
  id tradingrefprice_id( "TradingRefPrice" );

  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( MsgType_id, Messages::FieldAscii::create( "X" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldUInt64::create( 52 ) );
  msg.addField( tradedate_id, Messages::FieldUInt32::create( 75 ) );

  Messages::SequencePtr MDEntries_seq( new Messages::Sequence( mdentries_id, 1 ) );
  Messages::FieldSetPtr MDEntries( new Messages::FieldSet( 39 ) );

  MDEntries->addField( mdupdateaction_id, Messages::FieldUInt32::create( 279 ) );
  MDEntries->addField( mdpricelevel_id, Messages::FieldUInt32::create( 1023 ) );
  MDEntries->addField( mdentrytype_id, Messages::FieldAscii::create( "269" ) );
  MDEntries->addField( symbol_id, Messages::FieldAscii::create( "55" ) );
  MDEntries->addField( securityidsource_id, Messages::FieldUInt32::create( 8 ) );
  MDEntries->addField( securityexchange_id, Messages::FieldAscii::create( "BVMF" ) );
  MDEntries->addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  MDEntries->addField( rptseq_id, Messages::FieldUInt32::create( 83 ) );
  MDEntries->addField( quotecondition_id, Messages::FieldAscii::create( "276" ) );
  MDEntries->addField( mdentrypx_id, Messages::FieldDecimal::create( 270, 0 ) );
  MDEntries->addField( numberoforders_id, Messages::FieldUInt32::create( 346 ) );
  MDEntries->addField( pricetype_id, Messages::FieldAscii::create( "423" ) );
  MDEntries->addField( mdentrytime_id, Messages::FieldUInt32::create( 273 ) );
  MDEntries->addField( mdentrysize_id, Messages::FieldInt32::create( 271 ) );
  MDEntries->addField( mdentrydate_id, Messages::FieldUInt32::create( 272 ) );
  MDEntries->addField( mdinsertdate_id, Messages::FieldUInt32::create( 37016 ) );
  MDEntries->addField( mdinserttime_id, Messages::FieldUInt32::create( 37017 ) );
  MDEntries->addField( mdstreamid_id, Messages::FieldAscii::create( "1500" ) );
  MDEntries->addField( currency_id, Messages::FieldAscii::create( "15" ) );
  MDEntries->addField( tradingsessionid_id, Messages::FieldAscii::create( "336" ) );
  MDEntries->addField( netchgprevday_id, Messages::FieldDecimal::create( 451, 0 ) );
  MDEntries->addField( sellerdays_id, Messages::FieldUInt32::create( 287 ) );
  MDEntries->addField( tradevolume_id, Messages::FieldUInt64::create( 1020 ) );
  MDEntries->addField( tickdirection_id, Messages::FieldAscii::create( "274" ) );
  MDEntries->addField( tradecondition_id, Messages::FieldAscii::create( "277" ) );
  MDEntries->addField( openclosesettleflag_id, Messages::FieldUInt32::create( 286 ) );
  MDEntries->addField( orderid_id, Messages::FieldAscii::create( "37" ) );
  MDEntries->addField( tradeid_id, Messages::FieldAscii::create( "1003" ) );
  MDEntries->addField( mdentrybuyer_id, Messages::FieldAscii::create( "288" ) );
  MDEntries->addField( mdentryseller_id, Messages::FieldAscii::create( "289" ) );
  MDEntries->addField( mdentrypositionno_id, Messages::FieldUInt32::create( 290 ) );
  MDEntries->addField( settltype_id, Messages::FieldAscii::create( "63" ) );
  MDEntries->addField( settldate_id, Messages::FieldUInt32::create( 64 ) );
  MDEntries->addField( settlepricetype_id, Messages::FieldUInt32::create( 731 ) );
  MDEntries->addField( pricebandtype_id, Messages::FieldAscii::create( "6939" ) );
  MDEntries->addField( pricelimittype_id, Messages::FieldUInt32::create( 1306 ) );
  MDEntries->addField( lowlimitprice_id, Messages::FieldDecimal::create( 1148, 0 ) );
  MDEntries->addField( highlimitprice_id, Messages::FieldDecimal::create( 1149, 0 ) );
  MDEntries->addField( tradingrefprice_id, Messages::FieldDecimal::create( 1150, 0 ) );

  MDEntries_seq->addEntry( MDEntries );

  msg.addField( mdentries_id, Messages::FieldSequence::create( MDEntries_seq ) );

  encoder.encodeMessage( destination, 123, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<incremental_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "X", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  incremental& m = container.message_;

  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "X" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, 52 );
  BOOST_CHECK( m.TradeDate().first );
  BOOST_CHECK_EQUAL( m.TradeDate().second, 75 );

  BOOST_REQUIRE_EQUAL( m.MDEntries().size(), 1 );
  const incremental::mdentries& MDEntries_msg = m.MDEntries()[0];

  BOOST_CHECK( MDEntries_msg.MDUpdateAction().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDUpdateAction().second, 279 );
  BOOST_CHECK( MDEntries_msg.MDPriceLevel().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDPriceLevel().second, 1023 );
  BOOST_CHECK( MDEntries_msg.MDEntryType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryType().second, "269" );
  BOOST_CHECK( MDEntries_msg.Symbol().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.Symbol().second, "55" );
  BOOST_CHECK( MDEntries_msg.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityIDSource().second, 8 );
  BOOST_CHECK( MDEntries_msg.SecurityExchange().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityExchange().second, "BVMF" );
  BOOST_CHECK( MDEntries_msg.SecurityID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityID().second, 48 );
  BOOST_CHECK( MDEntries_msg.RptSeq().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.RptSeq().second, 83 );
  BOOST_CHECK( MDEntries_msg.QuoteCondition().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.QuoteCondition().second, "276" );
  BOOST_CHECK( MDEntries_msg.MDEntryPx().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryPx().second, apoena::msi::decimal( 270, 0 ) );
  BOOST_CHECK( MDEntries_msg.NumberOfOrders().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.NumberOfOrders().second, 346 );
  BOOST_CHECK( MDEntries_msg.PriceType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceType().second, "423" );
  BOOST_CHECK( MDEntries_msg.MDEntryTime().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryTime().second, 273 );
  BOOST_CHECK( MDEntries_msg.MDEntrySize().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntrySize().second, 271 );
  BOOST_CHECK( MDEntries_msg.MDEntryDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryDate().second, 272 );
  BOOST_CHECK( MDEntries_msg.MDInsertDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDInsertDate().second, 37016 );
  BOOST_CHECK( MDEntries_msg.MDInsertTime().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDInsertTime().second, 37017 );
  BOOST_CHECK( MDEntries_msg.MDStreamID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDStreamID().second, "1500" );
  BOOST_CHECK( MDEntries_msg.Currency().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.Currency().second, "15" );
  BOOST_CHECK( MDEntries_msg.TradingSessionID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradingSessionID().second, 336 );
  BOOST_CHECK( MDEntries_msg.NetChgPrevDay().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.NetChgPrevDay().second, apoena::msi::decimal( 451, 0 ) );
  BOOST_CHECK( MDEntries_msg.SellerDays().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SellerDays().second, 287 );
  BOOST_CHECK( MDEntries_msg.TradeVolume().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradeVolume().second, 1020 );
  BOOST_CHECK( MDEntries_msg.TickDirection().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TickDirection().second, "274" );
  BOOST_CHECK( MDEntries_msg.TradeCondition().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradeCondition().second, "277" );
  BOOST_CHECK( MDEntries_msg.OpenCloseSettlFlag().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.OpenCloseSettlFlag().second, 286 );
  BOOST_CHECK( MDEntries_msg.OrderID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.OrderID().second, "37" );
  BOOST_CHECK( MDEntries_msg.TradeID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradeID().second, "1003" );
  BOOST_CHECK( MDEntries_msg.MDEntryBuyer().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryBuyer().second, "288" );
  BOOST_CHECK( MDEntries_msg.MDEntrySeller().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntrySeller().second, "289" );
  BOOST_CHECK( MDEntries_msg.MDEntryPositionNo().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryPositionNo().second, 290 );
  BOOST_CHECK( MDEntries_msg.SettlType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SettlType().second, "63" );
  BOOST_CHECK( MDEntries_msg.SettlDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SettlDate().second, 64 );
  BOOST_CHECK( MDEntries_msg.SettPriceType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SettPriceType().second, 731 );
  BOOST_CHECK( MDEntries_msg.PriceBandType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceBandType().second, "6939" );
  BOOST_CHECK( MDEntries_msg.PriceLimitType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceLimitType().second, 1306 );
  BOOST_CHECK( MDEntries_msg.LowLimitPrice().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.LowLimitPrice().second, apoena::msi::decimal( 1148, 0 ) );
  BOOST_CHECK( MDEntries_msg.HighLimitPrice().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.HighLimitPrice().second, apoena::msi::decimal( 1149, 0 ) );
  BOOST_CHECK( MDEntries_msg.TradingReferencePrice().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradingReferencePrice().second, apoena::msi::decimal( 1150, 0 ) );

}

BOOST_AUTO_TEST_CASE( test_builder_126 )
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
  id MsgType_id( "MsgType" );
  id msgseqnum_id( "MsgSeqNum" );
  id sendingtime_id( "SendingTime" );
  id tradedate_id( "TradeDate" );
  id mdentries_id( "MDEntries" );
  id nomdentries_id( "NoMDEntries" );
  id mdupdateaction_id( "MDUpdateAction" );
  id mdpricelevel_id( "MDPriceLevel" );
  id mdentrytype_id( "MDEntryType" );
  id symbol_id( "Symbol" );
  id securityidsource_id( "SecurityIDSource" );
  id securityexchange_id( "SecurityExchange" );
  id securityid_id( "SecurityID" );
  id rptseq_id( "RptSeq" );
  id quotecondition_id( "QuoteCondition" );
  id mdentrypx_id( "MDEntryPx" );
  id numberoforders_id( "NumberOfOrders" );
  id pricetype_id( "PriceType" );
  id mdentrytime_id( "MDEntryTime" );
  id mdentrysize_id( "MDEntrySize" );
  id mdentrydate_id( "MDEntryDate" );
  id mdinsertdate_id( "MDInsertDate" );
  id mdinserttime_id( "MDInsertTime" );
  id mdstreamid_id( "MDStreamID" );
  id currency_id( "Currency" );
  id tradingsessionid_id( "TradingSessionID" );
  id netchgprevday_id( "NetChgPrevDay" );
  id sellerdays_id( "SellerDays" );
  id tradevolume_id( "TradeVolume" );
  id tickdirection_id( "TickDirection" );
  id tradecondition_id( "TradeCondition" );
  id openclosesettleflag_id( "OpenCloseSettleFlag" );
  id orderid_id( "OrderID" );
  id tradeid_id( "TradeID" );
  id mdentrybuyer_id( "MDEntryBuyer" );
  id mdentryseller_id( "MDEntrySeller" );
  id mdentrypositionno_id( "MDEntryPositionNo" );
  id settltype_id( "SettlType" );
  id settldate_id( "SettlDate" );
  id settlepricetype_id( "SettlePriceType" );
  id pricebandtype_id( "PriceBandType" );
  id pricelimittype_id( "PriceLimitType" );
  id lowlimitprice_id( "LowLimitPrice" );
  id highlimitprice_id( "HighLimitPrice" );
  id tradingrefprice_id( "TradingRefPrice" );

  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( MsgType_id, Messages::FieldAscii::create( "X" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldUInt64::create( 52 ) );
  msg.addField( tradedate_id, Messages::FieldUInt32::create( 75 ) );

  Messages::SequencePtr MDEntries_seq( new Messages::Sequence( mdentries_id, 1 ) );
  Messages::FieldSetPtr MDEntries( new Messages::FieldSet( 39 ) );

  MDEntries->addField( mdupdateaction_id, Messages::FieldUInt32::create( 279 ) );
  MDEntries->addField( mdpricelevel_id, Messages::FieldUInt32::create( 1023 ) );
  MDEntries->addField( mdentrytype_id, Messages::FieldAscii::create( "269" ) );
  MDEntries->addField( symbol_id, Messages::FieldAscii::create( "55" ) );
  MDEntries->addField( securityidsource_id, Messages::FieldUInt32::create( 8 ) );
  MDEntries->addField( securityexchange_id, Messages::FieldAscii::create( "BVMF" ) );
  MDEntries->addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  MDEntries->addField( rptseq_id, Messages::FieldUInt32::create( 83 ) );
  MDEntries->addField( quotecondition_id, Messages::FieldAscii::create( "276" ) );
  MDEntries->addField( mdentrypx_id, Messages::FieldDecimal::create( 270, 0 ) );
  MDEntries->addField( numberoforders_id, Messages::FieldUInt32::create( 346 ) );
  MDEntries->addField( pricetype_id, Messages::FieldAscii::create( "423" ) );
  MDEntries->addField( mdentrytime_id, Messages::FieldUInt32::create( 273 ) );
  MDEntries->addField( mdentrysize_id, Messages::FieldInt64::create( 271 ) );
  MDEntries->addField( mdentrydate_id, Messages::FieldUInt32::create( 272 ) );
  MDEntries->addField( mdinsertdate_id, Messages::FieldUInt32::create( 37016 ) );
  MDEntries->addField( mdinserttime_id, Messages::FieldUInt32::create( 37017 ) );
  MDEntries->addField( mdstreamid_id, Messages::FieldAscii::create( "1500" ) );
  MDEntries->addField( currency_id, Messages::FieldAscii::create( "15" ) );
  MDEntries->addField( tradingsessionid_id, Messages::FieldAscii::create( "336" ) );
  MDEntries->addField( netchgprevday_id, Messages::FieldDecimal::create( 451, 0 ) );
  MDEntries->addField( sellerdays_id, Messages::FieldUInt32::create( 287 ) );
  MDEntries->addField( tradevolume_id, Messages::FieldUInt64::create( 1020 ) );
  MDEntries->addField( tickdirection_id, Messages::FieldAscii::create( "274" ) );
  MDEntries->addField( tradecondition_id, Messages::FieldAscii::create( "277" ) );
  MDEntries->addField( openclosesettleflag_id, Messages::FieldUInt32::create( 286 ) );
  MDEntries->addField( orderid_id, Messages::FieldAscii::create( "37" ) );
  MDEntries->addField( tradeid_id, Messages::FieldAscii::create( "1003" ) );
  MDEntries->addField( mdentrybuyer_id, Messages::FieldAscii::create( "288" ) );
  MDEntries->addField( mdentryseller_id, Messages::FieldAscii::create( "289" ) );
  MDEntries->addField( mdentrypositionno_id, Messages::FieldUInt32::create( 290 ) );
  MDEntries->addField( settltype_id, Messages::FieldAscii::create( "63" ) );
  MDEntries->addField( settldate_id, Messages::FieldUInt32::create( 64 ) );
  MDEntries->addField( settlepricetype_id, Messages::FieldUInt32::create( 731 ) );
  MDEntries->addField( pricebandtype_id, Messages::FieldAscii::create( "6939" ) );
  MDEntries->addField( pricelimittype_id, Messages::FieldUInt32::create( 1306 ) );
  MDEntries->addField( lowlimitprice_id, Messages::FieldDecimal::create( 1148, 0 ) );
  MDEntries->addField( highlimitprice_id, Messages::FieldDecimal::create( 1149, 0 ) );
  MDEntries->addField( tradingrefprice_id, Messages::FieldDecimal::create( 1150, 0 ) );

  MDEntries_seq->addEntry( MDEntries );

  msg.addField( mdentries_id, Messages::FieldSequence::create( MDEntries_seq ) );

  encoder.encodeMessage( destination, 126, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<incremental_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "X", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  incremental& m = container.message_;

  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "X" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, 52 );
  BOOST_CHECK( m.TradeDate().first );
  BOOST_CHECK_EQUAL( m.TradeDate().second, 75 );

  BOOST_REQUIRE_EQUAL( m.MDEntries().size(), 1 );
  const incremental::mdentries& MDEntries_msg = m.MDEntries()[0];

  BOOST_CHECK( MDEntries_msg.MDUpdateAction().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDUpdateAction().second, 279 );
  BOOST_CHECK( MDEntries_msg.MDPriceLevel().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDPriceLevel().second, 1023 );
  BOOST_CHECK( MDEntries_msg.MDEntryType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryType().second, "269" );
  BOOST_CHECK( MDEntries_msg.Symbol().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.Symbol().second, "55" );
  BOOST_CHECK( MDEntries_msg.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityIDSource().second, 8 );
  BOOST_CHECK( MDEntries_msg.SecurityExchange().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityExchange().second, "BVMF" );
  BOOST_CHECK( MDEntries_msg.SecurityID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SecurityID().second, 48 );
  BOOST_CHECK( MDEntries_msg.RptSeq().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.RptSeq().second, 83 );
  BOOST_CHECK( MDEntries_msg.QuoteCondition().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.QuoteCondition().second, "276" );
  BOOST_CHECK( MDEntries_msg.MDEntryPx().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryPx().second, apoena::msi::decimal( 270, 0 ) );
  BOOST_CHECK( MDEntries_msg.NumberOfOrders().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.NumberOfOrders().second, 346 );
  BOOST_CHECK( MDEntries_msg.PriceType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceType().second, "423" );
  BOOST_CHECK( MDEntries_msg.MDEntryTime().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryTime().second, 273 );
  BOOST_CHECK( MDEntries_msg.MDEntrySize().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntrySize().second, 271 );
  BOOST_CHECK( MDEntries_msg.MDEntryDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryDate().second, 272 );
  BOOST_CHECK( MDEntries_msg.MDInsertDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDInsertDate().second, 37016 );
  BOOST_CHECK( MDEntries_msg.MDInsertTime().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDInsertTime().second, 37017 );
  BOOST_CHECK( MDEntries_msg.MDStreamID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDStreamID().second, "1500" );
  BOOST_CHECK( MDEntries_msg.Currency().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.Currency().second, "15" );
  BOOST_CHECK( MDEntries_msg.TradingSessionID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradingSessionID().second, 336 );
  BOOST_CHECK( MDEntries_msg.NetChgPrevDay().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.NetChgPrevDay().second, apoena::msi::decimal( 451, 0 ) );
  BOOST_CHECK( MDEntries_msg.SellerDays().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SellerDays().second, 287 );
  BOOST_CHECK( MDEntries_msg.TradeVolume().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradeVolume().second, 1020 );
  BOOST_CHECK( MDEntries_msg.TickDirection().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TickDirection().second, "274" );
  BOOST_CHECK( MDEntries_msg.TradeCondition().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradeCondition().second, "277" );
  BOOST_CHECK( MDEntries_msg.OpenCloseSettlFlag().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.OpenCloseSettlFlag().second, 286 );
  BOOST_CHECK( MDEntries_msg.OrderID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.OrderID().second, "37" );
  BOOST_CHECK( MDEntries_msg.TradeID().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradeID().second, "1003" );
  BOOST_CHECK( MDEntries_msg.MDEntryBuyer().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryBuyer().second, "288" );
  BOOST_CHECK( MDEntries_msg.MDEntrySeller().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntrySeller().second, "289" );
  BOOST_CHECK( MDEntries_msg.MDEntryPositionNo().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.MDEntryPositionNo().second, 290 );
  BOOST_CHECK( MDEntries_msg.SettlType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SettlType().second, "63" );
  BOOST_CHECK( MDEntries_msg.SettlDate().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SettlDate().second, 64 );
  BOOST_CHECK( MDEntries_msg.SettPriceType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.SettPriceType().second, 731 );
  BOOST_CHECK( MDEntries_msg.PriceBandType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceBandType().second, "6939" );
  BOOST_CHECK( MDEntries_msg.PriceLimitType().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.PriceLimitType().second, 1306 );
  BOOST_CHECK( MDEntries_msg.LowLimitPrice().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.LowLimitPrice().second, apoena::msi::decimal( 1148, 0 ) );
  BOOST_CHECK( MDEntries_msg.HighLimitPrice().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.HighLimitPrice().second, apoena::msi::decimal( 1149, 0 ) );
  BOOST_CHECK( MDEntries_msg.TradingReferencePrice().first );
  BOOST_CHECK_EQUAL( MDEntries_msg.TradingReferencePrice().second, apoena::msi::decimal( 1150, 0 ) );

}


BOOST_AUTO_TEST_SUITE_END()
