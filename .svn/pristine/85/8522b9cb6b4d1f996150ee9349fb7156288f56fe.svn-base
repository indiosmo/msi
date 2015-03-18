#ifndef APOENA_MSI_NETWORK_TCP_CLIENT_HPP
#define APOENA_MSI_NETWORK_TCP_CLIENT_HPP

#include <functional>
#include <boost/asio.hpp>
#include <msi/network/network_export.hpp>
#include <msi/network/tcp/header.hpp>

namespace apoena
{
namespace msi
{
namespace network
{
namespace tcp
{

class NETWORK_Export client
{
public:
  typedef std::function<void( client& )> on_connected_t;
  typedef std::function<void( const unsigned char*, std::size_t )> on_read_t;
  typedef std::function<void( boost::system::error_code )> on_error_t;

  client( boost::asio::io_service& io_service,
          const std::string& address,
          const std::string& port );

  client( const client& ) = delete;
  client& operator=( const client& ) = delete;

  void connect();

  void disconnect();

  void write( const unsigned char* data, std::size_t length );

  void register_on_connected_callback( on_connected_t callback );

  void register_on_read_callback( on_read_t callback );

  void register_on_error_callback( on_error_t callback );

private:
  void read_header();

  void read_body( std::size_t size );

  std::string address_;
  std::string port_;
  boost::asio::ip::tcp::endpoint endpoint_;

  boost::asio::io_service& io_service_;
  boost::asio::ip::tcp::resolver resolver_;
  boost::asio::ip::tcp::socket socket_;

  header write_header_;
  header read_header_;
  std::vector<unsigned char> body_;

  bool disconnected_;

  on_connected_t on_connected_;
  on_read_t on_read_;
  on_error_t on_error_;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_NETWORK_TCP_CLIENT_HPP */


