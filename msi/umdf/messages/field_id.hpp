//Generated with libs/umdf/messages/tools/generate_field_ids.[bat/sh]
#ifndef APOENA_MSI_UMDF_MESSAGES_FIELD_ID_HPP
#define APOENA_MSI_UMDF_MESSAGES_FIELD_ID_HPP

#include <string>
#include <msi/umdf/messages/umdf_messages_export.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

typedef std::string field_id_t;

class UMDF_MESSAGES_Export field_id
{
public:
  static const field_id_t MessageType;
  static const field_id_t MsgSeqNum;
  static const field_id_t SendingTime;
  static const field_id_t ApplVerID;
  static const field_id_t DataLen;
  static const field_id_t Data;
  static const field_id_t MessageEncoding;
  static const field_id_t MDReqID;
  static const field_id_t MDReqRejReason;
  static const field_id_t Text;
  static const field_id_t MsgType;
  static const field_id_t TotNoRelatedSym;
  static const field_id_t LastFragment;
  static const field_id_t NoRelatedSym;
  static const field_id_t Symbol;
  static const field_id_t SecurityID;
  static const field_id_t SecurityIDSource;
  static const field_id_t SecurityExchange;
  static const field_id_t NoApplIDs;
  static const field_id_t ApplID;
  static const field_id_t NoMDFeedTypes;
  static const field_id_t MDFeedType;
  static const field_id_t MarketDepth;
  static const field_id_t NoSecurityAltID;
  static const field_id_t SecurityAltID;
  static const field_id_t SecurityAltIDSource;
  static const field_id_t NoUnderlyings;
  static const field_id_t UnderlyingSymbol;
  static const field_id_t UnderlyingSecurityID;
  static const field_id_t UnderlyingSecurityIDSource;
  static const field_id_t UnderlyingSecurityExchange;
  static const field_id_t IndexPct;
  static const field_id_t IndexTheoreticalQty;
  static const field_id_t ImpliedMarketIndicator;
  static const field_id_t NoInstrAttrib;
  static const field_id_t InstAttribType;
  static const field_id_t InstAttribValue;
  static const field_id_t NoTickRules;
  static const field_id_t StartTickPriceRange;
  static const field_id_t EndTickPriceRange;
  static const field_id_t TickIncrement;
  static const field_id_t TickRuleType;
  static const field_id_t NoLegs;
  static const field_id_t LegSymbol;
  static const field_id_t LegSecurityID;
  static const field_id_t LegSecurityIDSource;
  static const field_id_t LegRatioQty;
  static const field_id_t LegSecurityType;
  static const field_id_t LegSide;
  static const field_id_t LegSecurityExchange;
  static const field_id_t SecurityUpdateAction;
  static const field_id_t NoLotTypeRules;
  static const field_id_t LotType;
  static const field_id_t MinLotSize;
  static const field_id_t MinPriceIncrement;
  static const field_id_t TickSizeDenominator;
  static const field_id_t PriceDivisor;
  static const field_id_t MinOrderQty;
  static const field_id_t MaxOrderQty;
  static const field_id_t MultiLegModel;
  static const field_id_t MultiLegPriceMethod;
  static const field_id_t Currency;
  static const field_id_t SettlCurrency;
  static const field_id_t Product;
  static const field_id_t SecurityType;
  static const field_id_t SecuritySubType;
  static const field_id_t SecurityStrategyType;
  static const field_id_t Asset;
  static const field_id_t SecurityDesc;
  static const field_id_t NoShareIssued;
  static const field_id_t MaturityDate;
  static const field_id_t MaturityMonthYear;
  static const field_id_t StrikePrice;
  static const field_id_t StrikeCurrency;
  static const field_id_t ExerciseStyle;
  static const field_id_t PutOrCall;
  static const field_id_t ContractMultiplier;
  static const field_id_t ContractSettlMonth;
  static const field_id_t CFICode;
  static const field_id_t CountryOfIssue;
  static const field_id_t IssueDate;
  static const field_id_t DatedDate;
  static const field_id_t StartDate;
  static const field_id_t EndDate;
  static const field_id_t SettlType;
  static const field_id_t SettlDate;
  static const field_id_t SecurityValidityTimestamp;
  static const field_id_t MarketSegmentID;
  static const field_id_t GovernanceIndicator;
  static const field_id_t CorporateActionEventID;
  static const field_id_t SecurityGroup;
  static const field_id_t SecurityMatchType;
  static const field_id_t NoApplIds;
  static const field_id_t ApplId;
  static const field_id_t LegType;
  static const field_id_t BuyersPerspective;
  static const field_id_t RoundLot;
  static const field_id_t MinTradeVol;
  static const field_id_t InstrumentID;
  static const field_id_t PosDupFlag;
  static const field_id_t NoMDEntries;
  static const field_id_t MDUpdateAction;
  static const field_id_t MDPriceLevel;
  static const field_id_t MDEntryType;
  static const field_id_t RptSeq;
  static const field_id_t MDEntryPx;
  static const field_id_t MDEntryTime;
  static const field_id_t MDEntrySize;
  static const field_id_t QuoteCondition;
  static const field_id_t NumberOfOrders;
  static const field_id_t TradingSessionID;
  static const field_id_t TradeDate;
  static const field_id_t MDEntryInterestRate;
  static const field_id_t PriceType;
  static const field_id_t MDEntryDate;
  static const field_id_t MDInsertDate;
  static const field_id_t MDInsertTime;
  static const field_id_t MDStreamID;
  static const field_id_t NetChgPrevDay;
  static const field_id_t SellerDays;
  static const field_id_t TradeVolume;
  static const field_id_t TickDirection;
  static const field_id_t TradeCondition;
  static const field_id_t OpenCloseSettlFlag;
  static const field_id_t OrderID;
  static const field_id_t TradeID;
  static const field_id_t MDEntryBuyer;
  static const field_id_t MDEntrySeller;
  static const field_id_t MDEntryPositionNo;
  static const field_id_t SettPriceType;
  static const field_id_t LastTradeDate;
  static const field_id_t PriceAdjustmentMethod;
  static const field_id_t PriceBandType;
  static const field_id_t PriceLimitType;
  static const field_id_t LowLimitPrice;
  static const field_id_t HighLimitPrice;
  static const field_id_t TradingReferencePrice;
  static const field_id_t PriceBandMidpointPriceType;
  static const field_id_t AvgDailyTradedQty;
  static const field_id_t ExpireDate;
  static const field_id_t EarlyTermination;
  static const field_id_t MaxTradeVol;
  static const field_id_t UnderlyingPx;
  static const field_id_t UnderlyingPxType;
  static const field_id_t IndexSeq;
  static const field_id_t OpenCloseSettleFlag;
  static const field_id_t SettlePriceType;
  static const field_id_t TradingRefPrice;
  static const field_id_t TradingSessionSubID;
  static const field_id_t SecurityTradingStatus;
  static const field_id_t TradSesOpenTime;
  static const field_id_t TransactTime;
  static const field_id_t SecurityTradingEvent;
  static const field_id_t LastMsgSeqNumProcessed;
  static const field_id_t TotNumReports;
  static const field_id_t Curerncy;
  static const field_id_t DayCumQty;
  static const field_id_t OrigTime;
  static const field_id_t NewsSource;
  static const field_id_t NewsID;
  static const field_id_t LanguageCode;
  static const field_id_t Headline;
  static const field_id_t URLLink;
  static const field_id_t EncodedHeadlineLen;
  static const field_id_t EncodedHeadline;
  static const field_id_t NoLinesOfText;
  static const field_id_t EncodedTextLen;
  static const field_id_t EncodedText;
  static const field_id_t NoRoutingIDs;
  static const field_id_t RoutingType;
  static const field_id_t RoutingID;
  static const field_id_t text;
  static const field_id_t EncryptMethod;
  static const field_id_t HeartbeatInt;
  static const field_id_t DefaultApplVerID;
  static const field_id_t NewSeqNo;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_MESSAGES_FIELD_ID_HPP */

