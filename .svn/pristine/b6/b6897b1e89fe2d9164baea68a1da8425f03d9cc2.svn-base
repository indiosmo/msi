#include <msi/msi_pch.hpp>
#include <msi/umdf/messages/incremental.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

void
incremental::mdentries::underlyings::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint64_t>
incremental::mdentries::underlyings::UnderlyingSecurityID() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_UnderlyingSecurityID], UnderlyingSecurityID_ );
}

void
incremental::mdentries::underlyings::set_UnderlyingSecurityID( uint64_t val )
{
  UnderlyingSecurityID_ = val;
  presence_map_[ix_UnderlyingSecurityID] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::underlyings::UnderlyingSecurityIDSource() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_UnderlyingSecurityIDSource], UnderlyingSecurityIDSource_ );
}

void
incremental::mdentries::underlyings::set_UnderlyingSecurityIDSource( uint32_t val )
{
  UnderlyingSecurityIDSource_ = val;
  presence_map_[ix_UnderlyingSecurityIDSource] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::underlyings::UnderlyingSecurityExchange() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_UnderlyingSecurityExchange], UnderlyingSecurityExchange_ );
}

void
incremental::mdentries::underlyings::set_UnderlyingSecurityExchange( const std::string& val )
{
  UnderlyingSecurityExchange_ = val;
  presence_map_[ix_UnderlyingSecurityExchange] = true;
}

std::pair<bool, decimal>
incremental::mdentries::underlyings::UnderlyingPx() const
{
  return std::pair<bool, decimal>( presence_map_[ix_UnderlyingPx], UnderlyingPx_ );
}

void
incremental::mdentries::underlyings::set_UnderlyingPx( decimal val )
{
  UnderlyingPx_ = val;
  presence_map_[ix_UnderlyingPx] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::underlyings::UnderlyingPxType() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_UnderlyingPxType], UnderlyingPxType_ );
}

void
incremental::mdentries::underlyings::set_UnderlyingPxType( uint32_t val )
{
  UnderlyingPxType_ = val;
  presence_map_[ix_UnderlyingPxType] = true;
}

void
incremental::mdentries::reset()
{
  presence_map_.reset();
  Underlyings_.clear();
}

std::pair<bool, uint32_t>
incremental::mdentries::MDUpdateAction() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MDUpdateAction], MDUpdateAction_ );
}

void
incremental::mdentries::set_MDUpdateAction( uint32_t val )
{
  MDUpdateAction_ = val;
  presence_map_[ix_MDUpdateAction] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::MDPriceLevel() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MDPriceLevel], MDPriceLevel_ );
}

void
incremental::mdentries::set_MDPriceLevel( uint32_t val )
{
  MDPriceLevel_ = val;
  presence_map_[ix_MDPriceLevel] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::MDEntryType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MDEntryType], MDEntryType_ );
}

void
incremental::mdentries::set_MDEntryType( const std::string& val )
{
  MDEntryType_ = val;
  presence_map_[ix_MDEntryType] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::Symbol() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_Symbol], Symbol_ );
}

void
incremental::mdentries::set_Symbol( const std::string& val )
{
  Symbol_ = val;
  presence_map_[ix_Symbol] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::SecurityIDSource() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SecurityIDSource], SecurityIDSource_ );
}

void
incremental::mdentries::set_SecurityIDSource( uint32_t val )
{
  SecurityIDSource_ = val;
  presence_map_[ix_SecurityIDSource] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::SecurityExchange() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityExchange], SecurityExchange_ );
}

void
incremental::mdentries::set_SecurityExchange( const std::string& val )
{
  SecurityExchange_ = val;
  presence_map_[ix_SecurityExchange] = true;
}

std::pair<bool, uint64_t>
incremental::mdentries::SecurityID() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_SecurityID], SecurityID_ );
}

void
incremental::mdentries::set_SecurityID( uint64_t val )
{
  SecurityID_ = val;
  presence_map_[ix_SecurityID] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::RptSeq() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_RptSeq], RptSeq_ );
}

void
incremental::mdentries::set_RptSeq( uint32_t val )
{
  RptSeq_ = val;
  presence_map_[ix_RptSeq] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::QuoteCondition() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_QuoteCondition], QuoteCondition_ );
}

void
incremental::mdentries::set_QuoteCondition( const std::string& val )
{
  QuoteCondition_ = val;
  presence_map_[ix_QuoteCondition] = true;
}

