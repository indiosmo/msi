#ifndef APOENA_MSI_NETWORK_TCP_SERVER_HPP
#define APOENA_MSI_NETWORK_TCP_SERVER_HPP

#include <string>
#include <functional>
#include <boost/asio.hpp>
#include <msi/network/tcp/connection.hpp>
#include <msi/network/tcp/connection_manager.hpp>
#include <msi/network/network_export.hpp>

namespace apoena
{
namespace msi
{
namespace network
{
namespace tcp
{

class NETWORK_Export server
{
public:
  typedef std::function<void ( connection_ptr )> on_connection_t;

  server( const server& ) = delete;
  server& operator=( const server& ) = delete;

  server( boost::asio::io_service& io_service,
          const std::string& address,
          const std::string& port );

  void run();

  void stop();

  void register_on_connection_callback( on_connection_t callback );

private:
  void bind_and_listen();

  void accept();

  std::string address_;
  std::string port_;
  boost::asio::ip::tcp::endpoint endpoint_;

  boost::asio::io_service& io_service_;
  boost::asio::ip::tcp::resolver resolver_;
  boost::asio::ip::tcp::acceptor acceptor_;
  connection_manager connection_manager_;
  boost::asio::ip::tcp::socket socket_;

  bool stopped_;

  on_connection_t on_connection_;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_NETWORK_TCP_SERVER_HPP */


