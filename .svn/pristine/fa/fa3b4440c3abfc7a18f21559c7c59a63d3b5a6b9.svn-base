#ifndef APOENA_MSI_MARKETDATA_MESSAGES_SECURITY_DEFINITION_HPP
#define APOENA_MSI_MARKETDATA_MESSAGES_SECURITY_DEFINITION_HPP

#include <bitset>
#include <utility>
#include <vector>
#include <map>
#include <msi/decimal/decimal.hpp>
#include <msi/marketdata/messages/marketdata_messages_export.hpp>
#include <msi/marketdata/messages/field_values.hpp>


namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

class MARKETDATA_MESSAGES_Export security_definition
{
public:
  class MARKETDATA_MESSAGES_Export appl_id_entry
  {
  public:
    class MARKETDATA_MESSAGES_Export feed_type_entry
    {
    public:
      enum field_index
      {
        ix_feed_type = 0,
        ix_market_depth,
        ix_field_count
      };

      void reset();

      std::pair<bool, const std::string&> feed_type() const;
      void set_feed_type( const std::string& val );

      std::pair<bool, uint32_t> market_depth() const;
      void set_market_depth( uint32_t val );

      const std::bitset<ix_field_count>& presence_map() const;
      void set_presence_map( uint32_t val );

    private:

      std::bitset<ix_field_count> presence_map_;

      std::string feed_type_;
      uint32_t market_depth_;

    };

    enum field_index
    {
      ix_feed_type = 0,
      ix_appl_id,
      ix_field_count
    };

    void reset();

    const std::vector<feed_type_entry>& feed_types() const;
    void add_feed_type( const feed_type_entry& val );

    std::pair<bool, const std::string&> appl_id() const;
    void set_appl_id( const std::string& val );

    const std::bitset<ix_field_count>& presence_map() const;
    void set_presence_map( uint32_t val );

  private:

    std::bitset<ix_field_count> presence_map_;

    std::vector<feed_type_entry> feed_types_;
    std::string appl_id_;

  };

  class MARKETDATA_MESSAGES_Export security_alt_id_entry
  {
  public:
    enum field_index
    {
      ix_security_id = 0,
      ix_security_id_source,
      ix_field_count
    };

    void reset();

    std::pair<bool, uint64_t> security_id() const;
    void set_security_id( uint64_t val );

    std::pair<bool, const std::string&> security_id_source() const;
    void set_security_id_source( const std::string& val );

    const std::bitset<ix_field_count>& presence_map() const;
    void set_presence_map( uint32_t val );

  private:

    std::bitset<ix_field_count> presence_map_;

    uint64_t security_id_;
    std::string security_id_source_;

  };

  class MARKETDATA_MESSAGES_Export underlying_entry
  {
  public:
    enum field_index
    {
      ix_symbol = 0,
      ix_security_id,
      ix_security_id_source,
      ix_security_exchange,
      ix_index_pct,
      ix_index_theoretical_qty,
      ix_field_count
    };

    void reset();

    std::pair<bool, const std::string&> symbol() const;
    void set_symbol( const std::string& val );

    std::pair<bool, uint64_t> security_id() const;
    void set_security_id( uint64_t val );

    std::pair<bool, const std::string&> security_id_source() const;
    void set_security_id_source( const std::string& val );

    std::pair<bool, const std::string&> security_exchange() const;
    void set_security_exchange( const std::string& val );

    std::pair<bool, decimal> index_pct() const;
    void set_index_pct( decimal val );

    std::pair<bool, decimal> index_theoretical_qty() const;
    void set_index_theoretical_qty( decimal val );

    const std::bitset<ix_field_count>& presence_map() const;
    void set_presence_map( uint32_t val );

  private:

    std::bitset<ix_field_count> presence_map_;

    std::string symbol_;
    uint64_t security_id_;
    std::string security_id_source_;
    std::string security_exchange_;
    decimal index_pct_;
    decimal index_theoretical_qty_;

  };

  class MARKETDATA_MESSAGES_Export instr_attrib_entry
  {
  public:
    enum field_index
    {
      ix_inst_attrib_type = 0,
      ix_inst_attrib_value,
      ix_field_count
    };

    void reset();

    std::pair<bool, uint32_t> inst_attrib_type() const;
    void set_inst_attrib_type( uint32_t val );

    std::pair<bool, const std::string&> inst_attrib_value() const;
    void set_inst_attrib_value( const std::string& val );

