#include <msi/msi_pch.hpp>
#include <msi/umdf/messages/snapshot.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

void
snapshot::mdentries::underlyings::reset()
{
  presence_map_.reset();
}

std::pair<bool, uint64_t>
snapshot::mdentries::underlyings::UnderlyingSecurityID() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_UnderlyingSecurityID], UnderlyingSecurityID_ );
}

void
snapshot::mdentries::underlyings::set_UnderlyingSecurityID( uint64_t val )
{
  UnderlyingSecurityID_ = val;
  presence_map_[ix_UnderlyingSecurityID] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::underlyings::UnderlyingSecurityIDSource() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_UnderlyingSecurityIDSource], UnderlyingSecurityIDSource_ );
}

void
snapshot::mdentries::underlyings::set_UnderlyingSecurityIDSource( uint32_t val )
{
  UnderlyingSecurityIDSource_ = val;
  presence_map_[ix_UnderlyingSecurityIDSource] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::underlyings::UnderlyingSecurityExchange() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_UnderlyingSecurityExchange], UnderlyingSecurityExchange_ );
}

void
snapshot::mdentries::underlyings::set_UnderlyingSecurityExchange( const std::string& val )
{
  UnderlyingSecurityExchange_ = val;
  presence_map_[ix_UnderlyingSecurityExchange] = true;
}

std::pair<bool, decimal>
snapshot::mdentries::underlyings::UnderlyingPx() const
{
  return std::pair<bool, decimal>( presence_map_[ix_UnderlyingPx], UnderlyingPx_ );
}

void
snapshot::mdentries::underlyings::set_UnderlyingPx( decimal val )
{
  UnderlyingPx_ = val;
  presence_map_[ix_UnderlyingPx] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::underlyings::UnderlyingPxType() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_UnderlyingPxType], UnderlyingPxType_ );
}

void
snapshot::mdentries::underlyings::set_UnderlyingPxType( uint32_t val )
{
  UnderlyingPxType_ = val;
  presence_map_[ix_UnderlyingPxType] = true;
}

void
snapshot::mdentries::reset()
{
  presence_map_.reset();
  Underlyings_.clear();
}

std::pair<bool, const std::string&>
snapshot::mdentries::MDEntryType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MDEntryType], MDEntryType_ );
}

void
snapshot::mdentries::set_MDEntryType( const std::string& val )
{
  MDEntryType_ = val;
  presence_map_[ix_MDEntryType] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::Currency() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_Currency], Currency_ );
}

void
snapshot::mdentries::set_Currency( const std::string& val )
{
  Currency_ = val;
  presence_map_[ix_Currency] = true;
}

std::pair<bool, decimal>
snapshot::mdentries::MDEntryPx() const
{
  return std::pair<bool, decimal>( presence_map_[ix_MDEntryPx], MDEntryPx_ );
}

void
snapshot::mdentries::set_MDEntryPx( decimal val )
{
  MDEntryPx_ = val;
  presence_map_[ix_MDEntryPx] = true;
}

std::pair<bool, decimal>
snapshot::mdentries::MDEntryInterestRate() const
{
  return std::pair<bool, decimal>( presence_map_[ix_MDEntryInterestRate], MDEntryInterestRate_ );
}

void
snapshot::mdentries::set_MDEntryInterestRate( decimal val )
{
  MDEntryInterestRate_ = val;
  presence_map_[ix_MDEntryInterestRate] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::IndexSeq() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_IndexSeq], IndexSeq_ );
}

void
snapshot::mdentries::set_IndexSeq( uint32_t val )
{
  IndexSeq_ = val;
  presence_map_[ix_IndexSeq] = true;
}

std::pair<bool, int64_t>
snapshot::mdentries::MDEntrySize() const
{
  return std::pair<bool, int64_t>( presence_map_[ix_MDEntrySize], MDEntrySize_ );
}

void
snapshot::mdentries::set_MDEntrySize( int64_t val )
{
  MDEntrySize_ = val;
  presence_map_[ix_MDEntrySize] = true;
}

std::pair<bool, uint64_t>
snapshot::mdentries::TradeVolume() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_TradeVolume], TradeVolume_ );
}

void
snapshot::mdentries::set_TradeVolume( uint64_t val )
{
  TradeVolume_ = val;
  presence_map_[ix_TradeVolume] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::MDEntryDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MDEntryDate], MDEntryDate_ );
}

void
snapshot::mdentries::set_MDEntryDate( uint32_t val )
{
  MDEntryDate_ = val;
  presence_map_[ix_MDEntryDate] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::MDEntryTime() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MDEntryTime], MDEntryTime_ );
}

