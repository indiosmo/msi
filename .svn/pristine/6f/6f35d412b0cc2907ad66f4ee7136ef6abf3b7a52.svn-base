#ifndef APOENA_MSI_NETWORK_MULTICASTSENDER_HPP
#define APOENA_MSI_NETWORK_MULTICASTSENDER_HPP

#include <string>
#include <memory>
#include <vector>
#include <boost/asio.hpp>
#include <msi/network/network_export.hpp>
#include <msi/logging/log.hpp>

namespace apoena
{
namespace msi
{
namespace network
{

class NETWORK_Export multicast_sender
{
public:
  typedef std::function<void( const unsigned char* buffer, std::size_t size )> on_send_callback_t;

  explicit multicast_sender( const std::string& address, unsigned short port,
                             boost::asio::io_service& io_service );

  multicast_sender( const multicast_sender& ) = delete;
  multicast_sender& operator=( const multicast_sender& ) = delete;

  void send( const unsigned char* buffer, std::size_t length );

  void register_on_send_callback( on_send_callback_t callback );

private:
  on_send_callback_t on_send_callback_;

  boost::asio::ip::udp::endpoint endpoint_;
  boost::asio::ip::udp::socket socket_;

  logging::logger_ptr logger_;

  void handle_send( std::shared_ptr<std::vector<uint8_t>> buffer,
                    const boost::system::error_code& error,
                    std::size_t bytes_transferred );
};

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_NETWORK_MULTICASTSENDER_HPP */

