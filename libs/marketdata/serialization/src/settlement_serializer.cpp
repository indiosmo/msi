#include <msi/msi_pch.hpp>
#include <msi/byte_conversion.hpp>
#include <msi/marketdata/serialization/sequence_serializer.hpp>
#include <msi/marketdata/serialization/string_serializer.hpp>
#include <msi/marketdata/serialization/reference_field_serializer.hpp>
#include <msi/marketdata/serialization/settlement_serializer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

settlement_serializer::settlement_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
settlement_serializer::serialize(
  const messages::settlement& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  byte_conversion::uint32_to_be( data_.data() + offset_seqnum, msg.seqnum().second );
  byte_conversion::uint64_to_be( data_.data() + offset_security_id, msg.security_id().second );
  byte_conversion::uint64_to_be( data_.data() + offset_entry_price_mantissa, msg.entry_price().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_entry_price_exponent, msg.entry_price().second.exponent() );
  offset += serialize_string_field( msg.price_type(), data_, offset_price_type, offset );
  byte_conversion::uint32_to_be( data_.data() + offset_entry_date, msg.entry_date().second );
  byte_conversion::uint32_to_be( data_.data() + offset_entry_time, msg.entry_time().second );
  offset += serialize_string_field( msg.settl_flag(), data_, offset_settl_flag, offset );
  offset += serialize_string_field( msg.settl_price_type(), data_, offset_settl_price_type, offset );

  return std::make_pair( data_.data(), offset );
}

std::size_t
settlement_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
settlement_serializer::deserialize( const unsigned char* data,
                                    messages::settlement& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );
  dst.set_seqnum( byte_conversion::be_to_uint32( data + offset_seqnum ) );
  dst.set_security_id( byte_conversion::be_to_uint64( data + offset_security_id ) );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_entry_price_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_entry_price_exponent ) );
  dst.set_entry_price( d );

  if ( dst.presence_map()[messages::settlement::ix_price_type] )
  {
    dst.set_price_type( deserialize_string_field( data, offset_price_type, offset ) );
    offset += dst.price_type().second.size();
  }

  dst.set_entry_date( byte_conversion::be_to_uint32( data + offset_entry_date ) );
  dst.set_entry_time( byte_conversion::be_to_uint32( data + offset_entry_time ) );

  if ( dst.presence_map()[messages::settlement::ix_settl_flag] )
  {
    dst.set_settl_flag( deserialize_string_field( data, offset_settl_flag, offset ) );
    offset += dst.settl_flag().second.size();
  }


  if ( dst.presence_map()[messages::settlement::ix_settl_price_type] )
  {
    dst.set_settl_price_type( deserialize_string_field( data, offset_settl_price_type, offset ) );
    offset += dst.settl_price_type().second.size();
  }


  return offset;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

