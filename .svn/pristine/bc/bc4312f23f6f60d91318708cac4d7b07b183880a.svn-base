#ifndef APOENA_MSI_LOGGING_CONSOLELOGGER_HPP
#define APOENA_MSI_LOGGING_CONSOLELOGGER_HPP

#include <string>
#include <iostream>
#include <mutex>
#include <msi/logging/logging_export.hpp>
#include <msi/logging/logger.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

class LOGGING_Export console_logger : public logger
{
public:
  explicit console_logger( severity log_level );
  console_logger( const console_logger& ) = delete;
  console_logger& operator=( const console_logger& ) = delete;

  virtual ~console_logger();

  virtual void log_impl( const std::string& message );

private:
  std::mutex mutex_;
};

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_LOGGING_CONSOLELOGGER_HPP */