    const std::bitset<ix_field_count>& presence_map() const;
    void set_presence_map( uint32_t val );

  private:

    std::bitset<ix_field_count> presence_map_;

    uint32_t inst_attrib_type_;
    std::string inst_attrib_value_;

  };

  class MARKETDATA_MESSAGES_Export tick_rule_entry
  {
  public:
    enum field_index
    {
      ix_start_tick_price_range = 0,
      ix_end_tick_price_range,
      ix_tick_increment,
      ix_tick_rule_type,
      ix_field_count
    };

    void reset();

    std::pair<bool, decimal> start_tick_price_range() const;
    void set_start_tick_price_range( decimal val );

    std::pair<bool, decimal> end_tick_price_range() const;
    void set_end_tick_price_range( decimal val );

    std::pair<bool, decimal> tick_increment() const;
    void set_tick_increment( decimal val );

    std::pair<bool, int32_t> tick_rule_type() const;
    void set_tick_rule_type( int32_t val );

    const std::bitset<ix_field_count>& presence_map() const;
    void set_presence_map( uint32_t val );

  private:

    std::bitset<ix_field_count> presence_map_;

    decimal start_tick_price_range_;
    decimal end_tick_price_range_;
    decimal tick_increment_;
    int32_t tick_rule_type_;

  };

  class MARKETDATA_MESSAGES_Export leg_entry
  {
  public:
    enum field_index
    {
      ix_leg_symbol = 0,
      ix_leg_security_id,
      ix_leg_security_id_source,
      ix_leg_ratio_qty,
      ix_leg_security_type,
      ix_leg_side,
      ix_leg_security_exchange,
      ix_field_count
    };

    void reset();

    std::pair<bool, const std::string&> leg_symbol() const;
    void set_leg_symbol( const std::string& val );

    std::pair<bool, uint64_t> leg_security_id() const;
    void set_leg_security_id( uint64_t val );

    std::pair<bool, const std::string&> leg_security_id_source() const;
    void set_leg_security_id_source( const std::string& val );

    std::pair<bool, int32_t> leg_ratio_qty() const;
    void set_leg_ratio_qty( int32_t val );

    std::pair<bool, const std::string&> leg_security_type() const;
    void set_leg_security_type( const std::string& val );

    std::pair<bool, int32_t> leg_side() const;
    void set_leg_side( int32_t val );

    std::pair<bool, const std::string&> leg_security_exchange() const;
    void set_leg_security_exchange( const std::string& val );

    const std::bitset<ix_field_count>& presence_map() const;
    void set_presence_map( uint32_t val );

  private:

    std::bitset<ix_field_count> presence_map_;

    std::string leg_symbol_;
    uint64_t leg_security_id_;
    std::string leg_security_id_source_;
    int32_t leg_ratio_qty_;
    std::string leg_security_type_;
    int32_t leg_side_;
    std::string leg_security_exchange_;

  };

  class MARKETDATA_MESSAGES_Export lot_entry
  {
  public:
    enum field_index
    {
      ix_lot_type = 0,
      ix_min_lot_size,
      ix_field_count
    };

    void reset();

    std::pair<bool, int32_t> lot_type() const;
    void set_lot_type( int32_t val );

    std::pair<bool, uint32_t> min_lot_size() const;
    void set_min_lot_size( uint32_t val );

    const std::bitset<ix_field_count>& presence_map() const;
    void set_presence_map( uint32_t val );

  private:

    std::bitset<ix_field_count> presence_map_;

    int32_t lot_type_;
    uint32_t min_lot_size_;

  };

  enum field_index
  {
    ix_appl_id = 0,
    ix_security_alt_id,
    ix_underlying,
    ix_instr_attrib,
    ix_tick_rule,
    ix_leg,
    ix_lot,
    ix_seqnum,
    ix_symbol,
    ix_security_id,
    ix_security_id_source,
    ix_security_exchange,
    ix_implied_market_indicator,
    ix_security_update_action,
    ix_round_lot,
    ix_min_trade_vol,
    ix_min_price_increment,
    ix_tick_size_denominator,
    ix_price_divisor,
    ix_min_order_qty,
    ix_max_order_qty,
    ix_instrument_id,
    ix_multi_leg_model,
    ix_multi_leg_price_method,
    ix_currency,
    ix_settl_currency,
    ix_product,
    ix_security_type,
    ix_security_sub_type,
    ix_security_strategy_type,
    ix_asset,
    ix_security_desc,
    ix_no_share_issued,
    ix_maturity_date,
    ix_maturity_month_year,
    ix_strike_price,
    ix_strike_currency,
    ix_exercise_style,
    ix_put_or_call,
    ix_contract_multiplier,
    ix_contract_settl_month,
    ix_cfi_code,
    ix_country_of_issue,
    ix_issue_date,
    ix_dated_date,
    ix_start_date,
    ix_end_date,
    ix_settl_type,
    ix_settl_date,
    ix_security_validity_timestamp,
    ix_market_segment_id,
    ix_governance_indicator,
    ix_corporate_action_event_id,
    ix_security_match_type,
    ix_security_group,
    ix_field_count
  };

