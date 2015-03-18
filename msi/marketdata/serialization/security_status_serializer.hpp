#ifndef APOENA_MSI_MARKETDATA_SERIALIZATION_SECURITY_STATUS_SERIALIZER_HPP
#define APOENA_MSI_MARKETDATA_SERIALIZATION_SECURITY_STATUS_SERIALIZER_HPP

#include <msi/marketdata/messages/security_status.hpp>
#include <msi/marketdata/serialization/marketdata_serialization_export.hpp>


namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

class MARKETDATA_SERIALIZATION_Export security_status_serializer
{
public:
  enum offset
  {
    offset_pmap = 0,
    offset_seqnum = offset_pmap + sizeof( uint32_t ),
    offset_security_id = offset_seqnum + sizeof( uint32_t ),
    offset_security_group = offset_security_id + sizeof( uint64_t ),
    offset_group_phase = offset_security_group + sizeof( uint32_t ),
    offset_instrument_state = offset_group_phase + sizeof( uint32_t ),
    offset_open_time = offset_instrument_state + sizeof( uint32_t ),
    offset_trading_event = offset_open_time + sizeof( uint64_t ),
    offset_variable_fields = offset_trading_event + sizeof( uint32_t )
  };

  security_status_serializer();
  std::pair<const unsigned char*, std::size_t> serialize( const messages::security_status& msg );
  std::size_t buffer_size() const;
  std::size_t deserialize( const unsigned char* data, messages::security_status& dst );

private:

  std::vector<unsigned char> data_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_SERIALIZATION_SECURITY_STATUS_SERIALIZER_HPP */

