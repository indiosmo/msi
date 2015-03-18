#include <msi/msi_pch.hpp>
#include <msi/byte_conversion.hpp>
#include <msi/marketdata/serialization/sequence_serializer.hpp>
#include <msi/marketdata/serialization/string_serializer.hpp>
#include <msi/marketdata/serialization/reference_field_serializer.hpp>
#include <msi/marketdata/serialization/snapshot_serializer.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

snapshot_serializer::snapshot_serializer()
{
  data_.resize( 500 +
                offset_variable_fields +
                auction_imbalance_serializer_.buffer_size() +
                bid_serializer_.buffer_size() +
                close_serializer_.buffer_size() +
                high_serializer_.buffer_size() +
                index_serializer_.buffer_size() +
                low_serializer_.buffer_size() +
                offer_serializer_.buffer_size() +
                open_serializer_.buffer_size() +
                open_interest_serializer_.buffer_size() +
                price_band_serializer_.buffer_size() +
                quantity_band_serializer_.buffer_size() +
                security_status_serializer_.buffer_size() +
                settlement_serializer_.buffer_size() +
                trade_serializer_.buffer_size() +
                trade_volume_serializer_.buffer_size() +
                vwap_serializer_.buffer_size() );
}

std::pair<const unsigned char*, std::size_t>
snapshot_serializer::serialize(
  const messages::snapshot& msg )
{
  std::size_t offset = offset_variable_fields;

  byte_conversion::uint32_to_be( data_.data(), msg.presence_map().to_ulong() );
  offset += serialize_reference_field( msg.auction_imbalance(), auction_imbalance_serializer_, data_, offset_auction_imbalance, offset );
  offset += serialize_sequence( msg.bids(), bid_serializer_, data_, offset_bid, offset );
  offset += serialize_reference_field( msg.close(), close_serializer_, data_, offset_close, offset );
  offset += serialize_reference_field( msg.high(), high_serializer_, data_, offset_high, offset );
  offset += serialize_reference_field( msg.index(), index_serializer_, data_, offset_index, offset );
  offset += serialize_reference_field( msg.low(), low_serializer_, data_, offset_low, offset );
  offset += serialize_sequence( msg.offers(), offer_serializer_, data_, offset_offer, offset );
  offset += serialize_reference_field( msg.open(), open_serializer_, data_, offset_open, offset );
  offset += serialize_reference_field( msg.open_interest(), open_interest_serializer_, data_, offset_open_interest, offset );
  offset += serialize_reference_field( msg.price_band(), price_band_serializer_, data_, offset_price_band, offset );
  offset += serialize_reference_field( msg.quantity_band(), quantity_band_serializer_, data_, offset_quantity_band, offset );
  offset += serialize_reference_field( msg.security_status(), security_status_serializer_, data_, offset_security_status, offset );
  offset += serialize_reference_field( msg.settlement(), settlement_serializer_, data_, offset_settlement, offset );
  offset += serialize_reference_field( msg.trade(), trade_serializer_, data_, offset_trade, offset );
  offset += serialize_reference_field( msg.trade_volume(), trade_volume_serializer_, data_, offset_trade_volume, offset );
  offset += serialize_reference_field( msg.vwap(), vwap_serializer_, data_, offset_vwap, offset );

  return std::make_pair( data_.data(), offset );
}

std::size_t
snapshot_serializer::buffer_size() const
{
  return data_.size();
}

std::size_t
snapshot_serializer::deserialize( const unsigned char* data,
                                  messages::snapshot& dst )
{
  decimal d;
  std::size_t offset = offset_variable_fields;

  dst.set_presence_map( byte_conversion::be_to_uint32( data + offset_pmap ) );

  if ( dst.presence_map()[messages::snapshot::ix_auction_imbalance] )
  {
    messages::auction_imbalance msg;
    offset += auction_imbalance_serializer_.deserialize( data + offset, msg );
    dst.set_auction_imbalance( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_bid] )
  {
    std::size_t entries = byte_conversion::be_to_uint32( data + offset_bid );
    messages::bid entry;

    for ( std::size_t i = 0; i < entries; i++ )
    {
      offset += bid_serializer_.deserialize( data + offset, entry );
      dst.add_bid( entry );
      entry.reset();
    }
  }

  if ( dst.presence_map()[messages::snapshot::ix_close] )
  {
    messages::close msg;
    offset += close_serializer_.deserialize( data + offset, msg );
    dst.set_close( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_high] )
  {
    messages::high msg;
    offset += high_serializer_.deserialize( data + offset, msg );
    dst.set_high( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_index] )
  {
    messages::index msg;
    offset += index_serializer_.deserialize( data + offset, msg );
    dst.set_index( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_low] )
  {
    messages::low msg;
    offset += low_serializer_.deserialize( data + offset, msg );
    dst.set_low( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_offer] )
  {
    std::size_t entries = byte_conversion::be_to_uint32( data + offset_offer );
    messages::offer entry;

    for ( std::size_t i = 0; i < entries; i++ )
    {
      offset += offer_serializer_.deserialize( data + offset, entry );
      dst.add_offer( entry );
      entry.reset();
    }
  }

  if ( dst.presence_map()[messages::snapshot::ix_open] )
  {
    messages::open msg;
    offset += open_serializer_.deserialize( data + offset, msg );
    dst.set_open( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_open_interest] )
  {
    messages::open_interest msg;
    offset += open_interest_serializer_.deserialize( data + offset, msg );
    dst.set_open_interest( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_price_band] )
  {
    messages::price_band msg;
    offset += price_band_serializer_.deserialize( data + offset, msg );
    dst.set_price_band( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_quantity_band] )
  {
    messages::quantity_band msg;
    offset += quantity_band_serializer_.deserialize( data + offset, msg );
    dst.set_quantity_band( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_security_status] )
  {
    messages::security_status msg;
    offset += security_status_serializer_.deserialize( data + offset, msg );
    dst.set_security_status( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_settlement] )
  {
    messages::settlement msg;
    offset += settlement_serializer_.deserialize( data + offset, msg );
    dst.set_settlement( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_trade] )
  {
    messages::trade msg;
    offset += trade_serializer_.deserialize( data + offset, msg );
    dst.set_trade( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_trade_volume] )
  {
    messages::trade_volume msg;
    offset += trade_volume_serializer_.deserialize( data + offset, msg );
    dst.set_trade_volume( msg );
  }


  if ( dst.presence_map()[messages::snapshot::ix_vwap] )
  {
    messages::vwap msg;
    offset += vwap_serializer_.deserialize( data + offset, msg );
    dst.set_vwap( msg );
  }


  return offset;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

