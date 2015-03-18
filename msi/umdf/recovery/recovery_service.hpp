#ifndef APOENA_MSI_UMDF_RECOVERY_RECOVERYSERVICE_HPP
#define APOENA_MSI_UMDF_RECOVERY_RECOVERYSERVICE_HPP

#include <string>
#include <functional>
#include <msi/event.hpp>
#include <msi/umdf/common/typedefs.hpp>
#include <msi/umdf/recovery/recovery_export.hpp>
#include <msi/umdf/recovery/responses.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace recovery
{

class RECOVERY_Export recovery_service
{
public:

  virtual ~recovery_service() {}

  virtual void connect() = 0;
  virtual void disconnect() = 0;
  virtual void request_recovery( const std::string& channel_id, seqnum_t first, seqnum_t last ) = 0;

  void register_on_ack_callback( event<ApplRespType, ApplRespError>::handler_t callback )
  {
    on_ack_.register_handler( callback );
  }

  void register_on_data_callback(
    event<seqnum_t, const unsigned char*, std::size_t>::handler_t callback )
  {
    on_data_.register_handler( callback );
  }

  void register_on_report_callback( event<ApplReportType, ApplRespError>::handler_t callback )
  {
    on_report_.register_handler( callback );
  }


protected:
  event<ApplRespType, ApplRespError> on_ack_;
  //seqnum, data, length
  event<seqnum_t, const unsigned char*, std::size_t> on_data_;
  event<ApplReportType, ApplRespError> on_report_;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_RECOVERY_RECOVERYSERVICE_HPP */


