#ifndef APOENA_MSI_NETWORK_MULTICASTRECEIVER_HPP
#define APOENA_MSI_NETWORK_MULTICASTRECEIVER_HPP

#include <string>
#include <memory>
#include <vector>
#include <cstdint>
#include <boost/asio.hpp>
#include <functional>
#include <msi/network/network_export.hpp>
#include <msi/logging/log.hpp>

namespace apoena
{
namespace msi
{
namespace network
{

class NETWORK_Export multicast_receiver
{
public:
  typedef std::function<void( const unsigned char* buffer, std::size_t size )> on_receive_callback_t;

  explicit multicast_receiver( const std::string& address, unsigned short port, std::size_t buffer_size,
                               boost::asio::io_service& io_service );

  multicast_receiver( const multicast_receiver& ) = delete;
  multicast_receiver& operator=( const multicast_receiver& ) = delete;

  bool buffer_size( std::size_t size );
  std::size_t buffer_size() const;

  void register_on_receive_callback( on_receive_callback_t callback );

  void start();
  void stop();

private:
  bool running_;
  std::vector<uint8_t> buffer_;
  on_receive_callback_t on_receive_callback_;

  boost::asio::ip::udp::endpoint endpoint_;
  boost::asio::ip::udp::socket socket_;

  logging::logger_ptr logger_;

  void handle_receive_from( const boost::system::error_code& error,
                            std::size_t bytes_transferred );
};

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_NETWORK_MULTICASTRECEIVER_HPP */

