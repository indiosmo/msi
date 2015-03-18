#ifndef APOENA_MSI_LOGGING_LOGGERFACTORY_HPP
#define APOENA_MSI_LOGGING_LOGGERFACTORY_HPP

#include <string>
#include <memory>
#include <msi/logging/logging_export.hpp>
#include <msi/logging/logger.hpp>
#include <msi/logging/severity.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

class LOGGING_Export logger_factory
{
public:
  logger_factory( severity log_level )
    : log_level_( log_level )
  {
  }

  severity log_level() const
  {
    return log_level_;
  }

  logger_factory( const logger_factory& ) = delete;
  logger_factory& operator=( const logger_factory& ) = delete;

  virtual ~logger_factory() {}
  virtual std::shared_ptr<logger> get_logger() = 0;

private:
  severity log_level_;
};

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_LOGGING_LOGGERFACTORY_HPP */

