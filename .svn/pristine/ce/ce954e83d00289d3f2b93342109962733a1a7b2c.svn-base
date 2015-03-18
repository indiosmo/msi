#include <msi/msi_pch.hpp>
#include <iostream>
#include <functional>
#include <msi/network/multicast_sender.hpp>

namespace apoena
{
namespace msi
{
namespace network
{

multicast_sender::multicast_sender( const std::string& address, unsigned short port,
                                    boost::asio::io_service& io_service )
  : endpoint_( boost::asio::ip::address::from_string( address ), port )
  , socket_( io_service, endpoint_.protocol() )
  , logger_( logging::log::get_logger() )
{
}

void
multicast_sender::register_on_send_callback( on_send_callback_t callback )
{
  on_send_callback_ = callback;
}

void
multicast_sender::send( const unsigned char* buffer, size_t length )
{
  //make a copy of the buffer and store in a shared_ptr that is passed to an async_write call
  //the shared_ptr will be deleted after the write handler returns.
  auto send_buffer = std::make_shared<std::vector<uint8_t>>( buffer, buffer + length );

  socket_.async_send_to( boost::asio::buffer( *send_buffer ), endpoint_,
                         std::bind( &multicast_sender::handle_send, this, send_buffer,
                                    std::placeholders::_1,
                                    std::placeholders::_2 ) );
}

void
multicast_sender::handle_send( std::shared_ptr<std::vector<uint8_t>> buffer,
                               const boost::system::error_code& error,
                               std::size_t bytes_transferred )
{
  if ( !error )
  {
    if ( on_send_callback_ )
    {
      on_send_callback_( buffer->data(), bytes_transferred );
    }
  }
  else if ( error.value() != boost::asio::error::operation_aborted )
  {
    logger_->log( logging::Error, "MulticastSender: Send error. '%s'. %d bytes transferred.", error.message(), bytes_transferred );
  }
}

} //end of namespace
} //end of namespace
} //end of namespace

