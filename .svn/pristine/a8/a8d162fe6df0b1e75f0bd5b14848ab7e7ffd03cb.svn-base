#ifndef APOENA_MSI_NETWORK_TCP_CONNECTION_HPP
#define APOENA_MSI_NETWORK_TCP_CONNECTION_HPP

#include <array>
#include <vector>
#include <memory>
#include <utility>
#include <functional>
#include <boost/asio.hpp>
#include <msi/network/tcp/header.hpp>
#include <msi/network/network_export.hpp>

namespace apoena
{
namespace msi
{
namespace network
{
namespace tcp
{

class connection_manager;

class NETWORK_Export connection
  : public std::enable_shared_from_this<connection>
{
public:
  typedef std::function<void( std::shared_ptr<connection> )> on_disconnect_t;
  typedef std::function<void( const unsigned char*, std::size_t )> on_read_t;

  connection( const connection& ) = delete;
  connection& operator=( const connection& ) = delete;

  connection( boost::asio::ip::tcp::socket socket,
              connection_manager& manager );

  void start();

  void stop();

  void write( const unsigned char* data, std::size_t length );

  void write( uint32_t service,
              uint32_t message_type,
              const unsigned char* data,
              std::size_t length );

  void write( const std::vector<boost::asio::const_buffer>& buffers );

  void register_on_disconnect_callback( on_disconnect_t callback );

  void register_on_read_callback( on_read_t callback );

private:
  void read_header();

  void read_body( std::size_t size );

  boost::asio::ip::tcp::socket socket_;
  connection_manager& connection_manager_;

  header write_header_;
  header read_header_;
  std::vector<unsigned char> body_;

  bool disconnected_;

  on_disconnect_t on_disconnect_;
  on_read_t on_read_;
};

typedef std::shared_ptr<connection> connection_ptr;

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_NETWORK_TCP_CONNECTION_HPP */

