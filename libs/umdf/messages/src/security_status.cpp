#include <msi/msi_pch.hpp>
#include <msi/umdf/messages/security_status.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

void
security_status::reset()
{
  presence_map_.reset();
}

std::pair<bool, const std::string&>
security_status::ApplVerID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_ApplVerID], ApplVerID_ );
}

void
security_status::set_ApplVerID( const std::string& val )
{
  ApplVerID_ = val;
  presence_map_[ix_ApplVerID] = true;
}

std::pair<bool, const std::string&>
security_status::MsgType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MsgType], MsgType_ );
}

void
security_status::set_MsgType( const std::string& val )
{
  MsgType_ = val;
  presence_map_[ix_MsgType] = true;
}

std::pair<bool, uint32_t>
security_status::MsgSeqNum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MsgSeqNum], MsgSeqNum_ );
}

void
security_status::set_MsgSeqNum( uint32_t val )
{
  MsgSeqNum_ = val;
  presence_map_[ix_MsgSeqNum] = true;
}

std::pair<bool, uint64_t>
security_status::SendingTime() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_SendingTime], SendingTime_ );
}

void
security_status::set_SendingTime( uint64_t val )
{
  SendingTime_ = val;
  presence_map_[ix_SendingTime] = true;
}

std::pair<bool, const std::string&>
security_status::SecurityGroup() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityGroup], SecurityGroup_ );
}

void
security_status::set_SecurityGroup( const std::string& val )
{
  SecurityGroup_ = val;
  presence_map_[ix_SecurityGroup] = true;
}

std::pair<bool, const std::string&>
security_status::Symbol() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_Symbol], Symbol_ );
}

void
security_status::set_Symbol( const std::string& val )
{
  Symbol_ = val;
  presence_map_[ix_Symbol] = true;
}

std::pair<bool, uint64_t>
security_status::SecurityID() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_SecurityID], SecurityID_ );
}

void
security_status::set_SecurityID( uint64_t val )
{
  SecurityID_ = val;
  presence_map_[ix_SecurityID] = true;
}

std::pair<bool, uint32_t>
security_status::SecurityIDSource() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SecurityIDSource], SecurityIDSource_ );
}

void
security_status::set_SecurityIDSource( uint32_t val )
{
  SecurityIDSource_ = val;
  presence_map_[ix_SecurityIDSource] = true;
}

std::pair<bool, const std::string&>
security_status::SecurityExchange() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityExchange], SecurityExchange_ );
}

void
security_status::set_SecurityExchange( const std::string& val )
{
  SecurityExchange_ = val;
  presence_map_[ix_SecurityExchange] = true;
}

std::pair<bool, const std::string&>
security_status::TradingSessionSubID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_TradingSessionSubID], TradingSessionSubID_ );
}

void
security_status::set_TradingSessionSubID( const std::string& val )
{
  TradingSessionSubID_ = val;
  presence_map_[ix_TradingSessionSubID] = true;
}

std::pair<bool, uint32_t>
security_status::SecurityTradingStatus() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SecurityTradingStatus], SecurityTradingStatus_ );
}

void
security_status::set_SecurityTradingStatus( uint32_t val )
{
  SecurityTradingStatus_ = val;
  presence_map_[ix_SecurityTradingStatus] = true;
}

std::pair<bool, uint32_t>
security_status::TradingSessionID() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_TradingSessionID], TradingSessionID_ );
}

void
security_status::set_TradingSessionID( uint32_t val )
{
  TradingSessionID_ = val;
  presence_map_[ix_TradingSessionID] = true;
}

std::pair<bool, uint64_t>
security_status::TradSesOpenTime() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_TradSesOpenTime], TradSesOpenTime_ );
}

void
security_status::set_TradSesOpenTime( uint64_t val )
{
  TradSesOpenTime_ = val;
  presence_map_[ix_TradSesOpenTime] = true;
}

std::pair<bool, uint64_t>
security_status::TransactTime() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_TransactTime], TransactTime_ );
}

void
security_status::set_TransactTime( uint64_t val )
{
  TransactTime_ = val;
  presence_map_[ix_TransactTime] = true;
}

std::pair<bool, uint32_t>
security_status::TradeDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_TradeDate], TradeDate_ );
}

void
security_status::set_TradeDate( uint32_t val )
{
  TradeDate_ = val;
  presence_map_[ix_TradeDate] = true;
}

std::pair<bool, uint32_t>
security_status::SecurityTradingEvent() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SecurityTradingEvent], SecurityTradingEvent_ );
}

void
security_status::set_SecurityTradingEvent( uint32_t val )
{
  SecurityTradingEvent_ = val;
  presence_map_[ix_SecurityTradingEvent] = true;
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

