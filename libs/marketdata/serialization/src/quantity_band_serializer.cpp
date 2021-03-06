#include <msi/msi_pch.hpp>
#include <msi/byte_conversion.hpp>
#include <msi/marketdata/serialization/sequence_serializer.hpp>
#include <msi/marketdata/serialization/string_serializer.hpp>
#include <msi/marketdata/serialization/reference_field_serializer.hpp>
#include <msi/marketdata/serialization/quantity_band_serializer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

quantity_band_serializer::quantity_band_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
quantity_band_serializer::serialize(
  const messages::quantity_band& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  byte_conversion::uint32_to_be( data_.data() + offset_seqnum, msg.seqnum().second );
  byte_conversion::uint64_to_be( data_.data() + offset_security_id, msg.security_id().second );
  byte_conversion::uint64_to_be( data_.data() + offset_low_limit_price_mantissa, msg.low_limit_price().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_low_limit_price_exponent, msg.low_limit_price().second.exponent() );
  byte_conversion::uint64_to_be( data_.data() + offset_high_limit_price_mantissa, msg.high_limit_price().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_high_limit_price_exponent, msg.high_limit_price().second.exponent() );
  byte_conversion::uint64_to_be( data_.data() + offset_trading_reference_price_mantissa, msg.trading_reference_price().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_trading_reference_price_exponent, msg.trading_reference_price().second.exponent() );
  byte_conversion::uint32_to_be( data_.data() + offset_price_band_midpoint_price_type, msg.price_band_midpoint_price_type().second );
  byte_conversion::uint64_to_be( data_.data() + offset_avg_daily_traded_qty, msg.avg_daily_traded_qty().second );
  byte_conversion::uint64_to_be( data_.data() + offset_max_trade_vol, msg.max_trade_vol().second );
  byte_conversion::uint32_to_be( data_.data() + offset_entry_date, msg.entry_date().second );
  byte_conversion::uint32_to_be( data_.data() + offset_entry_time, msg.entry_time().second );

  return std::make_pair( data_.data(), offset );
}

std::size_t
quantity_band_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
quantity_band_serializer::deserialize( const unsigned char* data,
                                       messages::quantity_band& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );
  dst.set_seqnum( byte_conversion::be_to_uint32( data + offset_seqnum ) );
  dst.set_security_id( byte_conversion::be_to_uint64( data + offset_security_id ) );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_low_limit_price_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_low_limit_price_exponent ) );
  dst.set_low_limit_price( d );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_high_limit_price_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_high_limit_price_exponent ) );
  dst.set_high_limit_price( d );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_trading_reference_price_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_trading_reference_price_exponent ) );
  dst.set_trading_reference_price( d );
  dst.set_price_band_midpoint_price_type( byte_conversion::be_to_uint32( data + offset_price_band_midpoint_price_type ) );
  dst.set_avg_daily_traded_qty( byte_conversion::be_to_uint64( data + offset_avg_daily_traded_qty ) );
  dst.set_max_trade_vol( byte_conversion::be_to_uint64( data + offset_max_trade_vol ) );
  dst.set_entry_date( byte_conversion::be_to_uint32( data + offset_entry_date ) );
  dst.set_entry_time( byte_conversion::be_to_uint32( data + offset_entry_time ) );

  return offset;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

