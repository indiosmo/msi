#ifndef APOENA_MSI_MARKETDATA_COMMON_RECEIVER_HPP
#define APOENA_MSI_MARKETDATA_COMMON_RECEIVER_HPP

#include <functional>
#include <memory>
#include <msi/event.hpp>
#include <msi/marketdata/common/marketdata_common_export.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{

class MARKETDATA_COMMON_Export receiver
{
public:
  ~receiver() {}

  virtual void register_on_receive_callback(
    event<const unsigned char*, std::size_t>::handler_t callback ) = 0;

  virtual void run() = 0;
  virtual void stop() = 0;
};

typedef std::shared_ptr<marketdata::receiver> receiver_ptr;

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_COMMON_RECEIVER_HPP */

