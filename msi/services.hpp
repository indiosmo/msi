#ifndef APOENA_MSI_SERVICES_HPP
#define APOENA_MSI_SERVICES_HPP

namespace apoena
{
namespace msi
{

enum service
{
  service_marketdata = 0,
  service_umdf_ticker_plant
};

enum message_offset
{
  message_offset_service = 0,
  message_offset_message_type = message_offset_service + sizeof( uint32_t ),
  message_offset_data = message_offset_message_type + sizeof( uint32_t )
};

} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_SERVICES_HPP */

