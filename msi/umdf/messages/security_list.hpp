#ifndef APOENA_MSI_UMDF_MESSAGES_SECURITY_LIST_HPP
#define APOENA_MSI_UMDF_MESSAGES_SECURITY_LIST_HPP

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

class UMDF_MESSAGES_Export security_list
{
public:

  class UMDF_MESSAGES_Export relatedsym
  {
  public:

    class UMDF_MESSAGES_Export applids
    {
    public:

      class UMDF_MESSAGES_Export feedtypes
      {
      public:

        enum field_index
        {
          ix_MDFeedType = 0,
          ix_MarketDepth,
          ix_field_count
        };

        void reset();

        std::pair<bool, const std::string&> MDFeedType() const;
        void set_MDFeedType( const std::string& val );

        std::pair<bool, uint32_t> MarketDepth() const;
        void set_MarketDepth( uint32_t val );

      private:
        std::bitset<ix_field_count> presence_map_;

        std::string MDFeedType_;
        uint32_t MarketDepth_;

      };

      enum field_index
      {
        ix_ApplID = 0,
        ix_FeedTypes,
        ix_field_count
      };

      void reset();

      std::pair<bool, const std::string&> ApplID() const;
      void set_ApplID( const std::string& val );

      const std::vector<feedtypes>& FeedTypes() const;
      void add_FeedTypes( const feedtypes& val );

    private:
      std::bitset<ix_field_count> presence_map_;

      std::string ApplID_;
      std::vector<feedtypes> FeedTypes_;

    };

    class UMDF_MESSAGES_Export securityaltids
    {
    public:

      enum field_index
      {
        ix_SecurityAltID = 0,
        ix_SecurityAltIDSource,
        ix_field_count
      };

      void reset();

      std::pair<bool, const std::string&> SecurityAltID() const;
      void set_SecurityAltID( const std::string& val );

      std::pair<bool, const std::string&> SecurityAltIDSource() const;
      void set_SecurityAltIDSource( const std::string& val );

    private:
      std::bitset<ix_field_count> presence_map_;

      std::string SecurityAltID_;
      std::string SecurityAltIDSource_;

    };

    class UMDF_MESSAGES_Export underlyings
    {
    public:

      enum field_index
      {
        ix_UnderlyingSymbol = 0,
        ix_UnderlyingSecurityID,
        ix_UnderlyingSecurityIDSource,
        ix_UnderlyingSecurityExchange,
        ix_IndexPct,
        ix_IndexTheoreticalQty,
        ix_field_count
      };

      void reset();

      std::pair<bool, const std::string&> UnderlyingSymbol() const;
      void set_UnderlyingSymbol( const std::string& val );

      std::pair<bool, uint64_t> UnderlyingSecurityID() const;
      void set_UnderlyingSecurityID( uint64_t val );

      std::pair<bool, const std::string&> UnderlyingSecurityIDSource() const;
      void set_UnderlyingSecurityIDSource( const std::string& val );

      std::pair<bool, const std::string&> UnderlyingSecurityExchange() const;
      void set_UnderlyingSecurityExchange( const std::string& val );

      std::pair<bool, decimal> IndexPct() const;
      void set_IndexPct( decimal val );

      std::pair<bool, decimal> IndexTheoreticalQty() const;
      void set_IndexTheoreticalQty( decimal val );

    private:
      std::bitset<ix_field_count> presence_map_;

      std::string UnderlyingSymbol_;
      uint64_t UnderlyingSecurityID_;
      std::string UnderlyingSecurityIDSource_;
      std::string UnderlyingSecurityExchange_;
      decimal IndexPct_;
      decimal IndexTheoreticalQty_;

    };

    class UMDF_MESSAGES_Export instrattrib
    {
    public:

      enum field_index
      {
        ix_InstAttribType = 0,
        ix_InstAttribValue,
        ix_field_count
      };

      void reset();

      std::pair<bool, int32_t> InstAttribType() const;
      void set_InstAttribType( int32_t val );

      std::pair<bool, const std::string&> InstAttribValue() const;
      void set_InstAttribValue( const std::string& val );

    private:
      std::bitset<ix_field_count> presence_map_;

      int32_t InstAttribType_;
      std::string InstAttribValue_;

    };

    class UMDF_MESSAGES_Export tickrules
    {
    public:

      enum field_index
      {
        ix_StartTickPriceRange = 0,
        ix_EndTickPriceRange,
        ix_TickIncrement,
        ix_TickRuleType,
        ix_field_count
      };

      void reset();

      std::pair<bool, decimal> StartTickPriceRange() const;
      void set_StartTickPriceRange( decimal val );

