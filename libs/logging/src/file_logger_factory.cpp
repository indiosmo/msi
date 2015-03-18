#include <msi/msi_pch.hpp>
#include <msi/logging/file_logger_factory.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

file_logger_factory::file_logger_factory( severity log_level, const std::string& filename )
  : logger_factory( log_level )
  , logger_( new file_logger( log_level, filename ) )
{
}

file_logger_factory::~file_logger_factory()
{
}

void
file_logger_factory::open_file()
{
  logger_->open_file();
}

std::shared_ptr<logger>
file_logger_factory::get_logger()
{
  return logger_;
}

} //end of namespace
} //end of namespace
} //end of namespace

