#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN network_test
#include <boost/test/unit_test.hpp>

#include <functional>
#include <thread>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <msi/network/tcp/server.hpp>
#include <msi/network/tcp/client.hpp>

namespace
{
using namespace apoena::msi::network;

struct server_handler
{
  server_handler()
    : disconnected( false )
  {

  }

  void on_connection( tcp::connection_ptr conn )
  {
    std::cout << "client connected" << std::endl;
    conn->register_on_read_callback( std::bind(
                                       &server_handler::on_read, this, std::placeholders::_1, std::placeholders::_2 ) );

    conn->register_on_disconnect_callback( std::bind(
        &server_handler::on_disconnect, this, std::placeholders::_1 ) );

    std::string s( "to_client" );
    tcp::header h;
    h.encode( s.size() );
    conn->write( h.data(), tcp::header::header_size );
    conn->write( reinterpret_cast<const unsigned char*>( s.c_str() ), s.size() );
  }

  void on_read( const unsigned char* data, std::size_t length )
  {
    msg = std::string( reinterpret_cast<const char*>( data ), length );
    std::cout << "read from client" << std::endl;
  }

  void on_disconnect( tcp::connection_ptr conn )
  {
    std::cout << "client disconnected" << std::endl;
    disconnected = true;
  }

  bool disconnected;
  std::string msg;
};

struct client_handler
{
  void on_connected( tcp::client& client )
  {
    std::cout << "client ok" << std::endl;
    std::string s( "to_server" );
    tcp::header h;
    h.encode( s.size() );
    client.write( h.data(), tcp::header::header_size );
    client.write( reinterpret_cast<const unsigned char*>( s.c_str() ), s.size() );
  }

  void on_read( const unsigned char* data, std::size_t length )
  {
    std::cout << "msg on client" << std::endl;
    msg = std::string( reinterpret_cast<const char*>( data ), length );
  }

  std::string msg;
};

}

BOOST_AUTO_TEST_SUITE( suite_tcp )

BOOST_AUTO_TEST_CASE( test_roundtrip )
{
  boost::asio::io_service io_service;
  std::unique_ptr<boost::asio::io_service::work> work(
    new boost::asio::io_service::work( io_service ) );

  std::thread io_thread( boost::bind( &boost::asio::io_service::run, &io_service ) );

  server_handler sh;
  tcp::server server( io_service, "localhost", "15700" );

  server.register_on_connection_callback( std::bind( &server_handler::on_connection,
                                          &sh, std::placeholders::_1 ) );

  server.run();

  client_handler ch;
  tcp::client client( io_service, "localhost", "15700" );

  client.register_on_connected_callback( std::bind( &client_handler::on_connected, &ch,
                                         std::placeholders::_1 ) );

  client.register_on_read_callback( std::bind( &client_handler::on_read, &ch,
                                    std::placeholders::_1, std::placeholders::_2 ) );

  client.connect();

  std::chrono::milliseconds wait( 500 );
  std::this_thread::sleep_for( wait );

  server.stop();
  client.disconnect();

  server.run();
  client.connect();

  std::this_thread::sleep_for( wait );

  server.stop();
  client.disconnect();

  work.reset();
  io_thread.join();

  BOOST_CHECK( sh.disconnected );
  BOOST_CHECK_EQUAL( sh.msg, "to_server" );
  BOOST_CHECK_EQUAL( ch.msg, "to_client" );
}

BOOST_AUTO_TEST_SUITE_END()

