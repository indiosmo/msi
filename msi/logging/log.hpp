#ifndef APOENA_MSI_LOGGING_LOG_HPP
#define APOENA_MSI_LOGGING_LOG_HPP

#include <memory>
#include <msi/logging/logging_export.hpp>
#include <msi/logging/logger.hpp>
#include <msi/logging/logger_factory.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

class LOGGING_Export log
{
public:
  log() = delete;
  log( const log& ) = delete;
  log& operator=( const log& ) = delete;

  static void register_factory( std::shared_ptr<logger_factory> factory );
  static std::shared_ptr<logger> get_logger();

private:

  static std::shared_ptr<logger_factory> factory_;

};

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_LOGGING_LOG_HPP */

