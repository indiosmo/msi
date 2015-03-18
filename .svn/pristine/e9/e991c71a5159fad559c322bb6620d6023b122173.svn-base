#include <msi/msi_pch.hpp>
#include <msi/byte_conversion.hpp>
#include <msi/marketdata/serialization/sequence_serializer.hpp>
#include <msi/marketdata/serialization/string_serializer.hpp>
#include <msi/marketdata/serialization/reference_field_serializer.hpp>
#include <msi/marketdata/serialization/security_definition_serializer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

security_definition_serializer::appl_id_entry_serializer::feed_type_entry_serializer::feed_type_entry_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
security_definition_serializer::appl_id_entry_serializer::feed_type_entry_serializer::serialize(
  const messages::security_definition::appl_id_entry::feed_type_entry& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  offset += serialize_string_field( msg.feed_type(), data_, offset_feed_type, offset );
  byte_conversion::uint32_to_be( data_.data() + offset_market_depth, msg.market_depth().second );

  return std::make_pair( data_.data(), offset );
}

std::size_t
security_definition_serializer::appl_id_entry_serializer::feed_type_entry_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
security_definition_serializer::appl_id_entry_serializer::feed_type_entry_serializer::deserialize( const unsigned char* data,
    messages::security_definition::appl_id_entry::feed_type_entry& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );

  if ( dst.presence_map()[messages::security_definition::appl_id_entry::feed_type_entry::ix_feed_type] )
  {
    dst.set_feed_type( deserialize_string_field( data, offset_feed_type, offset ) );
    offset += dst.feed_type().second.size();
  }

  dst.set_market_depth( byte_conversion::be_to_uint32( data + offset_market_depth ) );

  return offset;
}



security_definition_serializer::appl_id_entry_serializer::appl_id_entry_serializer()
{
  data_.resize( 500 +
                offset_variable_fields +
                feed_type_entry_serializer_.buffer_size() );
}

std::pair<const unsigned char*, std::size_t>
security_definition_serializer::appl_id_entry_serializer::serialize(
  const messages::security_definition::appl_id_entry& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  offset += serialize_string_field( msg.appl_id(), data_, offset_appl_id, offset );
  offset += serialize_sequence( msg.feed_types(), feed_type_entry_serializer_, data_, offset_feed_type, offset );

  return std::make_pair( data_.data(), offset );
}

std::size_t
security_definition_serializer::appl_id_entry_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
security_definition_serializer::appl_id_entry_serializer::deserialize( const unsigned char* data,
    messages::security_definition::appl_id_entry& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );

  if ( dst.presence_map()[messages::security_definition::appl_id_entry::ix_appl_id] )
  {
    dst.set_appl_id( deserialize_string_field( data, offset_appl_id, offset ) );
    offset += dst.appl_id().second.size();
  }


  if ( dst.presence_map()[messages::security_definition::appl_id_entry::ix_feed_type] )
  {
    std::size_t entries = byte_conversion::be_to_uint32( data + offset_feed_type );
    messages::security_definition::appl_id_entry::feed_type_entry entry;

    for ( std::size_t i = 0; i < entries; i++ )
    {
      offset += feed_type_entry_serializer_.deserialize( data + offset, entry );
      dst.add_feed_type( entry );
      entry.reset();
    }
  }

  return offset;
}



security_definition_serializer::security_alt_id_entry_serializer::security_alt_id_entry_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
security_definition_serializer::security_alt_id_entry_serializer::serialize(
  const messages::security_definition::security_alt_id_entry& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  byte_conversion::uint64_to_be( data_.data() + offset_security_id, msg.security_id().second );
  offset += serialize_string_field( msg.security_id_source(), data_, offset_security_id_source, offset );

  return std::make_pair( data_.data(), offset );
}

std::size_t
security_definition_serializer::security_alt_id_entry_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
security_definition_serializer::security_alt_id_entry_serializer::deserialize( const unsigned char* data,
    messages::security_definition::security_alt_id_entry& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );
  dst.set_security_id( byte_conversion::be_to_uint64( data + offset_security_id ) );

  if ( dst.presence_map()[messages::security_definition::security_alt_id_entry::ix_security_id_source] )
  {
    dst.set_security_id_source( deserialize_string_field( data, offset_security_id_source, offset ) );
    offset += dst.security_id_source().second.size();
  }


  return offset;
}



