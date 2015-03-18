#ifndef APOENA_MSI_LOGGING_LOGGER_HPP
#define APOENA_MSI_LOGGING_LOGGER_HPP

#include <string>
#include <boost/format.hpp>
#include <msi/logging/logging_export.hpp>
#include <msi/logging/severity.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

class LOGGING_Export logger
{
public:
  explicit logger( severity log_level );
  logger( const logger& ) = delete;
  logger& operator=( const logger& ) = delete;

  virtual ~logger();

  severity log_level() const
  {
    return log_level_;
  }

  template<typename... TArgs>
  void log( severity level, std::string fmt, TArgs... args );

private:
  template<typename TValue, typename... TArgs>
  void log_format( boost::format& message, TValue arg, TArgs... args );

  void log_format( boost::format& message );

  virtual void log_impl( const std::string& message ) = 0;

  severity log_level_;
};

typedef std::shared_ptr<logger> logger_ptr;

template<typename... TArgs>
void
logger::log( severity level, std::string fmt, TArgs... args )
{
  if ( level >= log_level_ )
  {
    boost::format message( fmt );
    log_format( message, args... );
  }
}

template<typename TValue, typename... TArgs>
void
logger::log_format( boost::format& message, TValue arg, TArgs... args )
{
  message % arg;
  log_format( message, args... );
}

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_LOGGING_LOGGER_HPP */