  void reset();

  const std::vector<appl_id_entry>& appl_ids() const;
  void add_appl_id( const appl_id_entry& val );

  const std::vector<security_alt_id_entry>& security_alt_ids() const;
  void add_security_alt_id( const security_alt_id_entry& val );

  const std::vector<underlying_entry>& underlyings() const;
  void add_underlying( const underlying_entry& val );

  const std::vector<instr_attrib_entry>& instr_attribs() const;
  void add_instr_attrib( const instr_attrib_entry& val );

  const std::vector<tick_rule_entry>& tick_rules() const;
  void add_tick_rule( const tick_rule_entry& val );

  const std::vector<leg_entry>& legs() const;
  void add_leg( const leg_entry& val );

  const std::vector<lot_entry>& lots() const;
  void add_lot( const lot_entry& val );

  std::pair<bool, uint32_t> seqnum() const;
  void set_seqnum( uint32_t val );

  std::pair<bool, const std::string&> symbol() const;
  void set_symbol( const std::string& val );

  std::pair<bool, uint64_t> security_id() const;
  void set_security_id( uint64_t val );

  std::pair<bool, const std::string&> security_id_source() const;
  void set_security_id_source( const std::string& val );

  std::pair<bool, const std::string&> security_exchange() const;
  void set_security_exchange( const std::string& val );

  std::pair<bool, int32_t> implied_market_indicator() const;
  void set_implied_market_indicator( int32_t val );

  std::pair<bool, const std::string&> security_update_action() const;
  void set_security_update_action( const std::string& val );

  std::pair<bool, uint32_t> round_lot() const;
  void set_round_lot( uint32_t val );

  std::pair<bool, uint64_t> min_trade_vol() const;
  void set_min_trade_vol( uint64_t val );

  std::pair<bool, decimal> min_price_increment() const;
  void set_min_price_increment( decimal val );

  std::pair<bool, uint32_t> tick_size_denominator() const;
  void set_tick_size_denominator( uint32_t val );

  std::pair<bool, decimal> price_divisor() const;
  void set_price_divisor( decimal val );

  std::pair<bool, uint32_t> min_order_qty() const;
  void set_min_order_qty( uint32_t val );

  std::pair<bool, uint64_t> max_order_qty() const;
  void set_max_order_qty( uint64_t val );

  std::pair<bool, const std::string&> instrument_id() const;
  void set_instrument_id( const std::string& val );

  std::pair<bool, int32_t> multi_leg_model() const;
  void set_multi_leg_model( int32_t val );

  std::pair<bool, int32_t> multi_leg_price_method() const;
  void set_multi_leg_price_method( int32_t val );

  std::pair<bool, const std::string&> currency() const;
  void set_currency( const std::string& val );

  std::pair<bool, const std::string&> settl_currency() const;
  void set_settl_currency( const std::string& val );

  std::pair<bool, int32_t> product() const;
  void set_product( int32_t val );

  std::pair<bool, const std::string&> security_type() const;
  void set_security_type( const std::string& val );

  std::pair<bool, const std::string&> security_sub_type() const;
  void set_security_sub_type( const std::string& val );

  std::pair<bool, const std::string&> security_strategy_type() const;
  void set_security_strategy_type( const std::string& val );

  std::pair<bool, const std::string&> asset() const;
  void set_asset( const std::string& val );

  std::pair<bool, const std::string&> security_desc() const;
  void set_security_desc( const std::string& val );

  std::pair<bool, uint64_t> no_share_issued() const;
  void set_no_share_issued( uint64_t val );

  std::pair<bool, uint32_t> maturity_date() const;
  void set_maturity_date( uint32_t val );

