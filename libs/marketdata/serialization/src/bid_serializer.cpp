#include <msi/msi_pch.hpp>
#include <msi/byte_conversion.hpp>
#include <msi/marketdata/serialization/sequence_serializer.hpp>
#include <msi/marketdata/serialization/string_serializer.hpp>
#include <msi/marketdata/serialization/reference_field_serializer.hpp>
#include <msi/marketdata/serialization/bid_serializer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

bid_serializer::bid_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
bid_serializer::serialize(
  const messages::bid& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  byte_conversion::uint32_to_be( data_.data() + offset_seqnum, msg.seqnum().second );
  byte_conversion::uint32_to_be( data_.data() + offset_update_action, msg.update_action().second );
  byte_conversion::uint64_to_be( data_.data() + offset_security_id, msg.security_id().second );
  byte_conversion::uint64_to_be( data_.data() + offset_entry_price_mantissa, msg.entry_price().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_entry_price_exponent, msg.entry_price().second.exponent() );
  byte_conversion::int64_to_be( data_.data() + offset_entry_size, msg.entry_size().second );
  byte_conversion::uint32_to_be( data_.data() + offset_entry_date, msg.entry_date().second );
  byte_conversion::uint32_to_be( data_.data() + offset_entry_time, msg.entry_time().second );
  offset += serialize_string_field( msg.buyer(), data_, offset_buyer, offset );
  byte_conversion::uint32_to_be( data_.data() + offset_position, msg.position().second );
  offset += serialize_string_field( msg.order_id(), data_, offset_order_id, offset );

  return std::make_pair( data_.data(), offset );
}

std::size_t
bid_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
bid_serializer::deserialize( const unsigned char* data,
                             messages::bid& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );
  dst.set_seqnum( byte_conversion::be_to_uint32( data + offset_seqnum ) );
  dst.set_update_action( byte_conversion::be_to_uint32( data + offset_update_action ) );
  dst.set_security_id( byte_conversion::be_to_uint64( data + offset_security_id ) );
  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_entry_price_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_entry_price_exponent ) );
  dst.set_entry_price( d );
  dst.set_entry_size( byte_conversion::be_to_int64( data + offset_entry_size ) );
  dst.set_entry_date( byte_conversion::be_to_uint32( data + offset_entry_date ) );
  dst.set_entry_time( byte_conversion::be_to_uint32( data + offset_entry_time ) );

  if ( dst.presence_map()[messages::bid::ix_buyer] )
  {
    dst.set_buyer( deserialize_string_field( data, offset_buyer, offset ) );
    offset += dst.buyer().second.size();
  }

  dst.set_position( byte_conversion::be_to_uint32( data + offset_position ) );

  if ( dst.presence_map()[messages::bid::ix_order_id] )
  {
    dst.set_order_id( deserialize_string_field( data, offset_order_id, offset ) );
    offset += dst.order_id().second.size();
  }


  return offset;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

