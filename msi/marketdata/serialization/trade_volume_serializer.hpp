#ifndef APOENA_MSI_MARKETDATA_SERIALIZATION_TRADE_VOLUME_SERIALIZER_HPP
#define APOENA_MSI_MARKETDATA_SERIALIZATION_TRADE_VOLUME_SERIALIZER_HPP

#include <msi/marketdata/messages/trade_volume.hpp>
#include <msi/marketdata/serialization/marketdata_serialization_export.hpp>


namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

class MARKETDATA_SERIALIZATION_Export trade_volume_serializer
{
public:
  enum offset
  {
    offset_pmap = 0,
    offset_seqnum = offset_pmap + sizeof( uint32_t ),
    offset_security_id = offset_seqnum + sizeof( uint32_t ),
    offset_financial_volume_mantissa = offset_security_id + sizeof( uint64_t ),
    offset_financial_volume_exponent = offset_financial_volume_mantissa + sizeof ( decimal::mantissa_t ),
    offset_number_of_trades = offset_financial_volume_exponent + sizeof( decimal::exponent_t ),
    offset_quantity_volume = offset_number_of_trades + sizeof( uint32_t ),
    offset_entry_date = offset_quantity_volume + sizeof( uint64_t ),
    offset_entry_time = offset_entry_date + sizeof( uint32_t ),
    offset_currency = offset_entry_time + sizeof( uint32_t ),
    offset_variable_fields = offset_currency + sizeof( uint32_t )
  };

  trade_volume_serializer();
  std::pair<const unsigned char*, std::size_t> serialize( const messages::trade_volume& msg );
  std::size_t buffer_size() const;
  std::size_t deserialize( const unsigned char* data, messages::trade_volume& dst );

private:

  std::vector<unsigned char> data_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_SERIALIZATION_TRADE_VOLUME_SERIALIZER_HPP */

