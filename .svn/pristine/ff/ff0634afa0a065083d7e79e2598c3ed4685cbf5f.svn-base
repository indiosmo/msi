#include <msi/msi_pch.hpp>
#include <msi/logging/logger.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

logger::logger( severity log_level )
  : log_level_( log_level )
{
}

logger::~logger()
{
}

void
logger::log_format( boost::format& message )
{
  log_impl( message.str() );
}

} //end of namespace
} //end of namespace
} //end of namespace

