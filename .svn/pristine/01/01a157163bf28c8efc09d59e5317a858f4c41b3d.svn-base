#include <msi/msi_pch.hpp>
#include <boost/tokenizer.hpp>
#include <msi/marketdata/messages/security_definition.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

void
security_definition::appl_id_entry::feed_type_entry::reset()
{
  presence_map_.reset();
}

std::pair<bool, const std::string&>
security_definition::appl_id_entry::feed_type_entry::feed_type() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_feed_type], feed_type_ );
}

void
security_definition::appl_id_entry::feed_type_entry::set_feed_type( const std::string& val )
{
  feed_type_ = val;
  presence_map_[ix_feed_type] = true;
}

std::pair<bool, uint32_t>
security_definition::appl_id_entry::feed_type_entry::market_depth() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_market_depth], market_depth_ );
}

void
security_definition::appl_id_entry::feed_type_entry::set_market_depth( uint32_t val )
{
  market_depth_ = val;
  presence_map_[ix_market_depth] = true;
}

const std::bitset<security_definition::appl_id_entry::feed_type_entry::ix_field_count>&
security_definition::appl_id_entry::feed_type_entry::presence_map() const
{
  return presence_map_;
}

void security_definition::appl_id_entry::feed_type_entry::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}

void
security_definition::appl_id_entry::reset()
{
  presence_map_.reset();
  feed_types_.clear();
}

const std::vector<security_definition::appl_id_entry::feed_type_entry>&
security_definition::appl_id_entry::feed_types() const
{
  return feed_types_;
}

void
security_definition::appl_id_entry::add_feed_type( const feed_type_entry& val )
{
  feed_types_.push_back( val );
  presence_map_[ix_feed_type] = true;
}

std::pair<bool, const std::string&>
security_definition::appl_id_entry::appl_id() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_appl_id], appl_id_ );
}

void
security_definition::appl_id_entry::set_appl_id( const std::string& val )
{
  appl_id_ = val;
  presence_map_[ix_appl_id] = true;
}

const std::bitset<security_definition::appl_id_entry::ix_field_count>&
security_definition::appl_id_entry::presence_map() const
{
  return presence_map_;
}

void security_definition::appl_id_entry::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}

void
security_definition::security_alt_id_entry::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint64_t>
security_definition::security_alt_id_entry::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
security_definition::security_alt_id_entry::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, const std::string&>
security_definition::security_alt_id_entry::security_id_source() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_security_id_source], security_id_source_ );
}

void
security_definition::security_alt_id_entry::set_security_id_source( const std::string& val )
{
  security_id_source_ = val;
  presence_map_[ix_security_id_source] = true;
}

const std::bitset<security_definition::security_alt_id_entry::ix_field_count>&
security_definition::security_alt_id_entry::presence_map() const
{
  return presence_map_;
}

void security_definition::security_alt_id_entry::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}

void
security_definition::underlying_entry::reset()
{
  presence_map_.reset();
}

std::pair<bool, const std::string&>
security_definition::underlying_entry::symbol() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_symbol], symbol_ );
}

void
security_definition::underlying_entry::set_symbol( const std::string& val )
{
  symbol_ = val;
  presence_map_[ix_symbol] = true;
}

std::pair<bool, uint64_t>
security_definition::underlying_entry::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
security_definition::underlying_entry::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, const std::string&>
security_definition::underlying_entry::security_id_source() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_security_id_source], security_id_source_ );
}

void
security_definition::underlying_entry::set_security_id_source( const std::string& val )
{
  security_id_source_ = val;
  presence_map_[ix_security_id_source] = true;
}

std::pair<bool, const std::string&>
security_definition::underlying_entry::security_exchange() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_security_exchange], security_exchange_ );
}

void
security_definition::underlying_entry::set_security_exchange( const std::string& val )
{
  security_exchange_ = val;
  presence_map_[ix_security_exchange] = true;
}

std::pair<bool, decimal>
security_definition::underlying_entry::index_pct() const
{
  return std::pair<bool, decimal>( presence_map_[ix_index_pct], index_pct_ );
}

void
security_definition::underlying_entry::set_index_pct( decimal val )
{
  index_pct_ = val;
  presence_map_[ix_index_pct] = true;
}

std::pair<bool, decimal>
security_definition::underlying_entry::index_theoretical_qty() const
{
  return std::pair<bool, decimal>( presence_map_[ix_index_theoretical_qty], index_theoretical_qty_ );
}

