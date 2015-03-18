#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp>
#define BOOST_TEST_NO_MAIN umdf_quickfast_decoder_test
#include <boost/test/unit_test.hpp>

#include <functional>
#include <Codecs/Encoder.h>
#include <Codecs/Decoder.h>
#include <Codecs/DataDestination.h>
#include <Codecs/DataSourceString.h>
#include <Common/Types.h>
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

#include <msi/decimal/decimal.hpp>
#include <msi/umdf/messages/field_id.hpp>
#include <msi/umdf/decoder/quickfast/builder_selector.hpp>
#include <msi/umdf/messages/sequence_reset.hpp>
#include <msi/umdf/decoder/quickfast/sequence_reset_builder.hpp>

namespace
{

using namespace apoena::msi::umdf::decoder::quickfast;
using namespace apoena::msi::umdf::messages;
using namespace QuickFAST;

struct message_container
{
  void on_message( const sequence_reset& message )
  {
    message_ = message;
  }

  sequence_reset message_;
};

}

BOOST_AUTO_TEST_SUITE( suite_sequence_reset_builder )

BOOST_AUTO_TEST_CASE( test_builder_122 )
{
  std::string xml( std::getenv( "MSI_ROOT" ) );
  xml += "/resources/templates-PUMA.xml";
  std::ifstream template_file( xml, std::ifstream::binary );

  BOOST_REQUIRE( template_file.good() ) ;

  Codecs::XMLTemplateParser parser;
  Codecs::TemplateRegistryPtr template_registry = parser.parse( template_file );

  Codecs::Encoder encoder( template_registry );
  Codecs::DataDestination destination;

  typedef Messages::FieldIdentity id;

  Messages::Message msg( template_registry->maxFieldCount() );

  id msgtype_id( "MsgType" );
  id msgseqnum_id( "MsgSeqNum" );
  id sendingtime_id( "SendingTime" );
  id applverid_id( "ApplVerID" );
  id newseqno_id( "NewSeqNo" );

  msg.addField( msgtype_id, Messages::FieldAscii::create( "4" ) );
  msg.addField( msgseqnum_id, Messages::FieldUInt32::create( 34 ) );
  msg.addField( sendingtime_id, Messages::FieldUInt64::create( 52 ) );
  msg.addField( applverid_id, Messages::FieldAscii::create( "9" ) );
  msg.addField( newseqno_id, Messages::FieldUInt32::create( 36 ) );

  encoder.encodeMessage( destination, 122, msg );
  std::string fast_string;
  destination.toString( fast_string );
  destination.clear();

  Codecs::Decoder decoder( template_registry );

  message_container container;
  auto builder = std::make_shared<sequence_reset_builder>();
  builder->register_on_message_callback( std::bind( &message_container::on_message, &container, std::placeholders::_1 ) );

  builder_selector selector;
  selector.add_builder( "4", builder );

  Codecs::DataSourceString source( fast_string );
  decoder.reset();
  decoder.decodeMessage( source, selector );

  sequence_reset& m = container.message_;

  BOOST_CHECK( m.MsgType().first );
  BOOST_CHECK_EQUAL( m.MsgType().second, "4" );
  BOOST_CHECK( m.MsgSeqNum().first );
  BOOST_CHECK_EQUAL( m.MsgSeqNum().second, 34 );
  BOOST_CHECK( m.SendingTime().first );
  BOOST_CHECK_EQUAL( m.SendingTime().second, 52 );
  BOOST_CHECK( m.ApplVerID().first );
  BOOST_CHECK_EQUAL( m.ApplVerID().second, "9" );
  BOOST_CHECK( m.NewSeqNo().first );
  BOOST_CHECK_EQUAL( m.NewSeqNo().second, 36 );

}


BOOST_AUTO_TEST_SUITE_END()