security_definition_serializer::underlying_entry_serializer::underlying_entry_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
security_definition_serializer::underlying_entry_serializer::serialize(
  const messages::security_definition::underlying_entry& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  offset += serialize_string_field( msg.symbol(), data_, offset_symbol, offset );
  byte_conversion::uint64_to_be( data_.data() + offset_security_id, msg.security_id().second );
  offset += serialize_string_field( msg.security_id_source(), data_, offset_security_id_source, offset );
  offset += serialize_string_field( msg.security_exchange(), data_, offset_security_exchange, offset );
  byte_conversion::uint64_to_be( data_.data() + offset_index_pct_mantissa, msg.index_pct().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_index_pct_exponent, msg.index_pct().second.exponent() );
  byte_conversion::uint64_to_be( data_.data() + offset_index_theoretical_qty_mantissa, msg.index_theoretical_qty().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_index_theoretical_qty_exponent, msg.index_theoretical_qty().second.exponent() );

  return std::make_pair( data_.data(), offset );
}

std::size_t
security_definition_serializer::underlying_entry_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
security_definition_serializer::underlying_entry_serializer::deserialize( const unsigned char* data,
    messages::security_definition::underlying_entry& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );

  if ( dst.presence_map()[messages::security_definition::underlying_entry::ix_symbol] )
  {
    dst.set_symbol( deserialize_string_field( data, offset_symbol, offset ) );
    offset += dst.symbol().second.size();
  }

  dst.set_security_id( byte_conversion::be_to_uint64( data + offset_security_id ) );

  if ( dst.presence_map()[messages::security_definition::underlying_entry::ix_security_id_source] )
  {
    dst.set_security_id_source( deserialize_string_field( data, offset_security_id_source, offset ) );
    offset += dst.security_id_source().second.size();
  }


  if ( dst.presence_map()[messages::security_definition::underlying_entry::ix_security_exchange] )
  {
    dst.set_security_exchange( deserialize_string_field( data, offset_security_exchange, offset ) );
    offset += dst.security_exchange().second.size();
  }

  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_index_pct_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_index_pct_exponent ) );
  dst.set_index_pct( d );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_index_theoretical_qty_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_index_theoretical_qty_exponent ) );
  dst.set_index_theoretical_qty( d );

  return offset;
}



security_definition_serializer::instr_attrib_entry_serializer::instr_attrib_entry_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
security_definition_serializer::instr_attrib_entry_serializer::serialize(
  const messages::security_definition::instr_attrib_entry& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  byte_conversion::uint32_to_be( data_.data() + offset_inst_attrib_type, msg.inst_attrib_type().second );
  offset += serialize_string_field( msg.inst_attrib_value(), data_, offset_inst_attrib_value, offset );

  return std::make_pair( data_.data(), offset );
}

std::size_t
security_definition_serializer::instr_attrib_entry_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
security_definition_serializer::instr_attrib_entry_serializer::deserialize( const unsigned char* data,
    messages::security_definition::instr_attrib_entry& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );
  dst.set_inst_attrib_type( byte_conversion::be_to_uint32( data + offset_inst_attrib_type ) );

  if ( dst.presence_map()[messages::security_definition::instr_attrib_entry::ix_inst_attrib_value] )
  {
    dst.set_inst_attrib_value( deserialize_string_field( data, offset_inst_attrib_value, offset ) );
    offset += dst.inst_attrib_value().second.size();
  }


  return offset;
}



security_definition_serializer::tick_rule_entry_serializer::tick_rule_entry_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
security_definition_serializer::tick_rule_entry_serializer::serialize(
  const messages::security_definition::tick_rule_entry& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  byte_conversion::uint64_to_be( data_.data() + offset_start_tick_price_range_mantissa, msg.start_tick_price_range().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_start_tick_price_range_exponent, msg.start_tick_price_range().second.exponent() );
  byte_conversion::uint64_to_be( data_.data() + offset_end_tick_price_range_mantissa, msg.end_tick_price_range().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_end_tick_price_range_exponent, msg.end_tick_price_range().second.exponent() );
  byte_conversion::uint64_to_be( data_.data() + offset_tick_increment_mantissa, msg.tick_increment().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_tick_increment_exponent, msg.tick_increment().second.exponent() );
  byte_conversion::int32_to_be( data_.data() + offset_tick_rule_type, msg.tick_rule_type().second );

  return std::make_pair( data_.data(), offset );
}