void
security_definition::underlying_entry::set_index_theoretical_qty( decimal val )
{
  index_theoretical_qty_ = val;
  presence_map_[ix_index_theoretical_qty] = true;
}

const std::bitset<security_definition::underlying_entry::ix_field_count>&
security_definition::underlying_entry::presence_map() const
{
  return presence_map_;
}

void security_definition::underlying_entry::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}

void
security_definition::instr_attrib_entry::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
security_definition::instr_attrib_entry::inst_attrib_type() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_inst_attrib_type], inst_attrib_type_ );
}

void
security_definition::instr_attrib_entry::set_inst_attrib_type( uint32_t val )
{
  inst_attrib_type_ = val;
  presence_map_[ix_inst_attrib_type] = true;
}

std::pair<bool, const std::string&>
security_definition::instr_attrib_entry::inst_attrib_value() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_inst_attrib_value], inst_attrib_value_ );
}

void
security_definition::instr_attrib_entry::set_inst_attrib_value( const std::string& val )
{
  inst_attrib_value_ = val;
  presence_map_[ix_inst_attrib_value] = true;
}

const std::bitset<security_definition::instr_attrib_entry::ix_field_count>&
security_definition::instr_attrib_entry::presence_map() const
{
  return presence_map_;
}

void security_definition::instr_attrib_entry::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}

void
security_definition::tick_rule_entry::reset()
{
  presence_map_.reset();
}

std::pair<bool, decimal>
security_definition::tick_rule_entry::start_tick_price_range() const
{
  return std::pair<bool, decimal>( presence_map_[ix_start_tick_price_range], start_tick_price_range_ );
}

void
security_definition::tick_rule_entry::set_start_tick_price_range( decimal val )
{
  start_tick_price_range_ = val;
  presence_map_[ix_start_tick_price_range] = true;
}

std::pair<bool, decimal>
security_definition::tick_rule_entry::end_tick_price_range() const
{
  return std::pair<bool, decimal>( presence_map_[ix_end_tick_price_range], end_tick_price_range_ );
}

void
security_definition::tick_rule_entry::set_end_tick_price_range( decimal val )
{
  end_tick_price_range_ = val;
  presence_map_[ix_end_tick_price_range] = true;
}

std::pair<bool, decimal>
security_definition::tick_rule_entry::tick_increment() const
{
  return std::pair<bool, decimal>( presence_map_[ix_tick_increment], tick_increment_ );
}

void
security_definition::tick_rule_entry::set_tick_increment( decimal val )
{
  tick_increment_ = val;
  presence_map_[ix_tick_increment] = true;
}

std::pair<bool, int32_t>
security_definition::tick_rule_entry::tick_rule_type() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_tick_rule_type], tick_rule_type_ );
}

void
security_definition::tick_rule_entry::set_tick_rule_type( int32_t val )
{
  tick_rule_type_ = val;
  presence_map_[ix_tick_rule_type] = true;
}

const std::bitset<security_definition::tick_rule_entry::ix_field_count>&
security_definition::tick_rule_entry::presence_map() const
{
  return presence_map_;
}

void security_definition::tick_rule_entry::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}

void
security_definition::leg_entry::reset()
{
  presence_map_.reset();
}

std::pair<bool, const std::string&>
security_definition::leg_entry::leg_symbol() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_leg_symbol], leg_symbol_ );
}

void
security_definition::leg_entry::set_leg_symbol( const std::string& val )
{
  leg_symbol_ = val;
  presence_map_[ix_leg_symbol] = true;
}

std::pair<bool, uint64_t>
security_definition::leg_entry::leg_security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_leg_security_id], leg_security_id_ );
}

void
security_definition::leg_entry::set_leg_security_id( uint64_t val )
{
  leg_security_id_ = val;
  presence_map_[ix_leg_security_id] = true;
}

std::pair<bool, const std::string&>
security_definition::leg_entry::leg_security_id_source() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_leg_security_id_source], leg_security_id_source_ );
}

void
security_definition::leg_entry::set_leg_security_id_source( const std::string& val )
{
  leg_security_id_source_ = val;
  presence_map_[ix_leg_security_id_source] = true;
}

std::pair<bool, int32_t>
security_definition::leg_entry::leg_ratio_qty() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_leg_ratio_qty], leg_ratio_qty_ );
}

