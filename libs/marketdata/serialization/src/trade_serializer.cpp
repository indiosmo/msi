#include <msi/msi_pch.hpp>
#include <msi/byte_conversion.hpp>
#include <msi/marketdata/serialization/sequence_serializer.hpp>
#include <msi/marketdata/serialization/string_serializer.hpp>
#include <msi/marketdata/serialization/reference_field_serializer.hpp>
#include <msi/marketdata/serialization/trade_serializer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

trade_serializer::trade_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
trade_serializer::serialize(
  const messages::trade& msg )
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
  byte_conversion::uint32_to_be( data_.data() + offset_tick_direction, msg.tick_direction().second );
  offset += serialize_string_field( msg.buyer(), data_, offset_buyer, offset );
  offset += serialize_string_field( msg.seller(), data_, offset_seller, offset );
  byte_conversion::uint64_to_be( data_.data() + offset_variation_mantissa, msg.variation().second.mantissa() );
  byte_conversion::uint8_to_be( data_.data() + offset_variation_exponent, msg.variation().second.exponent() );
  byte_conversion::uint64_to_be( data_.data() + offset_quantity_volume, msg.quantity_volume().second );
  offset += serialize_string_field( msg.trade_id(), data_, offset_trade_id, offset );
  byte_conversion::uint32_to_be( data_.data() + offset_trade_condition, msg.trade_condition().second );

  return std::make_pair( data_.data(), offset );
}

std::size_t
trade_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
trade_serializer::deserialize( const unsigned char* data,
                               messages::trade& dst )
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
  dst.set_tick_direction( byte_conversion::be_to_uint32( data + offset_tick_direction ) );

  if ( dst.presence_map()[messages::trade::ix_buyer] )
  {
    dst.set_buyer( deserialize_string_field( data, offset_buyer, offset ) );
    offset += dst.buyer().second.size();
  }


  if ( dst.presence_map()[messages::trade::ix_seller] )
  {
    dst.set_seller( deserialize_string_field( data, offset_seller, offset ) );
    offset += dst.seller().second.size();
  }

  d.set_mantissa( byte_conversion::be_to_uint64( data + offset_variation_mantissa ) );
  d.set_exponent( byte_conversion::be_to_uint8( data + offset_variation_exponent ) );
  dst.set_variation( d );
  dst.set_quantity_volume( byte_conversion::be_to_uint64( data + offset_quantity_volume ) );

  if ( dst.presence_map()[messages::trade::ix_trade_id] )
  {
    dst.set_trade_id( deserialize_string_field( data, offset_trade_id, offset ) );
    offset += dst.trade_id().second.size();
  }

  dst.set_trade_condition( byte_conversion::be_to_uint32( data + offset_trade_condition ) );

  return offset;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

