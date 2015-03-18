#include <msi/msi_pch.hpp>
#include <msi/byte_conversion.hpp>
#include <msi/marketdata/serialization/sequence_serializer.hpp>
#include <msi/marketdata/serialization/string_serializer.hpp>
#include <msi/marketdata/serialization/reference_field_serializer.hpp>
#include <msi/marketdata/serialization/security_status_serializer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

security_status_serializer::security_status_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
security_status_serializer::serialize(
  const messages::security_status& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  byte_conversion::uint32_to_be( data_.data() + offset_seqnum, msg.seqnum().second );
  byte_conversion::uint64_to_be( data_.data() + offset_security_id, msg.security_id().second );
  offset += serialize_string_field( msg.security_group(), data_, offset_security_group, offset );
  offset += serialize_string_field( msg.group_phase(), data_, offset_group_phase, offset );
  byte_conversion::uint32_to_be( data_.data() + offset_instrument_state, msg.instrument_state().second );
  byte_conversion::uint64_to_be( data_.data() + offset_open_time, msg.open_time().second );
  byte_conversion::uint32_to_be( data_.data() + offset_trading_event, msg.trading_event().second );

  return std::make_pair( data_.data(), offset );
}

std::size_t
security_status_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
security_status_serializer::deserialize( const unsigned char* data,
    messages::security_status& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );
  dst.set_seqnum( byte_conversion::be_to_uint32( data + offset_seqnum ) );
  dst.set_security_id( byte_conversion::be_to_uint64( data + offset_security_id ) );

  if ( dst.presence_map()[messages::security_status::ix_security_group] )
  {
    dst.set_security_group( deserialize_string_field( data, offset_security_group, offset ) );
    offset += dst.security_group().second.size();
  }


  if ( dst.presence_map()[messages::security_status::ix_group_phase] )
  {
    dst.set_group_phase( deserialize_string_field( data, offset_group_phase, offset ) );
    offset += dst.group_phase().second.size();
  }

  dst.set_instrument_state( byte_conversion::be_to_uint32( data + offset_instrument_state ) );
  dst.set_open_time( byte_conversion::be_to_uint64( data + offset_open_time ) );
  dst.set_trading_event( byte_conversion::be_to_uint32( data + offset_trading_event ) );

  return offset;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

