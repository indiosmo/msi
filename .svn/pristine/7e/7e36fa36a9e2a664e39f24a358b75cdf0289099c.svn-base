#ifndef APOENA_MSI_MARKETDATA_MESSAGES_FIELD_VALUES_HPP
#define APOENA_MSI_MARKETDATA_MESSAGES_FIELD_VALUES_HPP

#include <cstdint>
#include <map>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace messages
{

const uint32_t update_action_new = 0;
const uint32_t update_action_change = 1;
const uint32_t update_action_delete = 2;
const uint32_t update_action_delete_thru = 3;
const uint32_t update_action_delete_from = 4;
const uint32_t update_action_overlay = 5;

enum trade_condition_value_index
{
  ix_trade_condition_opening_price = 0,
  ix_trade_condition_crossed,
  ix_trade_condition_last_trade_at_price,
  ix_trade_condition_imbalance_more_buyers,
  ix_trade_condition_imbalance_more_sellers,
  ix_trade_condition_exchange_last,
  ix_trade_condition_multi_asset_trade,
  ix_trade_condition_leg_trade,
  ix_trade_condition_marketplace_entered_trade,
  trade_condition_field_count
};

const std::map<std::string, trade_condition_value_index> trade_condition_value_index_map =
{
  { "R", ix_trade_condition_opening_price },
  { "X", ix_trade_condition_crossed },
  { "L", ix_trade_condition_last_trade_at_price },
  { "P", ix_trade_condition_imbalance_more_buyers },
  { "Q", ix_trade_condition_imbalance_more_sellers },
  { "U", ix_trade_condition_exchange_last },
  { "3", ix_trade_condition_multi_asset_trade },
  { "2", ix_trade_condition_leg_trade },
  { "1", ix_trade_condition_marketplace_entered_trade }
};

const char* const feed_type_standard = "STD";
const char* const feed_type_implied = "IMP";

const uint32_t market_depth_full = 0;
const uint32_t market_depth_top = 0;

const char* const security_alt_id_source_isin = "4";
const char* const security_alt_id_source_clearing = "H";

const char* const underlying_security_id_source_isin = "4";
const char* const underlying_security_id_source_exchange = "8";

const char* const security_id_source_exchange = "8";

const char* const security_exchange_bvmf = "BVMF";

const int32_t implied_market_indicator_not_implied = 0;

const char* const security_update_action_add = "A";
const char* const security_update_action_delete = "D";
const char* const security_update_action_modify = "M";

const int32_t multi_leg_model_predefined = 0;
const int32_t multi_leg_model_user_defined = 1;

const int32_t multi_leg_price_method_individual = 3;

const int32_t product_commodity = 2;
const int32_t product_corporate = 3;
const int32_t product_currency = 4;
const int32_t product_equity = 5;
const int32_t product_government = 6;
const int32_t product_index = 7;
const int32_t product_economic_indicator = 15;
const int32_t product_multileg = 16;

const char* const security_type_future = "FUT";
const char* const security_type_spot = "SPOT";
const char* const security_type_spot_option = "SOPT";
const char* const security_type_future_option = "FOPT";
const char* const security_type_derivative_forward = "DTERM";
const char* const security_type_equity_rights = "CASH";
const char* const security_type_option = "OPT";
const char* const security_type_equity_forward = "FORWARD";
const char* const security_type_etf = "ETF";
const char* const security_type_index_non_tradable = "INDEX";
const char* const security_type_option_exercise = "OPTEXER";
const char* const security_type_multileg = "MLEG";
const char* const security_type_common_stock = "CS";
const char* const security_type_preferred_stock = "PS";
const char* const security_type_security_loan = "SECLOAN";
const char* const security_type_index_option = "INDEXPOT";

const char* const security_sub_type_fx_spot = "4";
const char* const security_sub_type_gold = "10";
const char* const security_sub_type_index = "20";
const char* const security_sub_type_interest_rate = "30";
const char* const security_sub_type_fx_rate = "40";
const char* const security_sub_type_foreign_debt = "50";
const char* const security_sub_type_agricultural = "60";
const char* const security_sub_type_energy = "70";
const char* const security_sub_type_economic_indicator = "80";
const char* const security_sub_type_strategy = "90";
const char* const security_sub_type_future_style_option = "100";
const char* const security_sub_type_volatilty = "110";
const char* const security_sub_type_swap = "120";
const char* const security_sub_type_mini_contract = "130";
const char* const security_sub_type_financial_rollover = "140";
const char* const security_sub_type_agricultural_rollover = "141";
const char* const security_sub_type_ordinary_rights = "1001";
const char* const security_sub_type_preferred_rights = "1002";
const char* const security_sub_type_common_shares = "1003";
const char* const security_sub_type_preferred_shares = "1004";
const char* const security_sub_type_class_a_shares = "1005";
const char* const security_sub_type_class_b_shares = "1006";
const char* const security_sub_type_class_c_shares = "1007";
const char* const security_sub_type_class_d_shares = "1008";
const char* const security_sub_type_ordinary_receipts = "1009";
const char* const security_sub_type_preferred_receipts = "1010";
const char* const security_sub_type_common_forward = "1100";
const char* const security_sub_type_flexible_forward = "1101";
const char* const security_sub_type_dollar_forward = "1102";
const char* const security_sub_type_index_points_forward = "1103";
const char* const security_sub_type_non_tradable_etf_nidex = "1104";
const char* const security_sub_type_predefined_covered_spread = "1105";
const char* const security_sub_type_traceable_etf = "1106";
const char* const security_sub_type_non_tradable_index = "1107";
const char* const security_sub_type_user_defined_spread = "1108";
const char* const security_sub_type_exchange_defined_spread = "1109";
const char* const security_sub_type_security_loan = "1110";
const char* const security_sub_type_tradable_index = "1111";
const char* const security_sub_type_others = "1999";
const char* const security_sub_type_outright_purchase = "1300";
const char* const security_sub_type_specific_collateral_repo = "1301";

const int32_t exercise_style_european = 0;
const int32_t exercise_style_american = 1;

const int32_t put_or_call_put = 0;
const int32_t put_or_call_call = 1;

const char* const governance_indicator_level_1 = "N1";
const char* const governance_indicator_level_2 = "N2";
const char* const governance_indicator_level_3 = "N3";
const char* const governance_indicator_new_market = "NM";
const char* const governance_indicator_mais_market = "MA";
const char* const governance_indicator_soma_market = "MB";

const int32_t security_match_type_issuing_or_buy_back_auction = 8;

const uint32_t price_adjust_method_no_adjustment = 0;
const uint32_t price_adjust_method_theoretical_ex = 1;
const uint32_t price_adjust_method_theoretical_ex_greater_than_with = 2;
const uint32_t price_adjust_method_theoretical_ex_different_stocks = 3;
const uint32_t price_adjust_method_market_arbitrated = 4;

const char* const settl_flag_daily = "0";
const char* const settl_flag_session = "1";
const char* const settl_flag_preliminary = "3";
const char* const settl_flag_previous_business_day = "4";
const char* const settl_flag_theoretical_price = "5";

const uint32_t tick_direction_plus = 0;
const uint32_t tick_direction_zero_plus = 1;
const uint32_t tick_direction_minus = 2;
const uint32_t tick_direction_zero_minus = 3;

const char* const price_band_type_hard_limit = "1";
const char* const price_band_type_auction_limit = "2";
const char* const price_band_type_rejection_band = "3";
const char* const price_band_type_static_limit = "4";

const uint32_t price_limit_type_price_unit = 0;
const uint32_t price_limit_type_ticks = 1;
const uint32_t price_limit_type_percentage = 2;

const uint32_t price_band_midpoint_price_type_last_traded = 0;
const uint32_t price_band_midpoint_price_type_complementary = 1;
const uint32_t price_band_midpoint_price_type_theoretical = 2;

const char* const group_phase_pause = "02";
const char* const group_phase_close = "04";
const char* const group_phase_open = "17";
const char* const group_phase_pre_close = "18";
const char* const group_phase_pre_open = "21";
const char* const group_phase_closing_call = "101";

const uint32_t instrument_state_pause = 02;
const uint32_t instrument_state_close = 04;
const uint32_t instrument_state_open = 17;
const uint32_t instrument_state_forbidden = 18;
const uint32_t instrument_state_unknown = 20;
const uint32_t instrument_state_reserved = 21;
const uint32_t instrument_state_closing_call = 101;

const uint32_t trading_event_change_of_trading_session = 4;
const uint32_t trading_event_separate_from_group = 101;
const uint32_t trading_event_following_group = 102;

const char* const settl_price_type_final = "1";
const char* const settl_price_type_theoretical = "2";
const char* const settl_price_type_updated = "3";

const char* const price_type_percentage = "1";
const char* const price_type_per_unit = "2";
const char* const price_type_fixed = "3";

const uint32_t inst_attrib_type_security_details = 24;
const uint32_t inst_attrib_type_gtd_gtc_eligibility = 34;

const char* const inst_attrib_value_electronic_match_eligible = "1";
const char* const inst_attrib_value_block_trade_eligible = "3";
const char* const inst_attrib_value_negotiated_quote_eligible = "17";
const char* const inst_attrib_value_gtd_gtc_eligible = "1";

const int32_t lot_type_odd_lot = 1;
const int32_t lot_type_round_lot = 2;
const int32_t lot_type_block_lot = 3;

const char* const leg_security_type_corporate_fixed_income = "CORP";
const char* const leg_security_type_future = "FUT";
const char* const leg_security_type_spot = "SPOT";
const char* const leg_security_type_spot_option = "SOPT";
const char* const leg_security_type_future_option = "FOPT";
const char* const leg_security_type_derivative_forward = "DTERM";
const char* const leg_security_type_equity_rights = "CASH";
const char* const leg_security_type_option = "OPT";
const char* const leg_security_type_equity_forward = "FORWARD";
const char* const leg_security_type_etf = "ETF";
const char* const leg_security_type_index_non_tradable = "INDEX";
const char* const leg_security_type_option_exercise = "OPTEXER";
const char* const leg_security_type_multileg = "MLEG";
const char* const leg_security_type_common_stock = "CS";
const char* const leg_security_type_preferred_stock = "PS";
const char* const leg_security_type_security_loan = "SECLOAN";
const char* const leg_security_type_index_option = "INDEXPOT";

const int32_t leg_side_buy = 1;
const int32_t leg_side_sell = 2;

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_MESSAGES_FIELD_VALUES_HPP */