void
snapshot::mdentries::set_MDEntryTime( const std::string& val )
{
  MDEntryTime_ = val;
  presence_map_[ix_MDEntryTime] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::MDInsertDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MDInsertDate], MDInsertDate_ );
}

void
snapshot::mdentries::set_MDInsertDate( uint32_t val )
{
  MDInsertDate_ = val;
  presence_map_[ix_MDInsertDate] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::MDInsertTime() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MDInsertTime], MDInsertTime_ );
}

void
snapshot::mdentries::set_MDInsertTime( uint32_t val )
{
  MDInsertTime_ = val;
  presence_map_[ix_MDInsertTime] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::TickDirection() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_TickDirection], TickDirection_ );
}

void
snapshot::mdentries::set_TickDirection( const std::string& val )
{
  TickDirection_ = val;
  presence_map_[ix_TickDirection] = true;
}

std::pair<bool, decimal>
snapshot::mdentries::NetChgPrevDay() const
{
  return std::pair<bool, decimal>( presence_map_[ix_NetChgPrevDay], NetChgPrevDay_ );
}

void
snapshot::mdentries::set_NetChgPrevDay( decimal val )
{
  NetChgPrevDay_ = val;
  presence_map_[ix_NetChgPrevDay] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::MDStreamID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MDStreamID], MDStreamID_ );
}

void
snapshot::mdentries::set_MDStreamID( const std::string& val )
{
  MDStreamID_ = val;
  presence_map_[ix_MDStreamID] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::PriceType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_PriceType], PriceType_ );
}

void
snapshot::mdentries::set_PriceType( const std::string& val )
{
  PriceType_ = val;
  presence_map_[ix_PriceType] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::TradingSessionSubID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_TradingSessionSubID], TradingSessionSubID_ );
}

void
snapshot::mdentries::set_TradingSessionSubID( const std::string& val )
{
  TradingSessionSubID_ = val;
  presence_map_[ix_TradingSessionSubID] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::SecurityTradingStatus() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SecurityTradingStatus], SecurityTradingStatus_ );
}

void
snapshot::mdentries::set_SecurityTradingStatus( uint32_t val )
{
  SecurityTradingStatus_ = val;
  presence_map_[ix_SecurityTradingStatus] = true;
}

std::pair<bool, uint64_t>
snapshot::mdentries::TradSesOpenTime() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_TradSesOpenTime], TradSesOpenTime_ );
}

void
snapshot::mdentries::set_TradSesOpenTime( uint64_t val )
{
  TradSesOpenTime_ = val;
  presence_map_[ix_TradSesOpenTime] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::TradingSessionID() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_TradingSessionID], TradingSessionID_ );
}

void
snapshot::mdentries::set_TradingSessionID( uint32_t val )
{
  TradingSessionID_ = val;
  presence_map_[ix_TradingSessionID] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::SecurityTradingEvent() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SecurityTradingEvent], SecurityTradingEvent_ );
}

void
snapshot::mdentries::set_SecurityTradingEvent( uint32_t val )
{
  SecurityTradingEvent_ = val;
  presence_map_[ix_SecurityTradingEvent] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::TradeCondition() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_TradeCondition], TradeCondition_ );
}

void
snapshot::mdentries::set_TradeCondition( const std::string& val )
{
  TradeCondition_ = val;
  presence_map_[ix_TradeCondition] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::OpenCloseSettlFlag() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_OpenCloseSettlFlag], OpenCloseSettlFlag_ );
}

void
snapshot::mdentries::set_OpenCloseSettlFlag( uint32_t val )
{
  OpenCloseSettlFlag_ = val;
  presence_map_[ix_OpenCloseSettlFlag] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::OrderID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_OrderID], OrderID_ );
}

void
snapshot::mdentries::set_OrderID( const std::string& val )
{
  OrderID_ = val;
  presence_map_[ix_OrderID] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::TradeID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_TradeID], TradeID_ );
}

void
snapshot::mdentries::set_TradeID( const std::string& val )
{
  TradeID_ = val;
  presence_map_[ix_TradeID] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::MDEntryBuyer() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MDEntryBuyer], MDEntryBuyer_ );
}

void
snapshot::mdentries::set_MDEntryBuyer( const std::string& val )
{
  MDEntryBuyer_ = val;
  presence_map_[ix_MDEntryBuyer] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::MDEntrySeller() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MDEntrySeller], MDEntrySeller_ );
}

void
snapshot::mdentries::set_MDEntrySeller( const std::string& val )
{
  MDEntrySeller_ = val;
  presence_map_[ix_MDEntrySeller] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::QuoteCondition() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_QuoteCondition], QuoteCondition_ );
}

void
snapshot::mdentries::set_QuoteCondition( const std::string& val )
{
  QuoteCondition_ = val;
  presence_map_[ix_QuoteCondition] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::NumberOfOrders() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_NumberOfOrders], NumberOfOrders_ );
}

