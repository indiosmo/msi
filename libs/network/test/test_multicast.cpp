#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN network_test
#include <boost/test/unit_test.hpp>

#include <string>
#include <thread>
#include <chrono>
#include <functional>
#include <memory>
#include <mutex>
#include <boost/asio/steady_timer.hpp>
#include <boost/bind.hpp>
#include <msi/network/multicast_receiver.hpp>
#include <msi/network/multicast_sender.hpp>
#include <msi/logging/console_logger_factory.hpp>

namespace
{

using namespace apoena::msi::network;
using namespace apoena::msi::logging;

struct mock_network_pipeline
{

  mock_network_pipeline( int packets_to_send, boost::asio::io_service& io_service )
    : packets_to_send( packets_to_send )
    , sender( "239.255.0.1", 16501, io_service )
    , receiver( "239.255.0.1", 16501, 2 << 5, io_service )
    , send_count( 0 )
    , receive_count( 0 )
    , timed_out( false )
    , work( new boost::asio::io_service::work( io_service ) )
    , timer( io_service )
    , logger( log::get_logger() )
  {
  }

  void on_receive( const unsigned char* buffer, std::size_t size )
  {
    if ( ++receive_count == packets_to_send )
    {
      logger->log( Info, "Receiver done" );
      timer.cancel();
      receiver.stop();
      work.reset();
    }
  }

  void on_send( const unsigned char* buffer, std::size_t size )
  {
    if ( ++send_count == packets_to_send )
    {
      logger->log( Info, "Sender done" );
    }
  }

  void on_timeout( const boost::system::error_code& error )
  {
    if ( !error )
    {
      timed_out = true;
      receiver.stop();
      work.reset();
    }
  }

  void start()
  {
    receiver.start();

    //See http://www.microsoft.com/en-us/download/details.aspx?id=13902
    /*
    ARP queues only one outbound IP datagram for a specified destination address
    while that IP address is being resolved to a MAC address. If a UDP-based
    application sends multiple IP datagrams to a single destination address without
    any pauses between them, some of the datagrams may be dropped if there is no ARP
    cache entry already present. An application can compensate for this by calling
    the Iphlpapi.dll routine SendArp() to establish an ARP cache entry, before sending
    the stream of packets.
    */
    std::string arp_cache( "ARP CACHE" );
    sender.send( reinterpret_cast<const unsigned char*>( arp_cache.c_str() ), arp_cache.length() );

    std::chrono::milliseconds wait_arp( 500 );
    std::this_thread::sleep_for( wait_arp );

    sender.register_on_send_callback( std::bind( &mock_network_pipeline::on_send, this, std::placeholders::_1, std::placeholders::_2 ) );
    receiver.register_on_receive_callback( std::bind( &mock_network_pipeline::on_receive, this, std::placeholders::_1, std::placeholders::_2 ) );

    //ARP cache should be up now, send packets.
    send_packets();

    timer.expires_from_now( std::chrono::seconds( 5 ) );
    timer.async_wait( std::bind( &mock_network_pipeline::on_timeout, this, std::placeholders::_1 ) );
  }

  void send_packets()
  {
    std::string msg( "Test Message" );

    for ( int i = 0; i < packets_to_send; ++i )
    {
      sender.send( reinterpret_cast<const unsigned char*>( msg.c_str() ), msg.length() );
    }
  }

  int packets_to_send;

  multicast_sender sender;
  multicast_receiver receiver;
  int send_count;
  int receive_count;
  bool timed_out;

  std::unique_ptr<boost::asio::io_service::work> work;
  boost::asio::steady_timer timer;

  std::shared_ptr<logger> logger;
};

}

BOOST_AUTO_TEST_SUITE( suite_multicast )

BOOST_AUTO_TEST_CASE( test_multicast )
{
  using namespace apoena::msi::logging;

  std::shared_ptr<console_logger_factory> factory( new console_logger_factory( Info ) );
  log::register_factory( factory );

  unsigned int packets = 10000;

  boost::asio::io_service io_service;
  std::unique_ptr<boost::asio::io_service::work> work( new boost::asio::io_service::work( io_service ) );
  std::thread io_thread( boost::bind( &boost::asio::io_service::run, &io_service ) );

  mock_network_pipeline m( packets, io_service );
  m.start();

  work.reset();
  io_thread.join();

  BOOST_CHECK( !m.timed_out );
  BOOST_CHECK_EQUAL( m.send_count, packets );
  BOOST_CHECK_EQUAL( m.receive_count, packets );
}


BOOST_AUTO_TEST_SUITE_END()

