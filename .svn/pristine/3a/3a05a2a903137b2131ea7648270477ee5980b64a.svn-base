#include <msi/msi_pch.hpp>
#include <msi/byte_conversion.hpp>
#include <msi/marketdata/serialization/sequence_serializer.hpp>
#include <msi/marketdata/serialization/string_serializer.hpp>
#include <msi/marketdata/serialization/reference_field_serializer.hpp>
#include <msi/marketdata/serialization/close_serializer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

close_serializer::close_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
close_serializer::serialize(
  const messages::close& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  byte_conversion::uint32_to_be( data_.data() + offset_seqnum, msg.seqnum().second );
  byte_conversion::uint64_to_be( data_.data() + offset_security_id, msg.security_id().second );
  byte_conversion::uint64_to_be( data_.data() + offset_entry_price_mantissa, msg.entry_price().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_entry_price_exponent, msg.entry_price().second.exponent() );
  byte_conversion::uint32_to_be( data_.data() + offset_last_trade_date, msg.last_trade_date().second );
  byte_conversion::uint32_to_be( data_.data() + offset_price_adjust_method, msg.price_adjust_method().second );
  byte_conversion::uint32_to_be( data_.data() + offset_entry_date, msg.entry_date().second );
  byte_conversion::uint32_to_be( data_.data() + offset_entry_time, msg.entry_time().second );
  offset += serialize_string_field( msg.settl_flag(), data_, offset_settl_flag, offset );

  return std::make_pair( data_.data(), offset );
}

std::size_t
close_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
close_serializer::deserialize( const unsigned char* data,
                               messages::close& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );
  dst.set_seqnum( byte_conversion::be_to_uint32( data + offset_seqnum ) );
  dst.set_security_id( byte_conversion::be_to_uint64( data + offset_security_id ) );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_entry_price_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_entry_price_exponent ) );
  dst.set_entry_price( d );
  dst.set_last_trade_date( byte_conversion::be_to_uint32( data + offset_last_trade_date ) );
  dst.set_price_adjust_method( byte_conversion::be_to_uint32( data + offset_price_adjust_method ) );
  dst.set_entry_date( byte_conversion::be_to_uint32( data + offset_entry_date ) );
  dst.set_entry_time( byte_conversion::be_to_uint32( data + offset_entry_time ) );

  if ( dst.presence_map()[messages::close::ix_settl_flag] )
  {
    dst.set_settl_flag( deserialize_string_field( data, offset_settl_flag, offset ) );
    offset += dst.settl_flag().second.size();
  }


  return offset;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