      std::pair<bool, decimal> EndTickPriceRange() const;
      void set_EndTickPriceRange( decimal val );

      std::pair<bool, decimal> TickIncrement() const;
      void set_TickIncrement( decimal val );

      std::pair<bool, int32_t> TickRuleType() const;
      void set_TickRuleType( int32_t val );

    private:
      std::bitset<ix_field_count> presence_map_;

      decimal StartTickPriceRange_;
      decimal EndTickPriceRange_;
      decimal TickIncrement_;
      int32_t TickRuleType_;

    };

    class UMDF_MESSAGES_Export legs
    {
    public:

      enum field_index
      {
        ix_LegSymbol = 0,
        ix_LegSecurityID,
        ix_LegSecurityIDSource,
        ix_LegRatioQty,
        ix_LegSecurityType,
        ix_LegSide,
        ix_LegSecurityExchange,
        ix_field_count
      };

      void reset();

      std::pair<bool, const std::string&> LegSymbol() const;
      void set_LegSymbol( const std::string& val );

      std::pair<bool, uint64_t> LegSecurityID() const;
      void set_LegSecurityID( uint64_t val );

      std::pair<bool, const std::string&> LegSecurityIDSource() const;
      void set_LegSecurityIDSource( const std::string& val );

      std::pair<bool, int32_t> LegRatioQty() const;
      void set_LegRatioQty( int32_t val );

      std::pair<bool, const std::string&> LegSecurityType() const;
      void set_LegSecurityType( const std::string& val );

      std::pair<bool, int32_t> LegSide() const;
      void set_LegSide( int32_t val );

      std::pair<bool, const std::string&> LegSecurityExchange() const;
      void set_LegSecurityExchange( const std::string& val );

    private:
      std::bitset<ix_field_count> presence_map_;

      std::string LegSymbol_;
      uint64_t LegSecurityID_;
      std::string LegSecurityIDSource_;
      int32_t LegRatioQty_;
      std::string LegSecurityType_;
      int32_t LegSide_;
      std::string LegSecurityExchange_;

    };

    class UMDF_MESSAGES_Export lots
    {
    public:

      enum field_index
      {
        ix_LotType = 0,
        ix_MinLotSize,
        ix_field_count
      };

      void reset();

      std::pair<bool, int32_t> LotType() const;
      void set_LotType( int32_t val );

      std::pair<bool, uint32_t> MinLotSize() const;
      void set_MinLotSize( uint32_t val );

    private:
      std::bitset<ix_field_count> presence_map_;

      int32_t LotType_;
      uint32_t MinLotSize_;

    };

    enum field_index
    {
      ix_Symbol = 0,
      ix_SecurityID,
      ix_SecurityIDSource,
      ix_SecurityExchange,
      ix_ApplIDs,
      ix_SecurityAltIDs,
      ix_Underlyings,
      ix_ImpliedMarketIndicator,
      ix_InstrAttrib,
      ix_TickRules,
      ix_Legs,
      ix_SecurityUpdateAction,
      ix_RoundLot,
      ix_MinTradeVol,
      ix_Lots,
      ix_MinPriceIncrement,
      ix_TickSizeDenominator,
      ix_PriceDivisor,
      ix_MinOrderQty,
      ix_MaxOrderQty,
      ix_InstrumentID,
      ix_MultiLegModel,
      ix_MultiLegPriceMethod,
      ix_Currency,
      ix_SettlCurrency,
      ix_Product,
      ix_SecurityType,
      ix_SecuritySubType,
      ix_SecurityStrategyType,
      ix_Asset,
      ix_SecurityDesc,
      ix_NoShareIssued,
      ix_MaturityDate,
      ix_MaturityMonthYear,
      ix_StrikePrice,
      ix_StrikeCurrency,
      ix_ExerciseStyle,
      ix_PutOrCall,
      ix_ContractMultiplier,
      ix_ContractSettlMonth,
      ix_CFICode,
      ix_CountryOfIssue,
      ix_IssueDate,
      ix_DatedDate,
      ix_StartDate,
      ix_EndDate,
      ix_SettlType,
      ix_SettlDate,
      ix_SecurityValidityTimestamp,
      ix_MarketSegmentID,
      ix_GovernanceIndicator,
      ix_CorporateActionEventID,
      ix_SecurityGroup,
      ix_SecurityMatchType,
      ix_field_count
    };

    void reset();

    std::pair<bool, const std::string&> Symbol() const;
    void set_Symbol( const std::string& val );

    std::pair<bool, uint64_t> SecurityID() const;
    void set_SecurityID( uint64_t val );

    std::pair<bool, const std::string&> SecurityIDSource() const;
    void set_SecurityIDSource( const std::string& val );

