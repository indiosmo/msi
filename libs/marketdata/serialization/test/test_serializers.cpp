#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN marketdata_serialization_test
#include <boost/test/unit_test.hpp>

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
#include <msi/marketdata/serialization/snapshot_serializer.hpp>

namespace
{
using namespace apoena::msi;
using namespace apoena::msi::marketdata::messages;
using namespace apoena::msi::marketdata::serialization;
}

BOOST_AUTO_TEST_SUITE( suite_marketdata_serialization )

BOOST_AUTO_TEST_CASE( test_auction_imbalance )
{
  auction_imbalance_serializer serializer;

  auction_imbalance msg;

  msg.set_seqnum( 1 );
  msg.set_update_action( 2 );
  msg.set_security_id( 3 );
  msg.set_entry_size( 4 );
  msg.set_entry_date( 5 );
  msg.set_entry_time( 6 );
  msg.set_trade_condition( "R X L P Q U 3 2 1" );

  auto smsg = serializer.serialize( msg );

  auction_imbalance dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

  BOOST_CHECK_EQUAL( smsg.second, msize );
  BOOST_CHECK( dmsg.seqnum().first );
  BOOST_CHECK_EQUAL( dmsg.seqnum().second, 1 );
  BOOST_CHECK( dmsg.update_action().first );
  BOOST_CHECK_EQUAL( dmsg.update_action().second, 2 );
  BOOST_CHECK( dmsg.security_id().first );
  BOOST_CHECK_EQUAL( dmsg.security_id().second, 3 );
  BOOST_CHECK( dmsg.entry_size().first );
  BOOST_CHECK_EQUAL( dmsg.entry_size().second, 4 );
  BOOST_CHECK( dmsg.entry_date().first );
  BOOST_CHECK_EQUAL( dmsg.entry_date().second, 5 );
  BOOST_CHECK( dmsg.entry_time().first );
  BOOST_CHECK_EQUAL( dmsg.entry_time().second, 6 );
  BOOST_CHECK( dmsg.trade_condition_opening_price() );
  BOOST_CHECK( dmsg.trade_condition_crossed() );
  BOOST_CHECK( dmsg.trade_condition_last_trade_at_price() );
  BOOST_CHECK( dmsg.trade_condition_imbalance_more_buyers() );
  BOOST_CHECK( dmsg.trade_condition_imbalance_more_sellers() );
  BOOST_CHECK( dmsg.trade_condition_exchange_last() );
  BOOST_CHECK( dmsg.trade_condition_multi_asset_trade() );
  BOOST_CHECK( dmsg.trade_condition_leg_trade() );
  BOOST_CHECK( dmsg.trade_condition_marketplace_entered_trade() );

};

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

  auto smsg = serializer.serialize( msg );

  bid dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

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

BOOST_AUTO_TEST_CASE( test_close )
{
  close_serializer serializer;

  close msg;

  msg.set_seqnum( 1 );
  msg.set_security_id( 2 );
  msg.set_entry_price( decimal( 3, 0 ) );
  msg.set_last_trade_date( 4 );
  msg.set_price_adjust_method( 5 );
  msg.set_entry_date( 6 );
  msg.set_entry_time( 7 );
  msg.set_settl_flag( "8" );

  auto smsg = serializer.serialize( msg );

  close dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

  BOOST_CHECK_EQUAL( smsg.second, msize );
  BOOST_CHECK( dmsg.seqnum().first );
  BOOST_CHECK_EQUAL( dmsg.seqnum().second, 1 );
  BOOST_CHECK( dmsg.security_id().first );
  BOOST_CHECK_EQUAL( dmsg.security_id().second, 2 );
  BOOST_CHECK( dmsg.entry_price().first );
  BOOST_CHECK_EQUAL( dmsg.entry_price().second, decimal( 3, 0 ) );
  BOOST_CHECK( dmsg.last_trade_date().first );
  BOOST_CHECK_EQUAL( dmsg.last_trade_date().second, 4 );
  BOOST_CHECK( dmsg.price_adjust_method().first );
  BOOST_CHECK_EQUAL( dmsg.price_adjust_method().second, 5 );
  BOOST_CHECK( dmsg.entry_date().first );
  BOOST_CHECK_EQUAL( dmsg.entry_date().second, 6 );
  BOOST_CHECK( dmsg.entry_time().first );
  BOOST_CHECK_EQUAL( dmsg.entry_time().second, 7 );
  BOOST_CHECK( dmsg.settl_flag().first );
  BOOST_CHECK_EQUAL( dmsg.settl_flag().second, "8" );

};

BOOST_AUTO_TEST_CASE( test_high )
{
  high_serializer serializer;

  high msg;

  msg.set_seqnum( 1 );
  msg.set_update_action( 2 );
  msg.set_security_id( 3 );
  msg.set_entry_price( decimal( 4, 0 ) );
  msg.set_entry_size( 5 );
  msg.set_entry_date( 6 );
  msg.set_entry_time( 7 );

  auto smsg = serializer.serialize( msg );

  high dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

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

};

