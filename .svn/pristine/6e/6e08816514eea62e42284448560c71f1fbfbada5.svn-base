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
#include <msi/umdf/messages/security_list.hpp>
#include <msi/umdf/decoder/quickfast/security_list_builder.hpp>

namespace
{

using namespace apoena::msi::umdf::decoder::quickfast;
using namespace apoena::msi::umdf::messages;
using namespace QuickFAST;

struct message_container
{
  void on_message( const security_list& message )
  {
    message_ = message;
  }

  security_list message_;
};

}

BOOST_AUTO_TEST_SUITE( suite_security_list_builder )

BOOST_AUTO_TEST_CASE( test_builder_149 )
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

  id msgtype_id( "MsgType" );
  id applverid_id( "ApplVerID" );
  id msgseqnum_id( "MsgSeqNum" );
  id sendingtime_id( "SendingTime" );
  id totnorelatedsym_id( "TotNoRelatedSym" );
  id lastfragment_id( "LastFragment" );
  id relatedsym_id( "RelatedSym" );
  id norelatedsym_id( "NoRelatedSym" );
  id symbol_id( "Symbol" );
  id securityid_id( "SecurityID" );
  id securityidsource_id( "SecurityIDSource" );
  id securityexchange_id( "SecurityExchange" );
  id applids_id( "ApplIDs" );
  id securityaltids_id( "SecurityAltIDs" );
  id underlyings_id( "Underlyings" );
  id impliedmarketindicator_id( "ImpliedMarketIndicator" );
  id instrattrib_id( "InstrAttrib" );
  id tickrules_id( "TickRules" );
  id legs_id( "Legs" );
  id securityupdateaction_id( "SecurityUpdateAction" );
  id lots_id( "Lots" );
  id minpriceincrement_id( "MinPriceIncrement" );
  id ticksizedenominator_id( "TickSizeDenominator" );
  id pricedivisor_id( "PriceDivisor" );
  id minorderqty_id( "MinOrderQty" );
  id maxorderqty_id( "MaxOrderQty" );
  id multilegmodel_id( "MultiLegModel" );
  id multilegpricemethod_id( "MultiLegPriceMethod" );
  id currency_id( "Currency" );
  id settlcurrency_id( "SettlCurrency" );
  id product_id( "Product" );
  id securitytype_id( "SecurityType" );
  id securitysubtype_id( "SecuritySubType" );
  id securitystrategytype_id( "SecurityStrategyType" );
  id asset_id( "Asset" );
  id securitydesc_id( "SecurityDesc" );
  id noshareissued_id( "NoShareIssued" );
  id maturitydate_id( "MaturityDate" );
  id maturitymonthyear_id( "MaturityMonthYear" );
  id strikeprice_id( "StrikePrice" );
  id strikecurrency_id( "StrikeCurrency" );
  id exercisestyle_id( "ExerciseStyle" );
  id putorcall_id( "PutOrCall" );
  id contractmultiplier_id( "ContractMultiplier" );
  id contractsettlmonth_id( "ContractSettlMonth" );
  id cficode_id( "CFICode" );
  id countryofissue_id( "CountryOfIssue" );
  id issuedate_id( "IssueDate" );
  id dateddate_id( "DatedDate" );
  id startdate_id( "StartDate" );
  id enddate_id( "EndDate" );
  id settltype_id( "SettlType" );
  id settldate_id( "SettlDate" );
  id securityvaliditytimestamp_id( "SecurityValidityTimestamp" );
  id marketsegmentid_id( "MarketSegmentID" );
  id governanceindicator_id( "GovernanceIndicator" );
  id corporateactioneventid_id( "CorporateActionEventID" );
  id securitygroup_id( "SecurityGroup" );
  id securitymatchtype_id( "SecurityMatchType" );
  id noapplids_id( "NoApplIDs" );
  id applid_id( "ApplID" );
  id feedtypes_id( "FeedTypes" );
  id nomdfeedtypes_id( "NoMDFeedTypes" );
  id mdfeedtype_id( "MDFeedType" );
  id marketdepth_id( "MarketDepth" );
  id nosecurityaltid_id( "NoSecurityAltID" );
  id securityaltid_id( "SecurityAltID" );
  id securityaltidsource_id( "SecurityAltIDSource" );
  id nounderlyings_id( "NoUnderlyings" );
  id underlyingsymbol_id( "UnderlyingSymbol" );
  id underlyingsecurityid_id( "UnderlyingSecurityID" );
  id underlyingsecurityidsource_id( "UnderlyingSecurityIDSource" );
  id underlyingsecurityexchange_id( "UnderlyingSecurityExchange" );
  id indexpct_id( "IndexPct" );
  id indextheoreticalqty_id( "IndexTheoreticalQty" );
  id noinstrattrib_id( "NoInstrAttrib" );
  id instattribtype_id( "InstAttribType" );
  id instattribvalue_id( "InstAttribValue" );
  id notickrules_id( "NoTickRules" );
  id starttickpricerange_id( "StartTickPriceRange" );
  id endtickpricerange_id( "EndTickPriceRange" );
  id tickincrement_id( "TickIncrement" );
  id tickruletype_id( "TickRuleType" );
  id nolegs_id( "NoLegs" );
  id legsymbol_id( "LegSymbol" );
  id legsecurityid_id( "LegSecurityID" );
  id legsecurityidsource_id( "LegSecurityIDSource" );
  id legratioqty_id( "LegRatioQty" );
  id legsecuritytype_id( "LegSecurityType" );
  id legside_id( "LegSide" );
  id legsecurityexchange_id( "LegSecurityExchange" );
  id nolottyperules_id( "NoLotTypeRules" );
  id lottype_id( "LotType" );
  id minlotsize_id( "MinLotSize" );

  msg.addField( msgtype_id, Messages::FieldAscii::create( "y" ) );
  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldAscii::create( "52" ) );
  msg.addField( totnorelatedsym_id, Messages::FieldUInt32::create( 393 ) );
  msg.addField( lastfragment_id, Messages::FieldAscii::create( "893" ) );

  Messages::SequencePtr RelatedSym_seq( new Messages::Sequence( relatedsym_id, 1 ) );
  Messages::FieldSetPtr RelatedSym( new Messages::FieldSet( 51 ) );

  RelatedSym->addField( symbol_id, Messages::FieldAscii::create( "55" ) );
  RelatedSym->addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  RelatedSym->addField( securityidsource_id, Messages::FieldAscii::create( "8" ) );
  RelatedSym->addField( securityexchange_id, Messages::FieldAscii::create( "BVMF" ) );
  RelatedSym->addField( impliedmarketindicator_id, Messages::FieldInt32::create( 1144 ) );
  RelatedSym->addField( securityupdateaction_id, Messages::FieldAscii::create( "980" ) );
  RelatedSym->addField( minpriceincrement_id, Messages::FieldDecimal::create( 969, 0 ) );
  RelatedSym->addField( ticksizedenominator_id, Messages::FieldUInt32::create( 5151 ) );
  RelatedSym->addField( pricedivisor_id, Messages::FieldDecimal::create( 37012, 0 ) );
  RelatedSym->addField( minorderqty_id, Messages::FieldUInt32::create( 9749 ) );
  RelatedSym->addField( maxorderqty_id, Messages::FieldUInt64::create( 9748 ) );
  RelatedSym->addField( multilegmodel_id, Messages::FieldInt32::create( 1377 ) );
  RelatedSym->addField( multilegpricemethod_id, Messages::FieldInt32::create( 1378 ) );
  RelatedSym->addField( currency_id, Messages::FieldAscii::create( "15" ) );
  RelatedSym->addField( settlcurrency_id, Messages::FieldAscii::create( "120" ) );
  RelatedSym->addField( product_id, Messages::FieldInt32::create( 460 ) );
  RelatedSym->addField( securitytype_id, Messages::FieldAscii::create( "167" ) );
  RelatedSym->addField( securitysubtype_id, Messages::FieldAscii::create( "762" ) );
  RelatedSym->addField( securitystrategytype_id, Messages::FieldAscii::create( "7534" ) );
  RelatedSym->addField( asset_id, Messages::FieldAscii::create( "6937" ) );
  RelatedSym->addField( securitydesc_id, Messages::FieldAscii::create( "107" ) );
  RelatedSym->addField( noshareissued_id, Messages::FieldUInt64::create( 7595 ) );
  RelatedSym->addField( maturitydate_id, Messages::FieldUInt32::create( 541 ) );
  RelatedSym->addField( maturitymonthyear_id, Messages::FieldUInt32::create( 200 ) );
  RelatedSym->addField( strikeprice_id, Messages::FieldDecimal::create( 202, 0 ) );
  RelatedSym->addField( strikecurrency_id, Messages::FieldAscii::create( "947" ) );
  RelatedSym->addField( exercisestyle_id, Messages::FieldInt32::create( 1194 ) );
  RelatedSym->addField( putorcall_id, Messages::FieldInt32::create( 201 ) );
  RelatedSym->addField( contractmultiplier_id, Messages::FieldDecimal::create( 231, 0 ) );
  RelatedSym->addField( contractsettlmonth_id, Messages::FieldUInt32::create( 667 ) );
  RelatedSym->addField( cficode_id, Messages::FieldAscii::create( "461" ) );
  RelatedSym->addField( countryofissue_id, Messages::FieldAscii::create( "470" ) );
  RelatedSym->addField( issuedate_id, Messages::FieldUInt32::create( 225 ) );
  RelatedSym->addField( dateddate_id, Messages::FieldUInt32::create( 873 ) );
  RelatedSym->addField( startdate_id, Messages::FieldUInt32::create( 916 ) );
  RelatedSym->addField( enddate_id, Messages::FieldUInt32::create( 917 ) );
  RelatedSym->addField( settltype_id, Messages::FieldAscii::create( "63" ) );
  RelatedSym->addField( settldate_id, Messages::FieldUInt32::create( 64 ) );
  RelatedSym->addField( securityvaliditytimestamp_id, Messages::FieldUInt64::create( 6938 ) );
  RelatedSym->addField( marketsegmentid_id, Messages::FieldAscii::create( "1300" ) );
  RelatedSym->addField( governanceindicator_id, Messages::FieldAscii::create( "37011" ) );
  RelatedSym->addField( corporateactioneventid_id, Messages::FieldInt32::create( 37010 ) );
  RelatedSym->addField( securitygroup_id, Messages::FieldAscii::create( "1151" ) );
  RelatedSym->addField( securitymatchtype_id, Messages::FieldInt32::create( 37015 ) );

  Messages::SequencePtr ApplIDs_seq( new Messages::Sequence( applids_id, 1 ) );
  Messages::FieldSetPtr ApplIDs( new Messages::FieldSet( 2 ) );

  ApplIDs->addField( applid_id, Messages::FieldAscii::create( "1180" ) );

  Messages::SequencePtr FeedTypes_seq( new Messages::Sequence( feedtypes_id, 1 ) );
  Messages::FieldSetPtr FeedTypes( new Messages::FieldSet( 2 ) );

  FeedTypes->addField( mdfeedtype_id, Messages::FieldAscii::create( "1022" ) );
  FeedTypes->addField( marketdepth_id, Messages::FieldUInt32::create( 264 ) );

  FeedTypes_seq->addEntry( FeedTypes );

  ApplIDs->addField( feedtypes_id, Messages::FieldSequence::create( FeedTypes_seq ) );

  ApplIDs_seq->addEntry( ApplIDs );

  RelatedSym->addField( applids_id, Messages::FieldSequence::create( ApplIDs_seq ) );

  Messages::SequencePtr SecurityAltIDs_seq( new Messages::Sequence( securityaltids_id, 1 ) );
  Messages::FieldSetPtr SecurityAltIDs( new Messages::FieldSet( 2 ) );

  SecurityAltIDs->addField( securityaltid_id, Messages::FieldAscii::create( "455" ) );
  SecurityAltIDs->addField( securityaltidsource_id, Messages::FieldAscii::create( "456" ) );

  SecurityAltIDs_seq->addEntry( SecurityAltIDs );

  RelatedSym->addField( securityaltids_id, Messages::FieldSequence::create( SecurityAltIDs_seq ) );

  Messages::SequencePtr Underlyings_seq( new Messages::Sequence( underlyings_id, 1 ) );
  Messages::FieldSetPtr Underlyings( new Messages::FieldSet( 6 ) );

  Underlyings->addField( underlyingsymbol_id, Messages::FieldAscii::create( "311" ) );
  Underlyings->addField( underlyingsecurityid_id, Messages::FieldUInt64::create( 309 ) );
  Underlyings->addField( underlyingsecurityidsource_id, Messages::FieldAscii::create( "8" ) );
  Underlyings->addField( underlyingsecurityexchange_id, Messages::FieldAscii::create( "BVMF" ) );
  Underlyings->addField( indexpct_id, Messages::FieldDecimal::create( 6919, 0 ) );
  Underlyings->addField( indextheoreticalqty_id, Messages::FieldDecimal::create( 37021, 0 ) );

  Underlyings_seq->addEntry( Underlyings );

  RelatedSym->addField( underlyings_id, Messages::FieldSequence::create( Underlyings_seq ) );

  Messages::SequencePtr InstrAttrib_seq( new Messages::Sequence( instrattrib_id, 1 ) );
  Messages::FieldSetPtr InstrAttrib( new Messages::FieldSet( 2 ) );

  InstrAttrib->addField( instattribtype_id, Messages::FieldInt32::create( 871 ) );
  InstrAttrib->addField( instattribvalue_id, Messages::FieldAscii::create( "872" ) );

  InstrAttrib_seq->addEntry( InstrAttrib );

  RelatedSym->addField( instrattrib_id, Messages::FieldSequence::create( InstrAttrib_seq ) );

  Messages::SequencePtr TickRules_seq( new Messages::Sequence( tickrules_id, 1 ) );
  Messages::FieldSetPtr TickRules( new Messages::FieldSet( 4 ) );

  TickRules->addField( starttickpricerange_id, Messages::FieldDecimal::create( 1206, 0 ) );
  TickRules->addField( endtickpricerange_id, Messages::FieldDecimal::create( 1207, 0 ) );
  TickRules->addField( tickincrement_id, Messages::FieldDecimal::create( 1208, 0 ) );
  TickRules->addField( tickruletype_id, Messages::FieldInt32::create( 1209 ) );

  TickRules_seq->addEntry( TickRules );

  RelatedSym->addField( tickrules_id, Messages::FieldSequence::create( TickRules_seq ) );

  Messages::SequencePtr Legs_seq( new Messages::Sequence( legs_id, 1 ) );
  Messages::FieldSetPtr Legs( new Messages::FieldSet( 7 ) );

  Legs->addField( legsymbol_id, Messages::FieldAscii::create( "600" ) );
  Legs->addField( legsecurityid_id, Messages::FieldUInt64::create( 602 ) );
  Legs->addField( legsecurityidsource_id, Messages::FieldAscii::create( "8" ) );
  Legs->addField( legratioqty_id, Messages::FieldInt32::create( 623 ) );
  Legs->addField( legsecuritytype_id, Messages::FieldAscii::create( "609" ) );
  Legs->addField( legside_id, Messages::FieldInt32::create( 624 ) );
  Legs->addField( legsecurityexchange_id, Messages::FieldAscii::create( "BVMF" ) );

  Legs_seq->addEntry( Legs );

  RelatedSym->addField( legs_id, Messages::FieldSequence::create( Legs_seq ) );

  Messages::SequencePtr Lots_seq( new Messages::Sequence( lots_id, 1 ) );
  Messages::FieldSetPtr Lots( new Messages::FieldSet( 2 ) );

  Lots->addField( lottype_id, Messages::FieldInt32::create( 1093 ) );
  Lots->addField( minlotsize_id, Messages::FieldUInt32::create( 1231 ) );

  Lots_seq->addEntry( Lots );

  RelatedSym->addField( lots_id, Messages::FieldSequence::create( Lots_seq ) );

  RelatedSym_seq->addEntry( RelatedSym );

  msg.addField( relatedsym_id, Messages::FieldSequence::create( RelatedSym_seq ) );

  encoder.encodeMessage( destination, 149, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<security_list_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "y", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  security_list& m = container.message_;

  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "y" );
  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, "52" );
  BOOST_CHECK( m.TotNoRelatedSym().first );
  BOOST_CHECK_EQUAL( m.TotNoRelatedSym().second, 393 );
  BOOST_CHECK( m.LastFragment().first );
  BOOST_CHECK_EQUAL( m.LastFragment().second, "893" );

  BOOST_REQUIRE_EQUAL( m.RelatedSym().size(), 1 );
  const security_list::relatedsym& RelatedSym_msg = m.RelatedSym()[0];

  BOOST_CHECK( RelatedSym_msg.Symbol().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.Symbol().second, "55" );
  BOOST_CHECK( RelatedSym_msg.SecurityID().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityID().second, 48 );
  BOOST_CHECK( RelatedSym_msg.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityIDSource().second, "8" );
  BOOST_CHECK( RelatedSym_msg.SecurityExchange().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityExchange().second, "BVMF" );
  BOOST_CHECK( RelatedSym_msg.ImpliedMarketIndicator().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.ImpliedMarketIndicator().second, 1144 );
  BOOST_CHECK( RelatedSym_msg.SecurityUpdateAction().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityUpdateAction().second, "980" );
  BOOST_CHECK( RelatedSym_msg.MinPriceIncrement().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MinPriceIncrement().second, apoena::msi::decimal( 969, 0 ) );
  BOOST_CHECK( RelatedSym_msg.TickSizeDenominator().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.TickSizeDenominator().second, 5151 );
  BOOST_CHECK( RelatedSym_msg.PriceDivisor().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.PriceDivisor().second, apoena::msi::decimal( 37012, 0 ) );
  BOOST_CHECK( RelatedSym_msg.MinOrderQty().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MinOrderQty().second, 9749 );
  BOOST_CHECK( RelatedSym_msg.MaxOrderQty().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MaxOrderQty().second, 9748 );
  BOOST_CHECK( RelatedSym_msg.MultiLegModel().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MultiLegModel().second, 1377 );
  BOOST_CHECK( RelatedSym_msg.MultiLegPriceMethod().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MultiLegPriceMethod().second, 1378 );
  BOOST_CHECK( RelatedSym_msg.Currency().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.Currency().second, "15" );
  BOOST_CHECK( RelatedSym_msg.SettlCurrency().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SettlCurrency().second, "120" );
  BOOST_CHECK( RelatedSym_msg.Product().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.Product().second, 460 );
  BOOST_CHECK( RelatedSym_msg.SecurityType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityType().second, "167" );
  BOOST_CHECK( RelatedSym_msg.SecuritySubType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecuritySubType().second, "762" );
  BOOST_CHECK( RelatedSym_msg.SecurityStrategyType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityStrategyType().second, "7534" );
  BOOST_CHECK( RelatedSym_msg.Asset().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.Asset().second, "6937" );
  BOOST_CHECK( RelatedSym_msg.SecurityDesc().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityDesc().second, "107" );
  BOOST_CHECK( RelatedSym_msg.NoShareIssued().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.NoShareIssued().second, 7595 );
  BOOST_CHECK( RelatedSym_msg.MaturityDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MaturityDate().second, 541 );
  BOOST_CHECK( RelatedSym_msg.MaturityMonthYear().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MaturityMonthYear().second, 200 );
  BOOST_CHECK( RelatedSym_msg.StrikePrice().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.StrikePrice().second, apoena::msi::decimal( 202, 0 ) );
  BOOST_CHECK( RelatedSym_msg.StrikeCurrency().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.StrikeCurrency().second, "947" );
  BOOST_CHECK( RelatedSym_msg.ExerciseStyle().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.ExerciseStyle().second, 1194 );
  BOOST_CHECK( RelatedSym_msg.PutOrCall().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.PutOrCall().second, 201 );
  BOOST_CHECK( RelatedSym_msg.ContractMultiplier().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.ContractMultiplier().second, apoena::msi::decimal( 231, 0 ) );
  BOOST_CHECK( RelatedSym_msg.ContractSettlMonth().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.ContractSettlMonth().second, 667 );
  BOOST_CHECK( RelatedSym_msg.CFICode().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.CFICode().second, "461" );
  BOOST_CHECK( RelatedSym_msg.CountryOfIssue().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.CountryOfIssue().second, "470" );
  BOOST_CHECK( RelatedSym_msg.IssueDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.IssueDate().second, 225 );
  BOOST_CHECK( RelatedSym_msg.DatedDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.DatedDate().second, 873 );
  BOOST_CHECK( RelatedSym_msg.StartDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.StartDate().second, 916 );
  BOOST_CHECK( RelatedSym_msg.EndDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.EndDate().second, 917 );
  BOOST_CHECK( RelatedSym_msg.SettlType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SettlType().second, "63" );
  BOOST_CHECK( RelatedSym_msg.SettlDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SettlDate().second, 64 );
  BOOST_CHECK( RelatedSym_msg.SecurityValidityTimestamp().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityValidityTimestamp().second, 6938 );
  BOOST_CHECK( RelatedSym_msg.MarketSegmentID().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MarketSegmentID().second, "1300" );
  BOOST_CHECK( RelatedSym_msg.GovernanceIndicator().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.GovernanceIndicator().second, "37011" );
  BOOST_CHECK( RelatedSym_msg.CorporateActionEventID().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.CorporateActionEventID().second, 37010 );
  BOOST_CHECK( RelatedSym_msg.SecurityGroup().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityGroup().second, "1151" );
  BOOST_CHECK( RelatedSym_msg.SecurityMatchType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityMatchType().second, 37015 );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.ApplIDs().size(), 1 );
  const security_list::relatedsym::applids& ApplIDs_msg = RelatedSym_msg.ApplIDs()[0];

  BOOST_CHECK( ApplIDs_msg.ApplID().first );
  BOOST_CHECK_EQUAL( ApplIDs_msg.ApplID().second, "1180" );

  BOOST_REQUIRE_EQUAL( ApplIDs_msg.FeedTypes().size(), 1 );
  const security_list::relatedsym::applids::feedtypes& FeedTypes_msg = ApplIDs_msg.FeedTypes()[0];

  BOOST_CHECK( FeedTypes_msg.MDFeedType().first );
  BOOST_CHECK_EQUAL( FeedTypes_msg.MDFeedType().second, "1022" );
  BOOST_CHECK( FeedTypes_msg.MarketDepth().first );
  BOOST_CHECK_EQUAL( FeedTypes_msg.MarketDepth().second, 264 );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.SecurityAltIDs().size(), 1 );
  const security_list::relatedsym::securityaltids& SecurityAltIDs_msg = RelatedSym_msg.SecurityAltIDs()[0];

  BOOST_CHECK( SecurityAltIDs_msg.SecurityAltID().first );
  BOOST_CHECK_EQUAL( SecurityAltIDs_msg.SecurityAltID().second, "455" );
  BOOST_CHECK( SecurityAltIDs_msg.SecurityAltIDSource().first );
  BOOST_CHECK_EQUAL( SecurityAltIDs_msg.SecurityAltIDSource().second, "456" );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.Underlyings().size(), 1 );
  const security_list::relatedsym::underlyings& Underlyings_msg = RelatedSym_msg.Underlyings()[0];

  BOOST_CHECK( Underlyings_msg.UnderlyingSymbol().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSymbol().second, "311" );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityID().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityID().second, 309 );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityIDSource().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityIDSource().second, "8" );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityExchange().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityExchange().second, "BVMF" );
  BOOST_CHECK( Underlyings_msg.IndexPct().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.IndexPct().second, apoena::msi::decimal( 6919, 0 ) );
  BOOST_CHECK( Underlyings_msg.IndexTheoreticalQty().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.IndexTheoreticalQty().second, apoena::msi::decimal( 37021, 0 ) );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.InstrAttrib().size(), 1 );
  const security_list::relatedsym::instrattrib& InstrAttrib_msg = RelatedSym_msg.InstrAttrib()[0];

  BOOST_CHECK( InstrAttrib_msg.InstAttribType().first );
  BOOST_CHECK_EQUAL( InstrAttrib_msg.InstAttribType().second, 871 );
  BOOST_CHECK( InstrAttrib_msg.InstAttribValue().first );
  BOOST_CHECK_EQUAL( InstrAttrib_msg.InstAttribValue().second, "872" );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.TickRules().size(), 1 );
  const security_list::relatedsym::tickrules& TickRules_msg = RelatedSym_msg.TickRules()[0];

  BOOST_CHECK( TickRules_msg.StartTickPriceRange().first );
  BOOST_CHECK_EQUAL( TickRules_msg.StartTickPriceRange().second, apoena::msi::decimal( 1206, 0 ) );
  BOOST_CHECK( TickRules_msg.EndTickPriceRange().first );
  BOOST_CHECK_EQUAL( TickRules_msg.EndTickPriceRange().second, apoena::msi::decimal( 1207, 0 ) );
  BOOST_CHECK( TickRules_msg.TickIncrement().first );
  BOOST_CHECK_EQUAL( TickRules_msg.TickIncrement().second, apoena::msi::decimal( 1208, 0 ) );
  BOOST_CHECK( TickRules_msg.TickRuleType().first );
  BOOST_CHECK_EQUAL( TickRules_msg.TickRuleType().second, 1209 );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.Legs().size(), 1 );
  const security_list::relatedsym::legs& Legs_msg = RelatedSym_msg.Legs()[0];

  BOOST_CHECK( Legs_msg.LegSymbol().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSymbol().second, "600" );
  BOOST_CHECK( Legs_msg.LegSecurityID().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSecurityID().second, 602 );
  BOOST_CHECK( Legs_msg.LegSecurityIDSource().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSecurityIDSource().second, "8" );
  BOOST_CHECK( Legs_msg.LegRatioQty().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegRatioQty().second, 623 );
  BOOST_CHECK( Legs_msg.LegSecurityType().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSecurityType().second, "609" );
  BOOST_CHECK( Legs_msg.LegSide().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSide().second, 624 );
  BOOST_CHECK( Legs_msg.LegSecurityExchange().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSecurityExchange().second, "BVMF" );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.Lots().size(), 1 );
  const security_list::relatedsym::lots& Lots_msg = RelatedSym_msg.Lots()[0];

  BOOST_CHECK( Lots_msg.LotType().first );
  BOOST_CHECK_EQUAL( Lots_msg.LotType().second, 1093 );
  BOOST_CHECK( Lots_msg.MinLotSize().first );
  BOOST_CHECK_EQUAL( Lots_msg.MinLotSize().second, 1231 );

}

