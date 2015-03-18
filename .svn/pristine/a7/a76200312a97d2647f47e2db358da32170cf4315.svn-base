#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN umdf_receiver_test
#include <boost/test/unit_test.hpp>

#include <functional>
#include <thread>
#include <sstream>
#include <boost/asio.hpp>
#include <msi/umdf/receiver/header.hpp>
#include <msi/umdf/receiver/receiver.hpp>
#include <msi/umdf/recovery/recovery_service.hpp>

namespace
{
using namespace apoena::msi;
using namespace apoena::msi::umdf;
using namespace apoena::msi::umdf::receiver;
namespace p = std::placeholders;

struct handlers
{
  handlers()
    : seqnum_( 0 )
  {

  }

  void handle_message( const unsigned char* buffer,
                       std::size_t length )
  {
    seqnum_ = byte_conversion::be_to_uint32( buffer );
    data_ = std::string( buffer + sizeof( uint32_t ), buffer + length );
  }

  seqnum_t seqnum_;
  std::string data_;
};

struct mock_recovery_service : public recovery::recovery_service
{
  virtual void connect() {}
  virtual void disconnect() {}

  virtual void request_recovery( const std::string& channel, seqnum_t first, seqnum_t last )
  {
    //nop
  }

  void send_ack( recovery::ApplRespType type, recovery::ApplRespError err )
  {
    on_ack_( type, err );
  }

  void send_data( seqnum_t seqnum, const unsigned char* buffer, std::size_t length )
  {
    on_data_( seqnum, buffer, length );
  }

  void send_report( recovery::ApplReportType type, recovery::ApplRespError err )
  {
    on_report_( type, err );
  }
};

std::vector<uint8_t>
build_packet( seqnum_t seqnum, chunk_t no_chunks, chunk_t current_chunk, const std::string& val )
{
  std::vector<uint8_t> data( header::header_size + val.size() );
  byte_conversion::uint32_to_be( data.data() + header::offset_seqnum, seqnum );
  byte_conversion::uint16_to_be( data.data() + header::offset_num_chunks, no_chunks );
  byte_conversion::uint16_to_be( data.data() + header::offset_current_chunk, current_chunk );
  byte_conversion::uint16_to_be( data.data() + header::offset_length, val.size() );

  std::copy( val.begin(), val.end(), data.data() + header::offset_data );

  return data;
}

std::vector<uint8_t>
build_packet( seqnum_t seqnum, chunk_t no_chunks, chunk_t current_chunk, uint32_t val )
{
  std::vector<uint8_t> data( header::header_size + sizeof( uint32_t ) );
  byte_conversion::uint32_to_be( data.data() + header::offset_seqnum, seqnum );
  byte_conversion::uint16_to_be( data.data() + header::offset_num_chunks, no_chunks );
  byte_conversion::uint16_to_be( data.data() + header::offset_current_chunk, current_chunk );
  byte_conversion::uint16_to_be( data.data() + header::offset_length, sizeof( uint32_t ) );

  byte_conversion::uint32_to_be( data.data() + header::offset_data, val );

  return data;
}

}

BOOST_AUTO_TEST_SUITE( suite_state_machine )

BOOST_AUTO_TEST_CASE( test_ordered_assembly )
{
  std::string data1( "data1" );
  std::string data2( "test" );
  std::string data3( "3moredata" );

  std::stringstream ss;
  ss << data1 << data2 << data3;

  handlers h;
  boost::asio::io_service io_service;
  std::shared_ptr<recovery::recovery_service> rs( new mock_recovery_service() );
  sequencing_machine s(
    std::ref( io_service ), "", channel_type_sequential, rs );

  s.register_on_message_callback( std::bind(
                                    &handlers::handle_message, &h, p::_1, p::_2 ) );

  //initial state
  BOOST_REQUIRE_EQUAL( get_fsm_state( s ), "st_uninitialized" );
  std::vector<uint8_t> data = build_packet( 1, 4, 1, 1 );
  s.handle_datagram( s, data.data(), data.size() );

  data = build_packet( 1, 4, 2, "data1" );;
  s.handle_datagram( s, data.data(), data.size() );

  data = build_packet( 1, 4, 3, "test" );;
  s.handle_datagram( s, data.data(), data.size() );

  data = build_packet( 1, 4, 4, "3moredata" );;
  s.handle_datagram( s, data.data(), data.size() );

  BOOST_REQUIRE_EQUAL( get_fsm_state( s ), "st_sequenced" );
  BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
  BOOST_REQUIRE_EQUAL( h.data_.c_str(), ss.str() );
}