BOOST_AUTO_TEST_CASE( test_index )
{
  index_serializer serializer;

  index msg;

  msg.set_seqnum( 1 );
  msg.set_update_action( 2 );
  msg.set_security_id( 3 );
  msg.set_entry_price( decimal( 4, 0 ) );
  msg.set_entry_date( 5 );
  msg.set_entry_time( 6 );
  msg.set_tick_direction( 7 );

  auto smsg = serializer.serialize( msg );

  index dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

  BOOST_CHECK_EQUAL( smsg.second, msize );
  BOOST_CHECK( dmsg.seqnum().first );
  BOOST_CHECK_EQUAL( dmsg.seqnum().second, 1 );
  BOOST_CHECK( dmsg.update_action().first );
  BOOST_CHECK_EQUAL( dmsg.update_action().second, 2 );
  BOOST_CHECK( dmsg.security_id().first );
  BOOST_CHECK_EQUAL( dmsg.security_id().second, 3 );
  BOOST_CHECK( dmsg.entry_price().first );
  BOOST_CHECK_EQUAL( dmsg.entry_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( dmsg.entry_date().first );
  BOOST_CHECK_EQUAL( dmsg.entry_date().second, 5 );
  BOOST_CHECK( dmsg.entry_time().first );
  BOOST_CHECK_EQUAL( dmsg.entry_time().second, 6 );
  BOOST_CHECK( dmsg.tick_direction().first );
  BOOST_CHECK_EQUAL( dmsg.tick_direction().second, 7 );

};

BOOST_AUTO_TEST_CASE( test_low )
{
  low_serializer serializer;

  low msg;

  msg.set_seqnum( 1 );
  msg.set_update_action( 2 );
  msg.set_security_id( 3 );
  msg.set_entry_price( decimal( 4, 0 ) );
  msg.set_entry_size( 5 );
  msg.set_entry_date( 6 );
  msg.set_entry_time( 7 );

  auto smsg = serializer.serialize( msg );

  low dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

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

};

BOOST_AUTO_TEST_CASE( test_offer )
{
  offer_serializer serializer;

  offer msg;

  msg.set_seqnum( 1 );
  msg.set_update_action( 2 );
  msg.set_security_id( 3 );
  msg.set_entry_price( decimal( 4, 0 ) );
  msg.set_entry_size( 5 );
  msg.set_entry_date( 6 );
  msg.set_entry_time( 7 );
  msg.set_seller( "8" );
  msg.set_position( 9 );
  msg.set_order_id( "10" );

  auto smsg = serializer.serialize( msg );

  offer dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

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
  BOOST_CHECK( dmsg.seller().first );
  BOOST_CHECK_EQUAL( dmsg.seller().second, "8" );
  BOOST_CHECK( dmsg.position().first );
  BOOST_CHECK_EQUAL( dmsg.position().second, 9 );
  BOOST_CHECK( dmsg.order_id().first );
  BOOST_CHECK_EQUAL( dmsg.order_id().second, "10" );

};

BOOST_AUTO_TEST_CASE( test_open )
{
  open_serializer serializer;

  open msg;

  msg.set_seqnum( 1 );
  msg.set_update_action( 2 );
  msg.set_security_id( 3 );
  msg.set_entry_price( decimal( 4, 0 ) );
  msg.set_entry_size( 5 );
  msg.set_entry_date( 6 );
  msg.set_entry_time( 7 );
  msg.set_settl_flag( "8" );
  msg.set_variation( decimal( 9, 0 ) );

  auto smsg = serializer.serialize( msg );

  open dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

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
  BOOST_CHECK( dmsg.settl_flag().first );
  BOOST_CHECK_EQUAL( dmsg.settl_flag().second, "8" );
  BOOST_CHECK( dmsg.variation().first );
  BOOST_CHECK_EQUAL( dmsg.variation().second, decimal( 9, 0 ) );

};

BOOST_AUTO_TEST_CASE( test_open_interest )
{
  open_interest_serializer serializer;

  open_interest msg;

  msg.set_seqnum( 1 );
  msg.set_security_id( 2 );
  msg.set_entry_price( decimal( 3, 0 ) );
  msg.set_entry_size( 4 );
  msg.set_entry_date( 5 );
  msg.set_entry_time( 6 );

  auto smsg = serializer.serialize( msg );

  open_interest dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

  BOOST_CHECK_EQUAL( smsg.second, msize );
  BOOST_CHECK( dmsg.seqnum().first );
  BOOST_CHECK_EQUAL( dmsg.seqnum().second, 1 );
  BOOST_CHECK( dmsg.security_id().first );
  BOOST_CHECK_EQUAL( dmsg.security_id().second, 2 );
  BOOST_CHECK( dmsg.entry_price().first );
  BOOST_CHECK_EQUAL( dmsg.entry_price().second, decimal( 3, 0 ) );
  BOOST_CHECK( dmsg.entry_size().first );
  BOOST_CHECK_EQUAL( dmsg.entry_size().second, 4 );
  BOOST_CHECK( dmsg.entry_date().first );
  BOOST_CHECK_EQUAL( dmsg.entry_date().second, 5 );
  BOOST_CHECK( dmsg.entry_time().first );
  BOOST_CHECK_EQUAL( dmsg.entry_time().second, 6 );

};

BOOST_AUTO_TEST_CASE( test_price_band )
{
  price_band_serializer serializer;

  price_band msg;

  msg.set_seqnum( 1 );
  msg.set_security_id( 2 );
  msg.set_price_band_type( "3" );
  msg.set_price_limit_type( 4 );
  msg.set_low_limit_price( decimal( 5, 0 ) );
  msg.set_high_limit_price( decimal( 6, 0 ) );
  msg.set_trading_reference_price( decimal( 7, 0 ) );
  msg.set_price_band_midpoint_price_type( 8 );
  msg.set_entry_date( 9 );
  msg.set_entry_time( 10 );

  auto smsg = serializer.serialize( msg );

  price_band dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

  BOOST_CHECK_EQUAL( smsg.second, msize );
  BOOST_CHECK( dmsg.seqnum().first );
  BOOST_CHECK_EQUAL( dmsg.seqnum().second, 1 );
  BOOST_CHECK( dmsg.security_id().first );
  BOOST_CHECK_EQUAL( dmsg.security_id().second, 2 );
  BOOST_CHECK( dmsg.price_band_type().first );
  BOOST_CHECK_EQUAL( dmsg.price_band_type().second, "3" );
  BOOST_CHECK( dmsg.price_limit_type().first );
  BOOST_CHECK_EQUAL( dmsg.price_limit_type().second, 4 );
  BOOST_CHECK( dmsg.low_limit_price().first );
  BOOST_CHECK_EQUAL( dmsg.low_limit_price().second, decimal( 5, 0 ) );
  BOOST_CHECK( dmsg.high_limit_price().first );
  BOOST_CHECK_EQUAL( dmsg.high_limit_price().second, decimal( 6, 0 ) );
  BOOST_CHECK( dmsg.trading_reference_price().first );
  BOOST_CHECK_EQUAL( dmsg.trading_reference_price().second, decimal( 7, 0 ) );
  BOOST_CHECK( dmsg.price_band_midpoint_price_type().first );
  BOOST_CHECK_EQUAL( dmsg.price_band_midpoint_price_type().second, 8 );
  BOOST_CHECK( dmsg.entry_date().first );
  BOOST_CHECK_EQUAL( dmsg.entry_date().second, 9 );
  BOOST_CHECK( dmsg.entry_time().first );
  BOOST_CHECK_EQUAL( dmsg.entry_time().second, 10 );

};

BOOST_AUTO_TEST_CASE( test_quantity_band )
{
  quantity_band_serializer serializer;

  quantity_band msg;

  msg.set_seqnum( 1 );
  msg.set_security_id( 2 );
  msg.set_low_limit_price( decimal( 3, 0 ) );
  msg.set_high_limit_price( decimal( 4, 0 ) );
  msg.set_trading_reference_price( decimal( 5, 0 ) );
  msg.set_price_band_midpoint_price_type( 6 );
  msg.set_avg_daily_traded_qty( 7 );
  msg.set_max_trade_vol( 8 );
  msg.set_entry_date( 9 );
  msg.set_entry_time( 10 );

  auto smsg = serializer.serialize( msg );

  quantity_band dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

  BOOST_CHECK_EQUAL( smsg.second, msize );
  BOOST_CHECK( dmsg.seqnum().first );
  BOOST_CHECK_EQUAL( dmsg.seqnum().second, 1 );
  BOOST_CHECK( dmsg.security_id().first );
  BOOST_CHECK_EQUAL( dmsg.security_id().second, 2 );
  BOOST_CHECK( dmsg.low_limit_price().first );
  BOOST_CHECK_EQUAL( dmsg.low_limit_price().second, decimal( 3, 0 ) );
  BOOST_CHECK( dmsg.high_limit_price().first );
  BOOST_CHECK_EQUAL( dmsg.high_limit_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( dmsg.trading_reference_price().first );
  BOOST_CHECK_EQUAL( dmsg.trading_reference_price().second, decimal( 5, 0 ) );
  BOOST_CHECK( dmsg.price_band_midpoint_price_type().first );
  BOOST_CHECK_EQUAL( dmsg.price_band_midpoint_price_type().second, 6 );
  BOOST_CHECK( dmsg.avg_daily_traded_qty().first );
  BOOST_CHECK_EQUAL( dmsg.avg_daily_traded_qty().second, 7 );
  BOOST_CHECK( dmsg.max_trade_vol().first );
  BOOST_CHECK_EQUAL( dmsg.max_trade_vol().second, 8 );
  BOOST_CHECK( dmsg.entry_date().first );
  BOOST_CHECK_EQUAL( dmsg.entry_date().second, 9 );
  BOOST_CHECK( dmsg.entry_time().first );
  BOOST_CHECK_EQUAL( dmsg.entry_time().second, 10 );

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
  auto smsg = serializer.serialize( msg );

  security_definition dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

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

BOOST_AUTO_TEST_CASE( test_security_status )
{
  security_status_serializer serializer;

  security_status msg;

  msg.set_seqnum( 1 );
  msg.set_security_id( 2 );
  msg.set_security_group( "3" );
  msg.set_group_phase( "4" );
  msg.set_instrument_state( 5 );
  msg.set_open_time( 6 );
  msg.set_trading_event( 7 );

  auto smsg = serializer.serialize( msg );

  security_status dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

  BOOST_CHECK_EQUAL( smsg.second, msize );
  BOOST_CHECK( dmsg.seqnum().first );
  BOOST_CHECK_EQUAL( dmsg.seqnum().second, 1 );
  BOOST_CHECK( dmsg.security_id().first );
  BOOST_CHECK_EQUAL( dmsg.security_id().second, 2 );
  BOOST_CHECK( dmsg.security_group().first );
  BOOST_CHECK_EQUAL( dmsg.security_group().second, "3" );
  BOOST_CHECK( dmsg.group_phase().first );
  BOOST_CHECK_EQUAL( dmsg.group_phase().second, "4" );
  BOOST_CHECK( dmsg.instrument_state().first );
  BOOST_CHECK_EQUAL( dmsg.instrument_state().second, 5 );
  BOOST_CHECK( dmsg.open_time().first );
  BOOST_CHECK_EQUAL( dmsg.open_time().second, 6 );
  BOOST_CHECK( dmsg.trading_event().first );
  BOOST_CHECK_EQUAL( dmsg.trading_event().second, 7 );

};

BOOST_AUTO_TEST_CASE( test_settlement )
{
  settlement_serializer serializer;

  settlement msg;

  msg.set_seqnum( 1 );
  msg.set_security_id( 2 );
  msg.set_entry_price( decimal( 3, 0 ) );
  msg.set_price_type( "4" );
  msg.set_entry_date( 5 );
  msg.set_entry_time( 6 );
  msg.set_settl_flag( "7" );
  msg.set_settl_price_type( "8" );

  auto smsg = serializer.serialize( msg );

  settlement dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

  BOOST_CHECK_EQUAL( smsg.second, msize );
  BOOST_CHECK( dmsg.seqnum().first );
  BOOST_CHECK_EQUAL( dmsg.seqnum().second, 1 );
  BOOST_CHECK( dmsg.security_id().first );
  BOOST_CHECK_EQUAL( dmsg.security_id().second, 2 );
  BOOST_CHECK( dmsg.entry_price().first );
  BOOST_CHECK_EQUAL( dmsg.entry_price().second, decimal( 3, 0 ) );
  BOOST_CHECK( dmsg.price_type().first );
  BOOST_CHECK_EQUAL( dmsg.price_type().second, "4" );
  BOOST_CHECK( dmsg.entry_date().first );
  BOOST_CHECK_EQUAL( dmsg.entry_date().second, 5 );
  BOOST_CHECK( dmsg.entry_time().first );
  BOOST_CHECK_EQUAL( dmsg.entry_time().second, 6 );
  BOOST_CHECK( dmsg.settl_flag().first );
  BOOST_CHECK_EQUAL( dmsg.settl_flag().second, "7" );
  BOOST_CHECK( dmsg.settl_price_type().first );
  BOOST_CHECK_EQUAL( dmsg.settl_price_type().second, "8" );

};

BOOST_AUTO_TEST_CASE( test_trade )
{
  trade_serializer serializer;

  trade msg;

  msg.set_seqnum( 1 );
  msg.set_update_action( 2 );
  msg.set_security_id( 3 );
  msg.set_entry_price( decimal( 4, 0 ) );
  msg.set_entry_size( 5 );
  msg.set_entry_date( 6 );
  msg.set_entry_time( 7 );
  msg.set_tick_direction( 8 );
  msg.set_buyer( "9" );
  msg.set_seller( "10" );
  msg.set_variation( decimal( 11, 0 ) );
  msg.set_quantity_volume( 12 );
  msg.set_trade_id( "13" );
  msg.set_trade_condition( "R X L P Q U 3 2 1" );

  auto smsg = serializer.serialize( msg );

  trade dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

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
  BOOST_CHECK( dmsg.tick_direction().first );
  BOOST_CHECK_EQUAL( dmsg.tick_direction().second, 8 );
  BOOST_CHECK( dmsg.buyer().first );
  BOOST_CHECK_EQUAL( dmsg.buyer().second, "9" );
  BOOST_CHECK( dmsg.seller().first );
  BOOST_CHECK_EQUAL( dmsg.seller().second, "10" );
  BOOST_CHECK( dmsg.variation().first );
  BOOST_CHECK_EQUAL( dmsg.variation().second, decimal( 11, 0 ) );
  BOOST_CHECK( dmsg.quantity_volume().first );
  BOOST_CHECK_EQUAL( dmsg.quantity_volume().second, 12 );
  BOOST_CHECK( dmsg.trade_id().first );
  BOOST_CHECK_EQUAL( dmsg.trade_id().second, "13" );
  BOOST_CHECK( dmsg.trade_condition_opening_price() );
  BOOST_CHECK( dmsg.trade_condition_crossed() );
  BOOST_CHECK( dmsg.trade_condition_last_trade_at_price() );
  BOOST_CHECK( dmsg.trade_condition_imbalance_more_buyers() );
  BOOST_CHECK( dmsg.trade_condition_imbalance_more_sellers() );
  BOOST_CHECK( dmsg.trade_condition_exchange_last() );
  BOOST_CHECK( dmsg.trade_condition_multi_asset_trade() );
  BOOST_CHECK( dmsg.trade_condition_leg_trade() );
  BOOST_CHECK( dmsg.trade_condition_marketplace_entered_trade() );

};

BOOST_AUTO_TEST_CASE( test_trade_volume )
{
  trade_volume_serializer serializer;

  trade_volume msg;

  msg.set_seqnum( 1 );
  msg.set_security_id( 2 );
  msg.set_financial_volume( decimal( 3, 0 ) );
  msg.set_number_of_trades( 4 );
  msg.set_quantity_volume( 5 );
  msg.set_entry_date( 6 );
  msg.set_entry_time( 7 );
  msg.set_currency( "8" );

  auto smsg = serializer.serialize( msg );

  trade_volume dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

  BOOST_CHECK_EQUAL( smsg.second, msize );
  BOOST_CHECK( dmsg.seqnum().first );
  BOOST_CHECK_EQUAL( dmsg.seqnum().second, 1 );
  BOOST_CHECK( dmsg.security_id().first );
  BOOST_CHECK_EQUAL( dmsg.security_id().second, 2 );
  BOOST_CHECK( dmsg.financial_volume().first );
  BOOST_CHECK_EQUAL( dmsg.financial_volume().second, decimal( 3, 0 ) );
  BOOST_CHECK( dmsg.number_of_trades().first );
  BOOST_CHECK_EQUAL( dmsg.number_of_trades().second, 4 );
  BOOST_CHECK( dmsg.quantity_volume().first );
  BOOST_CHECK_EQUAL( dmsg.quantity_volume().second, 5 );
  BOOST_CHECK( dmsg.entry_date().first );
  BOOST_CHECK_EQUAL( dmsg.entry_date().second, 6 );
  BOOST_CHECK( dmsg.entry_time().first );
  BOOST_CHECK_EQUAL( dmsg.entry_time().second, 7 );
  BOOST_CHECK( dmsg.currency().first );
  BOOST_CHECK_EQUAL( dmsg.currency().second, "8" );

};

BOOST_AUTO_TEST_CASE( test_vwap )
{
  vwap_serializer serializer;

  vwap msg;

  msg.set_seqnum( 1 );
  msg.set_update_action( 2 );
  msg.set_security_id( 3 );
  msg.set_entry_price( decimal( 4, 0 ) );
  msg.set_entry_size( 5 );
  msg.set_entry_date( 6 );
  msg.set_entry_time( 7 );

  auto smsg = serializer.serialize( msg );

  vwap dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

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

};

BOOST_AUTO_TEST_CASE( test_snapshot )
{
  snapshot_serializer serializer;

  snapshot msg;

  auction_imbalance auction_imbalance_entry;
  auction_imbalance_entry.set_seqnum( 1 );
  auction_imbalance_entry.set_update_action( 2 );
  auction_imbalance_entry.set_security_id( 3 );
  auction_imbalance_entry.set_entry_size( 4 );
  auction_imbalance_entry.set_entry_date( 5 );
  auction_imbalance_entry.set_entry_time( 6 );
  auction_imbalance_entry.set_trade_condition( "R X L P Q U 3 2 1" );

  msg.set_auction_imbalance( auction_imbalance_entry );

  bid bid_entry;
  bid_entry.set_seqnum( 1 );
  bid_entry.set_update_action( 2 );
  bid_entry.set_security_id( 3 );
  bid_entry.set_entry_price( decimal( 4, 0 ) );
  bid_entry.set_entry_size( 5 );
  bid_entry.set_entry_date( 6 );
  bid_entry.set_entry_time( 7 );
  bid_entry.set_buyer( "8" );
  bid_entry.set_position( 9 );
  bid_entry.set_order_id( "10" );

  msg.add_bid( bid_entry );
  msg.add_bid( bid_entry );

  close close_entry;
  close_entry.set_seqnum( 1 );
  close_entry.set_security_id( 2 );
  close_entry.set_entry_price( decimal( 3, 0 ) );
  close_entry.set_last_trade_date( 4 );
  close_entry.set_price_adjust_method( 5 );
  close_entry.set_entry_date( 6 );
  close_entry.set_entry_time( 7 );
  close_entry.set_settl_flag( "8" );

  msg.set_close( close_entry );

  high high_entry;
  high_entry.set_seqnum( 1 );
  high_entry.set_update_action( 2 );
  high_entry.set_security_id( 3 );
  high_entry.set_entry_price( decimal( 4, 0 ) );
  high_entry.set_entry_size( 5 );
  high_entry.set_entry_date( 6 );
  high_entry.set_entry_time( 7 );

  msg.set_high( high_entry );

  index index_entry;
  index_entry.set_seqnum( 1 );
  index_entry.set_update_action( 2 );
  index_entry.set_security_id( 3 );
  index_entry.set_entry_price( decimal( 4, 0 ) );
  index_entry.set_entry_date( 5 );
  index_entry.set_entry_time( 6 );
  index_entry.set_tick_direction( 7 );

  msg.set_index( index_entry );

  low low_entry;
  low_entry.set_seqnum( 1 );
  low_entry.set_update_action( 2 );
  low_entry.set_security_id( 3 );
  low_entry.set_entry_price( decimal( 4, 0 ) );
  low_entry.set_entry_size( 5 );
  low_entry.set_entry_date( 6 );
  low_entry.set_entry_time( 7 );

  msg.set_low( low_entry );

  offer offer_entry;
  offer_entry.set_seqnum( 1 );
  offer_entry.set_update_action( 2 );
  offer_entry.set_security_id( 3 );
  offer_entry.set_entry_price( decimal( 4, 0 ) );
  offer_entry.set_entry_size( 5 );
  offer_entry.set_entry_date( 6 );
  offer_entry.set_entry_time( 7 );
  offer_entry.set_seller( "8" );
  offer_entry.set_position( 9 );
  offer_entry.set_order_id( "10" );

  msg.add_offer( offer_entry );
  msg.add_offer( offer_entry );

  open open_entry;
  open_entry.set_seqnum( 1 );
  open_entry.set_update_action( 2 );
  open_entry.set_security_id( 3 );
  open_entry.set_entry_price( decimal( 4, 0 ) );
  open_entry.set_entry_size( 5 );
  open_entry.set_entry_date( 6 );
  open_entry.set_entry_time( 7 );
  open_entry.set_settl_flag( "8" );
  open_entry.set_variation( decimal( 9, 0 ) );

  msg.set_open( open_entry );

  open_interest open_interest_entry;
  open_interest_entry.set_seqnum( 1 );
  open_interest_entry.set_security_id( 2 );
  open_interest_entry.set_entry_price( decimal( 3, 0 ) );
  open_interest_entry.set_entry_size( 4 );
  open_interest_entry.set_entry_date( 5 );
  open_interest_entry.set_entry_time( 6 );

  msg.set_open_interest( open_interest_entry );

  price_band price_band_entry;
  price_band_entry.set_seqnum( 1 );
  price_band_entry.set_security_id( 2 );
  price_band_entry.set_price_band_type( "3" );
  price_band_entry.set_price_limit_type( 4 );
  price_band_entry.set_low_limit_price( decimal( 5, 0 ) );
  price_band_entry.set_high_limit_price( decimal( 6, 0 ) );
  price_band_entry.set_trading_reference_price( decimal( 7, 0 ) );
  price_band_entry.set_price_band_midpoint_price_type( 8 );
  price_band_entry.set_entry_date( 9 );
  price_band_entry.set_entry_time( 10 );

  msg.set_price_band( price_band_entry );

  quantity_band quantity_band_entry;
  quantity_band_entry.set_seqnum( 1 );
  quantity_band_entry.set_security_id( 2 );
  quantity_band_entry.set_low_limit_price( decimal( 3, 0 ) );
  quantity_band_entry.set_high_limit_price( decimal( 4, 0 ) );
  quantity_band_entry.set_trading_reference_price( decimal( 5, 0 ) );
  quantity_band_entry.set_price_band_midpoint_price_type( 6 );
  quantity_band_entry.set_avg_daily_traded_qty( 7 );
  quantity_band_entry.set_max_trade_vol( 8 );
  quantity_band_entry.set_entry_date( 9 );
  quantity_band_entry.set_entry_time( 10 );

  msg.set_quantity_band( quantity_band_entry );

  security_status security_status_entry;
  security_status_entry.set_seqnum( 1 );
  security_status_entry.set_security_id( 2 );
  security_status_entry.set_security_group( "3" );
  security_status_entry.set_group_phase( "4" );
  security_status_entry.set_instrument_state( 5 );
  security_status_entry.set_open_time( 6 );
  security_status_entry.set_trading_event( 7 );

  msg.set_security_status( security_status_entry );

  settlement settlement_entry;
  settlement_entry.set_seqnum( 1 );
  settlement_entry.set_security_id( 2 );
  settlement_entry.set_entry_price( decimal( 3, 0 ) );
  settlement_entry.set_price_type( "4" );
  settlement_entry.set_entry_date( 5 );
  settlement_entry.set_entry_time( 6 );
  settlement_entry.set_settl_flag( "7" );
  settlement_entry.set_settl_price_type( "8" );

  msg.set_settlement( settlement_entry );

  trade trade_entry;
  trade_entry.set_seqnum( 1 );
  trade_entry.set_update_action( 2 );
  trade_entry.set_security_id( 3 );
  trade_entry.set_entry_price( decimal( 4, 0 ) );
  trade_entry.set_entry_size( 5 );
  trade_entry.set_entry_date( 6 );
  trade_entry.set_entry_time( 7 );
  trade_entry.set_tick_direction( 8 );
  trade_entry.set_buyer( "9" );
  trade_entry.set_seller( "10" );
  trade_entry.set_variation( decimal( 11, 0 ) );
  trade_entry.set_quantity_volume( 12 );
  trade_entry.set_trade_id( "13" );
  trade_entry.set_trade_condition( "R X L P Q U 3 2 1" );

  msg.set_trade( trade_entry );

  trade_volume trade_volume_entry;
  trade_volume_entry.set_seqnum( 1 );
  trade_volume_entry.set_security_id( 2 );
  trade_volume_entry.set_financial_volume( decimal( 3, 0 ) );
  trade_volume_entry.set_number_of_trades( 4 );
  trade_volume_entry.set_quantity_volume( 5 );
  trade_volume_entry.set_entry_date( 6 );
  trade_volume_entry.set_entry_time( 7 );
  trade_volume_entry.set_currency( "8" );

  msg.set_trade_volume( trade_volume_entry );

  vwap vwap_entry;
  vwap_entry.set_seqnum( 1 );
  vwap_entry.set_update_action( 2 );
  vwap_entry.set_security_id( 3 );
  vwap_entry.set_entry_price( decimal( 4, 0 ) );
  vwap_entry.set_entry_size( 5 );
  vwap_entry.set_entry_date( 6 );
  vwap_entry.set_entry_time( 7 );

  msg.set_vwap( vwap_entry );


  auto smsg = serializer.serialize( msg );

  snapshot dmsg;
  std::size_t msize = serializer.deserialize( smsg.first, dmsg );

  BOOST_CHECK_EQUAL( smsg.second, msize );
  BOOST_CHECK( dmsg.auction_imbalance().first );
  auto dauction_imbalance = dmsg.auction_imbalance().second;
  BOOST_CHECK( dauction_imbalance.seqnum().first );
  BOOST_CHECK_EQUAL( dauction_imbalance.seqnum().second, 1 );
  BOOST_CHECK( dauction_imbalance.update_action().first );
  BOOST_CHECK_EQUAL( dauction_imbalance.update_action().second, 2 );
  BOOST_CHECK( dauction_imbalance.security_id().first );
  BOOST_CHECK_EQUAL( dauction_imbalance.security_id().second, 3 );
  BOOST_CHECK( dauction_imbalance.entry_size().first );
  BOOST_CHECK_EQUAL( dauction_imbalance.entry_size().second, 4 );
  BOOST_CHECK( dauction_imbalance.entry_date().first );
  BOOST_CHECK_EQUAL( dauction_imbalance.entry_date().second, 5 );
  BOOST_CHECK( dauction_imbalance.entry_time().first );
  BOOST_CHECK_EQUAL( dauction_imbalance.entry_time().second, 6 );
  BOOST_CHECK( dauction_imbalance.trade_condition_opening_price() );
  BOOST_CHECK( dauction_imbalance.trade_condition_crossed() );
  BOOST_CHECK( dauction_imbalance.trade_condition_last_trade_at_price() );
  BOOST_CHECK( dauction_imbalance.trade_condition_imbalance_more_buyers() );
  BOOST_CHECK( dauction_imbalance.trade_condition_imbalance_more_sellers() );
  BOOST_CHECK( dauction_imbalance.trade_condition_exchange_last() );
  BOOST_CHECK( dauction_imbalance.trade_condition_multi_asset_trade() );
  BOOST_CHECK( dauction_imbalance.trade_condition_leg_trade() );
  BOOST_CHECK( dauction_imbalance.trade_condition_marketplace_entered_trade() );
  BOOST_REQUIRE_EQUAL( dmsg.bids().size(), 2 );
  auto dbid = dmsg.bids()[0];
  BOOST_CHECK( dbid.seqnum().first );
  BOOST_CHECK_EQUAL( dbid.seqnum().second, 1 );
  BOOST_CHECK( dbid.update_action().first );
  BOOST_CHECK_EQUAL( dbid.update_action().second, 2 );
  BOOST_CHECK( dbid.security_id().first );
  BOOST_CHECK_EQUAL( dbid.security_id().second, 3 );
  BOOST_CHECK( dbid.entry_price().first );
  BOOST_CHECK_EQUAL( dbid.entry_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( dbid.entry_size().first );
  BOOST_CHECK_EQUAL( dbid.entry_size().second, 5 );
  BOOST_CHECK( dbid.entry_date().first );
  BOOST_CHECK_EQUAL( dbid.entry_date().second, 6 );
  BOOST_CHECK( dbid.entry_time().first );
  BOOST_CHECK_EQUAL( dbid.entry_time().second, 7 );
  BOOST_CHECK( dbid.buyer().first );
  BOOST_CHECK_EQUAL( dbid.buyer().second, "8" );
  BOOST_CHECK( dbid.position().first );
  BOOST_CHECK_EQUAL( dbid.position().second, 9 );
  BOOST_CHECK( dbid.order_id().first );
  BOOST_CHECK_EQUAL( dbid.order_id().second, "10" );
  dbid = dmsg.bids()[1];
  BOOST_CHECK( dbid.seqnum().first );
  BOOST_CHECK_EQUAL( dbid.seqnum().second, 1 );
  BOOST_CHECK( dbid.update_action().first );
  BOOST_CHECK_EQUAL( dbid.update_action().second, 2 );
  BOOST_CHECK( dbid.security_id().first );
  BOOST_CHECK_EQUAL( dbid.security_id().second, 3 );
  BOOST_CHECK( dbid.entry_price().first );
  BOOST_CHECK_EQUAL( dbid.entry_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( dbid.entry_size().first );
  BOOST_CHECK_EQUAL( dbid.entry_size().second, 5 );
  BOOST_CHECK( dbid.entry_date().first );
  BOOST_CHECK_EQUAL( dbid.entry_date().second, 6 );
  BOOST_CHECK( dbid.entry_time().first );
  BOOST_CHECK_EQUAL( dbid.entry_time().second, 7 );
  BOOST_CHECK( dbid.buyer().first );
  BOOST_CHECK_EQUAL( dbid.buyer().second, "8" );
  BOOST_CHECK( dbid.position().first );
  BOOST_CHECK_EQUAL( dbid.position().second, 9 );
  BOOST_CHECK( dbid.order_id().first );
  BOOST_CHECK_EQUAL( dbid.order_id().second, "10" );
  BOOST_CHECK( dmsg.close().first );
  auto dclose = dmsg.close().second;
  BOOST_CHECK( dclose.seqnum().first );
  BOOST_CHECK_EQUAL( dclose.seqnum().second, 1 );
  BOOST_CHECK( dclose.security_id().first );
  BOOST_CHECK_EQUAL( dclose.security_id().second, 2 );
  BOOST_CHECK( dclose.entry_price().first );
  BOOST_CHECK_EQUAL( dclose.entry_price().second, decimal( 3, 0 ) );
  BOOST_CHECK( dclose.last_trade_date().first );
  BOOST_CHECK_EQUAL( dclose.last_trade_date().second, 4 );
  BOOST_CHECK( dclose.price_adjust_method().first );
  BOOST_CHECK_EQUAL( dclose.price_adjust_method().second, 5 );
  BOOST_CHECK( dclose.entry_date().first );
  BOOST_CHECK_EQUAL( dclose.entry_date().second, 6 );
  BOOST_CHECK( dclose.entry_time().first );
  BOOST_CHECK_EQUAL( dclose.entry_time().second, 7 );
  BOOST_CHECK( dclose.settl_flag().first );
  BOOST_CHECK_EQUAL( dclose.settl_flag().second, "8" );
  BOOST_CHECK( dmsg.high().first );
  auto dhigh = dmsg.high().second;
  BOOST_CHECK( dhigh.seqnum().first );
  BOOST_CHECK_EQUAL( dhigh.seqnum().second, 1 );
  BOOST_CHECK( dhigh.update_action().first );
  BOOST_CHECK_EQUAL( dhigh.update_action().second, 2 );
  BOOST_CHECK( dhigh.security_id().first );
  BOOST_CHECK_EQUAL( dhigh.security_id().second, 3 );
  BOOST_CHECK( dhigh.entry_price().first );
  BOOST_CHECK_EQUAL( dhigh.entry_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( dhigh.entry_size().first );
  BOOST_CHECK_EQUAL( dhigh.entry_size().second, 5 );
  BOOST_CHECK( dhigh.entry_date().first );
  BOOST_CHECK_EQUAL( dhigh.entry_date().second, 6 );
  BOOST_CHECK( dhigh.entry_time().first );
  BOOST_CHECK_EQUAL( dhigh.entry_time().second, 7 );
  BOOST_CHECK( dmsg.index().first );
  auto dindex = dmsg.index().second;
  BOOST_CHECK( dindex.seqnum().first );
  BOOST_CHECK_EQUAL( dindex.seqnum().second, 1 );
  BOOST_CHECK( dindex.update_action().first );
  BOOST_CHECK_EQUAL( dindex.update_action().second, 2 );
  BOOST_CHECK( dindex.security_id().first );
  BOOST_CHECK_EQUAL( dindex.security_id().second, 3 );
  BOOST_CHECK( dindex.entry_price().first );
  BOOST_CHECK_EQUAL( dindex.entry_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( dindex.entry_date().first );
  BOOST_CHECK_EQUAL( dindex.entry_date().second, 5 );
  BOOST_CHECK( dindex.entry_time().first );
  BOOST_CHECK_EQUAL( dindex.entry_time().second, 6 );
  BOOST_CHECK( dindex.tick_direction().first );
  BOOST_CHECK_EQUAL( dindex.tick_direction().second, 7 );
  BOOST_CHECK( dmsg.low().first );
  auto dlow = dmsg.low().second;
  BOOST_CHECK( dlow.seqnum().first );
  BOOST_CHECK_EQUAL( dlow.seqnum().second, 1 );
  BOOST_CHECK( dlow.update_action().first );
  BOOST_CHECK_EQUAL( dlow.update_action().second, 2 );
  BOOST_CHECK( dlow.security_id().first );
  BOOST_CHECK_EQUAL( dlow.security_id().second, 3 );
  BOOST_CHECK( dlow.entry_price().first );
  BOOST_CHECK_EQUAL( dlow.entry_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( dlow.entry_size().first );
  BOOST_CHECK_EQUAL( dlow.entry_size().second, 5 );
  BOOST_CHECK( dlow.entry_date().first );
  BOOST_CHECK_EQUAL( dlow.entry_date().second, 6 );
  BOOST_CHECK( dlow.entry_time().first );
  BOOST_CHECK_EQUAL( dlow.entry_time().second, 7 );
  BOOST_REQUIRE_EQUAL( dmsg.offers().size(), 2 );
  auto doffer = dmsg.offers()[0];
  BOOST_CHECK( doffer.seqnum().first );
  BOOST_CHECK_EQUAL( doffer.seqnum().second, 1 );
  BOOST_CHECK( doffer.update_action().first );
  BOOST_CHECK_EQUAL( doffer.update_action().second, 2 );
  BOOST_CHECK( doffer.security_id().first );
  BOOST_CHECK_EQUAL( doffer.security_id().second, 3 );
  BOOST_CHECK( doffer.entry_price().first );
  BOOST_CHECK_EQUAL( doffer.entry_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( doffer.entry_size().first );
  BOOST_CHECK_EQUAL( doffer.entry_size().second, 5 );
  BOOST_CHECK( doffer.entry_date().first );
  BOOST_CHECK_EQUAL( doffer.entry_date().second, 6 );
  BOOST_CHECK( doffer.entry_time().first );
  BOOST_CHECK_EQUAL( doffer.entry_time().second, 7 );
  BOOST_CHECK( doffer.seller().first );
  BOOST_CHECK_EQUAL( doffer.seller().second, "8" );
  BOOST_CHECK( doffer.position().first );
  BOOST_CHECK_EQUAL( doffer.position().second, 9 );
  BOOST_CHECK( doffer.order_id().first );
  BOOST_CHECK_EQUAL( doffer.order_id().second, "10" );
  doffer = dmsg.offers()[1];
  BOOST_CHECK( doffer.seqnum().first );
  BOOST_CHECK_EQUAL( doffer.seqnum().second, 1 );
  BOOST_CHECK( doffer.update_action().first );
  BOOST_CHECK_EQUAL( doffer.update_action().second, 2 );
  BOOST_CHECK( doffer.security_id().first );
  BOOST_CHECK_EQUAL( doffer.security_id().second, 3 );
  BOOST_CHECK( doffer.entry_price().first );
  BOOST_CHECK_EQUAL( doffer.entry_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( doffer.entry_size().first );
  BOOST_CHECK_EQUAL( doffer.entry_size().second, 5 );
  BOOST_CHECK( doffer.entry_date().first );
  BOOST_CHECK_EQUAL( doffer.entry_date().second, 6 );
  BOOST_CHECK( doffer.entry_time().first );
  BOOST_CHECK_EQUAL( doffer.entry_time().second, 7 );
  BOOST_CHECK( doffer.seller().first );
  BOOST_CHECK_EQUAL( doffer.seller().second, "8" );
  BOOST_CHECK( doffer.position().first );
  BOOST_CHECK_EQUAL( doffer.position().second, 9 );
  BOOST_CHECK( doffer.order_id().first );
  BOOST_CHECK_EQUAL( doffer.order_id().second, "10" );
  BOOST_CHECK( dmsg.open().first );
  auto dopen = dmsg.open().second;
  BOOST_CHECK( dopen.seqnum().first );
  BOOST_CHECK_EQUAL( dopen.seqnum().second, 1 );
  BOOST_CHECK( dopen.update_action().first );
  BOOST_CHECK_EQUAL( dopen.update_action().second, 2 );
  BOOST_CHECK( dopen.security_id().first );
  BOOST_CHECK_EQUAL( dopen.security_id().second, 3 );
  BOOST_CHECK( dopen.entry_price().first );
  BOOST_CHECK_EQUAL( dopen.entry_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( dopen.entry_size().first );
  BOOST_CHECK_EQUAL( dopen.entry_size().second, 5 );
  BOOST_CHECK( dopen.entry_date().first );
  BOOST_CHECK_EQUAL( dopen.entry_date().second, 6 );
  BOOST_CHECK( dopen.entry_time().first );
  BOOST_CHECK_EQUAL( dopen.entry_time().second, 7 );
  BOOST_CHECK( dopen.settl_flag().first );
  BOOST_CHECK_EQUAL( dopen.settl_flag().second, "8" );
  BOOST_CHECK( dopen.variation().first );
  BOOST_CHECK_EQUAL( dopen.variation().second, decimal( 9, 0 ) );
  BOOST_CHECK( dmsg.open_interest().first );
  auto dopen_interest = dmsg.open_interest().second;
  BOOST_CHECK( dopen_interest.seqnum().first );
  BOOST_CHECK_EQUAL( dopen_interest.seqnum().second, 1 );
  BOOST_CHECK( dopen_interest.security_id().first );
  BOOST_CHECK_EQUAL( dopen_interest.security_id().second, 2 );
  BOOST_CHECK( dopen_interest.entry_price().first );
  BOOST_CHECK_EQUAL( dopen_interest.entry_price().second, decimal( 3, 0 ) );
  BOOST_CHECK( dopen_interest.entry_size().first );
  BOOST_CHECK_EQUAL( dopen_interest.entry_size().second, 4 );
  BOOST_CHECK( dopen_interest.entry_date().first );
  BOOST_CHECK_EQUAL( dopen_interest.entry_date().second, 5 );
  BOOST_CHECK( dopen_interest.entry_time().first );
  BOOST_CHECK_EQUAL( dopen_interest.entry_time().second, 6 );
  BOOST_CHECK( dmsg.price_band().first );
  auto dprice_band = dmsg.price_band().second;
  BOOST_CHECK( dprice_band.seqnum().first );
  BOOST_CHECK_EQUAL( dprice_band.seqnum().second, 1 );
  BOOST_CHECK( dprice_band.security_id().first );
  BOOST_CHECK_EQUAL( dprice_band.security_id().second, 2 );
  BOOST_CHECK( dprice_band.price_band_type().first );
  BOOST_CHECK_EQUAL( dprice_band.price_band_type().second, "3" );
  BOOST_CHECK( dprice_band.price_limit_type().first );
  BOOST_CHECK_EQUAL( dprice_band.price_limit_type().second, 4 );
  BOOST_CHECK( dprice_band.low_limit_price().first );
  BOOST_CHECK_EQUAL( dprice_band.low_limit_price().second, decimal( 5, 0 ) );
  BOOST_CHECK( dprice_band.high_limit_price().first );
  BOOST_CHECK_EQUAL( dprice_band.high_limit_price().second, decimal( 6, 0 ) );
  BOOST_CHECK( dprice_band.trading_reference_price().first );
  BOOST_CHECK_EQUAL( dprice_band.trading_reference_price().second, decimal( 7, 0 ) );
  BOOST_CHECK( dprice_band.price_band_midpoint_price_type().first );
  BOOST_CHECK_EQUAL( dprice_band.price_band_midpoint_price_type().second, 8 );
  BOOST_CHECK( dprice_band.entry_date().first );
  BOOST_CHECK_EQUAL( dprice_band.entry_date().second, 9 );
  BOOST_CHECK( dprice_band.entry_time().first );
  BOOST_CHECK_EQUAL( dprice_band.entry_time().second, 10 );
  BOOST_CHECK( dmsg.quantity_band().first );
  auto dquantity_band = dmsg.quantity_band().second;
  BOOST_CHECK( dquantity_band.seqnum().first );
  BOOST_CHECK_EQUAL( dquantity_band.seqnum().second, 1 );
  BOOST_CHECK( dquantity_band.security_id().first );
  BOOST_CHECK_EQUAL( dquantity_band.security_id().second, 2 );
  BOOST_CHECK( dquantity_band.low_limit_price().first );
  BOOST_CHECK_EQUAL( dquantity_band.low_limit_price().second, decimal( 3, 0 ) );
  BOOST_CHECK( dquantity_band.high_limit_price().first );
  BOOST_CHECK_EQUAL( dquantity_band.high_limit_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( dquantity_band.trading_reference_price().first );
  BOOST_CHECK_EQUAL( dquantity_band.trading_reference_price().second, decimal( 5, 0 ) );
  BOOST_CHECK( dquantity_band.price_band_midpoint_price_type().first );
  BOOST_CHECK_EQUAL( dquantity_band.price_band_midpoint_price_type().second, 6 );
  BOOST_CHECK( dquantity_band.avg_daily_traded_qty().first );
  BOOST_CHECK_EQUAL( dquantity_band.avg_daily_traded_qty().second, 7 );
  BOOST_CHECK( dquantity_band.max_trade_vol().first );
  BOOST_CHECK_EQUAL( dquantity_band.max_trade_vol().second, 8 );
  BOOST_CHECK( dquantity_band.entry_date().first );
  BOOST_CHECK_EQUAL( dquantity_band.entry_date().second, 9 );
  BOOST_CHECK( dquantity_band.entry_time().first );
  BOOST_CHECK_EQUAL( dquantity_band.entry_time().second, 10 );
  BOOST_CHECK( dmsg.security_status().first );
  auto dsecurity_status = dmsg.security_status().second;
  BOOST_CHECK( dsecurity_status.seqnum().first );
  BOOST_CHECK_EQUAL( dsecurity_status.seqnum().second, 1 );
  BOOST_CHECK( dsecurity_status.security_id().first );
  BOOST_CHECK_EQUAL( dsecurity_status.security_id().second, 2 );
  BOOST_CHECK( dsecurity_status.security_group().first );
  BOOST_CHECK_EQUAL( dsecurity_status.security_group().second, "3" );
  BOOST_CHECK( dsecurity_status.group_phase().first );
  BOOST_CHECK_EQUAL( dsecurity_status.group_phase().second, "4" );
  BOOST_CHECK( dsecurity_status.instrument_state().first );
  BOOST_CHECK_EQUAL( dsecurity_status.instrument_state().second, 5 );
  BOOST_CHECK( dsecurity_status.open_time().first );
  BOOST_CHECK_EQUAL( dsecurity_status.open_time().second, 6 );
  BOOST_CHECK( dsecurity_status.trading_event().first );
  BOOST_CHECK_EQUAL( dsecurity_status.trading_event().second, 7 );
  BOOST_CHECK( dmsg.settlement().first );
  auto dsettlement = dmsg.settlement().second;
  BOOST_CHECK( dsettlement.seqnum().first );
  BOOST_CHECK_EQUAL( dsettlement.seqnum().second, 1 );
  BOOST_CHECK( dsettlement.security_id().first );
  BOOST_CHECK_EQUAL( dsettlement.security_id().second, 2 );
  BOOST_CHECK( dsettlement.entry_price().first );
  BOOST_CHECK_EQUAL( dsettlement.entry_price().second, decimal( 3, 0 ) );
  BOOST_CHECK( dsettlement.price_type().first );
  BOOST_CHECK_EQUAL( dsettlement.price_type().second, "4" );
  BOOST_CHECK( dsettlement.entry_date().first );
  BOOST_CHECK_EQUAL( dsettlement.entry_date().second, 5 );
  BOOST_CHECK( dsettlement.entry_time().first );
  BOOST_CHECK_EQUAL( dsettlement.entry_time().second, 6 );
  BOOST_CHECK( dsettlement.settl_flag().first );
  BOOST_CHECK_EQUAL( dsettlement.settl_flag().second, "7" );
  BOOST_CHECK( dsettlement.settl_price_type().first );
  BOOST_CHECK_EQUAL( dsettlement.settl_price_type().second, "8" );
  BOOST_CHECK( dmsg.trade().first );
  auto dtrade = dmsg.trade().second;
  BOOST_CHECK( dtrade.seqnum().first );
  BOOST_CHECK_EQUAL( dtrade.seqnum().second, 1 );
  BOOST_CHECK( dtrade.update_action().first );
  BOOST_CHECK_EQUAL( dtrade.update_action().second, 2 );
  BOOST_CHECK( dtrade.security_id().first );
  BOOST_CHECK_EQUAL( dtrade.security_id().second, 3 );
  BOOST_CHECK( dtrade.entry_price().first );
  BOOST_CHECK_EQUAL( dtrade.entry_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( dtrade.entry_size().first );
  BOOST_CHECK_EQUAL( dtrade.entry_size().second, 5 );
  BOOST_CHECK( dtrade.entry_date().first );
  BOOST_CHECK_EQUAL( dtrade.entry_date().second, 6 );
  BOOST_CHECK( dtrade.entry_time().first );
  BOOST_CHECK_EQUAL( dtrade.entry_time().second, 7 );
  BOOST_CHECK( dtrade.tick_direction().first );
  BOOST_CHECK_EQUAL( dtrade.tick_direction().second, 8 );
  BOOST_CHECK( dtrade.buyer().first );
  BOOST_CHECK_EQUAL( dtrade.buyer().second, "9" );
  BOOST_CHECK( dtrade.seller().first );
  BOOST_CHECK_EQUAL( dtrade.seller().second, "10" );
  BOOST_CHECK( dtrade.variation().first );
  BOOST_CHECK_EQUAL( dtrade.variation().second, decimal( 11, 0 ) );
  BOOST_CHECK( dtrade.quantity_volume().first );
  BOOST_CHECK_EQUAL( dtrade.quantity_volume().second, 12 );
  BOOST_CHECK( dtrade.trade_id().first );
  BOOST_CHECK_EQUAL( dtrade.trade_id().second, "13" );
  BOOST_CHECK( dtrade.trade_condition_opening_price() );
  BOOST_CHECK( dtrade.trade_condition_crossed() );
  BOOST_CHECK( dtrade.trade_condition_last_trade_at_price() );
  BOOST_CHECK( dtrade.trade_condition_imbalance_more_buyers() );
  BOOST_CHECK( dtrade.trade_condition_imbalance_more_sellers() );
  BOOST_CHECK( dtrade.trade_condition_exchange_last() );
  BOOST_CHECK( dtrade.trade_condition_multi_asset_trade() );
  BOOST_CHECK( dtrade.trade_condition_leg_trade() );
  BOOST_CHECK( dtrade.trade_condition_marketplace_entered_trade() );
  BOOST_CHECK( dmsg.trade_volume().first );
  auto dtrade_volume = dmsg.trade_volume().second;
  BOOST_CHECK( dtrade_volume.seqnum().first );
  BOOST_CHECK_EQUAL( dtrade_volume.seqnum().second, 1 );
  BOOST_CHECK( dtrade_volume.security_id().first );
  BOOST_CHECK_EQUAL( dtrade_volume.security_id().second, 2 );
  BOOST_CHECK( dtrade_volume.financial_volume().first );
  BOOST_CHECK_EQUAL( dtrade_volume.financial_volume().second, decimal( 3, 0 ) );
  BOOST_CHECK( dtrade_volume.number_of_trades().first );
  BOOST_CHECK_EQUAL( dtrade_volume.number_of_trades().second, 4 );
  BOOST_CHECK( dtrade_volume.quantity_volume().first );
  BOOST_CHECK_EQUAL( dtrade_volume.quantity_volume().second, 5 );
  BOOST_CHECK( dtrade_volume.entry_date().first );
  BOOST_CHECK_EQUAL( dtrade_volume.entry_date().second, 6 );
  BOOST_CHECK( dtrade_volume.entry_time().first );
  BOOST_CHECK_EQUAL( dtrade_volume.entry_time().second, 7 );
  BOOST_CHECK( dtrade_volume.currency().first );
  BOOST_CHECK_EQUAL( dtrade_volume.currency().second, "8" );
  BOOST_CHECK( dmsg.vwap().first );
  auto dvwap = dmsg.vwap().second;
  BOOST_CHECK( dvwap.seqnum().first );
  BOOST_CHECK_EQUAL( dvwap.seqnum().second, 1 );
  BOOST_CHECK( dvwap.update_action().first );
  BOOST_CHECK_EQUAL( dvwap.update_action().second, 2 );
  BOOST_CHECK( dvwap.security_id().first );
  BOOST_CHECK_EQUAL( dvwap.security_id().second, 3 );
  BOOST_CHECK( dvwap.entry_price().first );
  BOOST_CHECK_EQUAL( dvwap.entry_price().second, decimal( 4, 0 ) );
  BOOST_CHECK( dvwap.entry_size().first );
  BOOST_CHECK_EQUAL( dvwap.entry_size().second, 5 );
  BOOST_CHECK( dvwap.entry_date().first );
  BOOST_CHECK_EQUAL( dvwap.entry_date().second, 6 );
  BOOST_CHECK( dvwap.entry_time().first );
  BOOST_CHECK_EQUAL( dvwap.entry_time().second, 7 );

};

BOOST_AUTO_TEST_SUITE_END()

