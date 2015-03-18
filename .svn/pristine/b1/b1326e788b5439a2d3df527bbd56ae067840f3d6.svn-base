#ifndef APOENA_MSI_MARKETDATA_SERIALIZATION_SECURITY_DEFINITION_SERIALIZER_HPP
#define APOENA_MSI_MARKETDATA_SERIALIZATION_SECURITY_DEFINITION_SERIALIZER_HPP

#include <msi/marketdata/messages/security_definition.hpp>
#include <msi/marketdata/serialization/marketdata_serialization_export.hpp>


namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

class MARKETDATA_SERIALIZATION_Export security_definition_serializer
{
  class MARKETDATA_SERIALIZATION_Export appl_id_entry_serializer
  {
    class MARKETDATA_SERIALIZATION_Export feed_type_entry_serializer
    {
    public:
      enum offset
      {
        offset_pmap = 0,
        offset_feed_type = offset_pmap + sizeof( uint32_t ),
        offset_market_depth = offset_feed_type + sizeof( uint32_t ),
        offset_variable_fields = offset_market_depth + sizeof( uint32_t )
      };

      feed_type_entry_serializer();
      std::pair<const unsigned char*, std::size_t> serialize( const messages::security_definition::appl_id_entry::feed_type_entry& msg );
      std::size_t buffer_size() const;
      std::size_t deserialize( const unsigned char* data, messages::security_definition::appl_id_entry::feed_type_entry& dst );

    private:

      std::vector<unsigned char> data_;

    };

  public:
    enum offset
    {
      offset_pmap = 0,
      offset_appl_id = offset_pmap + sizeof( uint32_t ),
      offset_feed_type = offset_appl_id + sizeof( uint32_t ),
      offset_variable_fields = offset_feed_type + sizeof( uint32_t )
    };

    appl_id_entry_serializer();
    std::pair<const unsigned char*, std::size_t> serialize( const messages::security_definition::appl_id_entry& msg );
    std::size_t buffer_size() const;
    std::size_t deserialize( const unsigned char* data, messages::security_definition::appl_id_entry& dst );

  private:
    feed_type_entry_serializer feed_type_entry_serializer_;

    std::vector<unsigned char> data_;

  };

  class MARKETDATA_SERIALIZATION_Export security_alt_id_entry_serializer
  {
  public:
    enum offset
    {
      offset_pmap = 0,
      offset_security_id = offset_pmap + sizeof( uint32_t ),
      offset_security_id_source = offset_security_id + sizeof( uint64_t ),
      offset_variable_fields = offset_security_id_source + sizeof( uint32_t )
    };

    security_alt_id_entry_serializer();
    std::pair<const unsigned char*, std::size_t> serialize( const messages::security_definition::security_alt_id_entry& msg );
    std::size_t buffer_size() const;
    std::size_t deserialize( const unsigned char* data, messages::security_definition::security_alt_id_entry& dst );

  private:

    std::vector<unsigned char> data_;

  };

  class MARKETDATA_SERIALIZATION_Export underlying_entry_serializer
  {
  public:
    enum offset
    {
      offset_pmap = 0,
      offset_symbol = offset_pmap + sizeof( uint32_t ),
      offset_security_id = offset_symbol + sizeof( uint32_t ),
      offset_security_id_source = offset_security_id + sizeof( uint64_t ),
      offset_security_exchange = offset_security_id_source + sizeof( uint32_t ),
      offset_index_pct_mantissa = offset_security_exchange + sizeof( uint32_t ),
      offset_index_pct_exponent = offset_index_pct_mantissa + sizeof ( decimal::mantissa_t ),
      offset_index_theoretical_qty_mantissa = offset_index_pct_exponent + sizeof( decimal::exponent_t ),
      offset_index_theoretical_qty_exponent = offset_index_theoretical_qty_mantissa + sizeof ( decimal::mantissa_t ),
      offset_variable_fields = offset_index_theoretical_qty_exponent + sizeof( decimal::exponent_t )
    };

    underlying_entry_serializer();
    std::pair<const unsigned char*, std::size_t> serialize( const messages::security_definition::underlying_entry& msg );
    std::size_t buffer_size() const;
    std::size_t deserialize( const unsigned char* data, messages::security_definition::underlying_entry& dst );

  private:

    std::vector<unsigned char> data_;

  };

  class MARKETDATA_SERIALIZATION_Export instr_attrib_entry_serializer
  {
  public:
    enum offset
    {
      offset_pmap = 0,
      offset_inst_attrib_type = offset_pmap + sizeof( uint32_t ),
      offset_inst_attrib_value = offset_inst_attrib_type + sizeof( uint32_t ),
      offset_variable_fields = offset_inst_attrib_value + sizeof( uint32_t )
    };

