#ifndef APOENA_MSI_UMDF_RECOVERY_NULL_RECOVERY_SERVICE_HPP
#define APOENA_MSI_UMDF_RECOVERY_NULL_RECOVERY_SERVICE_HPP

#include <msi/umdf/recovery/recovery_export.hpp>
#include <msi/umdf/recovery/recovery_service.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace recovery
{

class RECOVERY_Export null_recovery_service
  : public recovery_service
{
public:
  virtual ~null_recovery_service();
  virtual void connect();
  virtual void disconnect();
  virtual void request_recovery( const std::string& channel_id,
                                 seqnum_t first, seqnum_t last );

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_RECOVERY_NULL_RECOVERY_SERVICE_HPP */