std::size_t
security_definition_serializer::tick_rule_entry_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
security_definition_serializer::tick_rule_entry_serializer::deserialize( const unsigned char* data,
    messages::security_definition::tick_rule_entry& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_start_tick_price_range_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_start_tick_price_range_exponent ) );
  dst.set_start_tick_price_range( d );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_end_tick_price_range_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_end_tick_price_range_exponent ) );
  dst.set_end_tick_price_range( d );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_tick_increment_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_tick_increment_exponent ) );
  dst.set_tick_increment( d );
  dst.set_tick_rule_type( byte_conversion::be_to_int32( data + offset_tick_rule_type ) );

  return offset;
}



security_definition_serializer::leg_entry_serializer::leg_entry_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
security_definition_serializer::leg_entry_serializer::serialize(
  const messages::security_definition::leg_entry& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  offset += serialize_string_field( msg.leg_symbol(), data_, offset_leg_symbol, offset );
  byte_conversion::uint64_to_be( data_.data() + offset_leg_security_id, msg.leg_security_id().second );
  offset += serialize_string_field( msg.leg_security_id_source(), data_, offset_leg_security_id_source, offset );
  byte_conversion::int32_to_be( data_.data() + offset_leg_ratio_qty, msg.leg_ratio_qty().second );
  offset += serialize_string_field( msg.leg_security_type(), data_, offset_leg_security_type, offset );
  byte_conversion::int32_to_be( data_.data() + offset_leg_side, msg.leg_side().second );
  offset += serialize_string_field( msg.leg_security_exchange(), data_, offset_leg_security_exchange, offset );

  return std::make_pair( data_.data(), offset );
}

std::size_t
security_definition_serializer::leg_entry_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
security_definition_serializer::leg_entry_serializer::deserialize( const unsigned char* data,
    messages::security_definition::leg_entry& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );

  if ( dst.presence_map()[messages::security_definition::leg_entry::ix_leg_symbol] )
  {
    dst.set_leg_symbol( deserialize_string_field( data, offset_leg_symbol, offset ) );
    offset += dst.leg_symbol().second.size();
  }

  dst.set_leg_security_id( byte_conversion::be_to_uint64( data + offset_leg_security_id ) );

  if ( dst.presence_map()[messages::security_definition::leg_entry::ix_leg_security_id_source] )
  {
    dst.set_leg_security_id_source( deserialize_string_field( data, offset_leg_security_id_source, offset ) );
    offset += dst.leg_security_id_source().second.size();
  }

  dst.set_leg_ratio_qty( byte_conversion::be_to_int32( data + offset_leg_ratio_qty ) );

  if ( dst.presence_map()[messages::security_definition::leg_entry::ix_leg_security_type] )
  {
    dst.set_leg_security_type( deserialize_string_field( data, offset_leg_security_type, offset ) );
    offset += dst.leg_security_type().second.size();
  }

  dst.set_leg_side( byte_conversion::be_to_int32( data + offset_leg_side ) );

  if ( dst.presence_map()[messages::security_definition::leg_entry::ix_leg_security_exchange] )
  {
    dst.set_leg_security_exchange( deserialize_string_field( data, offset_leg_security_exchange, offset ) );
    offset += dst.leg_security_exchange().second.size();
  }


  return offset;
}



security_definition_serializer::lot_entry_serializer::lot_entry_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
security_definition_serializer::lot_entry_serializer::serialize(
  const messages::security_definition::lot_entry& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  byte_conversion::int32_to_be( data_.data() + offset_lot_type, msg.lot_type().second );
  byte_conversion::uint32_to_be( data_.data() + offset_min_lot_size, msg.min_lot_size().second );

  return std::make_pair( data_.data(), offset );
}

std::size_t
security_definition_serializer::lot_entry_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
security_definition_serializer::lot_entry_serializer::deserialize( const unsigned char* data,
    messages::security_definition::lot_entry& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );
  dst.set_lot_type( byte_conversion::be_to_int32( data + offset_lot_type ) );
  dst.set_min_lot_size( byte_conversion::be_to_uint32( data + offset_min_lot_size ) );

  return offset;
}



