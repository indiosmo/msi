#include <msi/msi_pch.hpp>
#include <msi/logging/file_logger.hpp>

namespace apoena
{
namespace msi
{
namespace logging
{

file_logger::file_logger( severity log_level, const std::string& filename )
  : logger( log_level )
  , filename_( filename )
{
}

file_logger::~file_logger()
{
}

void
file_logger::open_file()
{
  file_.open( filename_, std::ios::out | std::ios::app );
}

void
file_logger::log_impl( const std::string& message )
{
  file_ << message << std::endl;
}

} //end of namespace
} //end of namespace
} //end of namespace

