#include <msi/msi_pch.hpp>
#include <msi/logging/log.hpp>
#include <msi/logging/null_logger.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

std::shared_ptr<logger_factory> log::factory_;

void
log::register_factory( std::shared_ptr<logger_factory> factory )
{
  factory_ = factory;
}

std::shared_ptr<logger>
log::get_logger()
{
  if ( factory_ )
  {
    return factory_->get_logger();
  }
  else
  {
    return std::shared_ptr<logger>( new null_logger( None ) );
  }
}

} //end of namespace
} //end of namespace
} //end of namespace

