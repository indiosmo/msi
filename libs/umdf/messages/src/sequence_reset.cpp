#include <msi/msi_pch.hpp>
#include <msi/umdf/messages/sequence_reset.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

void
sequence_reset::reset()
{
  presence_map_.reset();
}

std::pair<bool, const std::string&>
sequence_reset::MsgType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MsgType], MsgType_ );
}

void
sequence_reset::set_MsgType( const std::string& val )
{
  MsgType_ = val;
  presence_map_[ix_MsgType] = true;
}

std::pair<bool, uint32_t>
sequence_reset::MsgSeqNum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MsgSeqNum], MsgSeqNum_ );
}

void
sequence_reset::set_MsgSeqNum( uint32_t val )
{
  MsgSeqNum_ = val;
  presence_map_[ix_MsgSeqNum] = true;
}

std::pair<bool, uint64_t>
sequence_reset::SendingTime() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_SendingTime], SendingTime_ );
}

void
sequence_reset::set_SendingTime( uint64_t val )
{
  SendingTime_ = val;
  presence_map_[ix_SendingTime] = true;
}

std::pair<bool, const std::string&>
sequence_reset::ApplVerID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_ApplVerID], ApplVerID_ );
}

void
sequence_reset::set_ApplVerID( const std::string& val )
{
  ApplVerID_ = val;
  presence_map_[ix_ApplVerID] = true;
}

std::pair<bool, uint32_t>
sequence_reset::NewSeqNo() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_NewSeqNo], NewSeqNo_ );
}

void
sequence_reset::set_NewSeqNo( uint32_t val )
{
  NewSeqNo_ = val;
  presence_map_[ix_NewSeqNo] = true;
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