BOOST_AUTO_TEST_CASE( test_builder_148 )
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

  id msgtype_id( "MsgType" );
  id applverid_id( "ApplVerID" );
  id msgseqnum_id( "MsgSeqNum" );
  id sendingtime_id( "SendingTime" );
  id totnorelatedsym_id( "TotNoRelatedSym" );
  id lastfragment_id( "LastFragment" );
  id relatedsym_id( "RelatedSym" );
  id norelatedsym_id( "NoRelatedSym" );
  id symbol_id( "Symbol" );
  id securityid_id( "SecurityID" );
  id securityidsource_id( "SecurityIDSource" );
  id securityexchange_id( "SecurityExchange" );
  id applids_id( "ApplIDs" );
  id securityaltids_id( "SecurityAltIDs" );
  id underlyings_id( "Underlyings" );
  id impliedmarketindicator_id( "ImpliedMarketIndicator" );
  id instrattrib_id( "InstrAttrib" );
  id tickrules_id( "TickRules" );
  id legs_id( "Legs" );
  id securityupdateaction_id( "SecurityUpdateAction" );
  id lots_id( "Lots" );
  id minpriceincrement_id( "MinPriceIncrement" );
  id ticksizedenominator_id( "TickSizeDenominator" );
  id pricedivisor_id( "PriceDivisor" );
  id minorderqty_id( "MinOrderQty" );
  id maxorderqty_id( "MaxOrderQty" );
  id multilegmodel_id( "MultiLegModel" );
  id multilegpricemethod_id( "MultiLegPriceMethod" );
  id currency_id( "Currency" );
  id settlcurrency_id( "SettlCurrency" );
  id product_id( "Product" );
  id securitytype_id( "SecurityType" );
  id securitysubtype_id( "SecuritySubType" );
  id securitystrategytype_id( "SecurityStrategyType" );
  id asset_id( "Asset" );
  id securitydesc_id( "SecurityDesc" );
  id noshareissued_id( "NoShareIssued" );
  id maturitydate_id( "MaturityDate" );
  id maturitymonthyear_id( "MaturityMonthYear" );
  id strikeprice_id( "StrikePrice" );
  id strikecurrency_id( "StrikeCurrency" );
  id exercisestyle_id( "ExerciseStyle" );
  id putorcall_id( "PutOrCall" );
  id contractmultiplier_id( "ContractMultiplier" );
  id contractsettlmonth_id( "ContractSettlMonth" );
  id cficode_id( "CFICode" );
  id countryofissue_id( "CountryOfIssue" );
  id issuedate_id( "IssueDate" );
  id dateddate_id( "DatedDate" );
  id startdate_id( "StartDate" );
  id enddate_id( "EndDate" );
  id settltype_id( "SettlType" );
  id settldate_id( "SettlDate" );
  id securityvaliditytimestamp_id( "SecurityValidityTimestamp" );
  id marketsegmentid_id( "MarketSegmentID" );
  id governanceindicator_id( "GovernanceIndicator" );
  id corporateactioneventid_id( "CorporateActionEventID" );
  id securitygroup_id( "SecurityGroup" );
  id securitymatchtype_id( "SecurityMatchType" );
  id noapplids_id( "NoApplIDs" );
  id applid_id( "ApplID" );
  id feedtypes_id( "FeedTypes" );
  id nomdfeedtypes_id( "NoMDFeedTypes" );
  id mdfeedtype_id( "MDFeedType" );
  id marketdepth_id( "MarketDepth" );
  id nosecurityaltid_id( "NoSecurityAltID" );
  id securityaltid_id( "SecurityAltID" );
  id securityaltidsource_id( "SecurityAltIDSource" );
  id nounderlyings_id( "NoUnderlyings" );
  id underlyingsymbol_id( "UnderlyingSymbol" );
  id underlyingsecurityid_id( "UnderlyingSecurityID" );
  id underlyingsecurityidsource_id( "UnderlyingSecurityIDSource" );
  id underlyingsecurityexchange_id( "UnderlyingSecurityExchange" );
  id indexpct_id( "IndexPct" );
  id noinstrattrib_id( "NoInstrAttrib" );
  id instattribtype_id( "InstAttribType" );
  id instattribvalue_id( "InstAttribValue" );
  id notickrules_id( "NoTickRules" );
  id starttickpricerange_id( "StartTickPriceRange" );
  id endtickpricerange_id( "EndTickPriceRange" );
  id tickincrement_id( "TickIncrement" );
  id tickruletype_id( "TickRuleType" );
  id nolegs_id( "NoLegs" );
  id legsymbol_id( "LegSymbol" );
  id legsecurityid_id( "LegSecurityID" );
  id legsecurityidsource_id( "LegSecurityIDSource" );
  id legratioqty_id( "LegRatioQty" );
  id legsecuritytype_id( "LegSecurityType" );
  id legside_id( "LegSide" );
  id legsecurityexchange_id( "LegSecurityExchange" );
  id nolottyperules_id( "NoLotTypeRules" );
  id lottype_id( "LotType" );
  id minlotsize_id( "MinLotSize" );

  msg.addField( msgtype_id, Messages::FieldAscii::create( "y" ) );
  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldAscii::create( "52" ) );
  msg.addField( totnorelatedsym_id, Messages::FieldUInt32::create( 393 ) );
  msg.addField( lastfragment_id, Messages::FieldAscii::create( "893" ) );

  Messages::SequencePtr RelatedSym_seq( new Messages::Sequence( relatedsym_id, 1 ) );
  Messages::FieldSetPtr RelatedSym( new Messages::FieldSet( 51 ) );

  RelatedSym->addField( symbol_id, Messages::FieldAscii::create( "55" ) );
  RelatedSym->addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  RelatedSym->addField( securityidsource_id, Messages::FieldAscii::create( "8" ) );
  RelatedSym->addField( securityexchange_id, Messages::FieldAscii::create( "BVMF" ) );
  RelatedSym->addField( impliedmarketindicator_id, Messages::FieldInt32::create( 1144 ) );
  RelatedSym->addField( securityupdateaction_id, Messages::FieldAscii::create( "980" ) );
  RelatedSym->addField( minpriceincrement_id, Messages::FieldDecimal::create( 969, 0 ) );
  RelatedSym->addField( ticksizedenominator_id, Messages::FieldUInt32::create( 5151 ) );
  RelatedSym->addField( pricedivisor_id, Messages::FieldDecimal::create( 37012, 0 ) );
  RelatedSym->addField( minorderqty_id, Messages::FieldUInt32::create( 9749 ) );
  RelatedSym->addField( maxorderqty_id, Messages::FieldUInt64::create( 9748 ) );
  RelatedSym->addField( multilegmodel_id, Messages::FieldInt32::create( 1377 ) );
  RelatedSym->addField( multilegpricemethod_id, Messages::FieldInt32::create( 1378 ) );
  RelatedSym->addField( currency_id, Messages::FieldAscii::create( "15" ) );
  RelatedSym->addField( settlcurrency_id, Messages::FieldAscii::create( "120" ) );
  RelatedSym->addField( product_id, Messages::FieldInt32::create( 460 ) );
  RelatedSym->addField( securitytype_id, Messages::FieldAscii::create( "167" ) );
  RelatedSym->addField( securitysubtype_id, Messages::FieldAscii::create( "762" ) );
  RelatedSym->addField( securitystrategytype_id, Messages::FieldAscii::create( "7534" ) );
  RelatedSym->addField( asset_id, Messages::FieldAscii::create( "6937" ) );
  RelatedSym->addField( securitydesc_id, Messages::FieldAscii::create( "107" ) );
  RelatedSym->addField( noshareissued_id, Messages::FieldUInt64::create( 7595 ) );
  RelatedSym->addField( maturitydate_id, Messages::FieldUInt32::create( 541 ) );
  RelatedSym->addField( maturitymonthyear_id, Messages::FieldUInt32::create( 200 ) );
  RelatedSym->addField( strikeprice_id, Messages::FieldDecimal::create( 202, 0 ) );
  RelatedSym->addField( strikecurrency_id, Messages::FieldAscii::create( "947" ) );
  RelatedSym->addField( exercisestyle_id, Messages::FieldInt32::create( 1194 ) );
  RelatedSym->addField( putorcall_id, Messages::FieldInt32::create( 201 ) );
  RelatedSym->addField( contractmultiplier_id, Messages::FieldDecimal::create( 231, 0 ) );
  RelatedSym->addField( contractsettlmonth_id, Messages::FieldUInt32::create( 667 ) );
  RelatedSym->addField( cficode_id, Messages::FieldAscii::create( "461" ) );
  RelatedSym->addField( countryofissue_id, Messages::FieldAscii::create( "470" ) );
  RelatedSym->addField( issuedate_id, Messages::FieldUInt32::create( 225 ) );
  RelatedSym->addField( dateddate_id, Messages::FieldUInt32::create( 873 ) );
  RelatedSym->addField( startdate_id, Messages::FieldUInt32::create( 916 ) );
  RelatedSym->addField( enddate_id, Messages::FieldUInt32::create( 917 ) );
  RelatedSym->addField( settltype_id, Messages::FieldAscii::create( "63" ) );
  RelatedSym->addField( settldate_id, Messages::FieldUInt32::create( 64 ) );
  RelatedSym->addField( securityvaliditytimestamp_id, Messages::FieldUInt64::create( 6938 ) );
  RelatedSym->addField( marketsegmentid_id, Messages::FieldAscii::create( "1300" ) );
  RelatedSym->addField( governanceindicator_id, Messages::FieldAscii::create( "37011" ) );
  RelatedSym->addField( corporateactioneventid_id, Messages::FieldInt32::create( 37010 ) );
  RelatedSym->addField( securitygroup_id, Messages::FieldAscii::create( "1151" ) );
  RelatedSym->addField( securitymatchtype_id, Messages::FieldInt32::create( 37015 ) );

  Messages::SequencePtr ApplIDs_seq( new Messages::Sequence( applids_id, 1 ) );
  Messages::FieldSetPtr ApplIDs( new Messages::FieldSet( 2 ) );

  ApplIDs->addField( applid_id, Messages::FieldAscii::create( "1180" ) );

  Messages::SequencePtr FeedTypes_seq( new Messages::Sequence( feedtypes_id, 1 ) );
  Messages::FieldSetPtr FeedTypes( new Messages::FieldSet( 2 ) );

  FeedTypes->addField( mdfeedtype_id, Messages::FieldAscii::create( "1022" ) );
  FeedTypes->addField( marketdepth_id, Messages::FieldUInt32::create( 264 ) );

  FeedTypes_seq->addEntry( FeedTypes );

  ApplIDs->addField( feedtypes_id, Messages::FieldSequence::create( FeedTypes_seq ) );

  ApplIDs_seq->addEntry( ApplIDs );

  RelatedSym->addField( applids_id, Messages::FieldSequence::create( ApplIDs_seq ) );

  Messages::SequencePtr SecurityAltIDs_seq( new Messages::Sequence( securityaltids_id, 1 ) );
  Messages::FieldSetPtr SecurityAltIDs( new Messages::FieldSet( 2 ) );

  SecurityAltIDs->addField( securityaltid_id, Messages::FieldAscii::create( "455" ) );
  SecurityAltIDs->addField( securityaltidsource_id, Messages::FieldAscii::create( "456" ) );

  SecurityAltIDs_seq->addEntry( SecurityAltIDs );

  RelatedSym->addField( securityaltids_id, Messages::FieldSequence::create( SecurityAltIDs_seq ) );

  Messages::SequencePtr Underlyings_seq( new Messages::Sequence( underlyings_id, 1 ) );
  Messages::FieldSetPtr Underlyings( new Messages::FieldSet( 5 ) );

  Underlyings->addField( underlyingsymbol_id, Messages::FieldAscii::create( "311" ) );
  Underlyings->addField( underlyingsecurityid_id, Messages::FieldUInt64::create( 309 ) );
  Underlyings->addField( underlyingsecurityidsource_id, Messages::FieldAscii::create( "8" ) );
  Underlyings->addField( underlyingsecurityexchange_id, Messages::FieldAscii::create( "BVMF" ) );
  Underlyings->addField( indexpct_id, Messages::FieldDecimal::create( 6919, 0 ) );

  Underlyings_seq->addEntry( Underlyings );

  RelatedSym->addField( underlyings_id, Messages::FieldSequence::create( Underlyings_seq ) );

  Messages::SequencePtr InstrAttrib_seq( new Messages::Sequence( instrattrib_id, 1 ) );
  Messages::FieldSetPtr InstrAttrib( new Messages::FieldSet( 2 ) );

  InstrAttrib->addField( instattribtype_id, Messages::FieldInt32::create( 871 ) );
  InstrAttrib->addField( instattribvalue_id, Messages::FieldAscii::create( "872" ) );

  InstrAttrib_seq->addEntry( InstrAttrib );

  RelatedSym->addField( instrattrib_id, Messages::FieldSequence::create( InstrAttrib_seq ) );

  Messages::SequencePtr TickRules_seq( new Messages::Sequence( tickrules_id, 1 ) );
  Messages::FieldSetPtr TickRules( new Messages::FieldSet( 4 ) );

  TickRules->addField( starttickpricerange_id, Messages::FieldDecimal::create( 1206, 0 ) );
  TickRules->addField( endtickpricerange_id, Messages::FieldDecimal::create( 1207, 0 ) );
  TickRules->addField( tickincrement_id, Messages::FieldDecimal::create( 1208, 0 ) );
  TickRules->addField( tickruletype_id, Messages::FieldInt32::create( 1209 ) );

  TickRules_seq->addEntry( TickRules );

  RelatedSym->addField( tickrules_id, Messages::FieldSequence::create( TickRules_seq ) );

  Messages::SequencePtr Legs_seq( new Messages::Sequence( legs_id, 1 ) );
  Messages::FieldSetPtr Legs( new Messages::FieldSet( 7 ) );

  Legs->addField( legsymbol_id, Messages::FieldAscii::create( "600" ) );
  Legs->addField( legsecurityid_id, Messages::FieldUInt64::create( 602 ) );
  Legs->addField( legsecurityidsource_id, Messages::FieldAscii::create( "8" ) );
  Legs->addField( legratioqty_id, Messages::FieldInt32::create( 623 ) );
  Legs->addField( legsecuritytype_id, Messages::FieldAscii::create( "609" ) );
  Legs->addField( legside_id, Messages::FieldInt32::create( 624 ) );
  Legs->addField( legsecurityexchange_id, Messages::FieldAscii::create( "BVMF" ) );

  Legs_seq->addEntry( Legs );

  RelatedSym->addField( legs_id, Messages::FieldSequence::create( Legs_seq ) );

  Messages::SequencePtr Lots_seq( new Messages::Sequence( lots_id, 1 ) );
  Messages::FieldSetPtr Lots( new Messages::FieldSet( 2 ) );

  Lots->addField( lottype_id, Messages::FieldInt32::create( 1093 ) );
  Lots->addField( minlotsize_id, Messages::FieldUInt32::create( 1231 ) );

  Lots_seq->addEntry( Lots );

  RelatedSym->addField( lots_id, Messages::FieldSequence::create( Lots_seq ) );

  RelatedSym_seq->addEntry( RelatedSym );

  msg.addField( relatedsym_id, Messages::FieldSequence::create( RelatedSym_seq ) );

  encoder.encodeMessage( destination, 148, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<security_list_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "y", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  security_list& m = container.message_;

  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "y" );
  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, "52" );
  BOOST_CHECK( m.TotNoRelatedSym().first );
  BOOST_CHECK_EQUAL( m.TotNoRelatedSym().second, 393 );
  BOOST_CHECK( m.LastFragment().first );
  BOOST_CHECK_EQUAL( m.LastFragment().second, "893" );

  BOOST_REQUIRE_EQUAL( m.RelatedSym().size(), 1 );
  const security_list::relatedsym& RelatedSym_msg = m.RelatedSym()[0];

  BOOST_CHECK( RelatedSym_msg.Symbol().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.Symbol().second, "55" );
  BOOST_CHECK( RelatedSym_msg.SecurityID().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityID().second, 48 );
  BOOST_CHECK( RelatedSym_msg.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityIDSource().second, "8" );
  BOOST_CHECK( RelatedSym_msg.SecurityExchange().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityExchange().second, "BVMF" );
  BOOST_CHECK( RelatedSym_msg.ImpliedMarketIndicator().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.ImpliedMarketIndicator().second, 1144 );
  BOOST_CHECK( RelatedSym_msg.SecurityUpdateAction().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityUpdateAction().second, "980" );
  BOOST_CHECK( RelatedSym_msg.MinPriceIncrement().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MinPriceIncrement().second, apoena::msi::decimal( 969, 0 ) );
  BOOST_CHECK( RelatedSym_msg.TickSizeDenominator().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.TickSizeDenominator().second, 5151 );
  BOOST_CHECK( RelatedSym_msg.PriceDivisor().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.PriceDivisor().second, apoena::msi::decimal( 37012, 0 ) );
  BOOST_CHECK( RelatedSym_msg.MinOrderQty().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MinOrderQty().second, 9749 );
  BOOST_CHECK( RelatedSym_msg.MaxOrderQty().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MaxOrderQty().second, 9748 );
  BOOST_CHECK( RelatedSym_msg.MultiLegModel().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MultiLegModel().second, 1377 );
  BOOST_CHECK( RelatedSym_msg.MultiLegPriceMethod().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MultiLegPriceMethod().second, 1378 );
  BOOST_CHECK( RelatedSym_msg.Currency().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.Currency().second, "15" );
  BOOST_CHECK( RelatedSym_msg.SettlCurrency().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SettlCurrency().second, "120" );
  BOOST_CHECK( RelatedSym_msg.Product().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.Product().second, 460 );
  BOOST_CHECK( RelatedSym_msg.SecurityType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityType().second, "167" );
  BOOST_CHECK( RelatedSym_msg.SecuritySubType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecuritySubType().second, "762" );
  BOOST_CHECK( RelatedSym_msg.SecurityStrategyType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityStrategyType().second, "7534" );
  BOOST_CHECK( RelatedSym_msg.Asset().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.Asset().second, "6937" );
  BOOST_CHECK( RelatedSym_msg.SecurityDesc().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityDesc().second, "107" );
  BOOST_CHECK( RelatedSym_msg.NoShareIssued().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.NoShareIssued().second, 7595 );
  BOOST_CHECK( RelatedSym_msg.MaturityDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MaturityDate().second, 541 );
  BOOST_CHECK( RelatedSym_msg.MaturityMonthYear().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MaturityMonthYear().second, 200 );
  BOOST_CHECK( RelatedSym_msg.StrikePrice().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.StrikePrice().second, apoena::msi::decimal( 202, 0 ) );
  BOOST_CHECK( RelatedSym_msg.StrikeCurrency().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.StrikeCurrency().second, "947" );
  BOOST_CHECK( RelatedSym_msg.ExerciseStyle().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.ExerciseStyle().second, 1194 );
  BOOST_CHECK( RelatedSym_msg.PutOrCall().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.PutOrCall().second, 201 );
  BOOST_CHECK( RelatedSym_msg.ContractMultiplier().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.ContractMultiplier().second, apoena::msi::decimal( 231, 0 ) );
  BOOST_CHECK( RelatedSym_msg.ContractSettlMonth().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.ContractSettlMonth().second, 667 );
  BOOST_CHECK( RelatedSym_msg.CFICode().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.CFICode().second, "461" );
  BOOST_CHECK( RelatedSym_msg.CountryOfIssue().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.CountryOfIssue().second, "470" );
  BOOST_CHECK( RelatedSym_msg.IssueDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.IssueDate().second, 225 );
  BOOST_CHECK( RelatedSym_msg.DatedDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.DatedDate().second, 873 );
  BOOST_CHECK( RelatedSym_msg.StartDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.StartDate().second, 916 );
  BOOST_CHECK( RelatedSym_msg.EndDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.EndDate().second, 917 );
  BOOST_CHECK( RelatedSym_msg.SettlType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SettlType().second, "63" );
  BOOST_CHECK( RelatedSym_msg.SettlDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SettlDate().second, 64 );
  BOOST_CHECK( RelatedSym_msg.SecurityValidityTimestamp().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityValidityTimestamp().second, 6938 );
  BOOST_CHECK( RelatedSym_msg.MarketSegmentID().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MarketSegmentID().second, "1300" );
  BOOST_CHECK( RelatedSym_msg.GovernanceIndicator().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.GovernanceIndicator().second, "37011" );
  BOOST_CHECK( RelatedSym_msg.CorporateActionEventID().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.CorporateActionEventID().second, 37010 );
  BOOST_CHECK( RelatedSym_msg.SecurityGroup().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityGroup().second, "1151" );
  BOOST_CHECK( RelatedSym_msg.SecurityMatchType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityMatchType().second, 37015 );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.ApplIDs().size(), 1 );
  const security_list::relatedsym::applids& ApplIDs_msg = RelatedSym_msg.ApplIDs()[0];

  BOOST_CHECK( ApplIDs_msg.ApplID().first );
  BOOST_CHECK_EQUAL( ApplIDs_msg.ApplID().second, "1180" );

  BOOST_REQUIRE_EQUAL( ApplIDs_msg.FeedTypes().size(), 1 );
  const security_list::relatedsym::applids::feedtypes& FeedTypes_msg = ApplIDs_msg.FeedTypes()[0];

  BOOST_CHECK( FeedTypes_msg.MDFeedType().first );
  BOOST_CHECK_EQUAL( FeedTypes_msg.MDFeedType().second, "1022" );
  BOOST_CHECK( FeedTypes_msg.MarketDepth().first );
  BOOST_CHECK_EQUAL( FeedTypes_msg.MarketDepth().second, 264 );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.SecurityAltIDs().size(), 1 );
  const security_list::relatedsym::securityaltids& SecurityAltIDs_msg = RelatedSym_msg.SecurityAltIDs()[0];

  BOOST_CHECK( SecurityAltIDs_msg.SecurityAltID().first );
  BOOST_CHECK_EQUAL( SecurityAltIDs_msg.SecurityAltID().second, "455" );
  BOOST_CHECK( SecurityAltIDs_msg.SecurityAltIDSource().first );
  BOOST_CHECK_EQUAL( SecurityAltIDs_msg.SecurityAltIDSource().second, "456" );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.Underlyings().size(), 1 );
  const security_list::relatedsym::underlyings& Underlyings_msg = RelatedSym_msg.Underlyings()[0];

  BOOST_CHECK( Underlyings_msg.UnderlyingSymbol().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSymbol().second, "311" );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityID().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityID().second, 309 );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityIDSource().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityIDSource().second, "8" );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityExchange().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityExchange().second, "BVMF" );
  BOOST_CHECK( Underlyings_msg.IndexPct().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.IndexPct().second, apoena::msi::decimal( 6919, 0 ) );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.InstrAttrib().size(), 1 );
  const security_list::relatedsym::instrattrib& InstrAttrib_msg = RelatedSym_msg.InstrAttrib()[0];

  BOOST_CHECK( InstrAttrib_msg.InstAttribType().first );
  BOOST_CHECK_EQUAL( InstrAttrib_msg.InstAttribType().second, 871 );
  BOOST_CHECK( InstrAttrib_msg.InstAttribValue().first );
  BOOST_CHECK_EQUAL( InstrAttrib_msg.InstAttribValue().second, "872" );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.TickRules().size(), 1 );
  const security_list::relatedsym::tickrules& TickRules_msg = RelatedSym_msg.TickRules()[0];

  BOOST_CHECK( TickRules_msg.StartTickPriceRange().first );
  BOOST_CHECK_EQUAL( TickRules_msg.StartTickPriceRange().second, apoena::msi::decimal( 1206, 0 ) );
  BOOST_CHECK( TickRules_msg.EndTickPriceRange().first );
  BOOST_CHECK_EQUAL( TickRules_msg.EndTickPriceRange().second, apoena::msi::decimal( 1207, 0 ) );
  BOOST_CHECK( TickRules_msg.TickIncrement().first );
  BOOST_CHECK_EQUAL( TickRules_msg.TickIncrement().second, apoena::msi::decimal( 1208, 0 ) );
  BOOST_CHECK( TickRules_msg.TickRuleType().first );
  BOOST_CHECK_EQUAL( TickRules_msg.TickRuleType().second, 1209 );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.Legs().size(), 1 );
  const security_list::relatedsym::legs& Legs_msg = RelatedSym_msg.Legs()[0];

  BOOST_CHECK( Legs_msg.LegSymbol().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSymbol().second, "600" );
  BOOST_CHECK( Legs_msg.LegSecurityID().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSecurityID().second, 602 );
  BOOST_CHECK( Legs_msg.LegSecurityIDSource().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSecurityIDSource().second, "8" );
  BOOST_CHECK( Legs_msg.LegRatioQty().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegRatioQty().second, 623 );
  BOOST_CHECK( Legs_msg.LegSecurityType().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSecurityType().second, "609" );
  BOOST_CHECK( Legs_msg.LegSide().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSide().second, 624 );
  BOOST_CHECK( Legs_msg.LegSecurityExchange().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSecurityExchange().second, "BVMF" );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.Lots().size(), 1 );
  const security_list::relatedsym::lots& Lots_msg = RelatedSym_msg.Lots()[0];

  BOOST_CHECK( Lots_msg.LotType().first );
  BOOST_CHECK_EQUAL( Lots_msg.LotType().second, 1093 );
  BOOST_CHECK( Lots_msg.MinLotSize().first );
  BOOST_CHECK_EQUAL( Lots_msg.MinLotSize().second, 1231 );

}