void
security_definition::leg_entry::set_leg_ratio_qty( int32_t val )
{
  leg_ratio_qty_ = val;
  presence_map_[ix_leg_ratio_qty] = true;
}

std::pair<bool, const std::string&>
security_definition::leg_entry::leg_security_type() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_leg_security_type], leg_security_type_ );
}

void
security_definition::leg_entry::set_leg_security_type( const std::string& val )
{
  leg_security_type_ = val;
  presence_map_[ix_leg_security_type] = true;
}

std::pair<bool, int32_t>
security_definition::leg_entry::leg_side() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_leg_side], leg_side_ );
}

void
security_definition::leg_entry::set_leg_side( int32_t val )
{
  leg_side_ = val;
  presence_map_[ix_leg_side] = true;
}

std::pair<bool, const std::string&>
security_definition::leg_entry::leg_security_exchange() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_leg_security_exchange], leg_security_exchange_ );
}

void
security_definition::leg_entry::set_leg_security_exchange( const std::string& val )
{
  leg_security_exchange_ = val;
  presence_map_[ix_leg_security_exchange] = true;
}

const std::bitset<security_definition::leg_entry::ix_field_count>&
security_definition::leg_entry::presence_map() const
{
  return presence_map_;
}

void security_definition::leg_entry::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}

void
security_definition::lot_entry::reset()
{
  presence_map_.reset();
}

std::pair<bool, int32_t>
security_definition::lot_entry::lot_type() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_lot_type], lot_type_ );
}

void
security_definition::lot_entry::set_lot_type( int32_t val )
{
  lot_type_ = val;
  presence_map_[ix_lot_type] = true;
}

std::pair<bool, uint32_t>
security_definition::lot_entry::min_lot_size() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_min_lot_size], min_lot_size_ );
}

void
security_definition::lot_entry::set_min_lot_size( uint32_t val )
{
  min_lot_size_ = val;
  presence_map_[ix_min_lot_size] = true;
}

const std::bitset<security_definition::lot_entry::ix_field_count>&
security_definition::lot_entry::presence_map() const
{
  return presence_map_;
}

void security_definition::lot_entry::set_presence_map( uint32_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}

void
security_definition::reset()
{
  presence_map_.reset();
  appl_ids_.clear();
  security_alt_ids_.clear();
  underlyings_.clear();
  instr_attribs_.clear();
  tick_rules_.clear();
  legs_.clear();
  lots_.clear();
}

const std::vector<security_definition::appl_id_entry>&
security_definition::appl_ids() const
{
  return appl_ids_;
}

void
security_definition::add_appl_id( const appl_id_entry& val )
{
  appl_ids_.push_back( val );
  presence_map_[ix_appl_id] = true;
}

const std::vector<security_definition::security_alt_id_entry>&
security_definition::security_alt_ids() const
{
  return security_alt_ids_;
}

void
security_definition::add_security_alt_id( const security_alt_id_entry& val )
{
  security_alt_ids_.push_back( val );
  presence_map_[ix_security_alt_id] = true;
}

const std::vector<security_definition::underlying_entry>&
security_definition::underlyings() const
{
  return underlyings_;
}

void
security_definition::add_underlying( const underlying_entry& val )
{
  underlyings_.push_back( val );
  presence_map_[ix_underlying] = true;
}

const std::vector<security_definition::instr_attrib_entry>&
security_definition::instr_attribs() const
{
  return instr_attribs_;
}

void
security_definition::add_instr_attrib( const instr_attrib_entry& val )
{
  instr_attribs_.push_back( val );
  presence_map_[ix_instr_attrib] = true;
}

const std::vector<security_definition::tick_rule_entry>&
security_definition::tick_rules() const
{
  return tick_rules_;
}

void
security_definition::add_tick_rule( const tick_rule_entry& val )
{
  tick_rules_.push_back( val );
  presence_map_[ix_tick_rule] = true;
}

const std::vector<security_definition::leg_entry>&
security_definition::legs() const
{
  return legs_;
}

void
security_definition::add_leg( const leg_entry& val )
{
  legs_.push_back( val );
  presence_map_[ix_leg] = true;
}

const std::vector<security_definition::lot_entry>&
security_definition::lots() const
{
  return lots_;
}

void
security_definition::add_lot( const lot_entry& val )
{
  lots_.push_back( val );
  presence_map_[ix_lot] = true;
}

