#include <msi/msi_pch.hpp>
#include <msi/logging/console_logger_factory.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

console_logger_factory::console_logger_factory( severity log_level )
  : logger_factory( log_level )
  , logger_( new console_logger( log_level ) )
{
}

console_logger_factory::~console_logger_factory()
{
}

std::shared_ptr<logger>
console_logger_factory::get_logger()
{
  return logger_;
}

} //end of namespace
} //end of namespace
} //end of namespace

