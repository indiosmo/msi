#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp>
#include <msi/umdf/decoder/quickfast/decoder.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace decoder
{
namespace quickfast
{

decoder::decoder( const std::string& template_path )
{
  std::ifstream template_file( template_path, std::ifstream::binary );

  if ( !template_file.good() )
  {
    std::stringstream ss;
    ss << "Failed to open template file " << template_path;
    throw std::runtime_error( ss.str() );
  }

  template_registry_ = template_parser_.parse( template_file );
  template_file.close();

  decoder_ = std::make_unique<QuickFAST::Codecs::Decoder>( template_registry_ );

  auto builder_heartbeat = std::make_shared<heartbeat_builder>();
  builder_heartbeat->register_on_message_callback( std::bind(
        &decoder::on_heartbeat, this, std::placeholders::_1 ) );
  builder_.add_builder( messages::message_type::heartbeat, builder_heartbeat );

  auto builder_incremental = std::make_shared<incremental_builder>();
  builder_incremental->register_on_message_callback( std::bind(
        &decoder::on_incremental, this, std::placeholders::_1 ) );
  builder_.add_builder( messages::message_type::incremental, builder_incremental );

  auto builder_news = std::make_shared<news_builder>();
  builder_news->register_on_message_callback( std::bind(
        &decoder::on_news, this, std::placeholders::_1 ) );
  builder_.add_builder( messages::message_type::news, builder_news );

  auto builder_security_list = std::make_shared<security_list_builder>();
  builder_security_list->register_on_message_callback( std::bind(
        &decoder::on_security_list, this, std::placeholders::_1 ) );
  builder_.add_builder( messages::message_type::security_list, builder_security_list );

  auto builder_security_status = std::make_shared<security_status_builder>();
  builder_security_status->register_on_message_callback( std::bind(
        &decoder::on_security_status, this, std::placeholders::_1 ) );
  builder_.add_builder( messages::message_type::security_status, builder_security_status );

  auto builder_sequence_reset = std::make_shared<sequence_reset_builder>();
  builder_sequence_reset->register_on_message_callback( std::bind(
        &decoder::on_sequence_reset, this, std::placeholders::_1 ) );
  builder_.add_builder( messages::message_type::sequence_reset, builder_sequence_reset );

  auto builder_snapshot = std::make_shared<snapshot_builder>();
  builder_snapshot->register_on_message_callback( std::bind(
        &decoder::on_snapshot, this, std::placeholders::_1 ) );
  builder_.add_builder( messages::message_type::snapshot, builder_snapshot );
}

void
decoder::register_on_heartbeat_callback( heartbeat_builder::on_message_t callback )
{
  on_heartbeat_ = callback;
}

void
decoder::register_on_incremental_callback( incremental_builder::on_message_t callback )
{
  on_incremental_ = callback;
}

void
decoder::register_on_news_callback( news_builder::on_message_t callback )
{
  on_news_ = callback;
}

void
decoder::register_on_security_list_callback( security_list_builder::on_message_t callback )
{
  on_security_list_ = callback;
}

void
decoder::register_on_security_status_callback( security_status_builder::on_message_t callback )
{
  on_security_status_ = callback;
}

void
decoder::register_on_sequence_reset_callback( sequence_reset_builder::on_message_t callback )
{
  on_sequence_reset_ = callback;
}

void
decoder::register_on_snapshot_callback( snapshot_builder::on_message_t callback )
{
  on_snapshot_ = callback;
}

void
decoder::decode( const unsigned char* data, std::size_t length )
{
  QuickFAST::Codecs::DataSourceBuffer source( data, length );
  decoder_->decodeMessage( source, builder_ );
}

void
decoder::on_heartbeat( const messages::heartbeat& message )
{
  if ( on_heartbeat_ )
  {
    on_heartbeat_( message );
  }
}

void
decoder::on_incremental( const messages::incremental& message )
{
  if ( on_incremental_ )
  {
    on_incremental_( message );
  }
}

void
decoder::on_news( const messages::news& message )
{
  if ( on_news_ )
  {
    on_news_( message );
  }
}

void
decoder::on_security_list( const messages::security_list& message )
{
  if ( on_security_list_ )
  {
    on_security_list_( message );
  }
}

void
decoder::on_security_status( const messages::security_status& message )
{
  if ( on_security_status_ )
  {
    on_security_status_( message );
  }
}

void
decoder::on_sequence_reset( const messages::sequence_reset& message )
{
  if ( on_sequence_reset_ )
  {
    on_sequence_reset_( message );
  }
}

void
decoder::on_snapshot( const messages::snapshot& message )
{
  if ( on_snapshot_ )
  {
    on_snapshot_( message );
  }
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
