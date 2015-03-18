#ifndef APOENA_MSI_LOGGING_FILELOGGER_HPP
#define APOENA_MSI_LOGGING_FILELOGGER_HPP

#include <string>
#include <fstream>
#include <msi/logging/logging_export.hpp>
#include <msi/logging/logger.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

class LOGGING_Export file_logger : public logger
{
public:
  explicit file_logger( severity log_level, const std::string& filename );

  file_logger( const file_logger& ) = delete;
  file_logger& operator=( const file_logger& ) = delete;

  virtual ~file_logger();

  virtual void log_impl( const std::string& message );

  void open_file();

private:
  std::string filename_;
  std::ofstream file_;
};

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_LOGGING_FILELOGGER_HPP */

