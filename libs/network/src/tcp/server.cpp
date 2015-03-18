#include <msi/msi_pch.hpp>
#include <msi/network/tcp/server.hpp>

namespace apoena
{
namespace msi
{
namespace network
{
namespace tcp
{

server::server( boost::asio::io_service& io_service,
                const std::string& address,
                const std::string& port )
  : address_( address )
  , port_( port )
  , io_service_( io_service )
  , resolver_( io_service_ )
  , acceptor_( io_service_ )
  , socket_( io_service_ )
{

}

void
server::run()
{
  stopped_ = false;

  resolver_.async_resolve( { address_, port_ },
                           [this]( boost::system::error_code ec, boost::asio::ip::tcp::resolver::iterator iterator )
  {
    if ( stopped_ )
    {
      return;
    }

    if ( !ec )
    {
      endpoint_ = *iterator;
      bind_and_listen();
    }
    else if ( ec != boost::asio::error::operation_aborted )
    {
      //TODO Log
    }
  } );
}

void
server::bind_and_listen()
{
  acceptor_.open( endpoint_.protocol() );
  acceptor_.set_option( boost::asio::ip::tcp::acceptor::reuse_address( true ) );
  acceptor_.bind( endpoint_ );
  acceptor_.listen();
  accept();
}

void
server::stop()
{
  if ( !stopped_ )
  {
    stopped_ = true;
    resolver_.cancel();
    acceptor_.close();
    connection_manager_.stop_all();
  }
}

void
server::register_on_connection_callback( on_connection_t callback )
{
  on_connection_ = callback;
}

void
server::accept()
{
  acceptor_.async_accept( socket_,
                          [this]( boost::system::error_code ec )
  {
    if ( !acceptor_.is_open() )
    {
      return;
    }

    if ( !ec )
    {
      auto conn = std::make_shared<connection>(
                    std::move( socket_ ),
                    connection_manager_ );

      if ( on_connection_ )
      {
        on_connection_( conn );
      }

      connection_manager_.start( conn );
    }

    accept();
  } );
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