    instr_attrib_entry_serializer();
    std::pair<const unsigned char*, std::size_t> serialize( const messages::security_definition::instr_attrib_entry& msg );
    std::size_t buffer_size() const;
    std::size_t deserialize( const unsigned char* data, messages::security_definition::instr_attrib_entry& dst );

  private:

    std::vector<unsigned char> data_;

  };

  class MARKETDATA_SERIALIZATION_Export tick_rule_entry_serializer
  {
  public:
    enum offset
    {
      offset_pmap = 0,
      offset_start_tick_price_range_mantissa = offset_pmap + sizeof( uint32_t ),
      offset_start_tick_price_range_exponent = offset_start_tick_price_range_mantissa + sizeof ( decimal::mantissa_t ),
      offset_end_tick_price_range_mantissa = offset_start_tick_price_range_exponent + sizeof( decimal::exponent_t ),
      offset_end_tick_price_range_exponent = offset_end_tick_price_range_mantissa + sizeof ( decimal::mantissa_t ),
      offset_tick_increment_mantissa = offset_end_tick_price_range_exponent + sizeof( decimal::exponent_t ),
      offset_tick_increment_exponent = offset_tick_increment_mantissa + sizeof ( decimal::mantissa_t ),
      offset_tick_rule_type = offset_tick_increment_exponent + sizeof( decimal::exponent_t ),
      offset_variable_fields = offset_tick_rule_type + sizeof( int32_t )
    };

    tick_rule_entry_serializer();
    std::pair<const unsigned char*, std::size_t> serialize( const messages::security_definition::tick_rule_entry& msg );
    std::size_t buffer_size() const;
    std::size_t deserialize( const unsigned char* data, messages::security_definition::tick_rule_entry& dst );

  private:

    std::vector<unsigned char> data_;

  };

  class MARKETDATA_SERIALIZATION_Export leg_entry_serializer
  {
  public:
    enum offset
    {
      offset_pmap = 0,
      offset_leg_symbol = offset_pmap + sizeof( uint32_t ),
      offset_leg_security_id = offset_leg_symbol + sizeof( uint32_t ),
      offset_leg_security_id_source = offset_leg_security_id + sizeof( uint64_t ),
      offset_leg_ratio_qty = offset_leg_security_id_source + sizeof( uint32_t ),
      offset_leg_security_type = offset_leg_ratio_qty + sizeof( int32_t ),
      offset_leg_side = offset_leg_security_type + sizeof( uint32_t ),
      offset_leg_security_exchange = offset_leg_side + sizeof( int32_t ),
      offset_variable_fields = offset_leg_security_exchange + sizeof( uint32_t )
    };

    leg_entry_serializer();
    std::pair<const unsigned char*, std::size_t> serialize( const messages::security_definition::leg_entry& msg );
    std::size_t buffer_size() const;
    std::size_t deserialize( const unsigned char* data, messages::security_definition::leg_entry& dst );

  private:

    std::vector<unsigned char> data_;

  };

  class MARKETDATA_SERIALIZATION_Export lot_entry_serializer
  {
  public:
    enum offset
    {
      offset_pmap = 0,
      offset_lot_type = offset_pmap + sizeof( uint32_t ),
      offset_min_lot_size = offset_lot_type + sizeof( int32_t ),
      offset_variable_fields = offset_min_lot_size + sizeof( uint32_t )
    };

    lot_entry_serializer();
    std::pair<const unsigned char*, std::size_t> serialize( const messages::security_definition::lot_entry& msg );
    std::size_t buffer_size() const;
    std::size_t deserialize( const unsigned char* data, messages::security_definition::lot_entry& dst );

  private:

