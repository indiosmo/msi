#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN marketdata_serialization_test
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <msi/decimal/decimal.hpp>
#include <msi/marketdata/serialization/auction_imbalance_serializer.hpp>
#include <msi/marketdata/serialization/bid_serializer.hpp>
#include <msi/marketdata/serialization/close_serializer.hpp>
#include <msi/marketdata/serialization/high_serializer.hpp>
#include <msi/marketdata/serialization/index_serializer.hpp>
#include <msi/marketdata/serialization/low_serializer.hpp>
#include <msi/marketdata/serialization/offer_serializer.hpp>
#include <msi/marketdata/serialization/open_serializer.hpp>
#include <msi/marketdata/serialization/open_interest_serializer.hpp>
#include <msi/marketdata/serialization/price_band_serializer.hpp>
#include <msi/marketdata/serialization/quantity_band_serializer.hpp>
#include <msi/marketdata/serialization/security_definition_serializer.hpp>
#include <msi/marketdata/serialization/security_status_serializer.hpp>
#include <msi/marketdata/serialization/settlement_serializer.hpp>
#include <msi/marketdata/serialization/trade_serializer.hpp>
#include <msi/marketdata/serialization/trade_volume_serializer.hpp>
#include <msi/marketdata/serialization/vwap_serializer.hpp>

namespace
{
using namespace apoena::msi;
using namespace apoena::msi::marketdata::messages;
using namespace apoena::msi::marketdata::serialization;
}

BOOST_AUTO_TEST_SUITE( suite_marketdata_serialization_performance )

