#ifndef APOENA_MSI_MARKETDATA_SERIALIZATION_QUANTITY_BAND_SERIALIZER_HPP
#define APOENA_MSI_MARKETDATA_SERIALIZATION_QUANTITY_BAND_SERIALIZER_HPP

#include <msi/marketdata/messages/quantity_band.hpp>
#include <msi/marketdata/serialization/marketdata_serialization_export.hpp>


namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

class MARKETDATA_SERIALIZATION_Export quantity_band_serializer
{
public:
  enum offset
  {
    offset_pmap = 0,
    offset_seqnum = offset_pmap + sizeof( uint32_t ),
    offset_security_id = offset_seqnum + sizeof( uint32_t ),
    offset_low_limit_price_mantissa = offset_security_id + sizeof( uint64_t ),
    offset_low_limit_price_exponent = offset_low_limit_price_mantissa + sizeof ( decimal::mantissa_t ),
    offset_high_limit_price_mantissa = offset_low_limit_price_exponent + sizeof( decimal::exponent_t ),
    offset_high_limit_price_exponent = offset_high_limit_price_mantissa + sizeof ( decimal::mantissa_t ),
    offset_trading_reference_price_mantissa = offset_high_limit_price_exponent + sizeof( decimal::exponent_t ),
    offset_trading_reference_price_exponent = offset_trading_reference_price_mantissa + sizeof ( decimal::mantissa_t ),
    offset_price_band_midpoint_price_type = offset_trading_reference_price_exponent + sizeof( decimal::exponent_t ),
    offset_avg_daily_traded_qty = offset_price_band_midpoint_price_type + sizeof( uint32_t ),
    offset_max_trade_vol = offset_avg_daily_traded_qty + sizeof( uint64_t ),
    offset_entry_date = offset_max_trade_vol + sizeof( uint64_t ),
    offset_entry_time = offset_entry_date + sizeof( uint32_t ),
    offset_variable_fields = offset_entry_time + sizeof( uint32_t )
  };

  quantity_band_serializer();
  std::pair<const unsigned char*, std::size_t> serialize( const messages::quantity_band& msg );
  std::size_t buffer_size() const;
  std::size_t deserialize( const unsigned char* data, messages::quantity_band& dst );

private:

  std::vector<unsigned char> data_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_SERIALIZATION_QUANTITY_BAND_SERIALIZER_HPP */

