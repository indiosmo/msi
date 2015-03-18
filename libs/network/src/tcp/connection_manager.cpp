#include <msi/msi_pch.hpp>
#include <msi/network/tcp/connection_manager.hpp>

namespace apoena
{
namespace msi
{
namespace network
{
namespace tcp
{

connection_manager::connection_manager()
{

}

void
connection_manager::start( connection_ptr c )
{
  connections_.insert( c );
  c->start();
}

void
connection_manager::stop( connection_ptr c )
{
  connections_.erase( c );
  c->stop();
}

void
connection_manager::stop_all()
{
  for ( auto c : connections_ )
  {
    c->stop();
  }

  connections_.clear();
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