BOOST_AUTO_TEST_CASE( test_bid )
{
  bid_serializer serializer;

  bid msg;

  msg.set_seqnum( 1 );
  msg.set_update_action( 2 );
  msg.set_security_id( 3 );
  msg.set_entry_price( decimal( 4, 0 ) );
  msg.set_entry_size( 5 );
  msg.set_entry_date( 6 );
  msg.set_entry_time( 7 );
  msg.set_buyer( "8" );
  msg.set_position( 9 );
  msg.set_order_id( "10" );

  LARGE_INTEGER f, start, end;
  QueryPerformanceFrequency( &f );
  double freq = double( f.QuadPart );
  unsigned int messages = 5 * 1000 * 1000;

  std::pair<const unsigned char*, std::size_t> smsg;
  bid dmsg;
  std::size_t msize;

  QueryPerformanceCounter( &start );

  for ( unsigned int i = 1; i <= messages; ++i )
  {
    smsg = serializer.serialize( msg );
    dmsg.reset();
    msize = serializer.deserialize( smsg.first, dmsg );
  }

  QueryPerformanceCounter( &end );

  double time = double( end.QuadPart - start.QuadPart ) / freq;
  double mps = messages / time;
  std::cout << messages << " messages in " << time << "s. " << std::endl;
  std::cout << mps << " messages/s" << std::endl;
  std::cout << time * 1000.0 * 1000.0 * 1000.0 / messages << "ns/msg" << std::endl;

  BOOST_CHECK_EQUAL( smsg.second, msize );
  BOOST_CHECK( dmsg.seqnum().first );
  BOOST_CHECK_EQUAL( dmsg.seqnum().second, 1 );
  BOOST_CHECK( dmsg.update_action().first );
  BOOST_CHECK_EQUAL( dmsg.update_action().second, 2 );
  BOOST_CHECK( dmsg.security_id().first );
  BOOST_CHECK_EQUAL( dmsg.security_id().second, 3 );
  BOOST_CHECK( dmsg.entry_price().first );
  BOOST_CHECK_EQUAL( dmsg.entry_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( dmsg.entry_size().first );
  BOOST_CHECK_EQUAL( dmsg.entry_size().second, 5 );
  BOOST_CHECK( dmsg.entry_date().first );
  BOOST_CHECK_EQUAL( dmsg.entry_date().second, 6 );
  BOOST_CHECK( dmsg.entry_time().first );
  BOOST_CHECK_EQUAL( dmsg.entry_time().second, 7 );
  BOOST_CHECK( dmsg.buyer().first );
  BOOST_CHECK_EQUAL( dmsg.buyer().second, "8" );
  BOOST_CHECK( dmsg.position().first );
  BOOST_CHECK_EQUAL( dmsg.position().second, 9 );
  BOOST_CHECK( dmsg.order_id().first );
  BOOST_CHECK_EQUAL( dmsg.order_id().second, "10" );

};

BOOST_AUTO_TEST_CASE( test_security_definition )
{
  security_definition_serializer serializer;

  security_definition msg;

  security_definition::appl_id_entry appl_id;

  security_definition::appl_id_entry appl_id2;

  security_definition::appl_id_entry::feed_type_entry feed_type;

  security_definition::appl_id_entry::feed_type_entry feed_type2;

  feed_type.set_feed_type( "1" );
  feed_type.set_market_depth( 2 );

  feed_type2.set_feed_type( "1" );
  feed_type2.set_market_depth( 2 );

  appl_id.add_feed_type( feed_type );
  appl_id.add_feed_type( feed_type2 );
  appl_id2.add_feed_type( feed_type );
  appl_id2.add_feed_type( feed_type2 );
  appl_id.set_appl_id( "1" );

  appl_id2.set_appl_id( "1" );

  security_definition::security_alt_id_entry security_alt_id;

  security_definition::security_alt_id_entry security_alt_id2;

  security_alt_id.set_security_id( 1 );
  security_alt_id.set_security_id_source( "2" );

  security_alt_id2.set_security_id( 1 );
  security_alt_id2.set_security_id_source( "2" );

  security_definition::underlying_entry underlying;

  security_definition::underlying_entry underlying2;

  underlying.set_symbol( "1" );
  underlying.set_security_id( 2 );
  underlying.set_security_id_source( "3" );
  underlying.set_security_exchange( "4" );
  underlying.set_index_pct( decimal( 5, 0 ) );
  underlying.set_index_theoretical_qty( decimal( 6, 0 ) );

  underlying2.set_symbol( "1" );
  underlying2.set_security_id( 2 );
  underlying2.set_security_id_source( "3" );
  underlying2.set_security_exchange( "4" );
  underlying2.set_index_pct( decimal( 5, 0 ) );
  underlying2.set_index_theoretical_qty( decimal( 6, 0 ) );

  security_definition::instr_attrib_entry instr_attrib;

  security_definition::instr_attrib_entry instr_attrib2;

  instr_attrib.set_inst_attrib_type( 1 );
  instr_attrib.set_inst_attrib_value( "2" );

  instr_attrib2.set_inst_attrib_type( 1 );
  instr_attrib2.set_inst_attrib_value( "2" );

  security_definition::tick_rule_entry tick_rule;

  security_definition::tick_rule_entry tick_rule2;

  tick_rule.set_start_tick_price_range( decimal( 1, 0 ) );
  tick_rule.set_end_tick_price_range( decimal( 2, 0 ) );
  tick_rule.set_tick_increment( decimal( 3, 0 ) );
  tick_rule.set_tick_rule_type( 4 );

  tick_rule2.set_start_tick_price_range( decimal( 1, 0 ) );
  tick_rule2.set_end_tick_price_range( decimal( 2, 0 ) );
  tick_rule2.set_tick_increment( decimal( 3, 0 ) );
  tick_rule2.set_tick_rule_type( 4 );

  security_definition::leg_entry leg;

  security_definition::leg_entry leg2;

  leg.set_leg_symbol( "1" );
  leg.set_leg_security_id( 2 );
  leg.set_leg_security_id_source( "3" );
  leg.set_leg_ratio_qty( 4 );
  leg.set_leg_security_type( "5" );
  leg.set_leg_side( 6 );
  leg.set_leg_security_exchange( "7" );

  leg2.set_leg_symbol( "1" );
  leg2.set_leg_security_id( 2 );
  leg2.set_leg_security_id_source( "3" );
  leg2.set_leg_ratio_qty( 4 );
  leg2.set_leg_security_type( "5" );
  leg2.set_leg_side( 6 );
  leg2.set_leg_security_exchange( "7" );

  security_definition::lot_entry lot;

  security_definition::lot_entry lot2;

  lot.set_lot_type( 1 );
  lot.set_min_lot_size( 2 );

  lot2.set_lot_type( 1 );
  lot2.set_min_lot_size( 2 );

  msg.set_seqnum( 1 );
  msg.set_symbol( "2" );
  msg.set_security_id( 3 );
  msg.set_security_id_source( "4" );
  msg.set_security_exchange( "5" );
  msg.set_implied_market_indicator( 6 );
  msg.set_security_update_action( "7" );
  msg.set_round_lot( 8 );
  msg.set_min_trade_vol( 9 );
  msg.set_min_price_increment( decimal( 10, 0 ) );
  msg.set_tick_size_denominator( 11 );
  msg.set_price_divisor( decimal( 12, 0 ) );
  msg.set_min_order_qty( 13 );
  msg.set_max_order_qty( 14 );
  msg.set_instrument_id( "15" );
  msg.set_multi_leg_model( 16 );
  msg.set_multi_leg_price_method( 17 );
  msg.set_currency( "18" );
  msg.set_settl_currency( "19" );
  msg.set_product( 20 );
  msg.set_security_type( "21" );
  msg.set_security_sub_type( "22" );
  msg.set_security_strategy_type( "23" );
  msg.set_asset( "24" );
  msg.set_security_desc( "25" );
  msg.set_no_share_issued( 26 );
  msg.set_maturity_date( 27 );
  msg.set_maturity_month_year( 28 );
  msg.set_strike_price( decimal( 29, 0 ) );
  msg.set_strike_currency( "30" );
  msg.set_exercise_style( 31 );
  msg.set_put_or_call( 32 );
  msg.set_contract_multiplier( decimal( 33, 0 ) );
  msg.set_contract_settl_month( 34 );
  msg.set_cfi_code( "35" );
  msg.set_country_of_issue( "36" );
  msg.set_issue_date( 37 );
  msg.set_dated_date( 38 );
  msg.set_start_date( 39 );
  msg.set_end_date( 40 );
  msg.set_settl_type( "41" );
  msg.set_settl_date( 42 );
  msg.set_security_validity_timestamp( 43 );
  msg.set_market_segment_id( "44" );
  msg.set_governance_indicator( "45" );
  msg.set_corporate_action_event_id( 46 );
  msg.set_security_match_type( 47 );
  msg.set_security_group( "48" );

  msg.add_appl_id( appl_id );
  msg.add_appl_id( appl_id2 );
  msg.add_security_alt_id( security_alt_id );
  msg.add_security_alt_id( security_alt_id2 );
  msg.add_underlying( underlying );
  msg.add_underlying( underlying2 );
  msg.add_instr_attrib( instr_attrib );
  msg.add_instr_attrib( instr_attrib2 );
  msg.add_tick_rule( tick_rule );
  msg.add_tick_rule( tick_rule2 );
  msg.add_leg( leg );
  msg.add_leg( leg2 );
  msg.add_lot( lot );
  msg.add_lot( lot2 );

  LARGE_INTEGER f, start, end;
  QueryPerformanceFrequency( &f );
  double freq = double( f.QuadPart );
  unsigned int messages = 200 * 1000;

  std::pair<const unsigned char*, std::size_t> smsg;
  security_definition dmsg;
  std::size_t msize;

  QueryPerformanceCounter( &start );

  for ( unsigned int i = 1; i <= messages; ++i )
  {
    smsg = serializer.serialize( msg );
    dmsg.reset();
    msize = serializer.deserialize( smsg.first, dmsg );
  }

  QueryPerformanceCounter( &end );

  double time = double( end.QuadPart - start.QuadPart ) / freq;
  double mps = messages / time;
  std::cout << messages << " messages in " << time << "s. " << std::endl;
  std::cout << mps << " messages/s" << std::endl;
  std::cout << time * 1000.0 * 1000.0 * 1000.0 / messages << "ns/msg" << std::endl;

  BOOST_CHECK_EQUAL( smsg.second, msize );
  BOOST_REQUIRE_EQUAL( dmsg.appl_ids().size(), 2 );
  auto dappl_id = dmsg.appl_ids()[0];
  auto dappl_id2 = dmsg.appl_ids()[1];
  BOOST_REQUIRE_EQUAL( dappl_id.feed_types().size(), 2 );
  auto dfeed_type = dappl_id.feed_types()[0];
  auto dfeed_type2 = dappl_id.feed_types()[1];
  BOOST_CHECK( dfeed_type.feed_type().first );
  BOOST_CHECK_EQUAL( dfeed_type.feed_type().second, "1" );
  BOOST_CHECK( dfeed_type.market_depth().first );
  BOOST_CHECK_EQUAL( dfeed_type.market_depth().second, 2 );
  BOOST_CHECK( dfeed_type2.feed_type().first );
  BOOST_CHECK_EQUAL( dfeed_type2.feed_type().second, "1" );
  BOOST_CHECK( dfeed_type2.market_depth().first );
  BOOST_CHECK_EQUAL( dfeed_type2.market_depth().second, 2 );
  BOOST_CHECK( dappl_id.appl_id().first );
  BOOST_CHECK_EQUAL( dappl_id.appl_id().second, "1" );
  BOOST_CHECK( dappl_id2.appl_id().first );
  BOOST_CHECK_EQUAL( dappl_id2.appl_id().second, "1" );
  BOOST_REQUIRE_EQUAL( dmsg.security_alt_ids().size(), 2 );
  auto dsecurity_alt_id = dmsg.security_alt_ids()[0];
  auto dsecurity_alt_id2 = dmsg.security_alt_ids()[1];
  BOOST_CHECK( dsecurity_alt_id.security_id().first );
  BOOST_CHECK_EQUAL( dsecurity_alt_id.security_id().second, 1 );
  BOOST_CHECK( dsecurity_alt_id.security_id_source().first );
  BOOST_CHECK_EQUAL( dsecurity_alt_id.security_id_source().second, "2" );
  BOOST_CHECK( dsecurity_alt_id2.security_id().first );
  BOOST_CHECK_EQUAL( dsecurity_alt_id2.security_id().second, 1 );
  BOOST_CHECK( dsecurity_alt_id2.security_id_source().first );
  BOOST_CHECK_EQUAL( dsecurity_alt_id2.security_id_source().second, "2" );
  BOOST_REQUIRE_EQUAL( dmsg.underlyings().size(), 2 );
  auto dunderlying = dmsg.underlyings()[0];
  auto dunderlying2 = dmsg.underlyings()[1];
  BOOST_CHECK( dunderlying.symbol().first );
  BOOST_CHECK_EQUAL( dunderlying.symbol().second, "1" );
  BOOST_CHECK( dunderlying.security_id().first );
  BOOST_CHECK_EQUAL( dunderlying.security_id().second, 2 );
  BOOST_CHECK( dunderlying.security_id_source().first );
  BOOST_CHECK_EQUAL( dunderlying.security_id_source().second, "3" );
  BOOST_CHECK( dunderlying.security_exchange().first );
  BOOST_CHECK_EQUAL( dunderlying.security_exchange().second, "4" );
  BOOST_CHECK( dunderlying.index_pct().first );
  BOOST_CHECK_EQUAL( dunderlying.index_pct().second, decimal( 5, 0 ) );
  BOOST_CHECK( dunderlying.index_theoretical_qty().first );
  BOOST_CHECK_EQUAL( dunderlying.index_theoretical_qty().second, decimal( 6, 0 ) );
  BOOST_CHECK( dunderlying2.symbol().first );
  BOOST_CHECK_EQUAL( dunderlying2.symbol().second, "1" );
  BOOST_CHECK( dunderlying2.security_id().first );
  BOOST_CHECK_EQUAL( dunderlying2.security_id().second, 2 );
  BOOST_CHECK( dunderlying2.security_id_source().first );
  BOOST_CHECK_EQUAL( dunderlying2.security_id_source().second, "3" );
  BOOST_CHECK( dunderlying2.security_exchange().first );
  BOOST_CHECK_EQUAL( dunderlying2.security_exchange().second, "4" );
  BOOST_CHECK( dunderlying2.index_pct().first );
  BOOST_CHECK_EQUAL( dunderlying2.index_pct().second, decimal( 5, 0 ) );
  BOOST_CHECK( dunderlying2.index_theoretical_qty().first );
  BOOST_CHECK_EQUAL( dunderlying2.index_theoretical_qty().second, decimal( 6, 0 ) );
  BOOST_REQUIRE_EQUAL( dmsg.instr_attribs().size(), 2 );
  auto dinstr_attrib = dmsg.instr_attribs()[0];
  auto dinstr_attrib2 = dmsg.instr_attribs()[1];
  BOOST_CHECK( dinstr_attrib.inst_attrib_type().first );
  BOOST_CHECK_EQUAL( dinstr_attrib.inst_attrib_type().second, 1 );
  BOOST_CHECK( dinstr_attrib.inst_attrib_value().first );
  BOOST_CHECK_EQUAL( dinstr_attrib.inst_attrib_value().second, "2" );
  BOOST_CHECK( dinstr_attrib2.inst_attrib_type().first );
  BOOST_CHECK_EQUAL( dinstr_attrib2.inst_attrib_type().second, 1 );
  BOOST_CHECK( dinstr_attrib2.inst_attrib_value().first );
  BOOST_CHECK_EQUAL( dinstr_attrib2.inst_attrib_value().second, "2" );
  BOOST_REQUIRE_EQUAL( dmsg.tick_rules().size(), 2 );
  auto dtick_rule = dmsg.tick_rules()[0];
  auto dtick_rule2 = dmsg.tick_rules()[1];
  BOOST_CHECK( dtick_rule.start_tick_price_range().first );
  BOOST_CHECK_EQUAL( dtick_rule.start_tick_price_range().second, decimal( 1, 0 ) );
  BOOST_CHECK( dtick_rule.end_tick_price_range().first );
  BOOST_CHECK_EQUAL( dtick_rule.end_tick_price_range().second, decimal( 2, 0 ) );
  BOOST_CHECK( dtick_rule.tick_increment().first );
  BOOST_CHECK_EQUAL( dtick_rule.tick_increment().second, decimal( 3, 0 ) );
  BOOST_CHECK( dtick_rule.tick_rule_type().first );
  BOOST_CHECK_EQUAL( dtick_rule.tick_rule_type().second, 4 );
  BOOST_CHECK( dtick_rule2.start_tick_price_range().first );
  BOOST_CHECK_EQUAL( dtick_rule2.start_tick_price_range().second, decimal( 1, 0 ) );
  BOOST_CHECK( dtick_rule2.end_tick_price_range().first );
  BOOST_CHECK_EQUAL( dtick_rule2.end_tick_price_range().second, decimal( 2, 0 ) );
  BOOST_CHECK( dtick_rule2.tick_increment().first );
  BOOST_CHECK_EQUAL( dtick_rule2.tick_increment().second, decimal( 3, 0 ) );
  BOOST_CHECK( dtick_rule2.tick_rule_type().first );
  BOOST_CHECK_EQUAL( dtick_rule2.tick_rule_type().second, 4 );
  BOOST_REQUIRE_EQUAL( dmsg.legs().size(), 2 );
  auto dleg = dmsg.legs()[0];
  auto dleg2 = dmsg.legs()[1];
  BOOST_CHECK( dleg.leg_symbol().first );
  BOOST_CHECK_EQUAL( dleg.leg_symbol().second, "1" );
  BOOST_CHECK( dleg.leg_security_id().first );
  BOOST_CHECK_EQUAL( dleg.leg_security_id().second, 2 );
  BOOST_CHECK( dleg.leg_security_id_source().first );
  BOOST_CHECK_EQUAL( dleg.leg_security_id_source().second, "3" );
  BOOST_CHECK( dleg.leg_ratio_qty().first );
  BOOST_CHECK_EQUAL( dleg.leg_ratio_qty().second, 4 );
  BOOST_CHECK( dleg.leg_security_type().first );
  BOOST_CHECK_EQUAL( dleg.leg_security_type().second, "5" );
  BOOST_CHECK( dleg.leg_side().first );
  BOOST_CHECK_EQUAL( dleg.leg_side().second, 6 );
  BOOST_CHECK( dleg.leg_security_exchange().first );
  BOOST_CHECK_EQUAL( dleg.leg_security_exchange().second, "7" );
  BOOST_CHECK( dleg2.leg_symbol().first );
  BOOST_CHECK_EQUAL( dleg2.leg_symbol().second, "1" );
  BOOST_CHECK( dleg2.leg_security_id().first );
  BOOST_CHECK_EQUAL( dleg2.leg_security_id().second, 2 );
  BOOST_CHECK( dleg2.leg_security_id_source().first );
  BOOST_CHECK_EQUAL( dleg2.leg_security_id_source().second, "3" );
  BOOST_CHECK( dleg2.leg_ratio_qty().first );
  BOOST_CHECK_EQUAL( dleg2.leg_ratio_qty().second, 4 );
  BOOST_CHECK( dleg2.leg_security_type().first );
  BOOST_CHECK_EQUAL( dleg2.leg_security_type().second, "5" );
  BOOST_CHECK( dleg2.leg_side().first );
  BOOST_CHECK_EQUAL( dleg2.leg_side().second, 6 );
  BOOST_CHECK( dleg2.leg_security_exchange().first );
  BOOST_CHECK_EQUAL( dleg2.leg_security_exchange().second, "7" );
  BOOST_REQUIRE_EQUAL( dmsg.lots().size(), 2 );
  auto dlot = dmsg.lots()[0];
  auto dlot2 = dmsg.lots()[1];
  BOOST_CHECK( dlot.lot_type().first );
  BOOST_CHECK_EQUAL( dlot.lot_type().second, 1 );
  BOOST_CHECK( dlot.min_lot_size().first );
  BOOST_CHECK_EQUAL( dlot.min_lot_size().second, 2 );
  BOOST_CHECK( dlot2.lot_type().first );
  BOOST_CHECK_EQUAL( dlot2.lot_type().second, 1 );
  BOOST_CHECK( dlot2.min_lot_size().first );
  BOOST_CHECK_EQUAL( dlot2.min_lot_size().second, 2 );
  BOOST_CHECK( dmsg.seqnum().first );
  BOOST_CHECK_EQUAL( dmsg.seqnum().second, 1 );
  BOOST_CHECK( dmsg.symbol().first );
  BOOST_CHECK_EQUAL( dmsg.symbol().second, "2" );
  BOOST_CHECK( dmsg.security_id().first );
  BOOST_CHECK_EQUAL( dmsg.security_id().second, 3 );
  BOOST_CHECK( dmsg.security_id_source().first );
  BOOST_CHECK_EQUAL( dmsg.security_id_source().second, "4" );
  BOOST_CHECK( dmsg.security_exchange().first );
  BOOST_CHECK_EQUAL( dmsg.security_exchange().second, "5" );
  BOOST_CHECK( dmsg.implied_market_indicator().first );
  BOOST_CHECK_EQUAL( dmsg.implied_market_indicator().second, 6 );
  BOOST_CHECK( dmsg.security_update_action().first );
  BOOST_CHECK_EQUAL( dmsg.security_update_action().second, "7" );
  BOOST_CHECK( dmsg.round_lot().first );
  BOOST_CHECK_EQUAL( dmsg.round_lot().second, 8 );
  BOOST_CHECK( dmsg.min_trade_vol().first );
  BOOST_CHECK_EQUAL( dmsg.min_trade_vol().second, 9 );
  BOOST_CHECK( dmsg.min_price_increment().first );
  BOOST_CHECK_EQUAL( dmsg.min_price_increment().second, decimal( 10, 0 ) );
  BOOST_CHECK( dmsg.tick_size_denominator().first );
  BOOST_CHECK_EQUAL( dmsg.tick_size_denominator().second, 11 );
  BOOST_CHECK( dmsg.price_divisor().first );
  BOOST_CHECK_EQUAL( dmsg.price_divisor().second, decimal( 12, 0 ) );
  BOOST_CHECK( dmsg.min_order_qty().first );
  BOOST_CHECK_EQUAL( dmsg.min_order_qty().second, 13 );
  BOOST_CHECK( dmsg.max_order_qty().first );
  BOOST_CHECK_EQUAL( dmsg.max_order_qty().second, 14 );
  BOOST_CHECK( dmsg.instrument_id().first );
  BOOST_CHECK_EQUAL( dmsg.instrument_id().second, "15" );
  BOOST_CHECK( dmsg.multi_leg_model().first );
  BOOST_CHECK_EQUAL( dmsg.multi_leg_model().second, 16 );
  BOOST_CHECK( dmsg.multi_leg_price_method().first );
  BOOST_CHECK_EQUAL( dmsg.multi_leg_price_method().second, 17 );
  BOOST_CHECK( dmsg.currency().first );
  BOOST_CHECK_EQUAL( dmsg.currency().second, "18" );
  BOOST_CHECK( dmsg.settl_currency().first );
  BOOST_CHECK_EQUAL( dmsg.settl_currency().second, "19" );
  BOOST_CHECK( dmsg.product().first );
  BOOST_CHECK_EQUAL( dmsg.product().second, 20 );
  BOOST_CHECK( dmsg.security_type().first );
  BOOST_CHECK_EQUAL( dmsg.security_type().second, "21" );
  BOOST_CHECK( dmsg.security_sub_type().first );
  BOOST_CHECK_EQUAL( dmsg.security_sub_type().second, "22" );
  BOOST_CHECK( dmsg.security_strategy_type().first );
  BOOST_CHECK_EQUAL( dmsg.security_strategy_type().second, "23" );
  BOOST_CHECK( dmsg.asset().first );
  BOOST_CHECK_EQUAL( dmsg.asset().second, "24" );
  BOOST_CHECK( dmsg.security_desc().first );
  BOOST_CHECK_EQUAL( dmsg.security_desc().second, "25" );
  BOOST_CHECK( dmsg.no_share_issued().first );
  BOOST_CHECK_EQUAL( dmsg.no_share_issued().second, 26 );
  BOOST_CHECK( dmsg.maturity_date().first );
  BOOST_CHECK_EQUAL( dmsg.maturity_date().second, 27 );
  BOOST_CHECK( dmsg.maturity_month_year().first );
  BOOST_CHECK_EQUAL( dmsg.maturity_month_year().second, 28 );
  BOOST_CHECK( dmsg.strike_price().first );
  BOOST_CHECK_EQUAL( dmsg.strike_price().second, decimal( 29, 0 ) );
  BOOST_CHECK( dmsg.strike_currency().first );
  BOOST_CHECK_EQUAL( dmsg.strike_currency().second, "30" );
  BOOST_CHECK( dmsg.exercise_style().first );
  BOOST_CHECK_EQUAL( dmsg.exercise_style().second, 31 );
  BOOST_CHECK( dmsg.put_or_call().first );
  BOOST_CHECK_EQUAL( dmsg.put_or_call().second, 32 );
  BOOST_CHECK( dmsg.contract_multiplier().first );
  BOOST_CHECK_EQUAL( dmsg.contract_multiplier().second, decimal( 33, 0 ) );
  BOOST_CHECK( dmsg.contract_settl_month().first );
  BOOST_CHECK_EQUAL( dmsg.contract_settl_month().second, 34 );
  BOOST_CHECK( dmsg.cfi_code().first );
  BOOST_CHECK_EQUAL( dmsg.cfi_code().second, "35" );
  BOOST_CHECK( dmsg.country_of_issue().first );
  BOOST_CHECK_EQUAL( dmsg.country_of_issue().second, "36" );
  BOOST_CHECK( dmsg.issue_date().first );
  BOOST_CHECK_EQUAL( dmsg.issue_date().second, 37 );
  BOOST_CHECK( dmsg.dated_date().first );
  BOOST_CHECK_EQUAL( dmsg.dated_date().second, 38 );
  BOOST_CHECK( dmsg.start_date().first );
  BOOST_CHECK_EQUAL( dmsg.start_date().second, 39 );
  BOOST_CHECK( dmsg.end_date().first );
  BOOST_CHECK_EQUAL( dmsg.end_date().second, 40 );
  BOOST_CHECK( dmsg.settl_type().first );
  BOOST_CHECK_EQUAL( dmsg.settl_type().second, "41" );
  BOOST_CHECK( dmsg.settl_date().first );
  BOOST_CHECK_EQUAL( dmsg.settl_date().second, 42 );
  BOOST_CHECK( dmsg.security_validity_timestamp().first );
  BOOST_CHECK_EQUAL( dmsg.security_validity_timestamp().second, 43 );
  BOOST_CHECK( dmsg.market_segment_id().first );
  BOOST_CHECK_EQUAL( dmsg.market_segment_id().second, "44" );
  BOOST_CHECK( dmsg.governance_indicator().first );
  BOOST_CHECK_EQUAL( dmsg.governance_indicator().second, "45" );
  BOOST_CHECK( dmsg.corporate_action_event_id().first );
  BOOST_CHECK_EQUAL( dmsg.corporate_action_event_id().second, 46 );
  BOOST_CHECK( dmsg.security_match_type().first );
  BOOST_CHECK_EQUAL( dmsg.security_match_type().second, 47 );
  BOOST_CHECK( dmsg.security_group().first );
  BOOST_CHECK_EQUAL( dmsg.security_group().second, "48" );

};

BOOST_AUTO_TEST_SUITE_END()