//
// BOOST_AUTO_TEST_CASE( test_unordered_assembly )
// {
//   handlers h;
//   boost::asio::io_service io_service;
//   std::shared_ptr<recovery_service> rs( new mock_recovery_service() );
//   event_handler e( "", io_service, sequencer::init_on_message_received, rs );
//
//   e.register_on_message_received_callback( std::bind(
//         &handlers::handle_message, &h, p::_1, p::_2, p::_3 ) );
//
//   std::string data1( "data1" );
//   std::string data2( "test" );
//   std::string data3( "3moredata" );
//
//   std::stringstream ss;
//   ss << data1 << data2 << data3;
//
//   //initial state
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   e.handle_multi( 1, 3, 1, reinterpret_cast<const unsigned char*>( data1.c_str() ), data1.size() );
//   e.handle_multi( 1, 3, 3, reinterpret_cast<const unsigned char*>( data3.c_str() ), data3.size() );
//   e.handle_multi( 1, 3, 2, reinterpret_cast<const unsigned char*>( data2.c_str() ), data2.size() );
//
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
//   BOOST_REQUIRE_EQUAL( *h.data_, ss.str() );
// }
//
// BOOST_AUTO_TEST_CASE( test_reset_on_gap )
// {
//   handlers h;
//   boost::asio::io_service io_service;
//   auto work = std::make_unique<boost::asio::io_service::work>( io_service );
//
//   event_handler e( "", io_service, sequencer::init_on_message_received );
//
//   e.register_on_message_received_callback( std::bind(
//         &handlers::handle_message, &h, p::_1, p::_2, p::_3 ) );
//
//   std::vector<uint8_t> data( 0 );
//
//   std::thread t( std::bind( static_cast<size_t( boost::asio::io_service::* )()>
//                             ( &boost::asio::io_service::run ), &io_service ) );
//
//   //initial state
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   e.handle_single( 1, data.data(), data.size() );
//
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
//
//   e.handle_single( 3, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   std::this_thread::sleep_for( std::chrono::milliseconds( 300 ) );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//
//   work.reset();
//   t.join();
// }
//
// BOOST_AUTO_TEST_CASE( test_transitions )
// {
//   handlers h;
//   boost::asio::io_service io_service;
//   auto work = std::make_unique<boost::asio::io_service::work>( io_service );
//
//   std::shared_ptr<mock_recovery_service> rs( new mock_recovery_service() );
//   event_handler e( "", io_service, sequencer::init_on_message_received, rs );
//
//   e.register_on_message_received_callback( std::bind(
//         &handlers::handle_message, &h, p::_1, p::_2, p::_3 ) );
//
//   std::vector<uint8_t> data( 0 );
//
//   std::thread t( std::bind( static_cast<size_t( boost::asio::io_service::* )()>
//                             ( &boost::asio::io_service::run ), &io_service ) );
//
//   //initial state
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//
//   //source + event [guard] / action == target
//   //st_sequenced + ev_reset / ta_reset == st_sequenced
//   e.reset( 0 );
//   h.seqnum_ = 0;
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//
//   //st_sequenced + ev_ordered_single / ta_publish_single == st_sequenced
//   e.handle_single( 1, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
//
//   //st_sequenced + ev_ordered_multi / ta_enqueue_chunk == st_sequenced
//   e.handle_multi( 2, 2, 1, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
//
//   //st_sequenced + ev_ordered_multi [gc_has_all_chunks] / ta_publish_multi == st_sequenced
//   e.handle_multi( 2, 2, 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 2 );
//
//   //stale single ignored
//   e.handle_single( 1, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 2 );
//
//   //stale multi ignored
//   e.handle_multi( 2, 2, 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 2 );
//
//   //st_sequenced + ev_unordered_single / ta_enqueue_unordered_single == st_gap
//   e.handle_single( 4, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 2 );
//
//   //st_gap + ev_reset / ta_reset == st_sequenced
//   e.reset( 0 );
//   h.seqnum_ = 0;
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//
//   //st_sequenced + ev_unordered_multi / ta_enqueue_unordered_multi == st_gap
//   e.handle_single( 1, data.data(), data.size() );
//   e.handle_multi( 4, 3, 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
//
//   //reset machine
//   e.reset( 0 );
//   h.seqnum_ = 0;
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//
//   //initialize sequencer and create gap
//   e.handle_single ( 1, data.data(), data.size() );
//   e.handle_single( 7, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
//
//   //process_queue raises ev_queue_processed
//   //st_gap + ev_ordered_single / ta_publish_and_process_single == st_gap
//   // -> st_gap + ev_queue_processed [gc_queue_sequenced] == sequenced
//   e.handle_single( 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 2 );
//
//   //st_gap + ev_ordered_multi / ta_enqueue_and_process_multi == st_gap
//   e.handle_multi( 3, 2, 1, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 2 );
//
//   //st_gap + ev_ordered_multi [gc_has_all_chunks] / ta_publish_and_process_multi
//   // -> st_gap + ev_queue_processed [gc_queue_sequenced] == sequenced
//   e.handle_multi( 3, 2, 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 3 );
//
//   //stale single ignored
//   e.handle_single( 3, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 3 );
//
//   //stale multi ignored
//   e.handle_multi( 2, 2, 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 3 );
//
//   //st_gap + ev_unordered_single / ta_enqueue_unordered_single == st_gap
//   e.handle_single( 5, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 3 );
//
//   //st_gap + ev_unordered_multi / ta_enqueue_unordered_multi == st_gap
//   e.handle_multi( 6, 2, 1, data.data(), data.size() );
//   e.handle_multi( 6, 2, 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 3 );
//
//   //fill gap with single
//   //st_gap + ev_ordered_single / ta_publish_and_process_single == st_gap
//   // -> st_gap + ev_queue_processed [gc_queue_sequenced] == sequenced
//   e.handle_single( 4, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 7 );
//
//   //create gap with multi
//   //st_gap + ev_unordered_multi / ta_enqueue_unordered_multi == st_gap
//   e.handle_multi( 8, 2, 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 7 );
//
//   //fill gap with multi
//   //st_gap + ev_ordered_multi [gc_has_all_chunks] / ta_publish_and_process_multi == st_gap
//   // -> st_gap + ev_queue_processed [gc_queue_sequenced] == sequenced
//   e.handle_multi( 8, 2, 1, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 8 );
//
//   //create gap and sleep for longer than k_gap_timeout to trigger a timeout.
//   //st_gap + ev_gap_timeout / ta_request_replay == st_recovery
//   e.handle_single( 10, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_gap" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 8 );
//
//   std::this_thread::sleep_for( std::chrono::milliseconds( 300 ) );
//
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//
//   //reset machine
//   e.reset( 0 );
//   h.seqnum_ = 0;
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//
//   //gap and sleep for recovery
//   e.handle_single( 1, data.data(), data.size() );
//   e.handle_multi( 16, 2, 1, data.data(), data.size() );
//
//   std::this_thread::sleep_for( std::chrono::milliseconds( 300 ) );
//
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
//
//   //st_recovery + ev_ordered_single / ta_publish_and_process_single == st_recovery
//   e.handle_single( 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 2 );
//
//   //st_recovery + ev_ordered_multi / ta_enqueue_and_process_multi == st_recovery
//   e.handle_multi( 3, 2, 1, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 2 );
//
//   //st_recovery + ev_ordered_multi [gc_has_all_chunks] / ta_publish_and_process_multi == st_recovery
//   e.handle_multi( 3, 2, 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 3 );
//
//   //stale recovery message
//   rs->send_data( 1, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 3 );
//
//   //st_recovery + ev_unordered_single / ta_enqueue_unordered_single == st_recovery
//   e.handle_single( 5, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 3 );
//
//   //st_recovery + ev_ordered_single / ta_publish_and_process_single == st_recovery
//   // -> st_recovery + ev_queue_processed == st_recovery
//   rs->send_data( 4, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 5 );
//
//   //full multi message out of order, then fill gap
//   //st_recovery + ev_unordered_multi / ta_enqueue_unordered_multi == st_recovery
//   // -> st_recovery + ev_queue_processed = st_recovery
//   e.handle_multi( 7, 2, 2, data.data(), data.size() );
//   e.handle_multi( 7, 2, 1, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 5 );
//
//   rs->send_data( 6, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 7 );
//
//   //interleave multi chunks (in order) and gap fill
//   e.handle_multi( 9, 2, 1, data.data(), data.size() );
//   rs->send_data( 8, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 8 );
//
//   e.handle_multi( 9, 2, 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 9 );
//
//   //interleave multi chunks (out of order) and gap fill
//   e.handle_multi( 11, 2, 2, data.data(), data.size() );
//   rs->send_data( 10, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 10 );
//
//   e.handle_multi( 11, 2, 1, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 11 );
//
//   //ordered_multi + same seqnum ordered_single from recovery
//   //chunks become stale after publishing and are removed from  assembly queue
//   e.handle_multi( 12, 3, 1, data.data(), data.size() );
//   e.handle_multi( 12, 3, 2, data.data(), data.size() );
//   rs->send_data( 12, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 12 );
//
//   //next ordered multi to make sure the stale 12/3/x chunks were cleared
//   e.handle_multi( 13, 2, 1, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 12 );
//
//   e.handle_multi( 13, 2, 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 13 );
//
//   //unordered_multi + same seqnum ordered_single from recovery
//   //chunks become stale after publishing and are removed from gap queue
//   e.handle_multi( 14, 3, 2, data.data(), data.size() );
//   e.handle_multi( 14, 3, 3, data.data(), data.size() );
//   rs->send_data( 14, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 14 );
//
//   //next ordered multi to make sure the stale 14/3/x chunks were cleared
//   e.handle_multi( 15, 2, 1, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 14 );
//
//   e.handle_multi( 15, 2, 2, data.data(), data.size() );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 15 );
//
//   //close gap
//   rs->send_data( 16, data.data(), data.size() );
//
//   //sleep to trigger recovery timeout
//   //st_recovery + ev_recovery_failed [gc_replay_sequenced] == st_sequenced
//   std::this_thread::sleep_for( std::chrono::milliseconds( 5100 ) );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 16 );
//
//   //reset machine
//   e.reset( 0 );
//   h.seqnum_ = 0;
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//
//   //gap and sleep for recovery
//   e.handle_single( 1, data.data(), data.size() );
//   e.handle_single( 3, data.data(), data.size() );
//
//   std::this_thread::sleep_for( std::chrono::milliseconds( 300 ) );
//
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
//
//   e.handle_single( 2, data.data(), data.size() );
//   e.handle_single( 3, data.data(), data.size() );
//   e.handle_single( 6, data.data(), data.size() );
//
//   //sleep to trigger recovery timeout
//   //st_recovery + ev_recovery_failed / ta_reset_on_failure == st_sequenced
//   //from timeout
//   std::this_thread::sleep_for( std::chrono::milliseconds( 5100 ) );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//
//   //reset machine
//   e.reset( 0 );
//   h.seqnum_ = 0;
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//
//   //gap and sleep for recovery
//   e.handle_single( 1, data.data(), data.size() );
//   e.handle_single( 3, data.data(), data.size() );
//
//   std::this_thread::sleep_for( std::chrono::milliseconds( 300 ) );
//
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
//
//   //st_recovery + ev_recovery_failed / ta_reset_on_failure == st_sequenced
//   //from failed ack
//   rs->send_ack( recovery_service::ApplRespType_RejectedOrPartial, recovery_service::ApplRespError_None );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   h.seqnum_ = 0;
//
//   //gap and sleep for recovery
//   e.handle_single( 1, data.data(), data.size() );
//   e.handle_single( 3, data.data(), data.size() );
//
//   std::this_thread::sleep_for( std::chrono::milliseconds( 300 ) );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
//
//   //st_recovery + ev_recovery_failed / ta_reset_on_failure == st_sequenced
//   //from failed report
//   rs->send_report( recovery_service::ApplReportType_Error, recovery_service::ApplRespError_None );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   h.seqnum_ = 0;
//
//   //reset machine
//   e.reset( 0 );
//   h.seqnum_ = 0;
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//
//   //gap and sleep for recovery
//   e.handle_single( 1, data.data(), data.size() );
//   e.handle_single( 3, data.data(), data.size() );
//
//   std::this_thread::sleep_for( std::chrono::milliseconds( 300 ) );
//
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
//
//   //st_recovery + ev_recovery_succeeded [gc_queue_sequenced] == st_sequenced
//   rs->send_ack( recovery_service::ApplRespType_Accepted, recovery_service::ApplRespError_None );
//   rs->send_data( 2, data.data(), data.size() );
//   rs->send_report( recovery_service::ApplReportType_Success, recovery_service::ApplRespError_None );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 3 );
//
//   //reset machine
//   e.reset( 0 );
//   h.seqnum_ = 0;
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//
//   //gap and sleep for recovery
//   e.handle_single( 1, data.data(), data.size() );
//   e.handle_single( 3, data.data(), data.size() );
//
//   std::this_thread::sleep_for( std::chrono::milliseconds( 300 ) );
//
//   BOOST_REQUIRE_EQUAL( e.state(), "st_recovery" );
//   BOOST_REQUIRE_EQUAL( h.seqnum_, 1 );
//
//   //st_recovery + ev_recovery_succeeded / ta_reset_on_failure == st_sequenced
//   rs->send_ack( recovery_service::ApplRespType_Accepted, recovery_service::ApplRespError_None );
//   rs->send_data( 2, data.data(), data.size() );
//   e.handle_single( 5, data.data(), data.size() );
//   rs->send_report( recovery_service::ApplReportType_Success, recovery_service::ApplRespError_None );
//   BOOST_REQUIRE_EQUAL( e.state(), "st_sequenced" );
//
//   e.reset( 0 );
//   work.reset();
//   t.join();
// }

BOOST_AUTO_TEST_SUITE_END()