void
snapshot::mdentries::set_NumberOfOrders( uint32_t val )
{
  NumberOfOrders_ = val;
  presence_map_[ix_NumberOfOrders] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::MDEntryPositionNo() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MDEntryPositionNo], MDEntryPositionNo_ );
}

void
snapshot::mdentries::set_MDEntryPositionNo( uint32_t val )
{
  MDEntryPositionNo_ = val;
  presence_map_[ix_MDEntryPositionNo] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::DayCumQty() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_DayCumQty], DayCumQty_ );
}

void
snapshot::mdentries::set_DayCumQty( uint32_t val )
{
  DayCumQty_ = val;
  presence_map_[ix_DayCumQty] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::SellerDays() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SellerDays], SellerDays_ );
}

void
snapshot::mdentries::set_SellerDays( uint32_t val )
{
  SellerDays_ = val;
  presence_map_[ix_SellerDays] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::SettPriceType() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SettPriceType], SettPriceType_ );
}

void
snapshot::mdentries::set_SettPriceType( uint32_t val )
{
  SettPriceType_ = val;
  presence_map_[ix_SettPriceType] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::LastTradeDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_LastTradeDate], LastTradeDate_ );
}

void
snapshot::mdentries::set_LastTradeDate( uint32_t val )
{
  LastTradeDate_ = val;
  presence_map_[ix_LastTradeDate] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::PriceAdjustmentMethod() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_PriceAdjustmentMethod], PriceAdjustmentMethod_ );
}

void
snapshot::mdentries::set_PriceAdjustmentMethod( uint32_t val )
{
  PriceAdjustmentMethod_ = val;
  presence_map_[ix_PriceAdjustmentMethod] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::PriceLimitType() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_PriceLimitType], PriceLimitType_ );
}

void
snapshot::mdentries::set_PriceLimitType( uint32_t val )
{
  PriceLimitType_ = val;
  presence_map_[ix_PriceLimitType] = true;
}

std::pair<bool, decimal>
snapshot::mdentries::LowLimitPrice() const
{
  return std::pair<bool, decimal>( presence_map_[ix_LowLimitPrice], LowLimitPrice_ );
}

void
snapshot::mdentries::set_LowLimitPrice( decimal val )
{
  LowLimitPrice_ = val;
  presence_map_[ix_LowLimitPrice] = true;
}

std::pair<bool, decimal>
snapshot::mdentries::HighLimitPrice() const
{
  return std::pair<bool, decimal>( presence_map_[ix_HighLimitPrice], HighLimitPrice_ );
}

void
snapshot::mdentries::set_HighLimitPrice( decimal val )
{
  HighLimitPrice_ = val;
  presence_map_[ix_HighLimitPrice] = true;
}

std::pair<bool, decimal>
snapshot::mdentries::TradingReferencePrice() const
{
  return std::pair<bool, decimal>( presence_map_[ix_TradingReferencePrice], TradingReferencePrice_ );
}

void
snapshot::mdentries::set_TradingReferencePrice( decimal val )
{
  TradingReferencePrice_ = val;
  presence_map_[ix_TradingReferencePrice] = true;
}

std::pair<bool, uint32_t>
snapshot::mdentries::PriceBandMidpointPriceType() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_PriceBandMidpointPriceType], PriceBandMidpointPriceType_ );
}

void
snapshot::mdentries::set_PriceBandMidpointPriceType( uint32_t val )
{
  PriceBandMidpointPriceType_ = val;
  presence_map_[ix_PriceBandMidpointPriceType] = true;
}

std::pair<bool, uint64_t>
snapshot::mdentries::AvgDailyTradedQty() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_AvgDailyTradedQty], AvgDailyTradedQty_ );
}

void
snapshot::mdentries::set_AvgDailyTradedQty( uint64_t val )
{
  AvgDailyTradedQty_ = val;
  presence_map_[ix_AvgDailyTradedQty] = true;
}

std::pair<bool, uint64_t>
snapshot::mdentries::ExpireDate() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_ExpireDate], ExpireDate_ );
}

void
snapshot::mdentries::set_ExpireDate( uint64_t val )
{
  ExpireDate_ = val;
  presence_map_[ix_ExpireDate] = true;
}

std::pair<bool, uint64_t>
snapshot::mdentries::EarlyTermination() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_EarlyTermination], EarlyTermination_ );
}

void
snapshot::mdentries::set_EarlyTermination( uint64_t val )
{
  EarlyTermination_ = val;
  presence_map_[ix_EarlyTermination] = true;
}

std::pair<bool, uint64_t>
snapshot::mdentries::MaxTradeVol() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_MaxTradeVol], MaxTradeVol_ );
}