  std::pair<bool, uint32_t> maturity_month_year() const;
  void set_maturity_month_year( uint32_t val );

  std::pair<bool, decimal> strike_price() const;
  void set_strike_price( decimal val );

  std::pair<bool, const std::string&> strike_currency() const;
  void set_strike_currency( const std::string& val );

  std::pair<bool, int32_t> exercise_style() const;
  void set_exercise_style( int32_t val );

  std::pair<bool, int32_t> put_or_call() const;
  void set_put_or_call( int32_t val );

  std::pair<bool, decimal> contract_multiplier() const;
  void set_contract_multiplier( decimal val );

  std::pair<bool, uint32_t> contract_settl_month() const;
  void set_contract_settl_month( uint32_t val );

  std::pair<bool, const std::string&> cfi_code() const;
  void set_cfi_code( const std::string& val );

  std::pair<bool, const std::string&> country_of_issue() const;
  void set_country_of_issue( const std::string& val );

  std::pair<bool, uint32_t> issue_date() const;
  void set_issue_date( uint32_t val );

  std::pair<bool, uint32_t> dated_date() const;
  void set_dated_date( uint32_t val );

  std::pair<bool, uint32_t> start_date() const;
  void set_start_date( uint32_t val );

  std::pair<bool, uint32_t> end_date() const;
  void set_end_date( uint32_t val );

  std::pair<bool, const std::string&> settl_type() const;
  void set_settl_type( const std::string& val );

  std::pair<bool, uint32_t> settl_date() const;
  void set_settl_date( uint32_t val );

  std::pair<bool, uint64_t> security_validity_timestamp() const;
  void set_security_validity_timestamp( uint64_t val );

  std::pair<bool, const std::string&> market_segment_id() const;
  void set_market_segment_id( const std::string& val );

  std::pair<bool, const std::string&> governance_indicator() const;
  void set_governance_indicator( const std::string& val );

  std::pair<bool, int32_t> corporate_action_event_id() const;
  void set_corporate_action_event_id( int32_t val );

  std::pair<bool, int32_t> security_match_type() const;
  void set_security_match_type( int32_t val );

  std::pair<bool, const std::string&> security_group() const;
  void set_security_group( const std::string& val );

  const std::bitset<ix_field_count>& presence_map() const;
  void set_presence_map( uint64_t val );

private:

  std::bitset<ix_field_count> presence_map_;

  std::vector<appl_id_entry> appl_ids_;
  std::vector<security_alt_id_entry> security_alt_ids_;
  std::vector<underlying_entry> underlyings_;
  std::vector<instr_attrib_entry> instr_attribs_;
  std::vector<tick_rule_entry> tick_rules_;
  std::vector<leg_entry> legs_;
  std::vector<lot_entry> lots_;
  uint32_t seqnum_;
  std::string symbol_;
  uint64_t security_id_;
  std::string security_id_source_;
  std::string security_exchange_;
  int32_t implied_market_indicator_;
  std::string security_update_action_;
  uint32_t round_lot_;
  uint64_t min_trade_vol_;
  decimal min_price_increment_;
  uint32_t tick_size_denominator_;
  decimal price_divisor_;
  uint32_t min_order_qty_;
  uint64_t max_order_qty_;
  std::string instrument_id_;
  int32_t multi_leg_model_;
  int32_t multi_leg_price_method_;
  std::string currency_;
  std::string settl_currency_;
  int32_t product_;
  std::string security_type_;
  std::string security_sub_type_;
  std::string security_strategy_type_;
  std::string asset_;
  std::string security_desc_;
  uint64_t no_share_issued_;
  uint32_t maturity_date_;
  uint32_t maturity_month_year_;
  decimal strike_price_;
  std::string strike_currency_;
  int32_t exercise_style_;
  int32_t put_or_call_;
  decimal contract_multiplier_;
  uint32_t contract_settl_month_;
  std::string cfi_code_;
  std::string country_of_issue_;
  uint32_t issue_date_;
  uint32_t dated_date_;
  uint32_t start_date_;
  uint32_t end_date_;
  std::string settl_type_;
  uint32_t settl_date_;
  uint64_t security_validity_timestamp_;
  std::string market_segment_id_;
  std::string governance_indicator_;
  int32_t corporate_action_event_id_;
  int32_t security_match_type_;
  std::string security_group_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_MESSAGES_SECURITY_DEFINITION_HPP */

