#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN concepts
#include <boost/test/unit_test.hpp>

#include <string>
#include <iostream>
#include <utility>
#include <boost/container/flat_set.hpp>
#include <msi/umdf/common/typedefs.hpp>
#include <msi/umdf/receiver/chunk.hpp>

namespace
{
using namespace apoena::msi::umdf;
using namespace apoena::msi::umdf::receiver;

struct container
{
  void insert( chunk&& chunk )
  {
    c.insert( std::move( chunk ) );
  }

  void emplace( seqnum_t seqnum, const unsigned char* data, std::size_t length )
  {
    c.emplace( seqnum, 1, 1, data, length );
  }

  boost::container::flat_set<chunk> c;
};
}

BOOST_AUTO_TEST_SUITE( suite_move_semantics )

BOOST_AUTO_TEST_CASE( test_move_semantics )
{
  LARGE_INTEGER f, start, end;
  QueryPerformanceFrequency( &f );
  double freq = double( f.QuadPart );

  unsigned int messages = 1 * 1000 * 1000;
  std::vector<uint8_t> data;

  for ( unsigned int i = 0; i < 300; ++i )
  {
    data.push_back( 'a' );
  }

  container c;

  QueryPerformanceCounter( &start );

  for ( unsigned int i = 0; i < messages; ++i )
  {
    c.insert( chunk( i, 1, 1, data.data() , data.size() ) );
  }

  QueryPerformanceCounter( &end );

  double time = double( end.QuadPart - start.QuadPart ) / freq;
  double mps = messages / time;
  std::cout << "Inserted: " << messages << " messages in " << time
            << "s. " << mps << " messages/s" << std::endl;
}

BOOST_AUTO_TEST_CASE( test_emplace )
{
  LARGE_INTEGER f, start, end;
  QueryPerformanceFrequency( &f );
  double freq = double( f.QuadPart );

  unsigned int messages = 1 * 1000 * 1000;
  std::vector<uint8_t> data;

  for ( unsigned int i = 0; i < 300; ++i )
  {
    data.push_back( 'a' );
  }

  container c;

  QueryPerformanceCounter( &start );

  for ( unsigned int i = 0; i < messages; ++i )
  {
    c.emplace( i, data.data(), data.size() );
  }

  QueryPerformanceCounter( &end );

  double time = double( end.QuadPart - start.QuadPart ) / freq;
  double mps = messages / time ;
  std::cout << "Emplaced: " << messages << " messages in " << time
            << "s. " << mps << " messages/s" << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()

