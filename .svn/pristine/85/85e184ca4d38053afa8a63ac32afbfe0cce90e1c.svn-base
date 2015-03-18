#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN concepts
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <boost/container/flat_set.hpp>

#include <msi/umdf/receiver/chunk.hpp>


BOOST_AUTO_TEST_SUITE( suite_flat_set )

BOOST_AUTO_TEST_CASE( test_flat_set_no_hint )
{
  using namespace apoena::msi::umdf::receiver;
  boost::container::flat_set<chunk> queue_;

  LARGE_INTEGER f, start, end;
  QueryPerformanceFrequency( &f );

  double freq = double( f.QuadPart );

  unsigned int messages = 1 * 1000 * 1000;
  const unsigned char data[5] = { 'a', 'b', 'c', 'd', 'e' };

  QueryPerformanceCounter( &start );

  for ( unsigned int i = 1; i <= messages; ++i )
  {
    queue_.insert( chunk( i, 1, 1, data, 5 ) );
  }

  QueryPerformanceCounter( &end );

  double time = double( end.QuadPart - start.QuadPart ) / freq;
  double mps = messages / time;
  std::cout << "Without hint: " << messages << " messages in " << time
            << "s. " << mps << " messages/s" << std::endl;
}


BOOST_AUTO_TEST_CASE( test_flat_set_hint )
{
  using namespace apoena::msi::umdf::receiver;
  boost::container::flat_set<chunk> queue_;

  LARGE_INTEGER f, start, end;
  QueryPerformanceFrequency( &f );

  double freq = double( f.QuadPart );

  unsigned int messages = 1 * 1000 * 1000;
  const unsigned char data[5] = { 'a', 'b', 'c', 'd', 'e' };

  QueryPerformanceCounter( &start );

  for ( unsigned int i = 1; i <= messages; ++i )
  {
    queue_.insert( queue_.end(), chunk( i, 1, 1, data, 5 ) );
  }

  QueryPerformanceCounter( &end );

  double time = double( end.QuadPart - start.QuadPart ) / freq;
  double mps = messages / time;
  std::cout << "With hint: " << messages << " messages in " << time
            << "s. " << mps << " messages/s" << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()