    std::vector<unsigned char> data_;

  };

public:
  enum offset
  {
    offset_pmap = 0,
    offset_seqnum = offset_pmap + sizeof( uint64_t ),
    offset_symbol = offset_seqnum + sizeof( uint32_t ),
    offset_security_id = offset_symbol + sizeof( uint32_t ),
    offset_security_id_source = offset_security_id + sizeof( uint64_t ),
    offset_security_exchange = offset_security_id_source + sizeof( uint32_t ),
    offset_implied_market_indicator = offset_security_exchange + sizeof( uint32_t ),
    offset_security_update_action = offset_implied_market_indicator + sizeof( int32_t ),
    offset_round_lot = offset_security_update_action + sizeof( uint32_t ),
    offset_min_trade_vol = offset_round_lot + sizeof( uint32_t ),
    offset_min_price_increment_mantissa = offset_min_trade_vol + sizeof( uint64_t ),
    offset_min_price_increment_exponent = offset_min_price_increment_mantissa + sizeof ( decimal::mantissa_t ),
    offset_tick_size_denominator = offset_min_price_increment_exponent + sizeof( decimal::exponent_t ),
    offset_price_divisor_mantissa = offset_tick_size_denominator + sizeof( uint32_t ),
    offset_price_divisor_exponent = offset_price_divisor_mantissa + sizeof ( decimal::mantissa_t ),
    offset_min_order_qty = offset_price_divisor_exponent + sizeof( decimal::exponent_t ),
    offset_max_order_qty = offset_min_order_qty + sizeof( uint32_t ),
    offset_instrument_id = offset_max_order_qty + sizeof( uint64_t ),
    offset_multi_leg_model = offset_instrument_id + sizeof( uint32_t ),
    offset_multi_leg_price_method = offset_multi_leg_model + sizeof( int32_t ),
    offset_currency = offset_multi_leg_price_method + sizeof( int32_t ),
    offset_settl_currency = offset_currency + sizeof( uint32_t ),
    offset_product = offset_settl_currency + sizeof( uint32_t ),
    offset_security_type = offset_product + sizeof( int32_t ),
    offset_security_sub_type = offset_security_type + sizeof( uint32_t ),
    offset_security_strategy_type = offset_security_sub_type + sizeof( uint32_t ),
    offset_asset = offset_security_strategy_type + sizeof( uint32_t ),
    offset_security_desc = offset_asset + sizeof( uint32_t ),
    offset_no_share_issued = offset_security_desc + sizeof( uint32_t ),
    offset_maturity_date = offset_no_share_issued + sizeof( uint64_t ),
    offset_maturity_month_year = offset_maturity_date + sizeof( uint32_t ),
    offset_strike_price_mantissa = offset_maturity_month_year + sizeof( uint32_t ),
    offset_strike_price_exponent = offset_strike_price_mantissa + sizeof ( decimal::mantissa_t ),
    offset_strike_currency = offset_strike_price_exponent + sizeof( decimal::exponent_t ),
    offset_exercise_style = offset_strike_currency + sizeof( uint32_t ),
    offset_put_or_call = offset_exercise_style + sizeof( int32_t ),
    offset_contract_multiplier_mantissa = offset_put_or_call + sizeof( int32_t ),
    offset_contract_multiplier_exponent = offset_contract_multiplier_mantissa + sizeof ( decimal::mantissa_t ),
    offset_contract_settl_month = offset_contract_multiplier_exponent + sizeof( decimal::exponent_t ),
    offset_cfi_code = offset_contract_settl_month + sizeof( uint32_t ),
    offset_country_of_issue = offset_cfi_code + sizeof( uint32_t ),
    offset_issue_date = offset_country_of_issue + sizeof( uint32_t ),
    offset_dated_date = offset_issue_date + sizeof( uint32_t ),
    offset_start_date = offset_dated_date + sizeof( uint32_t ),
    offset_end_date = offset_start_date + sizeof( uint32_t ),
    offset_settl_type = offset_end_date + sizeof( uint32_t ),
    offset_settl_date = offset_settl_type + sizeof( uint32_t ),
    offset_security_validity_timestamp = offset_settl_date + sizeof( uint32_t ),
    offset_market_segment_id = offset_security_validity_timestamp + sizeof( uint64_t ),
    offset_governance_indicator = offset_market_segment_id + sizeof( uint32_t ),
    offset_corporate_action_event_id = offset_governance_indicator + sizeof( uint32_t ),
    offset_security_match_type = offset_corporate_action_event_id + sizeof( int32_t ),
    offset_security_group = offset_security_match_type + sizeof( int32_t ),
    offset_appl_id = offset_security_group + sizeof( uint32_t ),
    offset_security_alt_id = offset_appl_id + sizeof( uint32_t ),
    offset_underlying = offset_security_alt_id + sizeof( uint32_t ),
    offset_instr_attrib = offset_underlying + sizeof( uint32_t ),
    offset_tick_rule = offset_instr_attrib + sizeof( uint32_t ),
    offset_leg = offset_tick_rule + sizeof( uint32_t ),
    offset_lot = offset_leg + sizeof( uint32_t ),
    offset_variable_fields = offset_lot + sizeof( uint32_t )
  };

  security_definition_serializer();
  std::pair<const unsigned char*, std::size_t> serialize( const messages::security_definition& msg );
  std::size_t buffer_size() const;
  std::size_t deserialize( const unsigned char* data, messages::security_definition& dst );

private:
  appl_id_entry_serializer appl_id_entry_serializer_;
  security_alt_id_entry_serializer security_alt_id_entry_serializer_;
  underlying_entry_serializer underlying_entry_serializer_;
  instr_attrib_entry_serializer instr_attrib_entry_serializer_;
  tick_rule_entry_serializer tick_rule_entry_serializer_;
  leg_entry_serializer leg_entry_serializer_;
  lot_entry_serializer lot_entry_serializer_;

  std::vector<unsigned char> data_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_SERIALIZATION_SECURITY_DEFINITION_SERIALIZER_HPP */

