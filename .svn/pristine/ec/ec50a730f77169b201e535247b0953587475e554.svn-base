#include <msi/msi_pch.hpp>
#include <iostream>
#include <functional>
#include <msi/network/multicast_receiver.hpp>

namespace apoena
{
namespace msi
{
namespace network
{

multicast_receiver::multicast_receiver( const std::string& address,
                                        unsigned short port,
                                        std::size_t buffer_size,
                                        boost::asio::io_service& io_service )
  : running_( false )
  , buffer_( buffer_size )
  , endpoint_( boost::asio::ip::address::from_string( address ), port )
  , socket_( io_service )
  , logger_( logging::log::get_logger() )
{
}

bool
multicast_receiver::buffer_size( std::size_t size )
{
  if ( !running_ )
  {
    return false;
  }

  buffer_.resize( size );
  return true;
}

std::size_t
multicast_receiver::buffer_size() const
{
  return buffer_.size();
}

void
multicast_receiver::register_on_receive_callback( on_receive_callback_t callback )
{
  on_receive_callback_ = callback;
}

void
multicast_receiver::start()
{
  if ( running_ )
  {
    return;
  }

  running_ = true;

  socket_.open( endpoint_.protocol() );
  socket_.set_option( boost::asio::ip::udp::socket::reuse_address( true ) );
  socket_.set_option( boost::asio::socket_base::receive_buffer_size( 1 << 19 ) );
  socket_.bind( boost::asio::ip::udp::endpoint( boost::asio::ip::address_v4::any(), endpoint_.port() ) );
  socket_.set_option( boost::asio::ip::multicast::join_group( endpoint_.address() ) );

  socket_.async_receive_from(
    boost::asio::buffer( buffer_ ), endpoint_,
    std::bind( &multicast_receiver::handle_receive_from, this,
               std::placeholders::_1,
               std::placeholders::_2 ) );
}

void
multicast_receiver::stop()
{
  if ( !running_ )
  {
    return;
  }

  running_ = false;
  socket_.shutdown( boost::asio::ip::udp::socket::shutdown_both );
  socket_.close();
}

void
multicast_receiver::handle_receive_from(
  const boost::system::error_code& error,
  std::size_t bytes_transferred )
{
  if ( !error )
  {
    if ( on_receive_callback_ )
    {
      on_receive_callback_( buffer_.data(), bytes_transferred );
    }

    //TODO once we have the "rotating buffer" class, start receiving on the next buffer before calling the callback.
    socket_.async_receive_from(
      boost::asio::buffer( buffer_ ), endpoint_,
      std::bind( &multicast_receiver::handle_receive_from, this,
                 std::placeholders::_1,
                 std::placeholders::_2 ) );
  }
  else if ( error.value() != boost::asio::error::operation_aborted )
  {
    logger_->log( logging::Error,
                  "MulticastReceiver: Error receiving from socket. %s",
                  error.message() );
  }
}

} //end of namespace
} //end of namespace
} //end of namespace

