#include <msi/msi_pch.hpp>
#include <msi/network/tcp/connection.hpp>
#include <msi/network/tcp/connection_manager.hpp>
#include <msi/byte_conversion.hpp>

namespace apoena
{
namespace msi
{
namespace network
{
namespace tcp
{


connection::connection( boost::asio::ip::tcp::socket socket,
                        connection_manager& manager )
  : socket_( std::move( socket ) )
  , connection_manager_( manager )
  , disconnected_( true )
{

}

void
connection::start()
{
  disconnected_ = false;
  read_header();
}

void
connection::stop()
{
  if ( !disconnected_ )
  {
    disconnected_ = true;

    if ( on_disconnect_ )
    {
      on_disconnect_( shared_from_this() );
    }

    socket_.close();
  }
}

void
connection::write( const unsigned char* data, std::size_t length )
{
  auto self( shared_from_this() );

  write_header_.encode( length );
  std::vector<boost::asio::const_buffer> buffers;
  buffers.push_back( boost::asio::buffer( write_header_.data(), tcp::header::header_size ) );
  buffers.push_back( boost::asio::buffer( data, length ) );

  boost::asio::async_write( socket_,
                            buffers,
                            [this, self]( boost::system::error_code ec, std::size_t )
  {
    if ( ec && ec != boost::asio::error::operation_aborted )
    {
      connection_manager_.stop( shared_from_this() );
    }
  } );
}

void
connection::write( uint32_t service,
                   uint32_t message_type,
                   const unsigned char* data,
                   std::size_t length )
{
  auto self( shared_from_this() );

  write_header_.encode( length + ( sizeof( uint32_t ) * 2 ) );

  std::array<unsigned char, sizeof( uint32_t )> service_envelope;
  byte_conversion::uint32_to_be( service_envelope.data(), service );

  std::array<unsigned char, sizeof( uint32_t )> msg_type_envelope;
  byte_conversion::uint32_to_be( msg_type_envelope.data(), message_type );

  std::vector<boost::asio::const_buffer> buffers;
  buffers.push_back( boost::asio::buffer( write_header_.data(), tcp::header::header_size ) );
  buffers.push_back( boost::asio::buffer( service_envelope, service_envelope.size() ) );
  buffers.push_back( boost::asio::buffer( msg_type_envelope, msg_type_envelope.size() ) );
  buffers.push_back( boost::asio::buffer( data, length ) );

  boost::asio::async_write( socket_,
                            buffers,
                            [this, self]( boost::system::error_code ec, std::size_t )
  {
    if ( ec && ec != boost::asio::error::operation_aborted )
    {
      connection_manager_.stop( shared_from_this() );
    }
  } );
}

void connection::write( const std::vector<boost::asio::const_buffer>& buffers )
{
  auto self( shared_from_this() );

  std::size_t length = 0;

  for ( auto buffer : buffers )
  {
    length += boost::asio::buffer_size( buffer );
  }

  write_header_.encode( length );

  std::vector<boost::asio::const_buffer> write_buffers;
  write_buffers.push_back( boost::asio::buffer( write_header_.data(), tcp::header::header_size ) );
  write_buffers.insert( write_buffers.end(), buffers.begin(), buffers.end() );

  boost::asio::async_write( socket_,
                            buffers,
                            [this, self]( boost::system::error_code ec, std::size_t )
  {
    if ( ec && ec != boost::asio::error::operation_aborted )
    {
      connection_manager_.stop( shared_from_this() );
    }
  } );
}

void
connection::register_on_disconnect_callback( on_disconnect_t callback )
{
  on_disconnect_ = callback;
}

void
connection::register_on_read_callback( on_read_t callback )
{
  on_read_ = callback;
}

void
connection::read_header()
{
  auto self( shared_from_this() );
  boost::asio::async_read( socket_,
                           boost::asio::buffer( read_header_.data(), header::header_size ),
                           [this, self]( boost::system::error_code ec, std::size_t )
  {
    if ( !ec )
    {
      read_body( read_header_.decode() );
    }
    else if ( ec != boost::asio::error::operation_aborted )
    {
      connection_manager_.stop( shared_from_this() );
    }
  } );
}

void
connection::read_body( std::size_t size )
{
  body_.resize( size );

  auto self( shared_from_this() );
  boost::asio::async_read( socket_,
                           boost::asio::buffer( body_ ),
                           [this, self]( boost::system::error_code ec, std::size_t )
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
      connection_manager_.stop( shared_from_this() );
    }
  } );
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