    std::pair<bool, const std::string&> SecurityExchange() const;
    void set_SecurityExchange( const std::string& val );

    const std::vector<applids>& ApplIDs() const;
    void add_ApplIDs( const applids& val );

    const std::vector<securityaltids>& SecurityAltIDs() const;
    void add_SecurityAltIDs( const securityaltids& val );

    const std::vector<underlyings>& Underlyings() const;
    void add_Underlyings( const underlyings& val );

    std::pair<bool, int32_t> ImpliedMarketIndicator() const;
    void set_ImpliedMarketIndicator( int32_t val );

    const std::vector<instrattrib>& InstrAttrib() const;
    void add_InstrAttrib( const instrattrib& val );

    const std::vector<tickrules>& TickRules() const;
    void add_TickRules( const tickrules& val );

    const std::vector<legs>& Legs() const;
    void add_Legs( const legs& val );

    std::pair<bool, const std::string&> SecurityUpdateAction() const;
    void set_SecurityUpdateAction( const std::string& val );

    std::pair<bool, uint32_t> RoundLot() const;
    void set_RoundLot( uint32_t val );

    std::pair<bool, uint64_t> MinTradeVol() const;
    void set_MinTradeVol( uint64_t val );

    const std::vector<lots>& Lots() const;
    void add_Lots( const lots& val );

    std::pair<bool, decimal> MinPriceIncrement() const;
    void set_MinPriceIncrement( decimal val );

    std::pair<bool, uint32_t> TickSizeDenominator() const;
    void set_TickSizeDenominator( uint32_t val );

    std::pair<bool, decimal> PriceDivisor() const;
    void set_PriceDivisor( decimal val );

    std::pair<bool, uint32_t> MinOrderQty() const;
    void set_MinOrderQty( uint32_t val );

    std::pair<bool, uint64_t> MaxOrderQty() const;
    void set_MaxOrderQty( uint64_t val );

    std::pair<bool, const std::string&> InstrumentID() const;
    void set_InstrumentID( const std::string& val );

    std::pair<bool, int32_t> MultiLegModel() const;
    void set_MultiLegModel( int32_t val );

    std::pair<bool, int32_t> MultiLegPriceMethod() const;
    void set_MultiLegPriceMethod( int32_t val );

    std::pair<bool, const std::string&> Currency() const;
    void set_Currency( const std::string& val );

    std::pair<bool, const std::string&> SettlCurrency() const;
    void set_SettlCurrency( const std::string& val );

    std::pair<bool, int32_t> Product() const;
    void set_Product( int32_t val );

    std::pair<bool, const std::string&> SecurityType() const;
    void set_SecurityType( const std::string& val );

    std::pair<bool, const std::string&> SecuritySubType() const;
    void set_SecuritySubType( const std::string& val );

    std::pair<bool, const std::string&> SecurityStrategyType() const;
    void set_SecurityStrategyType( const std::string& val );

    std::pair<bool, const std::string&> Asset() const;
    void set_Asset( const std::string& val );

    std::pair<bool, const std::string&> SecurityDesc() const;
    void set_SecurityDesc( const std::string& val );

    std::pair<bool, uint64_t> NoShareIssued() const;
    void set_NoShareIssued( uint64_t val );

    std::pair<bool, uint32_t> MaturityDate() const;
    void set_MaturityDate( uint32_t val );

    std::pair<bool, uint32_t> MaturityMonthYear() const;
    void set_MaturityMonthYear( uint32_t val );

    std::pair<bool, decimal> StrikePrice() const;
    void set_StrikePrice( decimal val );

    std::pair<bool, const std::string&> StrikeCurrency() const;
    void set_StrikeCurrency( const std::string& val );

    std::pair<bool, int32_t> ExerciseStyle() const;
    void set_ExerciseStyle( int32_t val );

    std::pair<bool, int32_t> PutOrCall() const;
    void set_PutOrCall( int32_t val );

    std::pair<bool, decimal> ContractMultiplier() const;
    void set_ContractMultiplier( decimal val );

    std::pair<bool, uint32_t> ContractSettlMonth() const;
    void set_ContractSettlMonth( uint32_t val );

    std::pair<bool, const std::string&> CFICode() const;
    void set_CFICode( const std::string& val );

    std::pair<bool, const std::string&> CountryOfIssue() const;
    void set_CountryOfIssue( const std::string& val );

    std::pair<bool, uint32_t> IssueDate() const;
    void set_IssueDate( uint32_t val );

    std::pair<bool, uint32_t> DatedDate() const;
    void set_DatedDate( uint32_t val );

    std::pair<bool, uint32_t> StartDate() const;
    void set_StartDate( uint32_t val );

