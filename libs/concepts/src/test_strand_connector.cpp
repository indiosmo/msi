#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN concepts
#include <boost/test/unit_test.hpp>

#include <string>
#include <functional>
#include <thread>
#include <iostream>
#include <memory>
#include <boost/asio.hpp>

// Use a strand as a queue between threads.
// Connector receives value from one thread and posts it to another.

namespace
{

struct mock
{
  mock()
    : strand( io_service )
  {

  }

  void post()
  {
    std::string message( "scope" );

    std::cout << "post '" << message << "' thread " << std::this_thread::get_id() << std::endl;
    strand.post( std::bind( &mock::handler_val, this, message ) ); //ok, copied
    strand.post( std::bind( &mock::handler_ref, this, message ) ); //ok, copied

    // Will try to dereference null pointer in handler.
    //strand.post(std::bind(&Mock::handler_ptr, this, &message));

    // An alternative to handlers that take pointers is to have a bridge handler that
    // takes a shared_ptr. When the post() stores the handler it will increment the shared_ptr
    // so we can be sure that the pointer will still be valid when the handler is called.
    auto message_ptr = std::make_shared<std::string>( message );
    strand.post( std::bind( &mock::handler_ptr_bridge, this, message_ptr ) ); //ok, shared_ptr outlives the scope

    // Lambda as a pointer handler bridge.
    auto bridge = [this]( std::shared_ptr<std::string> msg )
    {
      handler_ptr( msg.get() );
    };
    strand.post( std::bind( bridge, message_ptr ) );
  }

  void handler_val( std::string message )
  {
    std::cout << "handler_val '" << message << "' thread " << std::this_thread::get_id() << std::endl;
  }

  // This works even if message goes out of scope in the caller since a copy is made by strand::post().
  void handler_ref( const std::string& message )
  {
    std::cout << "handler_ref '" << message << "' thread " << std::this_thread::get_id() << std::endl;
  }

  // This will fail unless the caller makes sure that the pointer outlives the handler call.
  void handler_ptr( std::string* message )
  {
    std::cout << "handler_ptr '" << *message << "' thread " << std::this_thread::get_id() << std::endl;
  }

  // Bridge handler for calling handlers that take pointers
  void handler_ptr_bridge( std::shared_ptr<std::string> message )
  {
    handler_ptr( message.get() );
  }

  void run()
  {
    work.reset( new boost::asio::io_service::work( io_service ) );
    io_service.run();
  }

  void stop()
  {
    work.reset();
  }

  boost::asio::io_service io_service;
  std::unique_ptr<boost::asio::io_service::work> work;
  boost::asio::strand strand;
};

}

BOOST_AUTO_TEST_SUITE ( suite_strand_connector )

BOOST_AUTO_TEST_CASE( test_strand_parameter_scope )
{
  // Test how strand behaves when arguments go out of scope.
  mock m;
  m.post();

  std::thread t( std::bind( &mock::run, &m ) );

  m.stop();
  t.join();
}

BOOST_AUTO_TEST_SUITE_END()

