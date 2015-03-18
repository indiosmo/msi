#include <msi/msi_pch.hpp>
#include <msi/byte_conversion.hpp>
#include <msi/marketdata/serialization/sequence_serializer.hpp>
#include <msi/marketdata/serialization/string_serializer.hpp>
#include <msi/marketdata/serialization/reference_field_serializer.hpp>
#include <msi/marketdata/serialization/trade_volume_serializer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

trade_volume_serializer::trade_volume_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
trade_volume_serializer::serialize(
  const messages::trade_volume& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  byte_conversion::uint32_to_be( data_.data() + offset_seqnum, msg.seqnum().second );
  byte_conversion::uint64_to_be( data_.data() + offset_security_id, msg.security_id().second );
  byte_conversion::uint64_to_be( data_.data() + offset_financial_volume_mantissa, msg.financial_volume().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_financial_volume_exponent, msg.financial_volume().second.exponent() );
  byte_conversion::uint32_to_be( data_.data() + offset_number_of_trades, msg.number_of_trades().second );
  byte_conversion::uint64_to_be( data_.data() + offset_quantity_volume, msg.quantity_volume().second );
  byte_conversion::uint32_to_be( data_.data() + offset_entry_date, msg.entry_date().second );
  byte_conversion::uint32_to_be( data_.data() + offset_entry_time, msg.entry_time().second );
  offset += serialize_string_field( msg.currency(), data_, offset_currency, offset );

  return std::make_pair( data_.data(), offset );
}

std::size_t
trade_volume_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
trade_volume_serializer::deserialize( const unsigned char* data,
                                      messages::trade_volume& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );
  dst.set_seqnum( byte_conversion::be_to_uint32( data + offset_seqnum ) );
  dst.set_security_id( byte_conversion::be_to_uint64( data + offset_security_id ) );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_financial_volume_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_financial_volume_exponent ) );
  dst.set_financial_volume( d );
  dst.set_number_of_trades( byte_conversion::be_to_uint32( data + offset_number_of_trades ) );
  dst.set_quantity_volume( byte_conversion::be_to_uint64( data + offset_quantity_volume ) );
  dst.set_entry_date( byte_conversion::be_to_uint32( data + offset_entry_date ) );
  dst.set_entry_time( byte_conversion::be_to_uint32( data + offset_entry_time ) );

  if ( dst.presence_map()[messages::trade_volume::ix_currency] )
  {
    dst.set_currency( deserialize_string_field( data, offset_currency, offset ) );
    offset += dst.currency().second.size();
  }


  return offset;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