security_definition_serializer::security_definition_serializer()
{
  data_.resize( 500 +
                offset_variable_fields +
                appl_id_entry_serializer_.buffer_size() +
                security_alt_id_entry_serializer_.buffer_size() +
                underlying_entry_serializer_.buffer_size() +
                instr_attrib_entry_serializer_.buffer_size() +
                tick_rule_entry_serializer_.buffer_size() +
                leg_entry_serializer_.buffer_size() +
                lot_entry_serializer_.buffer_size() );
}

std::pair<const unsigned char*, std::size_t>
security_definition_serializer::serialize(
  const messages::security_definition& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint64_to_be( data_.data(), msg.presence_map().to_ullong() );
  byte_conversion::uint32_to_be( data_.data() + offset_seqnum, msg.seqnum().second );
  offset += serialize_string_field( msg.symbol(), data_, offset_symbol, offset );
  byte_conversion::uint64_to_be( data_.data() + offset_security_id, msg.security_id().second );
  offset += serialize_string_field( msg.security_id_source(), data_, offset_security_id_source, offset );
  offset += serialize_string_field( msg.security_exchange(), data_, offset_security_exchange, offset );
  byte_conversion::int32_to_be( data_.data() + offset_implied_market_indicator, msg.implied_market_indicator().second );
  offset += serialize_string_field( msg.security_update_action(), data_, offset_security_update_action, offset );
  byte_conversion::uint32_to_be( data_.data() + offset_round_lot, msg.round_lot().second );
  byte_conversion::uint64_to_be( data_.data() + offset_min_trade_vol, msg.min_trade_vol().second );
  byte_conversion::uint64_to_be( data_.data() + offset_min_price_increment_mantissa, msg.min_price_increment().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_min_price_increment_exponent, msg.min_price_increment().second.exponent() );
  byte_conversion::uint32_to_be( data_.data() + offset_tick_size_denominator, msg.tick_size_denominator().second );
  byte_conversion::uint64_to_be( data_.data() + offset_price_divisor_mantissa, msg.price_divisor().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_price_divisor_exponent, msg.price_divisor().second.exponent() );
  byte_conversion::uint32_to_be( data_.data() + offset_min_order_qty, msg.min_order_qty().second );
  byte_conversion::uint64_to_be( data_.data() + offset_max_order_qty, msg.max_order_qty().second );
  offset += serialize_string_field( msg.instrument_id(), data_, offset_instrument_id, offset );
  byte_conversion::int32_to_be( data_.data() + offset_multi_leg_model, msg.multi_leg_model().second );
  byte_conversion::int32_to_be( data_.data() + offset_multi_leg_price_method, msg.multi_leg_price_method().second );
  offset += serialize_string_field( msg.currency(), data_, offset_currency, offset );
  offset += serialize_string_field( msg.settl_currency(), data_, offset_settl_currency, offset );
  byte_conversion::int32_to_be( data_.data() + offset_product, msg.product().second );
  offset += serialize_string_field( msg.security_type(), data_, offset_security_type, offset );
  offset += serialize_string_field( msg.security_sub_type(), data_, offset_security_sub_type, offset );
  offset += serialize_string_field( msg.security_strategy_type(), data_, offset_security_strategy_type, offset );
  offset += serialize_string_field( msg.asset(), data_, offset_asset, offset );
  offset += serialize_string_field( msg.security_desc(), data_, offset_security_desc, offset );
  byte_conversion::uint64_to_be( data_.data() + offset_no_share_issued, msg.no_share_issued().second );
  byte_conversion::uint32_to_be( data_.data() + offset_maturity_date, msg.maturity_date().second );
  byte_conversion::uint32_to_be( data_.data() + offset_maturity_month_year, msg.maturity_month_year().second );
  byte_conversion::uint64_to_be( data_.data() + offset_strike_price_mantissa, msg.strike_price().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_strike_price_exponent, msg.strike_price().second.exponent() );
  offset += serialize_string_field( msg.strike_currency(), data_, offset_strike_currency, offset );
  byte_conversion::int32_to_be( data_.data() + offset_exercise_style, msg.exercise_style().second );
  byte_conversion::int32_to_be( data_.data() + offset_put_or_call, msg.put_or_call().second );
  byte_conversion::uint64_to_be( data_.data() + offset_contract_multiplier_mantissa, msg.contract_multiplier().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_contract_multiplier_exponent, msg.contract_multiplier().second.exponent() );
  byte_conversion::uint32_to_be( data_.data() + offset_contract_settl_month, msg.contract_settl_month().second );
  offset += serialize_string_field( msg.cfi_code(), data_, offset_cfi_code, offset );
  offset += serialize_string_field( msg.country_of_issue(), data_, offset_country_of_issue, offset );
  byte_conversion::uint32_to_be( data_.data() + offset_issue_date, msg.issue_date().second );
  byte_conversion::uint32_to_be( data_.data() + offset_dated_date, msg.dated_date().second );
  byte_conversion::uint32_to_be( data_.data() + offset_start_date, msg.start_date().second );
  byte_conversion::uint32_to_be( data_.data() + offset_end_date, msg.end_date().second );
  offset += serialize_string_field( msg.settl_type(), data_, offset_settl_type, offset );
  byte_conversion::uint32_to_be( data_.data() + offset_settl_date, msg.settl_date().second );
  byte_conversion::uint64_to_be( data_.data() + offset_security_validity_timestamp, msg.security_validity_timestamp().second );
  offset += serialize_string_field( msg.market_segment_id(), data_, offset_market_segment_id, offset );
  offset += serialize_string_field( msg.governance_indicator(), data_, offset_governance_indicator, offset );
  byte_conversion::int32_to_be( data_.data() + offset_corporate_action_event_id, msg.corporate_action_event_id().second );
  byte_conversion::int32_to_be( data_.data() + offset_security_match_type, msg.security_match_type().second );
  offset += serialize_string_field( msg.security_group(), data_, offset_security_group, offset );
  offset += serialize_sequence( msg.appl_ids(), appl_id_entry_serializer_, data_, offset_appl_id, offset );
  offset += serialize_sequence( msg.security_alt_ids(), security_alt_id_entry_serializer_, data_, offset_security_alt_id, offset );
  offset += serialize_sequence( msg.underlyings(), underlying_entry_serializer_, data_, offset_underlying, offset );
  offset += serialize_sequence( msg.instr_attribs(), instr_attrib_entry_serializer_, data_, offset_instr_attrib, offset );
  offset += serialize_sequence( msg.tick_rules(), tick_rule_entry_serializer_, data_, offset_tick_rule, offset );
  offset += serialize_sequence( msg.legs(), leg_entry_serializer_, data_, offset_leg, offset );
  offset += serialize_sequence( msg.lots(), lot_entry_serializer_, data_, offset_lot, offset );

  return std::make_pair( data_.data(), offset );
}