BOOST_AUTO_TEST_CASE( test_builder_141 )
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

  id msgtype_id( "MsgType" );
  id applverid_id( "ApplVerID" );
  id msgseqnum_id( "MsgSeqNum" );
  id sendingtime_id( "SendingTime" );
  id totnorelatedsym_id( "TotNoRelatedSym" );
  id lastfragment_id( "LastFragment" );
  id relatedsym_id( "RelatedSym" );
  id norelatedsym_id( "NoRelatedSym" );
  id symbol_id( "Symbol" );
  id securityid_id( "SecurityID" );
  id securityidsource_id( "SecurityIDSource" );
  id securityexchange_id( "SecurityExchange" );
  id applids_id( "ApplIDs" );
  id securityaltids_id( "SecurityAltIDs" );
  id underlyings_id( "Underlyings" );
  id impliedmarketindicator_id( "ImpliedMarketIndicator" );
  id instrattrib_id( "InstrAttrib" );
  id tickrules_id( "TickRules" );
  id legs_id( "Legs" );
  id securityupdateaction_id( "SecurityUpdateAction" );
  id lots_id( "Lots" );
  id minpriceincrement_id( "MinPriceIncrement" );
  id ticksizedenominator_id( "TickSizeDenominator" );
  id pricedivisor_id( "PriceDivisor" );
  id minorderqty_id( "MinOrderQty" );
  id maxorderqty_id( "MaxOrderQty" );
  id multilegmodel_id( "MultiLegModel" );
  id multilegpricemethod_id( "MultiLegPriceMethod" );
  id currency_id( "Currency" );
  id settlcurrency_id( "SettlCurrency" );
  id product_id( "Product" );
  id securitytype_id( "SecurityType" );
  id securitysubtype_id( "SecuritySubType" );
  id securitystrategytype_id( "SecurityStrategyType" );
  id asset_id( "Asset" );
  id securitydesc_id( "SecurityDesc" );
  id noshareissued_id( "NoShareIssued" );
  id maturitydate_id( "MaturityDate" );
  id maturitymonthyear_id( "MaturityMonthYear" );
  id strikeprice_id( "StrikePrice" );
  id strikecurrency_id( "StrikeCurrency" );
  id exercisestyle_id( "ExerciseStyle" );
  id putorcall_id( "PutOrCall" );
  id contractmultiplier_id( "ContractMultiplier" );
  id contractsettlmonth_id( "ContractSettlMonth" );
  id cficode_id( "CFICode" );
  id countryofissue_id( "CountryOfIssue" );
  id issuedate_id( "IssueDate" );
  id dateddate_id( "DatedDate" );
  id startdate_id( "StartDate" );
  id enddate_id( "EndDate" );
  id settltype_id( "SettlType" );
  id settldate_id( "SettlDate" );
  id securityvaliditytimestamp_id( "SecurityValidityTimestamp" );
  id marketsegmentid_id( "MarketSegmentID" );
  id governanceindicator_id( "GovernanceIndicator" );
  id corporateactioneventid_id( "CorporateActionEventID" );
  id securitygroup_id( "SecurityGroup" );
  id securitymatchtype_id( "SecurityMatchType" );
  id noapplids_id( "NoApplIDs" );
  id applid_id( "ApplID" );
  id feedtypes_id( "FeedTypes" );
  id nomdfeedtypes_id( "NoMDFeedTypes" );
  id mdfeedtype_id( "MDFeedType" );
  id marketdepth_id( "MarketDepth" );
  id nosecurityaltid_id( "NoSecurityAltID" );
  id securityaltid_id( "SecurityAltID" );
  id securityaltidsource_id( "SecurityAltIDSource" );
  id nounderlyings_id( "NoUnderlyings" );
  id underlyingsymbol_id( "UnderlyingSymbol" );
  id underlyingsecurityid_id( "UnderlyingSecurityID" );
  id underlyingsecurityidsource_id( "UnderlyingSecurityIDSource" );
  id underlyingsecurityexchange_id( "UnderlyingSecurityExchange" );
  id indexpct_id( "IndexPct" );
  id noinstrattrib_id( "NoInstrAttrib" );
  id instattribtype_id( "InstAttribType" );
  id instattribvalue_id( "InstAttribValue" );
  id notickrules_id( "NoTickRules" );
  id starttickpricerange_id( "StartTickPriceRange" );
  id endtickpricerange_id( "EndTickPriceRange" );
  id tickincrement_id( "TickIncrement" );
  id tickruletype_id( "TickRuleType" );
  id nolegs_id( "NoLegs" );
  id legsymbol_id( "LegSymbol" );
  id legsecurityid_id( "LegSecurityID" );
  id legsecurityidsource_id( "LegSecurityIDSource" );
  id legratioqty_id( "LegRatioQty" );
  id legsecuritytype_id( "LegSecurityType" );
  id legside_id( "LegSide" );
  id legsecurityexchange_id( "LegSecurityExchange" );
  id nolottyperules_id( "NoLotTypeRules" );
  id lottype_id( "LotType" );
  id minlotsize_id( "MinLotSize" );

  msg.addField( msgtype_id, Messages::FieldAscii::create( "y" ) );
  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldAscii::create( "52" ) );
  msg.addField( totnorelatedsym_id, Messages::FieldUInt32::create( 393 ) );
  msg.addField( lastfragment_id, Messages::FieldAscii::create( "893" ) );

  Messages::SequencePtr RelatedSym_seq( new Messages::Sequence( relatedsym_id, 1 ) );
  Messages::FieldSetPtr RelatedSym( new Messages::FieldSet( 51 ) );

  RelatedSym->addField( symbol_id, Messages::FieldAscii::create( "55" ) );
  RelatedSym->addField( securityid_id, Messages::FieldUInt64::create( 48 ) );
  RelatedSym->addField( securityidsource_id, Messages::FieldAscii::create( "8" ) );
  RelatedSym->addField( securityexchange_id, Messages::FieldAscii::create( "BVMF" ) );
  RelatedSym->addField( impliedmarketindicator_id, Messages::FieldInt32::create( 1144 ) );
  RelatedSym->addField( securityupdateaction_id, Messages::FieldAscii::create( "980" ) );
  RelatedSym->addField( minpriceincrement_id, Messages::FieldDecimal::create( 969, 0 ) );
  RelatedSym->addField( ticksizedenominator_id, Messages::FieldUInt32::create( 5151 ) );
  RelatedSym->addField( pricedivisor_id, Messages::FieldDecimal::create( 37012, 0 ) );
  RelatedSym->addField( minorderqty_id, Messages::FieldUInt32::create( 9749 ) );
  RelatedSym->addField( maxorderqty_id, Messages::FieldUInt64::create( 9748 ) );
  RelatedSym->addField( multilegmodel_id, Messages::FieldInt32::create( 1377 ) );
  RelatedSym->addField( multilegpricemethod_id, Messages::FieldInt32::create( 1378 ) );
  RelatedSym->addField( currency_id, Messages::FieldAscii::create( "15" ) );
  RelatedSym->addField( settlcurrency_id, Messages::FieldAscii::create( "120" ) );
  RelatedSym->addField( product_id, Messages::FieldInt32::create( 460 ) );
  RelatedSym->addField( securitytype_id, Messages::FieldAscii::create( "167" ) );
  RelatedSym->addField( securitysubtype_id, Messages::FieldAscii::create( "762" ) );
  RelatedSym->addField( securitystrategytype_id, Messages::FieldAscii::create( "7534" ) );
  RelatedSym->addField( asset_id, Messages::FieldAscii::create( "6937" ) );
  RelatedSym->addField( securitydesc_id, Messages::FieldAscii::create( "107" ) );
  RelatedSym->addField( noshareissued_id, Messages::FieldUInt64::create( 7595 ) );
  RelatedSym->addField( maturitydate_id, Messages::FieldUInt32::create( 541 ) );
  RelatedSym->addField( maturitymonthyear_id, Messages::FieldUInt32::create( 200 ) );
  RelatedSym->addField( strikeprice_id, Messages::FieldDecimal::create( 202, 0 ) );
  RelatedSym->addField( strikecurrency_id, Messages::FieldAscii::create( "947" ) );
  RelatedSym->addField( exercisestyle_id, Messages::FieldInt32::create( 1194 ) );
  RelatedSym->addField( putorcall_id, Messages::FieldInt32::create( 201 ) );
  RelatedSym->addField( contractmultiplier_id, Messages::FieldDecimal::create( 231, 0 ) );
  RelatedSym->addField( contractsettlmonth_id, Messages::FieldUInt32::create( 667 ) );
  RelatedSym->addField( cficode_id, Messages::FieldAscii::create( "461" ) );
  RelatedSym->addField( countryofissue_id, Messages::FieldAscii::create( "470" ) );
  RelatedSym->addField( issuedate_id, Messages::FieldUInt32::create( 225 ) );
  RelatedSym->addField( dateddate_id, Messages::FieldUInt32::create( 873 ) );
  RelatedSym->addField( startdate_id, Messages::FieldUInt32::create( 916 ) );
  RelatedSym->addField( enddate_id, Messages::FieldUInt32::create( 917 ) );
  RelatedSym->addField( settltype_id, Messages::FieldAscii::create( "63" ) );
  RelatedSym->addField( settldate_id, Messages::FieldUInt32::create( 64 ) );
  RelatedSym->addField( securityvaliditytimestamp_id, Messages::FieldUInt64::create( 6938 ) );
  RelatedSym->addField( marketsegmentid_id, Messages::FieldAscii::create( "1300" ) );
  RelatedSym->addField( governanceindicator_id, Messages::FieldAscii::create( "37011" ) );
  RelatedSym->addField( corporateactioneventid_id, Messages::FieldInt32::create( 37010 ) );
  RelatedSym->addField( securitygroup_id, Messages::FieldAscii::create( "1151" ) );
  RelatedSym->addField( securitymatchtype_id, Messages::FieldInt32::create( 37015 ) );

  Messages::SequencePtr ApplIDs_seq( new Messages::Sequence( applids_id, 1 ) );
  Messages::FieldSetPtr ApplIDs( new Messages::FieldSet( 2 ) );

  ApplIDs->addField( applid_id, Messages::FieldAscii::create( "1180" ) );

  Messages::SequencePtr FeedTypes_seq( new Messages::Sequence( feedtypes_id, 1 ) );
  Messages::FieldSetPtr FeedTypes( new Messages::FieldSet( 2 ) );

  FeedTypes->addField( mdfeedtype_id, Messages::FieldAscii::create( "1022" ) );
  FeedTypes->addField( marketdepth_id, Messages::FieldUInt32::create( 264 ) );

  FeedTypes_seq->addEntry( FeedTypes );

  ApplIDs->addField( feedtypes_id, Messages::FieldSequence::create( FeedTypes_seq ) );

  ApplIDs_seq->addEntry( ApplIDs );

  RelatedSym->addField( applids_id, Messages::FieldSequence::create( ApplIDs_seq ) );

  Messages::SequencePtr SecurityAltIDs_seq( new Messages::Sequence( securityaltids_id, 1 ) );
  Messages::FieldSetPtr SecurityAltIDs( new Messages::FieldSet( 2 ) );

  SecurityAltIDs->addField( securityaltid_id, Messages::FieldAscii::create( "455" ) );
  SecurityAltIDs->addField( securityaltidsource_id, Messages::FieldAscii::create( "456" ) );

  SecurityAltIDs_seq->addEntry( SecurityAltIDs );

  RelatedSym->addField( securityaltids_id, Messages::FieldSequence::create( SecurityAltIDs_seq ) );

  Messages::SequencePtr Underlyings_seq( new Messages::Sequence( underlyings_id, 1 ) );
  Messages::FieldSetPtr Underlyings( new Messages::FieldSet( 5 ) );

  Underlyings->addField( underlyingsymbol_id, Messages::FieldAscii::create( "311" ) );
  Underlyings->addField( underlyingsecurityid_id, Messages::FieldUInt64::create( 309 ) );
  Underlyings->addField( underlyingsecurityidsource_id, Messages::FieldAscii::create( "8" ) );
  Underlyings->addField( underlyingsecurityexchange_id, Messages::FieldAscii::create( "BVMF" ) );
  Underlyings->addField( indexpct_id, Messages::FieldDecimal::create( 6919, 0 ) );

  Underlyings_seq->addEntry( Underlyings );

  RelatedSym->addField( underlyings_id, Messages::FieldSequence::create( Underlyings_seq ) );

  Messages::SequencePtr InstrAttrib_seq( new Messages::Sequence( instrattrib_id, 1 ) );
  Messages::FieldSetPtr InstrAttrib( new Messages::FieldSet( 2 ) );

  InstrAttrib->addField( instattribtype_id, Messages::FieldInt32::create( 871 ) );
  InstrAttrib->addField( instattribvalue_id, Messages::FieldAscii::create( "872" ) );

  InstrAttrib_seq->addEntry( InstrAttrib );

  RelatedSym->addField( instrattrib_id, Messages::FieldSequence::create( InstrAttrib_seq ) );

  Messages::SequencePtr TickRules_seq( new Messages::Sequence( tickrules_id, 1 ) );
  Messages::FieldSetPtr TickRules( new Messages::FieldSet( 4 ) );

  TickRules->addField( starttickpricerange_id, Messages::FieldDecimal::create( 1206, 0 ) );
  TickRules->addField( endtickpricerange_id, Messages::FieldDecimal::create( 1207, 0 ) );
  TickRules->addField( tickincrement_id, Messages::FieldDecimal::create( 1208, 0 ) );
  TickRules->addField( tickruletype_id, Messages::FieldInt32::create( 1209 ) );

  TickRules_seq->addEntry( TickRules );

  RelatedSym->addField( tickrules_id, Messages::FieldSequence::create( TickRules_seq ) );

  Messages::SequencePtr Legs_seq( new Messages::Sequence( legs_id, 1 ) );
  Messages::FieldSetPtr Legs( new Messages::FieldSet( 7 ) );

  Legs->addField( legsymbol_id, Messages::FieldAscii::create( "600" ) );
  Legs->addField( legsecurityid_id, Messages::FieldUInt64::create( 602 ) );
  Legs->addField( legsecurityidsource_id, Messages::FieldAscii::create( "8" ) );
  Legs->addField( legratioqty_id, Messages::FieldInt32::create( 623 ) );
  Legs->addField( legsecuritytype_id, Messages::FieldAscii::create( "609" ) );
  Legs->addField( legside_id, Messages::FieldInt32::create( 624 ) );
  Legs->addField( legsecurityexchange_id, Messages::FieldAscii::create( "BVMF" ) );

  Legs_seq->addEntry( Legs );

  RelatedSym->addField( legs_id, Messages::FieldSequence::create( Legs_seq ) );

  Messages::SequencePtr Lots_seq( new Messages::Sequence( lots_id, 1 ) );
  Messages::FieldSetPtr Lots( new Messages::FieldSet( 2 ) );

  Lots->addField( lottype_id, Messages::FieldInt32::create( 1093 ) );
  Lots->addField( minlotsize_id, Messages::FieldUInt32::create( 1231 ) );

  Lots_seq->addEntry( Lots );

  RelatedSym->addField( lots_id, Messages::FieldSequence::create( Lots_seq ) );

  RelatedSym_seq->addEntry( RelatedSym );

  msg.addField( relatedsym_id, Messages::FieldSequence::create( RelatedSym_seq ) );

  encoder.encodeMessage( destination, 141, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<security_list_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "y", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  security_list& m = container.message_;

  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "y" );
  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, "52" );
  BOOST_CHECK( m.TotNoRelatedSym().first );
  BOOST_CHECK_EQUAL( m.TotNoRelatedSym().second, 393 );
  BOOST_CHECK( m.LastFragment().first );
  BOOST_CHECK_EQUAL( m.LastFragment().second, "893" );

  BOOST_REQUIRE_EQUAL( m.RelatedSym().size(), 1 );
  const security_list::relatedsym& RelatedSym_msg = m.RelatedSym()[0];

  BOOST_CHECK( RelatedSym_msg.Symbol().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.Symbol().second, "55" );
  BOOST_CHECK( RelatedSym_msg.SecurityID().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityID().second, 48 );
  BOOST_CHECK( RelatedSym_msg.SecurityIDSource().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityIDSource().second, "8" );
  BOOST_CHECK( RelatedSym_msg.SecurityExchange().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityExchange().second, "BVMF" );
  BOOST_CHECK( RelatedSym_msg.ImpliedMarketIndicator().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.ImpliedMarketIndicator().second, 1144 );
  BOOST_CHECK( RelatedSym_msg.SecurityUpdateAction().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityUpdateAction().second, "980" );
  BOOST_CHECK( RelatedSym_msg.MinPriceIncrement().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MinPriceIncrement().second, apoena::msi::decimal( 969, 0 ) );
  BOOST_CHECK( RelatedSym_msg.TickSizeDenominator().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.TickSizeDenominator().second, 5151 );
  BOOST_CHECK( RelatedSym_msg.PriceDivisor().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.PriceDivisor().second, apoena::msi::decimal( 37012, 0 ) );
  BOOST_CHECK( RelatedSym_msg.MinOrderQty().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MinOrderQty().second, 9749 );
  BOOST_CHECK( RelatedSym_msg.MaxOrderQty().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MaxOrderQty().second, 9748 );
  BOOST_CHECK( RelatedSym_msg.MultiLegModel().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MultiLegModel().second, 1377 );
  BOOST_CHECK( RelatedSym_msg.MultiLegPriceMethod().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MultiLegPriceMethod().second, 1378 );
  BOOST_CHECK( RelatedSym_msg.Currency().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.Currency().second, "15" );
  BOOST_CHECK( RelatedSym_msg.SettlCurrency().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SettlCurrency().second, "120" );
  BOOST_CHECK( RelatedSym_msg.Product().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.Product().second, 460 );
  BOOST_CHECK( RelatedSym_msg.SecurityType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityType().second, "167" );
  BOOST_CHECK( RelatedSym_msg.SecuritySubType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecuritySubType().second, "762" );
  BOOST_CHECK( RelatedSym_msg.SecurityStrategyType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityStrategyType().second, "7534" );
  BOOST_CHECK( RelatedSym_msg.Asset().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.Asset().second, "6937" );
  BOOST_CHECK( RelatedSym_msg.SecurityDesc().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityDesc().second, "107" );
  BOOST_CHECK( RelatedSym_msg.NoShareIssued().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.NoShareIssued().second, 7595 );
  BOOST_CHECK( RelatedSym_msg.MaturityDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MaturityDate().second, 541 );
  BOOST_CHECK( RelatedSym_msg.MaturityMonthYear().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MaturityMonthYear().second, 200 );
  BOOST_CHECK( RelatedSym_msg.StrikePrice().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.StrikePrice().second, apoena::msi::decimal( 202, 0 ) );
  BOOST_CHECK( RelatedSym_msg.StrikeCurrency().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.StrikeCurrency().second, "947" );
  BOOST_CHECK( RelatedSym_msg.ExerciseStyle().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.ExerciseStyle().second, 1194 );
  BOOST_CHECK( RelatedSym_msg.PutOrCall().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.PutOrCall().second, 201 );
  BOOST_CHECK( RelatedSym_msg.ContractMultiplier().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.ContractMultiplier().second, apoena::msi::decimal( 231, 0 ) );
  BOOST_CHECK( RelatedSym_msg.ContractSettlMonth().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.ContractSettlMonth().second, 667 );
  BOOST_CHECK( RelatedSym_msg.CFICode().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.CFICode().second, "461" );
  BOOST_CHECK( RelatedSym_msg.CountryOfIssue().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.CountryOfIssue().second, "470" );
  BOOST_CHECK( RelatedSym_msg.IssueDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.IssueDate().second, 225 );
  BOOST_CHECK( RelatedSym_msg.DatedDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.DatedDate().second, 873 );
  BOOST_CHECK( RelatedSym_msg.StartDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.StartDate().second, 916 );
  BOOST_CHECK( RelatedSym_msg.EndDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.EndDate().second, 917 );
  BOOST_CHECK( RelatedSym_msg.SettlType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SettlType().second, "63" );
  BOOST_CHECK( RelatedSym_msg.SettlDate().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SettlDate().second, 64 );
  BOOST_CHECK( RelatedSym_msg.SecurityValidityTimestamp().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityValidityTimestamp().second, 6938 );
  BOOST_CHECK( RelatedSym_msg.MarketSegmentID().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.MarketSegmentID().second, "1300" );
  BOOST_CHECK( RelatedSym_msg.GovernanceIndicator().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.GovernanceIndicator().second, "37011" );
  BOOST_CHECK( RelatedSym_msg.CorporateActionEventID().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.CorporateActionEventID().second, 37010 );
  BOOST_CHECK( RelatedSym_msg.SecurityGroup().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityGroup().second, "1151" );
  BOOST_CHECK( RelatedSym_msg.SecurityMatchType().first );
  BOOST_CHECK_EQUAL( RelatedSym_msg.SecurityMatchType().second, 37015 );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.ApplIDs().size(), 1 );
  const security_list::relatedsym::applids& ApplIDs_msg = RelatedSym_msg.ApplIDs()[0];

  BOOST_CHECK( ApplIDs_msg.ApplID().first );
  BOOST_CHECK_EQUAL( ApplIDs_msg.ApplID().second, "1180" );

  BOOST_REQUIRE_EQUAL( ApplIDs_msg.FeedTypes().size(), 1 );
  const security_list::relatedsym::applids::feedtypes& FeedTypes_msg = ApplIDs_msg.FeedTypes()[0];

  BOOST_CHECK( FeedTypes_msg.MDFeedType().first );
  BOOST_CHECK_EQUAL( FeedTypes_msg.MDFeedType().second, "1022" );
  BOOST_CHECK( FeedTypes_msg.MarketDepth().first );
  BOOST_CHECK_EQUAL( FeedTypes_msg.MarketDepth().second, 264 );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.SecurityAltIDs().size(), 1 );
  const security_list::relatedsym::securityaltids& SecurityAltIDs_msg = RelatedSym_msg.SecurityAltIDs()[0];

  BOOST_CHECK( SecurityAltIDs_msg.SecurityAltID().first );
  BOOST_CHECK_EQUAL( SecurityAltIDs_msg.SecurityAltID().second, "455" );
  BOOST_CHECK( SecurityAltIDs_msg.SecurityAltIDSource().first );
  BOOST_CHECK_EQUAL( SecurityAltIDs_msg.SecurityAltIDSource().second, "456" );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.Underlyings().size(), 1 );
  const security_list::relatedsym::underlyings& Underlyings_msg = RelatedSym_msg.Underlyings()[0];

  BOOST_CHECK( Underlyings_msg.UnderlyingSymbol().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSymbol().second, "311" );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityID().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityID().second, 309 );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityIDSource().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityIDSource().second, "8" );
  BOOST_CHECK( Underlyings_msg.UnderlyingSecurityExchange().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.UnderlyingSecurityExchange().second, "BVMF" );
  BOOST_CHECK( Underlyings_msg.IndexPct().first );
  BOOST_CHECK_EQUAL( Underlyings_msg.IndexPct().second, apoena::msi::decimal( 6919, 0 ) );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.InstrAttrib().size(), 1 );
  const security_list::relatedsym::instrattrib& InstrAttrib_msg = RelatedSym_msg.InstrAttrib()[0];

  BOOST_CHECK( InstrAttrib_msg.InstAttribType().first );
  BOOST_CHECK_EQUAL( InstrAttrib_msg.InstAttribType().second, 871 );
  BOOST_CHECK( InstrAttrib_msg.InstAttribValue().first );
  BOOST_CHECK_EQUAL( InstrAttrib_msg.InstAttribValue().second, "872" );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.TickRules().size(), 1 );
  const security_list::relatedsym::tickrules& TickRules_msg = RelatedSym_msg.TickRules()[0];

  BOOST_CHECK( TickRules_msg.StartTickPriceRange().first );
  BOOST_CHECK_EQUAL( TickRules_msg.StartTickPriceRange().second, apoena::msi::decimal( 1206, 0 ) );
  BOOST_CHECK( TickRules_msg.EndTickPriceRange().first );
  BOOST_CHECK_EQUAL( TickRules_msg.EndTickPriceRange().second, apoena::msi::decimal( 1207, 0 ) );
  BOOST_CHECK( TickRules_msg.TickIncrement().first );
  BOOST_CHECK_EQUAL( TickRules_msg.TickIncrement().second, apoena::msi::decimal( 1208, 0 ) );
  BOOST_CHECK( TickRules_msg.TickRuleType().first );
  BOOST_CHECK_EQUAL( TickRules_msg.TickRuleType().second, 1209 );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.Legs().size(), 1 );
  const security_list::relatedsym::legs& Legs_msg = RelatedSym_msg.Legs()[0];

  BOOST_CHECK( Legs_msg.LegSymbol().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSymbol().second, "600" );
  BOOST_CHECK( Legs_msg.LegSecurityID().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSecurityID().second, 602 );
  BOOST_CHECK( Legs_msg.LegSecurityIDSource().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSecurityIDSource().second, "8" );
  BOOST_CHECK( Legs_msg.LegRatioQty().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegRatioQty().second, 623 );
  BOOST_CHECK( Legs_msg.LegSecurityType().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSecurityType().second, "609" );
  BOOST_CHECK( Legs_msg.LegSide().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSide().second, 624 );
  BOOST_CHECK( Legs_msg.LegSecurityExchange().first );
  BOOST_CHECK_EQUAL( Legs_msg.LegSecurityExchange().second, "BVMF" );

  BOOST_REQUIRE_EQUAL( RelatedSym_msg.Lots().size(), 1 );
  const security_list::relatedsym::lots& Lots_msg = RelatedSym_msg.Lots()[0];

  BOOST_CHECK( Lots_msg.LotType().first );
  BOOST_CHECK_EQUAL( Lots_msg.LotType().second, 1093 );
  BOOST_CHECK( Lots_msg.MinLotSize().first );
  BOOST_CHECK_EQUAL( Lots_msg.MinLotSize().second, 1231 );

}


BOOST_AUTO_TEST_SUITE_END()
