#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN umdf_receiver_test
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <thread>
#include <msi/byte_conversion.hpp>
#include <msi/umdf/receiver/receiver.hpp>
#include <msi/umdf/recovery/null_recovery_service.hpp>

namespace
{
using namespace apoena::msi;
using namespace apoena::msi::umdf;
using namespace apoena::msi::umdf::receiver;
namespace p = std::placeholders;

} //end of namespace

BOOST_AUTO_TEST_SUITE( suite_event_handler_performance )

BOOST_AUTO_TEST_CASE( test_performance )
{
  boost::asio::io_service io_service;
  auto work = std::make_unique<boost::asio::io_service::work>( io_service );
  sequencing_machine s(
    std::ref( io_service ), "", channel_type_sequential, std::make_shared<recovery::null_recovery_service>() );

  seqnum_t seqnum = 0;

  s.register_on_message_callback( std::bind(
                                    [&seqnum]( const unsigned char* data, std::size_t )
  {
    seqnum = byte_conversion::be_to_uint32( data );
  },
  p::_1, p::_2 ) );

  std::vector<uint8_t> data( 20, 'a' );
  byte_conversion::uint32_to_be( data.data() + header::offset_seqnum, 0 );
  byte_conversion::uint16_to_be( data.data() + header::offset_num_chunks, 1 );
  byte_conversion::uint16_to_be( data.data() + header::offset_current_chunk, 1 );
  byte_conversion::uint16_to_be( data.data() + header::offset_length, data.size() - header::header_size );
  //include seqnum inside message
  byte_conversion::uint32_to_be( data.data() + header::offset_data, 0 );

  std::thread t( std::bind( static_cast<size_t( boost::asio::io_service::* )()>
                            ( &boost::asio::io_service::run ), &io_service ) );

  uint32_t messages = 100 * 1000 * 1000;

  LARGE_INTEGER li, start, end;
  QueryPerformanceFrequency( &li );
  double freq = double( li.QuadPart );

  QueryPerformanceCounter( &start );

  for ( uint32_t i = 1; i <= messages; ++i )
  {
    byte_conversion::uint32_to_be( data.data() + header::offset_seqnum, i );
    byte_conversion::uint32_to_be( data.data() + header::offset_data, i );
    s.handle_datagram( s, data.data(), data.size() );
  }

  QueryPerformanceCounter( &end );

  double time = double( end.QuadPart - start.QuadPart ) / freq;
  double mps = messages / time;
  std::cout << messages << " messages in " << time << "s. " << std::endl;
  std::cout << mps << " messages/s" << std::endl;
  std::cout << time * 1000.0 * 1000.0 * 1000.0 / messages << "ns/msg" << std::endl;

  BOOST_CHECK_EQUAL( seqnum, messages );

  s.stop();
  work.reset();
  io_service.stop();
  t.join();
}

BOOST_AUTO_TEST_SUITE_END()
