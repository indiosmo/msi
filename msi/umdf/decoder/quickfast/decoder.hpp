#ifndef APOENA_MSI_UMDF_DECODER_QUICKFAST_DECODER_HPP
#define APOENA_MSI_UMDF_DECODER_QUICKFAST_DECODER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <functional>
#include <Codecs/Decoder.h>
#include <Codecs/DataSourceBuffer.h>
#include <Codecs/XMLTemplateParser.h>
#include <Codecs/TemplateRegistry_fwd.h>
#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_export.hpp>
#include <msi/umdf/decoder/quickfast/builder_selector.hpp>
#include <msi/umdf/decoder/quickfast/heartbeat_builder.hpp>
#include <msi/umdf/decoder/quickfast/incremental_builder.hpp>
#include <msi/umdf/decoder/quickfast/news_builder.hpp>
#include <msi/umdf/decoder/quickfast/security_list_builder.hpp>
#include <msi/umdf/decoder/quickfast/security_status_builder.hpp>
#include <msi/umdf/decoder/quickfast/sequence_reset_builder.hpp>
#include <msi/umdf/decoder/quickfast/snapshot_builder.hpp>

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

class UMDF_DECODER_QUICKFAST_Export decoder
{
public:

  explicit decoder( const std::string& template_path );

  void register_on_heartbeat_callback( heartbeat_builder::on_message_t callback );
  void register_on_incremental_callback( incremental_builder::on_message_t callback );
  void register_on_news_callback( news_builder::on_message_t callback );
  void register_on_security_list_callback( security_list_builder::on_message_t callback );
  void register_on_security_status_callback( security_status_builder::on_message_t callback );
  void register_on_sequence_reset_callback( sequence_reset_builder::on_message_t callback );
  void register_on_snapshot_callback( snapshot_builder::on_message_t callback );

  void decode( const unsigned char* data, std::size_t length );

private:
  void on_heartbeat( const messages::heartbeat& message );
  void on_incremental( const messages::incremental& message );
  void on_news( const messages::news& message );
  void on_security_list( const messages::security_list& message );
  void on_security_status( const messages::security_status& message );
  void on_sequence_reset( const messages::sequence_reset& message );
  void on_snapshot( const messages::snapshot& message );

  heartbeat_builder::on_message_t on_heartbeat_;
  incremental_builder::on_message_t on_incremental_;
  news_builder::on_message_t on_news_;
  security_list_builder::on_message_t on_security_list_;
  security_status_builder::on_message_t on_security_status_;
  sequence_reset_builder::on_message_t on_sequence_reset_;
  snapshot_builder::on_message_t on_snapshot_;

  std::unique_ptr<QuickFAST::Codecs::Decoder> decoder_;
  QuickFAST::Codecs::XMLTemplateParser template_parser_;
  QuickFAST::Codecs::TemplateRegistryPtr template_registry_;

  builder_selector builder_;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_DECODER_QUICKFAST_DECODER_HPP */