std::pair<bool, uint32_t>
security_definition::seqnum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_seqnum], seqnum_ );
}

void
security_definition::set_seqnum( uint32_t val )
{
  seqnum_ = val;
  presence_map_[ix_seqnum] = true;
}

std::pair<bool, const std::string&>
security_definition::symbol() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_symbol], symbol_ );
}

void
security_definition::set_symbol( const std::string& val )
{
  symbol_ = val;
  presence_map_[ix_symbol] = true;
}

std::pair<bool, uint64_t>
security_definition::security_id() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_id], security_id_ );
}

void
security_definition::set_security_id( uint64_t val )
{
  security_id_ = val;
  presence_map_[ix_security_id] = true;
}

std::pair<bool, const std::string&>
security_definition::security_id_source() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_security_id_source], security_id_source_ );
}

void
security_definition::set_security_id_source( const std::string& val )
{
  security_id_source_ = val;
  presence_map_[ix_security_id_source] = true;
}

std::pair<bool, const std::string&>
security_definition::security_exchange() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_security_exchange], security_exchange_ );
}

void
security_definition::set_security_exchange( const std::string& val )
{
  security_exchange_ = val;
  presence_map_[ix_security_exchange] = true;
}

std::pair<bool, int32_t>
security_definition::implied_market_indicator() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_implied_market_indicator], implied_market_indicator_ );
}

void
security_definition::set_implied_market_indicator( int32_t val )
{
  implied_market_indicator_ = val;
  presence_map_[ix_implied_market_indicator] = true;
}

std::pair<bool, const std::string&>
security_definition::security_update_action() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_security_update_action], security_update_action_ );
}

void
security_definition::set_security_update_action( const std::string& val )
{
  security_update_action_ = val;
  presence_map_[ix_security_update_action] = true;
}

std::pair<bool, uint32_t>
security_definition::round_lot() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_round_lot], round_lot_ );
}

void
security_definition::set_round_lot( uint32_t val )
{
  round_lot_ = val;
  presence_map_[ix_round_lot] = true;
}

std::pair<bool, uint64_t>
security_definition::min_trade_vol() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_min_trade_vol], min_trade_vol_ );
}

void
security_definition::set_min_trade_vol( uint64_t val )
{
  min_trade_vol_ = val;
  presence_map_[ix_min_trade_vol] = true;
}

std::pair<bool, decimal>
security_definition::min_price_increment() const
{
  return std::pair<bool, decimal>( presence_map_[ix_min_price_increment], min_price_increment_ );
}

void
security_definition::set_min_price_increment( decimal val )
{
  min_price_increment_ = val;
  presence_map_[ix_min_price_increment] = true;
}

std::pair<bool, uint32_t>
security_definition::tick_size_denominator() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_tick_size_denominator], tick_size_denominator_ );
}

void
security_definition::set_tick_size_denominator( uint32_t val )
{
  tick_size_denominator_ = val;
  presence_map_[ix_tick_size_denominator] = true;
}

std::pair<bool, decimal>
security_definition::price_divisor() const
{
  return std::pair<bool, decimal>( presence_map_[ix_price_divisor], price_divisor_ );
}

void
security_definition::set_price_divisor( decimal val )
{
  price_divisor_ = val;
  presence_map_[ix_price_divisor] = true;
}

std::pair<bool, uint32_t>
security_definition::min_order_qty() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_min_order_qty], min_order_qty_ );
}

void
security_definition::set_min_order_qty( uint32_t val )
{
  min_order_qty_ = val;
  presence_map_[ix_min_order_qty] = true;
}

std::pair<bool, uint64_t>
security_definition::max_order_qty() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_max_order_qty], max_order_qty_ );
}

void
security_definition::set_max_order_qty( uint64_t val )
{
  max_order_qty_ = val;
  presence_map_[ix_max_order_qty] = true;
}

std::pair<bool, const std::string&>
security_definition::instrument_id() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_instrument_id], instrument_id_ );
}

void
security_definition::set_instrument_id( const std::string& val )
{
  instrument_id_ = val;
  presence_map_[ix_instrument_id] = true;
}

std::pair<bool, int32_t>
security_definition::multi_leg_model() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_multi_leg_model], multi_leg_model_ );
}

void
security_definition::set_multi_leg_model( int32_t val )
{
  multi_leg_model_ = val;
  presence_map_[ix_multi_leg_model] = true;
}

