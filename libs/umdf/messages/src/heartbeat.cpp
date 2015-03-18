#include <msi/msi_pch.hpp>
#include <msi/umdf/messages/heartbeat.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

void
heartbeat::reset()
{
  presence_map_.reset();
}

std::pair<bool, const std::string&>
heartbeat::ApplVerID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_ApplVerID], ApplVerID_ );
}

void
heartbeat::set_ApplVerID( const std::string& val )
{
  ApplVerID_ = val;
  presence_map_[ix_ApplVerID] = true;
}

std::pair<bool, const std::string&>
heartbeat::MsgType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MsgType], MsgType_ );
}

void
heartbeat::set_MsgType( const std::string& val )
{
  MsgType_ = val;
  presence_map_[ix_MsgType] = true;
}

std::pair<bool, uint32_t>
heartbeat::MsgSeqNum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MsgSeqNum], MsgSeqNum_ );
}

void
heartbeat::set_MsgSeqNum( uint32_t val )
{
  MsgSeqNum_ = val;
  presence_map_[ix_MsgSeqNum] = true;
}

std::pair<bool, uint64_t>
heartbeat::SendingTime() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_SendingTime], SendingTime_ );
}

void
heartbeat::set_SendingTime( uint64_t val )
{
  SendingTime_ = val;
  presence_map_[ix_SendingTime] = true;
}

std::pair<bool, const std::string&>
heartbeat::PosDupFlag() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_PosDupFlag], PosDupFlag_ );
}

void
heartbeat::set_PosDupFlag( const std::string& val )
{
  PosDupFlag_ = val;
  presence_map_[ix_PosDupFlag] = true;
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

