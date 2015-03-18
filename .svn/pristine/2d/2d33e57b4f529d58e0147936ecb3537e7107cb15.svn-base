#ifndef APOENA_MSI_MARKETDATA_SERIALIZATION_OFFER_SERIALIZER_HPP
#define APOENA_MSI_MARKETDATA_SERIALIZATION_OFFER_SERIALIZER_HPP

#include <msi/marketdata/messages/offer.hpp>
#include <msi/marketdata/serialization/marketdata_serialization_export.hpp>


namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

class MARKETDATA_SERIALIZATION_Export offer_serializer
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
    offset_seller = offset_entry_time + sizeof( uint32_t ),
    offset_position = offset_seller + sizeof( uint32_t ),
    offset_order_id = offset_position + sizeof( uint32_t ),
    offset_variable_fields = offset_order_id + sizeof( uint32_t )
  };

  offer_serializer();
  std::pair<const unsigned char*, std::size_t> serialize( const messages::offer& msg );
  std::size_t buffer_size() const;
  std::size_t deserialize( const unsigned char* data, messages::offer& dst );

private:

  std::vector<unsigned char> data_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_SERIALIZATION_OFFER_SERIALIZER_HPP */