std::pair<bool, int32_t>
security_definition::multi_leg_price_method() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_multi_leg_price_method], multi_leg_price_method_ );
}

void
security_definition::set_multi_leg_price_method( int32_t val )
{
  multi_leg_price_method_ = val;
  presence_map_[ix_multi_leg_price_method] = true;
}

std::pair<bool, const std::string&>
security_definition::currency() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_currency], currency_ );
}

void
security_definition::set_currency( const std::string& val )
{
  currency_ = val;
  presence_map_[ix_currency] = true;
}

std::pair<bool, const std::string&>
security_definition::settl_currency() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_settl_currency], settl_currency_ );
}

void
security_definition::set_settl_currency( const std::string& val )
{
  settl_currency_ = val;
  presence_map_[ix_settl_currency] = true;
}

std::pair<bool, int32_t>
security_definition::product() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_product], product_ );
}

void
security_definition::set_product( int32_t val )
{
  product_ = val;
  presence_map_[ix_product] = true;
}

std::pair<bool, const std::string&>
security_definition::security_type() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_security_type], security_type_ );
}

void
security_definition::set_security_type( const std::string& val )
{
  security_type_ = val;
  presence_map_[ix_security_type] = true;
}

std::pair<bool, const std::string&>
security_definition::security_sub_type() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_security_sub_type], security_sub_type_ );
}

void
security_definition::set_security_sub_type( const std::string& val )
{
  security_sub_type_ = val;
  presence_map_[ix_security_sub_type] = true;
}

std::pair<bool, const std::string&>
security_definition::security_strategy_type() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_security_strategy_type], security_strategy_type_ );
}

void
security_definition::set_security_strategy_type( const std::string& val )
{
  security_strategy_type_ = val;
  presence_map_[ix_security_strategy_type] = true;
}

std::pair<bool, const std::string&>
security_definition::asset() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_asset], asset_ );
}

void
security_definition::set_asset( const std::string& val )
{
  asset_ = val;
  presence_map_[ix_asset] = true;
}

std::pair<bool, const std::string&>
security_definition::security_desc() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_security_desc], security_desc_ );
}

void
security_definition::set_security_desc( const std::string& val )
{
  security_desc_ = val;
  presence_map_[ix_security_desc] = true;
}

std::pair<bool, uint64_t>
security_definition::no_share_issued() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_no_share_issued], no_share_issued_ );
}

void
security_definition::set_no_share_issued( uint64_t val )
{
  no_share_issued_ = val;
  presence_map_[ix_no_share_issued] = true;
}

std::pair<bool, uint32_t>
security_definition::maturity_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_maturity_date], maturity_date_ );
}

void
security_definition::set_maturity_date( uint32_t val )
{
  maturity_date_ = val;
  presence_map_[ix_maturity_date] = true;
}

std::pair<bool, uint32_t>
security_definition::maturity_month_year() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_maturity_month_year], maturity_month_year_ );
}

void
security_definition::set_maturity_month_year( uint32_t val )
{
  maturity_month_year_ = val;
  presence_map_[ix_maturity_month_year] = true;
}

std::pair<bool, decimal>
security_definition::strike_price() const
{
  return std::pair<bool, decimal>( presence_map_[ix_strike_price], strike_price_ );
}

void
security_definition::set_strike_price( decimal val )
{
  strike_price_ = val;
  presence_map_[ix_strike_price] = true;
}

std::pair<bool, const std::string&>
security_definition::strike_currency() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_strike_currency], strike_currency_ );
}

void
security_definition::set_strike_currency( const std::string& val )
{
  strike_currency_ = val;
  presence_map_[ix_strike_currency] = true;
}

std::pair<bool, int32_t>
security_definition::exercise_style() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_exercise_style], exercise_style_ );
}

void
security_definition::set_exercise_style( int32_t val )
{
  exercise_style_ = val;
  presence_map_[ix_exercise_style] = true;
}

std::pair<bool, int32_t>
security_definition::put_or_call() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_put_or_call], put_or_call_ );
}

void
security_definition::set_put_or_call( int32_t val )
{
  put_or_call_ = val;
  presence_map_[ix_put_or_call] = true;
}

std::pair<bool, decimal>
security_definition::contract_multiplier() const
{
  return std::pair<bool, decimal>( presence_map_[ix_contract_multiplier], contract_multiplier_ );
}

