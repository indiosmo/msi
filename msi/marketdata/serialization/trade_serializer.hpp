#ifndef APOENA_MSI_MARKETDATA_SERIALIZATION_TRADE_SERIALIZER_HPP
#define APOENA_MSI_MARKETDATA_SERIALIZATION_TRADE_SERIALIZER_HPP

#include <msi/marketdata/messages/trade.hpp>
#include <msi/marketdata/serialization/marketdata_serialization_export.hpp>


namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

class MARKETDATA_SERIALIZATION_Export trade_serializer
{
public:
  enum offset
  {
    offset_pmap = 0,
    offset_seqnum = offset_pmap + sizeof( uint32_t ),
    offset_update_action = offset_seqnum + sizeof( uint32_t ),
    offset_security_id = offset_update_action + sizeof( uint32_t ),
    offset_entry_price_mantissa = offset_security_id + sizeof( uint64_t ),
    offset_entry_price_exponent = offset_entry_price_mantissa + sizeof ( decimal::mantissa_t ),
    offset_entry_size = offset_entry_price_exponent + sizeof( decimal::exponent_t ),
    offset_entry_date = offset_entry_size + sizeof( int64_t ),
    offset_entry_time = offset_entry_date + sizeof( uint32_t ),
    offset_tick_direction = offset_entry_time + sizeof( uint32_t ),
    offset_buyer = offset_tick_direction + sizeof( uint32_t ),
    offset_seller = offset_buyer + sizeof( uint32_t ),
    offset_variation_mantissa = offset_seller + sizeof( uint32_t ),
    offset_variation_exponent = offset_variation_mantissa + sizeof ( decimal::mantissa_t ),
    offset_quantity_volume = offset_variation_exponent + sizeof( decimal::exponent_t ),
    offset_trade_id = offset_quantity_volume + sizeof( uint64_t ),
    offset_trade_condition = offset_trade_id + sizeof( uint32_t ),
    offset_variable_fields = offset_trade_condition + sizeof( uint32_t )
  };

  trade_serializer();
  std::pair<const unsigned char*, std::size_t> serialize( const messages::trade& msg );
  std::size_t buffer_size() const;
  std::size_t deserialize( const unsigned char* data, messages::trade& dst );

private:

  std::vector<unsigned char> data_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_SERIALIZATION_TRADE_SERIALIZER_HPP */