void
snapshot::mdentries::set_MaxTradeVol( uint64_t val )
{
  MaxTradeVol_ = val;
  presence_map_[ix_MaxTradeVol] = true;
}

std::pair<bool, const std::string&>
snapshot::mdentries::PriceBandType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_PriceBandType], PriceBandType_ );
}

void
snapshot::mdentries::set_PriceBandType( const std::string& val )
{
  PriceBandType_ = val;
  presence_map_[ix_PriceBandType] = true;
}

const std::vector<snapshot::mdentries::underlyings>&
snapshot::mdentries::Underlyings() const
{
  return Underlyings_;
}

void
snapshot::mdentries::add_Underlyings( const underlyings& val )
{
  Underlyings_.push_back( val );
}

void
snapshot::reset()
{
  presence_map_.reset();
  MDEntries_.clear();
}

std::pair<bool, const std::string&>
snapshot::MsgType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MsgType], MsgType_ );
}

void
snapshot::set_MsgType( const std::string& val )
{
  MsgType_ = val;
  presence_map_[ix_MsgType] = true;
}

std::pair<bool, uint32_t>
snapshot::MsgSeqNum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MsgSeqNum], MsgSeqNum_ );
}

void
snapshot::set_MsgSeqNum( uint32_t val )
{
  MsgSeqNum_ = val;
  presence_map_[ix_MsgSeqNum] = true;
}

std::pair<bool, const std::string&>
snapshot::ApplVerID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_ApplVerID], ApplVerID_ );
}

void
snapshot::set_ApplVerID( const std::string& val )
{
  ApplVerID_ = val;
  presence_map_[ix_ApplVerID] = true;
}

std::pair<bool, uint64_t>
snapshot::SendingTime() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_SendingTime], SendingTime_ );
}

void
snapshot::set_SendingTime( uint64_t val )
{
  SendingTime_ = val;
  presence_map_[ix_SendingTime] = true;
}

std::pair<bool, uint32_t>
snapshot::LastMsgSeqNumProcessed() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_LastMsgSeqNumProcessed], LastMsgSeqNumProcessed_ );
}

void
snapshot::set_LastMsgSeqNumProcessed( uint32_t val )
{
  LastMsgSeqNumProcessed_ = val;
  presence_map_[ix_LastMsgSeqNumProcessed] = true;
}

std::pair<bool, uint32_t>
snapshot::TotNumReports() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_TotNumReports], TotNumReports_ );
}

void
snapshot::set_TotNumReports( uint32_t val )
{
  TotNumReports_ = val;
  presence_map_[ix_TotNumReports] = true;
}

std::pair<bool, uint32_t>
snapshot::TradeDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_TradeDate], TradeDate_ );
}

void
snapshot::set_TradeDate( uint32_t val )
{
  TradeDate_ = val;
  presence_map_[ix_TradeDate] = true;
}

std::pair<bool, const std::string&>
snapshot::MDReqID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MDReqID], MDReqID_ );
}

void
snapshot::set_MDReqID( const std::string& val )
{
  MDReqID_ = val;
  presence_map_[ix_MDReqID] = true;
}

std::pair<bool, int32_t>
snapshot::MarketDepth() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_MarketDepth], MarketDepth_ );
}

void
snapshot::set_MarketDepth( int32_t val )
{
  MarketDepth_ = val;
  presence_map_[ix_MarketDepth] = true;
}

std::pair<bool, uint32_t>
snapshot::RptSeq() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_RptSeq], RptSeq_ );
}

void
snapshot::set_RptSeq( uint32_t val )
{
  RptSeq_ = val;
  presence_map_[ix_RptSeq] = true;
}

std::pair<bool, uint64_t>
snapshot::SecurityID() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_SecurityID], SecurityID_ );
}

void
snapshot::set_SecurityID( uint64_t val )
{
  SecurityID_ = val;
  presence_map_[ix_SecurityID] = true;
}

std::pair<bool, uint32_t>
snapshot::SecurityIDSource() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SecurityIDSource], SecurityIDSource_ );
}

void
snapshot::set_SecurityIDSource( uint32_t val )
{
  SecurityIDSource_ = val;
  presence_map_[ix_SecurityIDSource] = true;
}

std::pair<bool, const std::string&>
snapshot::SecurityExchange() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityExchange], SecurityExchange_ );
}

void
snapshot::set_SecurityExchange( const std::string& val )
{
  SecurityExchange_ = val;
  presence_map_[ix_SecurityExchange] = true;
}

const std::vector<snapshot::mdentries>&
snapshot::MDEntries() const
{
  return MDEntries_;
}

void
snapshot::add_MDEntries( const mdentries& val )
{
  MDEntries_.push_back( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

