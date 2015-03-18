#include <msi/msi_pch.hpp>
#include <msi/network/tcp/client.hpp>
#include <iostream>

namespace apoena
{
namespace msi
{
namespace network
{
namespace tcp
{

client::client( boost::asio::io_service& io_service,
                const std::string& address,
                const std::string& port )
  : io_service_( io_service )
  , resolver_( io_service_ )
  , socket_( io_service_ )
  , address_( address )
  , port_( port )
  , disconnected_( true )
{

}

void
client::connect()
{
  disconnected_ = false;

  resolver_.async_resolve( { address_, port_ },
                           [this]( boost::system::error_code ec, boost::asio::ip::tcp::resolver::iterator iterator )
  {
    if ( disconnected_ )
    {
      return;
    }

    endpoint_ = *iterator;

    socket_.async_connect( endpoint_,
                           [this]( boost::system::error_code ec )
    {
      if ( !ec )
      {
        if ( on_connected_ )
        {
          on_connected_( *this );
        }

        read_header();
      }
    } );
  } );
}

void
client::disconnect()
{
  if ( !disconnected_ )
  {
    disconnected_ = true;
    resolver_.cancel();
    socket_.close();
  }
}

void
client::write( const unsigned char* data, std::size_t length )
{
  write_header_.encode( length );
  std::vector<boost::asio::const_buffer> buffers;
  buffers.push_back( boost::asio::buffer( write_header_.data(), tcp::header::header_size ) );
  buffers.push_back( boost::asio::buffer( data, length ) );

  boost::asio::async_write( socket_,
                            buffers,
                            [this]( boost::system::error_code ec, std::size_t )
  {
    if ( ec && ec != boost::asio::error::operation_aborted )
    {
      if ( on_error_ )
      {
        on_error_( ec );
      }

      disconnect();
    }
  } );
}

void client::register_on_connected_callback( on_connected_t callback )
{
  on_connected_ = callback;
}

void
client::register_on_read_callback( on_read_t callback )
{
  on_read_ = callback;
}

void
client::register_on_error_callback( on_error_t callback )
{
  on_error_ = callback;
}

void
client::read_header()
{
  boost::asio::async_read( socket_,
                           boost::asio::buffer( read_header_.data(), header::header_size ),
                           [this]( boost::system::error_code ec, std::size_t )
  {
    if ( !ec )
    {
      read_body( read_header_.decode() );
    }
    else if ( ec != boost::asio::error::operation_aborted )
    {
      if ( on_error_ )
      {
        on_error_( ec );
      }

      disconnect();
      //TODO log error
    }
  } );
}

void
client::read_body( std::size_t size )
{
  body_.resize( size );

  boost::asio::async_read( socket_,
                           boost::asio::buffer( body_ ),
                           [this]( boost::system::error_code ec, std::size_t )
  {
    if ( !ec )
    {
      if ( on_read_ )
      {
        on_read_( body_.data(), body_.size() );
      }

      read_header();
    }
    else if ( ec != boost::asio::error::operation_aborted )
    {
      if ( on_error_ )
      {
        on_error_( ec );
      }

      disconnect();
      //TODO log error
    }
  } );
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace


