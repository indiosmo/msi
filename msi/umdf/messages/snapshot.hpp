#ifndef APOENA_MSI_UMDF_MESSAGES_SNAPSHOT_HPP
#define APOENA_MSI_UMDF_MESSAGES_SNAPSHOT_HPP

#include <bitset>
#include <utility>
#include <vector>
#include <msi/decimal/decimal.hpp>
#include <msi/umdf/messages/umdf_messages_export.hpp>
#include <msi/umdf/common/typedefs.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

class UMDF_MESSAGES_Export snapshot
{
public:

  class UMDF_MESSAGES_Export mdentries
  {
  public:

    class UMDF_MESSAGES_Export underlyings
    {
    public:

      enum field_index
      {
        ix_UnderlyingSecurityID = 0,
        ix_UnderlyingSecurityIDSource,
        ix_UnderlyingSecurityExchange,
        ix_UnderlyingPx,
        ix_UnderlyingPxType,
        ix_field_count
      };

      void reset();

      std::pair<bool, uint64_t> UnderlyingSecurityID() const;
      void set_UnderlyingSecurityID( uint64_t val );

      std::pair<bool, uint32_t> UnderlyingSecurityIDSource() const;
      void set_UnderlyingSecurityIDSource( uint32_t val );

      std::pair<bool, const std::string&> UnderlyingSecurityExchange() const;
      void set_UnderlyingSecurityExchange( const std::string& val );

      std::pair<bool, decimal> UnderlyingPx() const;
      void set_UnderlyingPx( decimal val );

      std::pair<bool, uint32_t> UnderlyingPxType() const;
      void set_UnderlyingPxType( uint32_t val );

    private:
      std::bitset<ix_field_count> presence_map_;

      uint64_t UnderlyingSecurityID_;
      uint32_t UnderlyingSecurityIDSource_;
      std::string UnderlyingSecurityExchange_;
      decimal UnderlyingPx_;
      uint32_t UnderlyingPxType_;

    };

    enum field_index
    {
      ix_MDEntryType = 0,
      ix_Currency,
      ix_MDEntryPx,
      ix_MDEntryInterestRate,
      ix_IndexSeq,
      ix_MDEntrySize,
      ix_TradeVolume,
      ix_MDEntryDate,
      ix_MDEntryTime,
      ix_MDInsertDate,
      ix_MDInsertTime,
      ix_TickDirection,
      ix_NetChgPrevDay,
      ix_MDStreamID,
      ix_PriceType,
      ix_TradingSessionSubID,
      ix_SecurityTradingStatus,
      ix_TradSesOpenTime,
      ix_TradingSessionID,
      ix_SecurityTradingEvent,
      ix_TradeCondition,
      ix_OpenCloseSettlFlag,
      ix_OrderID,
      ix_TradeID,
      ix_MDEntryBuyer,
      ix_MDEntrySeller,
      ix_QuoteCondition,
      ix_NumberOfOrders,
      ix_MDEntryPositionNo,
      ix_DayCumQty,
      ix_SellerDays,
      ix_SettPriceType,
      ix_LastTradeDate,
      ix_PriceAdjustmentMethod,
      ix_PriceLimitType,
      ix_LowLimitPrice,
      ix_HighLimitPrice,
      ix_TradingReferencePrice,
      ix_PriceBandMidpointPriceType,
      ix_AvgDailyTradedQty,
      ix_ExpireDate,
      ix_EarlyTermination,
      ix_MaxTradeVol,
      ix_PriceBandType,
      ix_Underlyings,
      ix_field_count
    };

    void reset();

    std::pair<bool, const std::string&> MDEntryType() const;
    void set_MDEntryType( const std::string& val );

    std::pair<bool, const std::string&> Currency() const;
    void set_Currency( const std::string& val );

    std::pair<bool, decimal> MDEntryPx() const;
    void set_MDEntryPx( decimal val );

    std::pair<bool, decimal> MDEntryInterestRate() const;
    void set_MDEntryInterestRate( decimal val );

    std::pair<bool, uint32_t> IndexSeq() const;
    void set_IndexSeq( uint32_t val );

    std::pair<bool, int64_t> MDEntrySize() const;
    void set_MDEntrySize( int64_t val );

    std::pair<bool, uint64_t> TradeVolume() const;
    void set_TradeVolume( uint64_t val );

    std::pair<bool, uint32_t> MDEntryDate() const;
    void set_MDEntryDate( uint32_t val );

