#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN marketdata_common_test
#include <boost/test/unit_test.hpp>

#include <msi/marketdata/common/security_list.hpp>

namespace
{
using namespace apoena::msi::marketdata;
}

BOOST_AUTO_TEST_SUITE( suite_marketdata_common )

BOOST_AUTO_TEST_CASE( test_security_list )
{
  security_list s;

  s.add_instrument( "test", 1234, "g1" );

  auto symbol = s.get_symbol( 1234 );
  BOOST_REQUIRE( symbol.first );
  BOOST_CHECK_EQUAL( *symbol.second, "test" );

  symbol = s.get_symbol( 1 );
  BOOST_CHECK( !symbol.first );

  auto secid = s.get_security_id( "test" );
  BOOST_REQUIRE( secid.first );
  BOOST_CHECK_EQUAL( secid.second, 1234 );

  secid = s.get_security_id( "x" );
  BOOST_CHECK( !secid.first );

  auto group = s.get_group( 1234 );
  BOOST_REQUIRE( group.first );
  BOOST_CHECK_EQUAL( *group.second, "g1" );

  group = s.get_group( 1 );
  BOOST_CHECK( !group.first );

  s.update_instrument( 1234, "g2" );
  group = s.get_group( 1234 );
  BOOST_REQUIRE( group.first );
  BOOST_CHECK_EQUAL( *group.second, "g2" );

  s.add_instrument( "test2", 2345, "g2" );

  auto members = s.get_group_members( "g2" );
  BOOST_REQUIRE( members.first );
  BOOST_CHECK_EQUAL( members.second->size(), 2 );
  BOOST_CHECK_EQUAL( members.second->count( 1234 ), 1 );
  BOOST_CHECK_EQUAL( members.second->count( 2345 ), 1 );

  s.remove_instrument( 2345 );

  symbol = s.get_symbol( 2345 );
  BOOST_CHECK( !symbol.first );

  secid = s.get_security_id( "test2" );
  BOOST_CHECK( !secid.first );

  group = s.get_group( 2345 );
  BOOST_CHECK( !group.first );

  members = s.get_group_members( "g2" );
  BOOST_REQUIRE( members.first );
  BOOST_CHECK_EQUAL( members.second->size(), 1 );
  BOOST_CHECK_EQUAL( members.second->count( 1234 ), 1 );
  BOOST_CHECK_EQUAL( members.second->count( 2345 ), 0 );
}

BOOST_AUTO_TEST_SUITE_END()
