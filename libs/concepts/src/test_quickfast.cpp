#include <msi/msi_pch.hpp>
#define BOOST_TEST_NO_MAIN concepts
#include <boost/test/unit_test.hpp>

#include <Application/QuickFAST.h>
#include <Codecs/Encoder.h>
#include <Codecs/DataDestination.h>
#include <Codecs/DataSourceString.h>
#include <Codecs/SingleMessageConsumer.h>
#include <Codecs/GenericMessageBuilder.h>
#include <Messages/Message.h>
#include <Messages/FieldIdentity.h>
#include <Messages/FieldInt32.h>
#include <Messages/FieldUInt32.h>
#include <Messages/FieldInt64.h>
#include <Messages/FieldUInt64.h>
#include <Messages/FieldAscii.h>
#include <Messages/FieldByteVector.h>
#include <Messages/FieldDecimal.h>
#include <Messages/FieldGroup.h>
#include <Messages/FieldSequence.h>
#include <Messages/FieldUtf8.h>
#include <Messages/Sequence.h>
#include <Messages/MessageFormatter.h>

namespace
{
using namespace QuickFAST;
}

BOOST_AUTO_TEST_SUITE( suite_quickfast )

BOOST_AUTO_TEST_CASE( test_quickfast_performance )
{
  std::string xml( std::getenv( "MSI_ROOT" ) );
  xml += "/resources/templates-PUMA.xml";
  std::ifstream template_file( xml, std::ifstream::binary );

  BOOST_REQUIRE( template_file.good() );

  Messages::MessageFormatter formatter( std::cout );

  Codecs::XMLTemplateParser parser;
  Codecs::TemplateRegistryPtr template_registry =
    parser.parse( template_file );

  Codecs::Encoder encoder( template_registry );
  Codecs::DataDestination destination;

  Messages::Message msg( template_registry->maxFieldCount() );

  typedef Messages::FieldIdentity id;

  id seqnum_id( "MsgSeqNum" );
  id sendingtime_id( "SendingTime" );

  id mdentries_id( "MDEntries" );
  id mdupdateaction_id( "MDUpdateAction" );
  id mdentrytype_id( "MDEntryType" );
  id securityid_id( "SecurityID" );
  id rptseq_id( "RptSeq" );
  id mdentrypx_id( "MDEntryPx" );
  id mdentrytime_id( "MDEntryTime" );
  id mdentrysize_id( "MDEntrySize" );
  id mdentrypositionno( "MDEntryPositionNo" );

  msg.addField( seqnum_id, Messages::FieldUInt32::create( 123456 ) );
  msg.addField( sendingtime_id, Messages::FieldUInt64::create( 20140101150932 ) );

  Messages::SequencePtr mdEntries( new Messages::Sequence( mdentries_id, 2 ) );

  Messages::FieldSetPtr entry1( new Messages::FieldSet( 8 ) );
  entry1->addField( mdupdateaction_id, Messages::FieldUInt32::create( 0 ) );
  entry1->addField( mdentrytype_id, Messages::FieldAscii::create( "0" ) );
  entry1->addField( securityid_id, Messages::FieldUInt64::create( 645312548 ) );
  entry1->addField( rptseq_id, Messages::FieldUInt32::create( 523 ) );
  entry1->addField( mdentrypx_id, Messages::FieldDecimal::create( Decimal( 1050, -2 ) ) );
  entry1->addField( mdentrytime_id, Messages::FieldUInt32::create( 152532 ) );
  entry1->addField( mdentrysize_id, Messages::FieldInt64::create( 250000 ) );
  entry1->addField( mdentrypositionno, Messages::FieldUInt32::create( 1 ) );

  Messages::FieldSetPtr entry2( new Messages::FieldSet( 8 ) );
  entry2->addField( mdupdateaction_id, Messages::FieldUInt32::create( 0 ) );
  entry2->addField( mdentrytype_id, Messages::FieldAscii::create( "1" ) );
  entry2->addField( securityid_id, Messages::FieldUInt64::create( 645312548 ) );
  entry2->addField( rptseq_id, Messages::FieldUInt32::create( 523 ) );
  entry2->addField( mdentrypx_id, Messages::FieldDecimal::create( Decimal( 1051, -2 ) ) );
  entry2->addField( mdentrytime_id, Messages::FieldUInt32::create( 152532 ) );
  entry2->addField( mdentrysize_id, Messages::FieldInt64::create( 250000 ) );
  entry2->addField( mdentrypositionno, Messages::FieldUInt32::create( 1 ) );

  mdEntries->addEntry( entry1 );
  mdEntries->addEntry( entry2 );

  msg.addField( mdentries_id, Messages::FieldSequence::create( mdEntries ) );

  encoder.encodeMessage( destination, 145, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );
  Codecs::SingleMessageConsumer consumer;
  Codecs::GenericMessageBuilder builder( consumer );

  LARGE_INTEGER f, start, end;
  QueryPerformanceFrequency( &f );

  double freq = double( f.QuadPart );
  unsigned int messages = 200 * 1000;

  QueryPerformanceCounter( &start );

  for ( unsigned int i = 1; i <= messages; ++i )
  {
    Codecs::DataSourceString source( fast_string );
    //decoder.reset();
    decoder.decodeMessage( source, builder );
  }

  QueryPerformanceCounter( &end );

  double time = double( end.QuadPart - start.QuadPart ) / freq;
  double mps = messages / time;
  std::cout << messages << " messages in " << time << "s. " << std::endl;
  std::cout << mps << " messages/s" << std::endl;
  std::cout << time * 1000.0 * 1000.0 / messages << "us/msg" << std::endl;

  /*
  Messages::Message& decoded_message = consumer.message();
  formatter.formatMessage(decoded_message);
  std::cout << std::endl;
  */

}

BOOST_AUTO_TEST_SUITE_END()

