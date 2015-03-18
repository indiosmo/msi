#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN logging_test
#include <boost/test/unit_test.hpp>

#include <memory>
#include <msi/logging/log.hpp>
#include <msi/logging/file_logger_factory.hpp>
#include <msi/logging/console_logger_factory.hpp>

BOOST_AUTO_TEST_SUITE( suite_logging )

BOOST_AUTO_TEST_CASE( test_severity )
{
  using namespace apoena::msi::logging;

  std::shared_ptr<console_logger_factory> factory( new console_logger_factory( Info ) );

  log::register_factory( factory );

  auto logger = log::get_logger();
  logger->log( Debug, "Severity disabled" );
  logger->log( Info, "Severity enabled %s", logger->log_level() );
}

BOOST_AUTO_TEST_CASE( test_NullLogger )
{
  using namespace apoena::msi::logging;

  //get logger without registering, should result in a null logger.
  auto logger = log::get_logger();
  logger->log( Info, "NullTest" );
}

BOOST_AUTO_TEST_CASE( test_console_logger )
{
  using namespace apoena::msi::logging;

  std::shared_ptr<console_logger_factory> factory( new console_logger_factory( Info ) );

  log::register_factory( factory );

  auto logger = log::get_logger();
  logger->log( Info, "ConsoleLogger" );
}

BOOST_AUTO_TEST_CASE( test_file_logger )
{
  using namespace apoena::msi::logging;

  std::shared_ptr<file_logger_factory> factory( new file_logger_factory( Info, "log.txt" ) );
  factory->open_file();

  log::register_factory( factory );

  auto logger = log::get_logger();
  logger->log( Info, "FileLogger" );
}

#ifdef _WIN32

BOOST_AUTO_TEST_CASE( test_performance )
{
  using namespace apoena::msi::logging;

  auto logger = log::get_logger();

  LARGE_INTEGER li, start, end;
  QueryPerformanceFrequency( &li );
  double freq = double( li.QuadPart );

  int messages = 100000;

  QueryPerformanceCounter( &start );

  for ( int i = 0; i < messages; ++i )
  {
    //TODO this is a null logger, and error is ignored by default
    //change level and test again. Test passing the string by copy,
    // or const reference, or rvalue reference.
    logger->log( Error, "Test %s %d %f", "string", 20, 15.25 );
  }

  QueryPerformanceCounter( &end );

  double time = ( double )( end.QuadPart - start.QuadPart ) / freq;
  double msg_per_sec = messages / time;

  std::cout << "Took " << time << "s. " << msg_per_sec << " msg/sec." << std::endl;
}

#endif /* _WIN32 */

BOOST_AUTO_TEST_SUITE_END()
