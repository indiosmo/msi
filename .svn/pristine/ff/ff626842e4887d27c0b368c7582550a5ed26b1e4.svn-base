#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN concepts
#include <boost/test/unit_test.hpp>

#include <string>
#include <iostream>

namespace
{

struct bid
{
  const std::string val = "BID";
};

struct ask
{
  const std::string  val = "ASK";
};

class topic
{
public:
  void handle_bid( const bid& msg )
  {
    std::cout << msg.val << std::endl;
  }

  void handle_ask( const ask& msg )
  {
    std::cout << msg.val << std::endl;
  }
};

class dispatcher
{
public:

  template<typename MESSAGE_T, void( topic::*F )( const MESSAGE_T& )>
  void handle_message( const MESSAGE_T& msg )
  {
    ( topic_.*F )( msg );
  }

private:
  topic topic_;
};

}

BOOST_AUTO_TEST_SUITE( suite_template_handler )

BOOST_AUTO_TEST_CASE( test_template_handler )
{
  bid b;
  ask a;
  dispatcher d;

  std::function<void( const bid& )> bid_handler = std::bind(
        &dispatcher::handle_message<bid, &topic::handle_bid>, &d, std::placeholders::_1 );

  std::function<void( const ask& )> ask_handler = std::bind(
        &dispatcher::handle_message<ask, &topic::handle_ask>, &d, std::placeholders::_1 );

  bid_handler( b );
  ask_handler( a );
}

BOOST_AUTO_TEST_SUITE_END()
