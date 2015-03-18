#ifndef APOENA_MSI_LOGGING_CONSOLELOGGERFACTORY_HPP
#define APOENA_MSI_LOGGING_CONSOLELOGGERFACTORY_HPP

#include <string>
#include <memory>
#include <msi/logging/logging_export.hpp>
#include <msi/logging/logger_factory.hpp>
#include <msi/logging/console_logger.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

class LOGGING_Export console_logger_factory : public logger_factory
{
public:
  explicit console_logger_factory( severity log_level );
  console_logger_factory( const console_logger_factory& ) = delete;
  console_logger_factory& operator=( const console_logger_factory& ) = delete;

  virtual ~console_logger_factory();
  virtual std::shared_ptr<logger> get_logger();

private:
  std::shared_ptr<console_logger> logger_;
};

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_LOGGING_CONSOLELOGGERFACTORY_HPP */

