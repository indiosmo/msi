#include <msi/msi_pch.hpp>
#include <msi/byte_conversion.hpp>
#include <msi/marketdata/serialization/sequence_serializer.hpp>
#include <msi/marketdata/serialization/string_serializer.hpp>
#include <msi/marketdata/serialization/reference_field_serializer.hpp>
#include <msi/marketdata/serialization/auction_imbalance_serializer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

auction_imbalance_serializer::auction_imbalance_serializer()
{
  data_.resize( 500 +
                offset_variable_fields );
}

std::pair<const unsigned char*, std::size_t>
auction_imbalance_serializer::serialize(
  const messages::auction_imbalance& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  byte_conversion::uint32_to_be( data_.data() + offset_seqnum, msg.seqnum().second );
  byte_conversion::uint32_to_be( data_.data() + offset_update_action, msg.update_action().second );
  byte_conversion::uint64_to_be( data_.data() + offset_security_id, msg.security_id().second );
  byte_conversion::int64_to_be( data_.data() + offset_entry_size, msg.entry_size().second );
  byte_conversion::uint32_to_be( data_.data() + offset_entry_date, msg.entry_date().second );
  byte_conversion::uint32_to_be( data_.data() + offset_entry_time, msg.entry_time().second );
  byte_conversion::uint32_to_be( data_.data() + offset_trade_condition, msg.trade_condition().second );

  return std::make_pair( data_.data(), offset );
}

std::size_t
auction_imbalance_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
auction_imbalance_serializer::deserialize( const unsigned char* data,
    messages::auction_imbalance& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );
  dst.set_seqnum( byte_conversion::be_to_uint32( data + offset_seqnum ) );
  dst.set_update_action( byte_conversion::be_to_uint32( data + offset_update_action ) );
  dst.set_security_id( byte_conversion::be_to_uint64( data + offset_security_id ) );
  dst.set_entry_size( byte_conversion::be_to_int64( data + offset_entry_size ) );
  dst.set_entry_date( byte_conversion::be_to_uint32( data + offset_entry_date ) );
  dst.set_entry_time( byte_conversion::be_to_uint32( data + offset_entry_time ) );
  dst.set_trade_condition( byte_conversion::be_to_uint32( data + offset_trade_condition ) );

  return offset;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