std::pair<bool, decimal>
incremental::mdentries::MDEntryPx() const
{
  return std::pair<bool, decimal>( presence_map_[ix_MDEntryPx], MDEntryPx_ );
}

void
incremental::mdentries::set_MDEntryPx( decimal val )
{
  MDEntryPx_ = val;
  presence_map_[ix_MDEntryPx] = true;
}

std::pair<bool, decimal>
incremental::mdentries::MDEntryInterestRate() const
{
  return std::pair<bool, decimal>( presence_map_[ix_MDEntryInterestRate], MDEntryInterestRate_ );
}

void
incremental::mdentries::set_MDEntryInterestRate( decimal val )
{
  MDEntryInterestRate_ = val;
  presence_map_[ix_MDEntryInterestRate] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::NumberOfOrders() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_NumberOfOrders], NumberOfOrders_ );
}

void
incremental::mdentries::set_NumberOfOrders( uint32_t val )
{
  NumberOfOrders_ = val;
  presence_map_[ix_NumberOfOrders] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::PriceType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_PriceType], PriceType_ );
}

void
incremental::mdentries::set_PriceType( const std::string& val )
{
  PriceType_ = val;
  presence_map_[ix_PriceType] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::MDEntryTime() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MDEntryTime], MDEntryTime_ );
}

void
incremental::mdentries::set_MDEntryTime( uint32_t val )
{
  MDEntryTime_ = val;
  presence_map_[ix_MDEntryTime] = true;
}

std::pair<bool, int64_t>
incremental::mdentries::MDEntrySize() const
{
  return std::pair<bool, int64_t>( presence_map_[ix_MDEntrySize], MDEntrySize_ );
}

void
incremental::mdentries::set_MDEntrySize( int64_t val )
{
  MDEntrySize_ = val;
  presence_map_[ix_MDEntrySize] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::MDEntryDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MDEntryDate], MDEntryDate_ );
}

void
incremental::mdentries::set_MDEntryDate( uint32_t val )
{
  MDEntryDate_ = val;
  presence_map_[ix_MDEntryDate] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::MDInsertDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MDInsertDate], MDInsertDate_ );
}

void
incremental::mdentries::set_MDInsertDate( uint32_t val )
{
  MDInsertDate_ = val;
  presence_map_[ix_MDInsertDate] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::MDInsertTime() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MDInsertTime], MDInsertTime_ );
}

void
incremental::mdentries::set_MDInsertTime( uint32_t val )
{
  MDInsertTime_ = val;
  presence_map_[ix_MDInsertTime] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::MDStreamID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MDStreamID], MDStreamID_ );
}

void
incremental::mdentries::set_MDStreamID( const std::string& val )
{
  MDStreamID_ = val;
  presence_map_[ix_MDStreamID] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::Currency() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_Currency], Currency_ );
}

void
incremental::mdentries::set_Currency( const std::string& val )
{
  Currency_ = val;
  presence_map_[ix_Currency] = true;
}

std::pair<bool, decimal>
incremental::mdentries::NetChgPrevDay() const
{
  return std::pair<bool, decimal>( presence_map_[ix_NetChgPrevDay], NetChgPrevDay_ );
}

void
incremental::mdentries::set_NetChgPrevDay( decimal val )
{
  NetChgPrevDay_ = val;
  presence_map_[ix_NetChgPrevDay] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::SellerDays() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SellerDays], SellerDays_ );
}

void
incremental::mdentries::set_SellerDays( uint32_t val )
{
  SellerDays_ = val;
  presence_map_[ix_SellerDays] = true;
}

std::pair<bool, uint64_t>
incremental::mdentries::TradeVolume() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_TradeVolume], TradeVolume_ );
}

void
incremental::mdentries::set_TradeVolume( uint64_t val )
{
  TradeVolume_ = val;
  presence_map_[ix_TradeVolume] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::TickDirection() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_TickDirection], TickDirection_ );
}

void
incremental::mdentries::set_TickDirection( const std::string& val )
{
  TickDirection_ = val;
  presence_map_[ix_TickDirection] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::TradeCondition() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_TradeCondition], TradeCondition_ );
}

void
incremental::mdentries::set_TradeCondition( const std::string& val )
{
  TradeCondition_ = val;
  presence_map_[ix_TradeCondition] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::TradingSessionID() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_TradingSessionID], TradingSessionID_ );
}

