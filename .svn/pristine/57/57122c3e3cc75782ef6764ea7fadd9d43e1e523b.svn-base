#ifndef APOENA_MSI_UMDF_MESSAGES_INCREMENTAL_HPP
#define APOENA_MSI_UMDF_MESSAGES_INCREMENTAL_HPP

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

class UMDF_MESSAGES_Export incremental
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
      ix_MDUpdateAction = 0,
      ix_MDPriceLevel,
      ix_MDEntryType,
      ix_Symbol,
      ix_SecurityIDSource,
      ix_SecurityExchange,
      ix_SecurityID,
      ix_RptSeq,
      ix_QuoteCondition,
      ix_MDEntryPx,
      ix_MDEntryInterestRate,
      ix_NumberOfOrders,
      ix_PriceType,
      ix_MDEntryTime,
      ix_MDEntrySize,
      ix_MDEntryDate,
      ix_MDInsertDate,
      ix_MDInsertTime,
      ix_MDStreamID,
      ix_Currency,
      ix_NetChgPrevDay,
      ix_SellerDays,
      ix_TradeVolume,
      ix_TickDirection,
      ix_TradeCondition,
      ix_TradingSessionID,
      ix_OpenCloseSettlFlag,
      ix_OrderID,
      ix_TradeID,
      ix_MDEntryBuyer,
      ix_MDEntrySeller,
      ix_MDEntryPositionNo,
      ix_SettlType,
      ix_SettlDate,
      ix_SettPriceType,
      ix_LastTradeDate,
      ix_PriceAdjustmentMethod,
      ix_PriceBandType,
      ix_PriceLimitType,
      ix_LowLimitPrice,
      ix_HighLimitPrice,
      ix_TradingReferencePrice,
      ix_PriceBandMidpointPriceType,
      ix_AvgDailyTradedQty,
      ix_ExpireDate,
      ix_EarlyTermination,
      ix_MaxTradeVol,
      ix_Underlyings,
      ix_IndexSeq,
      ix_field_count
    };

    void reset();

    std::pair<bool, uint32_t> MDUpdateAction() const;
    void set_MDUpdateAction( uint32_t val );

    std::pair<bool, uint32_t> MDPriceLevel() const;
    void set_MDPriceLevel( uint32_t val );

    std::pair<bool, const std::string&> MDEntryType() const;
    void set_MDEntryType( const std::string& val );

    std::pair<bool, const std::string&> Symbol() const;
    void set_Symbol( const std::string& val );

    std::pair<bool, uint32_t> SecurityIDSource() const;
    void set_SecurityIDSource( uint32_t val );

    std::pair<bool, const std::string&> SecurityExchange() const;
    void set_SecurityExchange( const std::string& val );

    std::pair<bool, uint64_t> SecurityID() const;
    void set_SecurityID( uint64_t val );

    std::pair<bool, uint32_t> RptSeq() const;
    void set_RptSeq( uint32_t val );

    std::pair<bool, const std::string&> QuoteCondition() const;
    void set_QuoteCondition( const std::string& val );

    std::pair<bool, decimal> MDEntryPx() const;
    void set_MDEntryPx( decimal val );

    std::pair<bool, decimal> MDEntryInterestRate() const;
    void set_MDEntryInterestRate( decimal val );

    std::pair<bool, uint32_t> NumberOfOrders() const;
    void set_NumberOfOrders( uint32_t val );

    std::pair<bool, const std::string&> PriceType() const;
    void set_PriceType( const std::string& val );

    std::pair<bool, uint32_t> MDEntryTime() const;
    void set_MDEntryTime( uint32_t val );

    std::pair<bool, int64_t> MDEntrySize() const;
    void set_MDEntrySize( int64_t val );

    std::pair<bool, uint32_t> MDEntryDate() const;
    void set_MDEntryDate( uint32_t val );

    std::pair<bool, uint32_t> MDInsertDate() const;
    void set_MDInsertDate( uint32_t val );

    std::pair<bool, uint32_t> MDInsertTime() const;
    void set_MDInsertTime( uint32_t val );

    std::pair<bool, const std::string&> MDStreamID() const;
    void set_MDStreamID( const std::string& val );

    std::pair<bool, const std::string&> Currency() const;
    void set_Currency( const std::string& val );

    std::pair<bool, decimal> NetChgPrevDay() const;
    void set_NetChgPrevDay( decimal val );

    std::pair<bool, uint32_t> SellerDays() const;
    void set_SellerDays( uint32_t val );

    std::pair<bool, uint64_t> TradeVolume() const;
    void set_TradeVolume( uint64_t val );

    std::pair<bool, const std::string&> TickDirection() const;
    void set_TickDirection( const std::string& val );

    std::pair<bool, const std::string&> TradeCondition() const;
    void set_TradeCondition( const std::string& val );

    std::pair<bool, uint32_t> TradingSessionID() const;
    void set_TradingSessionID( uint32_t val );

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

    std::pair<bool, uint32_t> MDEntryPositionNo() const;
    void set_MDEntryPositionNo( uint32_t val );

    std::pair<bool, const std::string&> SettlType() const;
    void set_SettlType( const std::string& val );

    std::pair<bool, uint32_t> SettlDate() const;
    void set_SettlDate( uint32_t val );

    std::pair<bool, uint32_t> SettPriceType() const;
    void set_SettPriceType( uint32_t val );

    std::pair<bool, uint32_t> LastTradeDate() const;
    void set_LastTradeDate( uint32_t val );

    std::pair<bool, uint32_t> PriceAdjustmentMethod() const;
    void set_PriceAdjustmentMethod( uint32_t val );

    std::pair<bool, const std::string&> PriceBandType() const;
    void set_PriceBandType( const std::string& val );

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

    const std::vector<underlyings>& Underlyings() const;
    void add_Underlyings( const underlyings& val );

    std::pair<bool, uint64_t> IndexSeq() const;
    void set_IndexSeq( uint64_t val );

  private:
    std::bitset<ix_field_count> presence_map_;

    uint32_t MDUpdateAction_;
    uint32_t MDPriceLevel_;
    std::string MDEntryType_;
    std::string Symbol_;
    uint32_t SecurityIDSource_;
    std::string SecurityExchange_;
    uint64_t SecurityID_;
    uint32_t RptSeq_;
    std::string QuoteCondition_;
    decimal MDEntryPx_;
    decimal MDEntryInterestRate_;
    uint32_t NumberOfOrders_;
    std::string PriceType_;
    uint32_t MDEntryTime_;
    int64_t MDEntrySize_;
    uint32_t MDEntryDate_;
    uint32_t MDInsertDate_;
    uint32_t MDInsertTime_;
    std::string MDStreamID_;
    std::string Currency_;
    decimal NetChgPrevDay_;
    uint32_t SellerDays_;
    uint64_t TradeVolume_;
    std::string TickDirection_;
    std::string TradeCondition_;
    uint32_t TradingSessionID_;
    uint32_t OpenCloseSettlFlag_;
    std::string OrderID_;
    std::string TradeID_;
    std::string MDEntryBuyer_;
    std::string MDEntrySeller_;
    uint32_t MDEntryPositionNo_;
    std::string SettlType_;
    uint32_t SettlDate_;
    uint32_t SettPriceType_;
    uint32_t LastTradeDate_;
    uint32_t PriceAdjustmentMethod_;
    std::string PriceBandType_;
    uint32_t PriceLimitType_;
    decimal LowLimitPrice_;
    decimal HighLimitPrice_;
    decimal TradingReferencePrice_;
    uint32_t PriceBandMidpointPriceType_;
    uint64_t AvgDailyTradedQty_;
    uint64_t ExpireDate_;
    uint64_t EarlyTermination_;
    uint64_t MaxTradeVol_;
    std::vector<underlyings> Underlyings_;
    uint64_t IndexSeq_;

  };

  enum field_index
  {
    ix_ApplVerID = 0,
    ix_MsgType,
    ix_MsgSeqNum,
    ix_SendingTime,
    ix_PosDupFlag,
    ix_TradeDate,
    ix_MDEntries,
    ix_field_count
  };

  void reset();

  std::pair<bool, const std::string&> ApplVerID() const;
  void set_ApplVerID( const std::string& val );

  std::pair<bool, const std::string&> MsgType() const;
  void set_MsgType( const std::string& val );

  std::pair<bool, uint32_t> MsgSeqNum() const;
  void set_MsgSeqNum( uint32_t val );

  std::pair<bool, uint64_t> SendingTime() const;
  void set_SendingTime( uint64_t val );

  std::pair<bool, const std::string&> PosDupFlag() const;
  void set_PosDupFlag( const std::string& val );

  std::pair<bool, uint32_t> TradeDate() const;
  void set_TradeDate( uint32_t val );

  const std::vector<mdentries>& MDEntries() const;
  void add_MDEntries( const mdentries& val );

private:
  std::bitset<ix_field_count> presence_map_;

  std::string ApplVerID_;
  std::string MsgType_;
  uint32_t MsgSeqNum_;
  uint64_t SendingTime_;
  std::string PosDupFlag_;
  uint32_t TradeDate_;
  std::vector<mdentries> MDEntries_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_MESSAGES_INCREMENTAL_HPP */

