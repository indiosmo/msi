#ifndef APOENA_MSI_NETWORK_TCP_CONNECTION_MANAGER_HPP
#define APOENA_MSI_NETWORK_TCP_CONNECTION_MANAGER_HPP

#include <set>
#include <msi/network/tcp/connection.hpp>
#include <msi/network/network_export.hpp>

namespace apoena
{
namespace msi
{
namespace network
{
namespace tcp
{

class NETWORK_Export connection_manager
{
public:
  connection_manager( const connection_manager& ) = delete;
  connection_manager& operator=( const connection_manager& ) = delete;

  connection_manager();

  void start( connection_ptr c );

  void stop( connection_ptr c );

  void stop_all();

private:
  std::set<connection_ptr> connections_;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_NETWORK_TCP_CONNECTION_MANAGER_HPP */

