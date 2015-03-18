#ifndef APOENA_MSI_LOG_NULLLOGGER_HPP
#define APOENA_MSI_LOG_NULLLOGGER_HPP

#include <string>
#include <msi/logging/logging_export.hpp>
#include <msi/logging/logger.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

class LOGGING_Export null_logger : public logger
{
public:
  null_logger( severity log_level )
    : logger( log_level )
  {
  }

  null_logger( const null_logger& ) = delete;
  null_logger& operator=( const null_logger& ) = delete;

  virtual ~null_logger() {}
  virtual void log_impl( const std::string& message ) {} //noop
};

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_LOG_NULLLOGGER_HPP */

