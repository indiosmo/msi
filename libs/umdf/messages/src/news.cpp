#include <msi/msi_pch.hpp>
#include <msi/umdf/messages/news.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

void
news::relatedsym::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint64_t>
news::relatedsym::SecurityID() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_SecurityID], SecurityID_ );
}

void
news::relatedsym::set_SecurityID( uint64_t val )
{
  SecurityID_ = val;
  presence_map_[ix_SecurityID] = true;
}

std::pair<bool, uint32_t>
news::relatedsym::SecurityIDSource() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SecurityIDSource], SecurityIDSource_ );
}

void
news::relatedsym::set_SecurityIDSource( uint32_t val )
{
  SecurityIDSource_ = val;
  presence_map_[ix_SecurityIDSource] = true;
}

std::pair<bool, const std::string&>
news::relatedsym::SecurityExchange() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityExchange], SecurityExchange_ );
}

void
news::relatedsym::set_SecurityExchange( const std::string& val )
{
  SecurityExchange_ = val;
  presence_map_[ix_SecurityExchange] = true;
}

void
news::routingids::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint32_t>
news::routingids::RoutingType() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_RoutingType], RoutingType_ );
}

void
news::routingids::set_RoutingType( uint32_t val )
{
  RoutingType_ = val;
  presence_map_[ix_RoutingType] = true;
}

std::pair<bool, const std::string&>
news::routingids::RoutingID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_RoutingID], RoutingID_ );
}

void
news::routingids::set_RoutingID( const std::string& val )
{
  RoutingID_ = val;
  presence_map_[ix_RoutingID] = true;
}

void
news::linesoftext::reset()
{
  presence_map_.reset();
}

std::pair<bool, const std::string&>
news::linesoftext::Text() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_Text], Text_ );
}

void
news::linesoftext::set_Text( const std::string& val )
{
  Text_ = val;
  presence_map_[ix_Text] = true;
}

std::pair<bool, uint32_t>
news::linesoftext::EncodedTextLen() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_EncodedTextLen], EncodedTextLen_ );
}

void
news::linesoftext::set_EncodedTextLen( uint32_t val )
{
  EncodedTextLen_ = val;
  presence_map_[ix_EncodedTextLen] = true;
}

std::pair<bool, const std::string&>
news::linesoftext::EncodedText() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_EncodedText], EncodedText_ );
}

void
news::linesoftext::set_EncodedText( const std::string& val )
{
  EncodedText_ = val;
  presence_map_[ix_EncodedText] = true;
}

void
news::reset()
{
  presence_map_.reset();
  RelatedSym_.clear();
  RoutingIds_.clear();
  LinesOfText_.clear();
}

std::pair<bool, const std::string&>
news::ApplVerID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_ApplVerID], ApplVerID_ );
}

void
news::set_ApplVerID( const std::string& val )
{
  ApplVerID_ = val;
  presence_map_[ix_ApplVerID] = true;
}

std::pair<bool, const std::string&>
news::MsgType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MsgType], MsgType_ );
}

void
news::set_MsgType( const std::string& val )
{
  MsgType_ = val;
  presence_map_[ix_MsgType] = true;
}

std::pair<bool, uint32_t>
news::MsgSeqNum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MsgSeqNum], MsgSeqNum_ );
}

void
news::set_MsgSeqNum( uint32_t val )
{
  MsgSeqNum_ = val;
  presence_map_[ix_MsgSeqNum] = true;
}

std::pair<bool, uint64_t>
news::SendingTime() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_SendingTime], SendingTime_ );
}

void
news::set_SendingTime( uint64_t val )
{
  SendingTime_ = val;
  presence_map_[ix_SendingTime] = true;
}

std::pair<bool, uint64_t>
news::OrigTime() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_OrigTime], OrigTime_ );
}

void
news::set_OrigTime( uint64_t val )
{
  OrigTime_ = val;
  presence_map_[ix_OrigTime] = true;
}

std::pair<bool, const std::string&>
news::NewsSource() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_NewsSource], NewsSource_ );
}

void
news::set_NewsSource( const std::string& val )
{
  NewsSource_ = val;
  presence_map_[ix_NewsSource] = true;
}

std::pair<bool, const std::string&>
news::NewsID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_NewsID], NewsID_ );
}

void
news::set_NewsID( const std::string& val )
{
  NewsID_ = val;
  presence_map_[ix_NewsID] = true;
}

std::pair<bool, const std::string&>
news::LanguageCode() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_LanguageCode], LanguageCode_ );
}

void
news::set_LanguageCode( const std::string& val )
{
  LanguageCode_ = val;
  presence_map_[ix_LanguageCode] = true;
}

std::pair<bool, const std::string&>
news::Headline() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_Headline], Headline_ );
}

void
news::set_Headline( const std::string& val )
{
  Headline_ = val;
  presence_map_[ix_Headline] = true;
}

std::pair<bool, const std::string&>
news::URLLink() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_URLLink], URLLink_ );
}

void
news::set_URLLink( const std::string& val )
{
  URLLink_ = val;
  presence_map_[ix_URLLink] = true;
}

std::pair<bool, uint32_t>
news::EncodedHeadlineLen() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_EncodedHeadlineLen], EncodedHeadlineLen_ );
}

void
news::set_EncodedHeadlineLen( uint32_t val )
{
  EncodedHeadlineLen_ = val;
  presence_map_[ix_EncodedHeadlineLen] = true;
}

std::pair<bool, const std::string&>
news::EncodedHeadline() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_EncodedHeadline], EncodedHeadline_ );
}

void
news::set_EncodedHeadline( const std::string& val )
{
  EncodedHeadline_ = val;
  presence_map_[ix_EncodedHeadline] = true;
}

const std::vector<news::relatedsym>&
news::RelatedSym() const
{
  return RelatedSym_;
}

void
news::add_RelatedSym( const relatedsym& val )
{
  RelatedSym_.push_back( val );
}

const std::vector<news::routingids>&
news::RoutingIds() const
{
  return RoutingIds_;
}

void
news::add_RoutingIds( const routingids& val )
{
  RoutingIds_.push_back( val );
}

const std::vector<news::linesoftext>&
news::LinesOfText() const
{
  return LinesOfText_;
}

void
news::add_LinesOfText( const linesoftext& val )
{
  LinesOfText_.push_back( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

