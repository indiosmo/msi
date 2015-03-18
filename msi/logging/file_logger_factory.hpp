#ifndef APOENA_MSI_LOGGING_FILELOGGERFACTORY_HPP
#define APOENA_MSI_LOGGING_FILELOGGERFACTORY_HPP

#include <string>
#include <memory>
#include <msi/logging/logging_export.hpp>
#include <msi/logging/logger_factory.hpp>
#include <msi/logging/file_logger.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

class LOGGING_Export file_logger_factory : public logger_factory
{
public:
  explicit file_logger_factory( severity log_level, const std::string& filename );
  file_logger_factory( const file_logger_factory& ) = delete;
  file_logger_factory& operator=( const file_logger_factory& ) = delete;

  void open_file();

  virtual ~file_logger_factory();
  virtual std::shared_ptr<logger> get_logger();

private:
  std::shared_ptr<file_logger> logger_;
};

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_LOGGING_FILELOGGERFACTORY_HPP */