    std::pair<bool, const std::string&> MDEntryTime() const;
    void set_MDEntryTime( const std::string& val );

    std::pair<bool, uint32_t> MDInsertDate() const;
    void set_MDInsertDate( uint32_t val );

    std::pair<bool, uint32_t> MDInsertTime() const;
    void set_MDInsertTime( uint32_t val );

    std::pair<bool, const std::string&> TickDirection() const;
    void set_TickDirection( const std::string& val );

    std::pair<bool, decimal> NetChgPrevDay() const;
    void set_NetChgPrevDay( decimal val );

    std::pair<bool, const std::string&> MDStreamID() const;
    void set_MDStreamID( const std::string& val );

    std::pair<bool, const std::string&> PriceType() const;
    void set_PriceType( const std::string& val );

    std::pair<bool, const std::string&> TradingSessionSubID() const;
    void set_TradingSessionSubID( const std::string& val );

    std::pair<bool, uint32_t> SecurityTradingStatus() const;
    void set_SecurityTradingStatus( uint32_t val );

    std::pair<bool, uint64_t> TradSesOpenTime() const;
    void set_TradSesOpenTime( uint64_t val );

    std::pair<bool, uint32_t> TradingSessionID() const;
    void set_TradingSessionID( uint32_t val );

    std::pair<bool, uint32_t> SecurityTradingEvent() const;
    void set_SecurityTradingEvent( uint32_t val );

    std::pair<bool, const std::string&> TradeCondition() const;
    void set_TradeCondition( const std::string& val );

    std::pair<bool, uint32_t> OpenCloseSettlFlag() const;
    void set_OpenCloseSettlFlag( uint32_t val );

    std::pair<bool, const std::string&> OrderID() const;
    void set_OrderID( const std::string& val );

    std::pair<bool, const std::string&> TradeID() const;
    void set_TradeID( const std::string& val );

    std::pair<bool, const std::string&> MDEntryBuyer() const;
    void set_MDEntryBuyer( const std::string& val );

    std::pair<bool, const std::string&> MDEntrySeller() const;
    void set_MDEntrySeller( const std::string& val );

    std::pair<bool, const std::string&> QuoteCondition() const;
    void set_QuoteCondition( const std::string& val );

    std::pair<bool, uint32_t> NumberOfOrders() const;
    void set_NumberOfOrders( uint32_t val );

    std::pair<bool, uint32_t> MDEntryPositionNo() const;
    void set_MDEntryPositionNo( uint32_t val );

    std::pair<bool, uint32_t> DayCumQty() const;
    void set_DayCumQty( uint32_t val );

    std::pair<bool, uint32_t> SellerDays() const;
    void set_SellerDays( uint32_t val );

    std::pair<bool, uint32_t> SettPriceType() const;
    void set_SettPriceType( uint32_t val );

    std::pair<bool, uint32_t> LastTradeDate() const;
    void set_LastTradeDate( uint32_t val );

    std::pair<bool, uint32_t> PriceAdjustmentMethod() const;
    void set_PriceAdjustmentMethod( uint32_t val );

    std::pair<bool, uint32_t> PriceLimitType() const;
    void set_PriceLimitType( uint32_t val );

    std::pair<bool, decimal> LowLimitPrice() const;
    void set_LowLimitPrice( decimal val );

    std::pair<bool, decimal> HighLimitPrice() const;
    void set_HighLimitPrice( decimal val );

    std::pair<bool, decimal> TradingReferencePrice() const;
    void set_TradingReferencePrice( decimal val );

    std::pair<bool, uint32_t> PriceBandMidpointPriceType() const;
    void set_PriceBandMidpointPriceType( uint32_t val );

    std::pair<bool, uint64_t> AvgDailyTradedQty() const;
    void set_AvgDailyTradedQty( uint64_t val );

    std::pair<bool, uint64_t> ExpireDate() const;
    void set_ExpireDate( uint64_t val );

    std::pair<bool, uint64_t> EarlyTermination() const;
    void set_EarlyTermination( uint64_t val );

    std::pair<bool, uint64_t> MaxTradeVol() const;
    void set_MaxTradeVol( uint64_t val );

    std::pair<bool, const std::string&> PriceBandType() const;
    void set_PriceBandType( const std::string& val );

    const std::vector<underlyings>& Underlyings() const;
    void add_Underlyings( const underlyings& val );

  private:
    std::bitset<ix_field_count> presence_map_;

