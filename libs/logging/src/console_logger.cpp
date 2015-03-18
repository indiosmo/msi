#include <msi/msi_pch.hpp>
#include <msi/logging/console_logger.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

console_logger::console_logger( severity log_level )
  : logger( log_level )
{
}

console_logger::~console_logger()
{
}


void
console_logger::log_impl( const std::string& message )
{
  std::lock_guard<std::mutex> lock( mutex_ );
  std::cout << message << std::endl;
}

} //end of namespace
} //end of namespace
} //end of namespace