void
security_definition::set_contract_multiplier( decimal val )
{
  contract_multiplier_ = val;
  presence_map_[ix_contract_multiplier] = true;
}

std::pair<bool, uint32_t>
security_definition::contract_settl_month() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_contract_settl_month], contract_settl_month_ );
}

void
security_definition::set_contract_settl_month( uint32_t val )
{
  contract_settl_month_ = val;
  presence_map_[ix_contract_settl_month] = true;
}

std::pair<bool, const std::string&>
security_definition::cfi_code() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_cfi_code], cfi_code_ );
}

void
security_definition::set_cfi_code( const std::string& val )
{
  cfi_code_ = val;
  presence_map_[ix_cfi_code] = true;
}

std::pair<bool, const std::string&>
security_definition::country_of_issue() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_country_of_issue], country_of_issue_ );
}

void
security_definition::set_country_of_issue( const std::string& val )
{
  country_of_issue_ = val;
  presence_map_[ix_country_of_issue] = true;
}

std::pair<bool, uint32_t>
security_definition::issue_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_issue_date], issue_date_ );
}

void
security_definition::set_issue_date( uint32_t val )
{
  issue_date_ = val;
  presence_map_[ix_issue_date] = true;
}

std::pair<bool, uint32_t>
security_definition::dated_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_dated_date], dated_date_ );
}

void
security_definition::set_dated_date( uint32_t val )
{
  dated_date_ = val;
  presence_map_[ix_dated_date] = true;
}

std::pair<bool, uint32_t>
security_definition::start_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_start_date], start_date_ );
}

void
security_definition::set_start_date( uint32_t val )
{
  start_date_ = val;
  presence_map_[ix_start_date] = true;
}

std::pair<bool, uint32_t>
security_definition::end_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_end_date], end_date_ );
}

void
security_definition::set_end_date( uint32_t val )
{
  end_date_ = val;
  presence_map_[ix_end_date] = true;
}

std::pair<bool, const std::string&>
security_definition::settl_type() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_settl_type], settl_type_ );
}

void
security_definition::set_settl_type( const std::string& val )
{
  settl_type_ = val;
  presence_map_[ix_settl_type] = true;
}

std::pair<bool, uint32_t>
security_definition::settl_date() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_settl_date], settl_date_ );
}

void
security_definition::set_settl_date( uint32_t val )
{
  settl_date_ = val;
  presence_map_[ix_settl_date] = true;
}

std::pair<bool, uint64_t>
security_definition::security_validity_timestamp() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_security_validity_timestamp], security_validity_timestamp_ );
}

void
security_definition::set_security_validity_timestamp( uint64_t val )
{
  security_validity_timestamp_ = val;
  presence_map_[ix_security_validity_timestamp] = true;
}

std::pair<bool, const std::string&>
security_definition::market_segment_id() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_market_segment_id], market_segment_id_ );
}

void
security_definition::set_market_segment_id( const std::string& val )
{
  market_segment_id_ = val;
  presence_map_[ix_market_segment_id] = true;
}

std::pair<bool, const std::string&>
security_definition::governance_indicator() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_governance_indicator], governance_indicator_ );
}

void
security_definition::set_governance_indicator( const std::string& val )
{
  governance_indicator_ = val;
  presence_map_[ix_governance_indicator] = true;
}

std::pair<bool, int32_t>
security_definition::corporate_action_event_id() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_corporate_action_event_id], corporate_action_event_id_ );
}

void
security_definition::set_corporate_action_event_id( int32_t val )
{
  corporate_action_event_id_ = val;
  presence_map_[ix_corporate_action_event_id] = true;
}

std::pair<bool, int32_t>
security_definition::security_match_type() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_security_match_type], security_match_type_ );
}

void
security_definition::set_security_match_type( int32_t val )
{
  security_match_type_ = val;
  presence_map_[ix_security_match_type] = true;
}

std::pair<bool, const std::string&>
security_definition::security_group() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_security_group], security_group_ );
}

void
security_definition::set_security_group( const std::string& val )
{
  security_group_ = val;
  presence_map_[ix_security_group] = true;
}

const std::bitset<security_definition::ix_field_count>&
security_definition::presence_map() const
{
  return presence_map_;
}

void security_definition::set_presence_map( uint64_t val )
{
  presence_map_ = std::bitset<ix_field_count>( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