void
incremental::mdentries::set_TradingSessionID( uint32_t val )
{
  TradingSessionID_ = val;
  presence_map_[ix_TradingSessionID] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::OpenCloseSettlFlag() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_OpenCloseSettlFlag], OpenCloseSettlFlag_ );
}

void
incremental::mdentries::set_OpenCloseSettlFlag( uint32_t val )
{
  OpenCloseSettlFlag_ = val;
  presence_map_[ix_OpenCloseSettlFlag] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::OrderID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_OrderID], OrderID_ );
}

void
incremental::mdentries::set_OrderID( const std::string& val )
{
  OrderID_ = val;
  presence_map_[ix_OrderID] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::TradeID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_TradeID], TradeID_ );
}

void
incremental::mdentries::set_TradeID( const std::string& val )
{
  TradeID_ = val;
  presence_map_[ix_TradeID] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::MDEntryBuyer() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MDEntryBuyer], MDEntryBuyer_ );
}

void
incremental::mdentries::set_MDEntryBuyer( const std::string& val )
{
  MDEntryBuyer_ = val;
  presence_map_[ix_MDEntryBuyer] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::MDEntrySeller() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MDEntrySeller], MDEntrySeller_ );
}

void
incremental::mdentries::set_MDEntrySeller( const std::string& val )
{
  MDEntrySeller_ = val;
  presence_map_[ix_MDEntrySeller] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::MDEntryPositionNo() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MDEntryPositionNo], MDEntryPositionNo_ );
}

void
incremental::mdentries::set_MDEntryPositionNo( uint32_t val )
{
  MDEntryPositionNo_ = val;
  presence_map_[ix_MDEntryPositionNo] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::SettlType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SettlType], SettlType_ );
}

void
incremental::mdentries::set_SettlType( const std::string& val )
{
  SettlType_ = val;
  presence_map_[ix_SettlType] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::SettlDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SettlDate], SettlDate_ );
}

void
incremental::mdentries::set_SettlDate( uint32_t val )
{
  SettlDate_ = val;
  presence_map_[ix_SettlDate] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::SettPriceType() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SettPriceType], SettPriceType_ );
}

void
incremental::mdentries::set_SettPriceType( uint32_t val )
{
  SettPriceType_ = val;
  presence_map_[ix_SettPriceType] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::LastTradeDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_LastTradeDate], LastTradeDate_ );
}

void
incremental::mdentries::set_LastTradeDate( uint32_t val )
{
  LastTradeDate_ = val;
  presence_map_[ix_LastTradeDate] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::PriceAdjustmentMethod() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_PriceAdjustmentMethod], PriceAdjustmentMethod_ );
}

void
incremental::mdentries::set_PriceAdjustmentMethod( uint32_t val )
{
  PriceAdjustmentMethod_ = val;
  presence_map_[ix_PriceAdjustmentMethod] = true;
}

std::pair<bool, const std::string&>
incremental::mdentries::PriceBandType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_PriceBandType], PriceBandType_ );
}

void
incremental::mdentries::set_PriceBandType( const std::string& val )
{
  PriceBandType_ = val;
  presence_map_[ix_PriceBandType] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::PriceLimitType() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_PriceLimitType], PriceLimitType_ );
}

void
incremental::mdentries::set_PriceLimitType( uint32_t val )
{
  PriceLimitType_ = val;
  presence_map_[ix_PriceLimitType] = true;
}

std::pair<bool, decimal>
incremental::mdentries::LowLimitPrice() const
{
  return std::pair<bool, decimal>( presence_map_[ix_LowLimitPrice], LowLimitPrice_ );
}

void
incremental::mdentries::set_LowLimitPrice( decimal val )
{
  LowLimitPrice_ = val;
  presence_map_[ix_LowLimitPrice] = true;
}

std::pair<bool, decimal>
incremental::mdentries::HighLimitPrice() const
{
  return std::pair<bool, decimal>( presence_map_[ix_HighLimitPrice], HighLimitPrice_ );
}

void
incremental::mdentries::set_HighLimitPrice( decimal val )
{
  HighLimitPrice_ = val;
  presence_map_[ix_HighLimitPrice] = true;
}

std::pair<bool, decimal>
incremental::mdentries::TradingReferencePrice() const
{
  return std::pair<bool, decimal>( presence_map_[ix_TradingReferencePrice], TradingReferencePrice_ );
}