    std::string MDEntryType_;
    std::string Currency_;
    decimal MDEntryPx_;
    decimal MDEntryInterestRate_;
    uint32_t IndexSeq_;
    int64_t MDEntrySize_;
    uint64_t TradeVolume_;
    uint32_t MDEntryDate_;
    std::string MDEntryTime_;
    uint32_t MDInsertDate_;
    uint32_t MDInsertTime_;
    std::string TickDirection_;
    decimal NetChgPrevDay_;
    std::string MDStreamID_;
    std::string PriceType_;
    std::string TradingSessionSubID_;
    uint32_t SecurityTradingStatus_;
    uint64_t TradSesOpenTime_;
    uint32_t TradingSessionID_;
    uint32_t SecurityTradingEvent_;
    std::string TradeCondition_;
    uint32_t OpenCloseSettlFlag_;
    std::string OrderID_;
    std::string TradeID_;
    std::string MDEntryBuyer_;
    std::string MDEntrySeller_;
    std::string QuoteCondition_;
    uint32_t NumberOfOrders_;
    uint32_t MDEntryPositionNo_;
    uint32_t DayCumQty_;
    uint32_t SellerDays_;
    uint32_t SettPriceType_;
    uint32_t LastTradeDate_;
    uint32_t PriceAdjustmentMethod_;
    uint32_t PriceLimitType_;
    decimal LowLimitPrice_;
    decimal HighLimitPrice_;
    decimal TradingReferencePrice_;
    uint32_t PriceBandMidpointPriceType_;
    uint64_t AvgDailyTradedQty_;
    uint64_t ExpireDate_;
    uint64_t EarlyTermination_;
    uint64_t MaxTradeVol_;
    std::string PriceBandType_;
    std::vector<underlyings> Underlyings_;

  };

  enum field_index
  {
    ix_MsgType = 0,
    ix_MsgSeqNum,
    ix_ApplVerID,
    ix_SendingTime,
    ix_LastMsgSeqNumProcessed,
    ix_TotNumReports,
    ix_TradeDate,
    ix_MDReqID,
    ix_MarketDepth,
    ix_RptSeq,
    ix_SecurityID,
    ix_SecurityIDSource,
    ix_SecurityExchange,
    ix_MDEntries,
    ix_field_count
  };

  void reset();

  std::pair<bool, const std::string&> MsgType() const;
  void set_MsgType( const std::string& val );

  std::pair<bool, uint32_t> MsgSeqNum() const;
  void set_MsgSeqNum( uint32_t val );

  std::pair<bool, const std::string&> ApplVerID() const;
  void set_ApplVerID( const std::string& val );

  std::pair<bool, uint64_t> SendingTime() const;
  void set_SendingTime( uint64_t val );

  std::pair<bool, uint32_t> LastMsgSeqNumProcessed() const;
  void set_LastMsgSeqNumProcessed( uint32_t val );

  std::pair<bool, uint32_t> TotNumReports() const;
  void set_TotNumReports( uint32_t val );

  std::pair<bool, uint32_t> TradeDate() const;
  void set_TradeDate( uint32_t val );

  std::pair<bool, const std::string&> MDReqID() const;
  void set_MDReqID( const std::string& val );

  std::pair<bool, int32_t> MarketDepth() const;
  void set_MarketDepth( int32_t val );

  std::pair<bool, uint32_t> RptSeq() const;
  void set_RptSeq( uint32_t val );

  std::pair<bool, uint64_t> SecurityID() const;
  void set_SecurityID( uint64_t val );

  std::pair<bool, uint32_t> SecurityIDSource() const;
  void set_SecurityIDSource( uint32_t val );

  std::pair<bool, const std::string&> SecurityExchange() const;
  void set_SecurityExchange( const std::string& val );

  const std::vector<mdentries>& MDEntries() const;
  void add_MDEntries( const mdentries& val );

private:
  std::bitset<ix_field_count> presence_map_;

  std::string MsgType_;
  uint32_t MsgSeqNum_;
  std::string ApplVerID_;
  uint64_t SendingTime_;
  uint32_t LastMsgSeqNumProcessed_;
  uint32_t TotNumReports_;
  uint32_t TradeDate_;
  std::string MDReqID_;
  int32_t MarketDepth_;
  uint32_t RptSeq_;
  uint64_t SecurityID_;
  uint32_t SecurityIDSource_;
  std::string SecurityExchange_;
  std::vector<mdentries> MDEntries_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_MESSAGES_SNAPSHOT_HPP */