    std::pair<bool, uint32_t> EndDate() const;
    void set_EndDate( uint32_t val );

    std::pair<bool, const std::string&> SettlType() const;
    void set_SettlType( const std::string& val );

    std::pair<bool, uint32_t> SettlDate() const;
    void set_SettlDate( uint32_t val );

    std::pair<bool, uint64_t> SecurityValidityTimestamp() const;
    void set_SecurityValidityTimestamp( uint64_t val );

    std::pair<bool, const std::string&> MarketSegmentID() const;
    void set_MarketSegmentID( const std::string& val );

    std::pair<bool, const std::string&> GovernanceIndicator() const;
    void set_GovernanceIndicator( const std::string& val );

    std::pair<bool, int32_t> CorporateActionEventID() const;
    void set_CorporateActionEventID( int32_t val );

    std::pair<bool, const std::string&> SecurityGroup() const;
    void set_SecurityGroup( const std::string& val );

    std::pair<bool, int32_t> SecurityMatchType() const;
    void set_SecurityMatchType( int32_t val );

  private:
    std::bitset<ix_field_count> presence_map_;

    std::string Symbol_;
    uint64_t SecurityID_;
    std::string SecurityIDSource_;
    std::string SecurityExchange_;
    std::vector<applids> ApplIDs_;
    std::vector<securityaltids> SecurityAltIDs_;
    std::vector<underlyings> Underlyings_;
    int32_t ImpliedMarketIndicator_;
    std::vector<instrattrib> InstrAttrib_;
    std::vector<tickrules> TickRules_;
    std::vector<legs> Legs_;
    std::string SecurityUpdateAction_;
    uint32_t RoundLot_;
    uint64_t MinTradeVol_;
    std::vector<lots> Lots_;
    decimal MinPriceIncrement_;
    uint32_t TickSizeDenominator_;
    decimal PriceDivisor_;
    uint32_t MinOrderQty_;
    uint64_t MaxOrderQty_;
    std::string InstrumentID_;
    int32_t MultiLegModel_;
    int32_t MultiLegPriceMethod_;
    std::string Currency_;
    std::string SettlCurrency_;
    int32_t Product_;
    std::string SecurityType_;
    std::string SecuritySubType_;
    std::string SecurityStrategyType_;
    std::string Asset_;
    std::string SecurityDesc_;
    uint64_t NoShareIssued_;
    uint32_t MaturityDate_;
    uint32_t MaturityMonthYear_;
    decimal StrikePrice_;
    std::string StrikeCurrency_;
    int32_t ExerciseStyle_;
    int32_t PutOrCall_;
    decimal ContractMultiplier_;
    uint32_t ContractSettlMonth_;
    std::string CFICode_;
    std::string CountryOfIssue_;
    uint32_t IssueDate_;
    uint32_t DatedDate_;
    uint32_t StartDate_;
    uint32_t EndDate_;
    std::string SettlType_;
    uint32_t SettlDate_;
    uint64_t SecurityValidityTimestamp_;
    std::string MarketSegmentID_;
    std::string GovernanceIndicator_;
    int32_t CorporateActionEventID_;
    std::string SecurityGroup_;
    int32_t SecurityMatchType_;

  };

  enum field_index
  {
    ix_MsgType = 0,
    ix_ApplVerID,
    ix_MsgSeqNum,
    ix_SendingTime,
    ix_TotNoRelatedSym,
    ix_LastFragment,
    ix_RelatedSym,
    ix_field_count
  };

  void reset();

  std::pair<bool, const std::string&> MsgType() const;
  void set_MsgType( const std::string& val );

  std::pair<bool, const std::string&> ApplVerID() const;
  void set_ApplVerID( const std::string& val );

  std::pair<bool, uint32_t> MsgSeqNum() const;
  void set_MsgSeqNum( uint32_t val );

  std::pair<bool, const std::string&> SendingTime() const;
  void set_SendingTime( const std::string& val );

  std::pair<bool, uint32_t> TotNoRelatedSym() const;
  void set_TotNoRelatedSym( uint32_t val );

  std::pair<bool, const std::string&> LastFragment() const;
  void set_LastFragment( const std::string& val );

  const std::vector<relatedsym>& RelatedSym() const;
  void add_RelatedSym( const relatedsym& val );

private:
  std::bitset<ix_field_count> presence_map_;

  std::string MsgType_;
  std::string ApplVerID_;
  uint32_t MsgSeqNum_;
  std::string SendingTime_;
  uint32_t TotNoRelatedSym_;
  std::string LastFragment_;
  std::vector<relatedsym> RelatedSym_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_MESSAGES_SECURITY_LIST_HPP */