std::size_t
security_definition_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
security_definition_serializer::deserialize( const unsigned char* data,
    messages::security_definition& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint64( data + offset_pmap ) );
  dst.set_seqnum( byte_conversion::be_to_uint32( data + offset_seqnum ) );

  if ( dst.presence_map()[messages::security_definition::ix_symbol] )
  {
    dst.set_symbol( deserialize_string_field( data, offset_symbol, offset ) );
    offset += dst.symbol().second.size();
  }

  dst.set_security_id( byte_conversion::be_to_uint64( data + offset_security_id ) );

  if ( dst.presence_map()[messages::security_definition::ix_security_id_source] )
  {
    dst.set_security_id_source( deserialize_string_field( data, offset_security_id_source, offset ) );
    offset += dst.security_id_source().second.size();
  }


  if ( dst.presence_map()[messages::security_definition::ix_security_exchange] )
  {
    dst.set_security_exchange( deserialize_string_field( data, offset_security_exchange, offset ) );
    offset += dst.security_exchange().second.size();
  }

  dst.set_implied_market_indicator( byte_conversion::be_to_int32( data + offset_implied_market_indicator ) );

  if ( dst.presence_map()[messages::security_definition::ix_security_update_action] )
  {
    dst.set_security_update_action( deserialize_string_field( data, offset_security_update_action, offset ) );
    offset += dst.security_update_action().second.size();
  }

  dst.set_round_lot( byte_conversion::be_to_uint32( data + offset_round_lot ) );
  dst.set_min_trade_vol( byte_conversion::be_to_uint64( data + offset_min_trade_vol ) );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_min_price_increment_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_min_price_increment_exponent ) );
  dst.set_min_price_increment( d );
  dst.set_tick_size_denominator( byte_conversion::be_to_uint32( data + offset_tick_size_denominator ) );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_price_divisor_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_price_divisor_exponent ) );
  dst.set_price_divisor( d );
  dst.set_min_order_qty( byte_conversion::be_to_uint32( data + offset_min_order_qty ) );
  dst.set_max_order_qty( byte_conversion::be_to_uint64( data + offset_max_order_qty ) );

  if ( dst.presence_map()[messages::security_definition::ix_instrument_id] )
  {
    dst.set_instrument_id( deserialize_string_field( data, offset_instrument_id, offset ) );
    offset += dst.instrument_id().second.size();
  }

  dst.set_multi_leg_model( byte_conversion::be_to_int32( data + offset_multi_leg_model ) );
  dst.set_multi_leg_price_method( byte_conversion::be_to_int32( data + offset_multi_leg_price_method ) );

  if ( dst.presence_map()[messages::security_definition::ix_currency] )
  {
    dst.set_currency( deserialize_string_field( data, offset_currency, offset ) );
    offset += dst.currency().second.size();
  }


  if ( dst.presence_map()[messages::security_definition::ix_settl_currency] )
  {
    dst.set_settl_currency( deserialize_string_field( data, offset_settl_currency, offset ) );
    offset += dst.settl_currency().second.size();
  }

  dst.set_product( byte_conversion::be_to_int32( data + offset_product ) );

  if ( dst.presence_map()[messages::security_definition::ix_security_type] )
  {
    dst.set_security_type( deserialize_string_field( data, offset_security_type, offset ) );
    offset += dst.security_type().second.size();
  }


  if ( dst.presence_map()[messages::security_definition::ix_security_sub_type] )
  {
    dst.set_security_sub_type( deserialize_string_field( data, offset_security_sub_type, offset ) );
    offset += dst.security_sub_type().second.size();
  }


  if ( dst.presence_map()[messages::security_definition::ix_security_strategy_type] )
  {
    dst.set_security_strategy_type( deserialize_string_field( data, offset_security_strategy_type, offset ) );
    offset += dst.security_strategy_type().second.size();
  }


  if ( dst.presence_map()[messages::security_definition::ix_asset] )
  {
    dst.set_asset( deserialize_string_field( data, offset_asset, offset ) );
    offset += dst.asset().second.size();
  }


  if ( dst.presence_map()[messages::security_definition::ix_security_desc] )
  {
    dst.set_security_desc( deserialize_string_field( data, offset_security_desc, offset ) );
    offset += dst.security_desc().second.size();
  }

  dst.set_no_share_issued( byte_conversion::be_to_uint64( data + offset_no_share_issued ) );
  dst.set_maturity_date( byte_conversion::be_to_uint32( data + offset_maturity_date ) );
  dst.set_maturity_month_year( byte_conversion::be_to_uint32( data + offset_maturity_month_year ) );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_strike_price_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_strike_price_exponent ) );
  dst.set_strike_price( d );

  if ( dst.presence_map()[messages::security_definition::ix_strike_currency] )
  {
    dst.set_strike_currency( deserialize_string_field( data, offset_strike_currency, offset ) );
    offset += dst.strike_currency().second.size();
  }

  dst.set_exercise_style( byte_conversion::be_to_int32( data + offset_exercise_style ) );
  dst.set_put_or_call( byte_conversion::be_to_int32( data + offset_put_or_call ) );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_contract_multiplier_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_contract_multiplier_exponent ) );
  dst.set_contract_multiplier( d );
  dst.set_contract_settl_month( byte_conversion::be_to_uint32( data + offset_contract_settl_month ) );

  if ( dst.presence_map()[messages::security_definition::ix_cfi_code] )
  {
    dst.set_cfi_code( deserialize_string_field( data, offset_cfi_code, offset ) );
    offset += dst.cfi_code().second.size();
  }


  if ( dst.presence_map()[messages::security_definition::ix_country_of_issue] )
  {
    dst.set_country_of_issue( deserialize_string_field( data, offset_country_of_issue, offset ) );
    offset += dst.country_of_issue().second.size();
  }

  dst.set_issue_date( byte_conversion::be_to_uint32( data + offset_issue_date ) );
  dst.set_dated_date( byte_conversion::be_to_uint32( data + offset_dated_date ) );
  dst.set_start_date( byte_conversion::be_to_uint32( data + offset_start_date ) );
  dst.set_end_date( byte_conversion::be_to_uint32( data + offset_end_date ) );

  if ( dst.presence_map()[messages::security_definition::ix_settl_type] )
  {
    dst.set_settl_type( deserialize_string_field( data, offset_settl_type, offset ) );
    offset += dst.settl_type().second.size();
  }

  dst.set_settl_date( byte_conversion::be_to_uint32( data + offset_settl_date ) );
  dst.set_security_validity_timestamp( byte_conversion::be_to_uint64( data + offset_security_validity_timestamp ) );

  if ( dst.presence_map()[messages::security_definition::ix_market_segment_id] )
  {
    dst.set_market_segment_id( deserialize_string_field( data, offset_market_segment_id, offset ) );
    offset += dst.market_segment_id().second.size();
  }


  if ( dst.presence_map()[messages::security_definition::ix_governance_indicator] )
  {
    dst.set_governance_indicator( deserialize_string_field( data, offset_governance_indicator, offset ) );
    offset += dst.governance_indicator().second.size();
  }

  dst.set_corporate_action_event_id( byte_conversion::be_to_int32( data + offset_corporate_action_event_id ) );
  dst.set_security_match_type( byte_conversion::be_to_int32( data + offset_security_match_type ) );

  if ( dst.presence_map()[messages::security_definition::ix_security_group] )
  {
    dst.set_security_group( deserialize_string_field( data, offset_security_group, offset ) );
    offset += dst.security_group().second.size();
  }


  if ( dst.presence_map()[messages::security_definition::ix_appl_id] )
  {
    std::size_t entries = byte_conversion::be_to_uint32( data + offset_appl_id );
    messages::security_definition::appl_id_entry entry;

    for ( std::size_t i = 0; i < entries; i++ )
    {
      offset += appl_id_entry_serializer_.deserialize( data + offset, entry );
      dst.add_appl_id( entry );
      entry.reset();
    }
  }

  if ( dst.presence_map()[messages::security_definition::ix_security_alt_id] )
  {
    std::size_t entries = byte_conversion::be_to_uint32( data + offset_security_alt_id );
    messages::security_definition::security_alt_id_entry entry;

    for ( std::size_t i = 0; i < entries; i++ )
    {
      offset += security_alt_id_entry_serializer_.deserialize( data + offset, entry );
      dst.add_security_alt_id( entry );
      entry.reset();
    }
  }

  if ( dst.presence_map()[messages::security_definition::ix_underlying] )
  {
    std::size_t entries = byte_conversion::be_to_uint32( data + offset_underlying );
    messages::security_definition::underlying_entry entry;

    for ( std::size_t i = 0; i < entries; i++ )
    {
      offset += underlying_entry_serializer_.deserialize( data + offset, entry );
      dst.add_underlying( entry );
      entry.reset();
    }
  }

  if ( dst.presence_map()[messages::security_definition::ix_instr_attrib] )
  {
    std::size_t entries = byte_conversion::be_to_uint32( data + offset_instr_attrib );
    messages::security_definition::instr_attrib_entry entry;

    for ( std::size_t i = 0; i < entries; i++ )
    {
      offset += instr_attrib_entry_serializer_.deserialize( data + offset, entry );
      dst.add_instr_attrib( entry );
      entry.reset();
    }
  }

  if ( dst.presence_map()[messages::security_definition::ix_tick_rule] )
  {
    std::size_t entries = byte_conversion::be_to_uint32( data + offset_tick_rule );
    messages::security_definition::tick_rule_entry entry;

    for ( std::size_t i = 0; i < entries; i++ )
    {
      offset += tick_rule_entry_serializer_.deserialize( data + offset, entry );
      dst.add_tick_rule( entry );
      entry.reset();
    }
  }

  if ( dst.presence_map()[messages::security_definition::ix_leg] )
  {
    std::size_t entries = byte_conversion::be_to_uint32( data + offset_leg );
    messages::security_definition::leg_entry entry;

    for ( std::size_t i = 0; i < entries; i++ )
    {
      offset += leg_entry_serializer_.deserialize( data + offset, entry );
      dst.add_leg( entry );
      entry.reset();
    }
  }

  if ( dst.presence_map()[messages::security_definition::ix_lot] )
  {
    std::size_t entries = byte_conversion::be_to_uint32( data + offset_lot );
    messages::security_definition::lot_entry entry;

    for ( std::size_t i = 0; i < entries; i++ )
    {
      offset += lot_entry_serializer_.deserialize( data + offset, entry );
      dst.add_lot( entry );
      entry.reset();
    }
  }

  return offset;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