void
incremental::mdentries::set_TradingReferencePrice( decimal val )
{
  TradingReferencePrice_ = val;
  presence_map_[ix_TradingReferencePrice] = true;
}

std::pair<bool, uint32_t>
incremental::mdentries::PriceBandMidpointPriceType() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_PriceBandMidpointPriceType], PriceBandMidpointPriceType_ );
}

void
incremental::mdentries::set_PriceBandMidpointPriceType( uint32_t val )
{
  PriceBandMidpointPriceType_ = val;
  presence_map_[ix_PriceBandMidpointPriceType] = true;
}

std::pair<bool, uint64_t>
incremental::mdentries::AvgDailyTradedQty() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_AvgDailyTradedQty], AvgDailyTradedQty_ );
}

void
incremental::mdentries::set_AvgDailyTradedQty( uint64_t val )
{
  AvgDailyTradedQty_ = val;
  presence_map_[ix_AvgDailyTradedQty] = true;
}

std::pair<bool, uint64_t>
incremental::mdentries::ExpireDate() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_ExpireDate], ExpireDate_ );
}

void
incremental::mdentries::set_ExpireDate( uint64_t val )
{
  ExpireDate_ = val;
  presence_map_[ix_ExpireDate] = true;
}

std::pair<bool, uint64_t>
incremental::mdentries::EarlyTermination() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_EarlyTermination], EarlyTermination_ );
}

void
incremental::mdentries::set_EarlyTermination( uint64_t val )
{
  EarlyTermination_ = val;
  presence_map_[ix_EarlyTermination] = true;
}

std::pair<bool, uint64_t>
incremental::mdentries::MaxTradeVol() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_MaxTradeVol], MaxTradeVol_ );
}

void
incremental::mdentries::set_MaxTradeVol( uint64_t val )
{
  MaxTradeVol_ = val;
  presence_map_[ix_MaxTradeVol] = true;
}

const std::vector<incremental::mdentries::underlyings>&
incremental::mdentries::Underlyings() const
{
  return Underlyings_;
}

void
incremental::mdentries::add_Underlyings( const underlyings& val )
{
  Underlyings_.push_back( val );
}

std::pair<bool, uint64_t>
incremental::mdentries::IndexSeq() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_IndexSeq], IndexSeq_ );
}

void
incremental::mdentries::set_IndexSeq( uint64_t val )
{
  IndexSeq_ = val;
  presence_map_[ix_IndexSeq] = true;
}

void
incremental::reset()
{
  presence_map_.reset();
  MDEntries_.clear();
}

std::pair<bool, const std::string&>
incremental::ApplVerID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_ApplVerID], ApplVerID_ );
}

void
incremental::set_ApplVerID( const std::string& val )
{
  ApplVerID_ = val;
  presence_map_[ix_ApplVerID] = true;
}

std::pair<bool, const std::string&>
incremental::MsgType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MsgType], MsgType_ );
}

void
incremental::set_MsgType( const std::string& val )
{
  MsgType_ = val;
  presence_map_[ix_MsgType] = true;
}

std::pair<bool, uint32_t>
incremental::MsgSeqNum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MsgSeqNum], MsgSeqNum_ );
}

void
incremental::set_MsgSeqNum( uint32_t val )
{
  MsgSeqNum_ = val;
  presence_map_[ix_MsgSeqNum] = true;
}

std::pair<bool, uint64_t>
incremental::SendingTime() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_SendingTime], SendingTime_ );
}

void
incremental::set_SendingTime( uint64_t val )
{
  SendingTime_ = val;
  presence_map_[ix_SendingTime] = true;
}

std::pair<bool, const std::string&>
incremental::PosDupFlag() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_PosDupFlag], PosDupFlag_ );
}

void
incremental::set_PosDupFlag( const std::string& val )
{
  PosDupFlag_ = val;
  presence_map_[ix_PosDupFlag] = true;
}

std::pair<bool, uint32_t>
incremental::TradeDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_TradeDate], TradeDate_ );
}

void
incremental::set_TradeDate( uint32_t val )
{
  TradeDate_ = val;
  presence_map_[ix_TradeDate] = true;
}

const std::vector<incremental::mdentries>&
incremental::MDEntries() const
{
  return MDEntries_;
}

void
incremental::add_MDEntries( const mdentries& val )
{
  MDEntries_.push_back( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

