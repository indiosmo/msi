#include <msi/msi_pch.hpp>
#include <msi/umdf/messages/security_list.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace messages
{

void
security_list::relatedsym::applids::feedtypes::reset()
{
  presence_map_.reset();
}

std::pair<bool, const std::string&>
security_list::relatedsym::applids::feedtypes::MDFeedType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MDFeedType], MDFeedType_ );
}

void
security_list::relatedsym::applids::feedtypes::set_MDFeedType( const std::string& val )
{
  MDFeedType_ = val;
  presence_map_[ix_MDFeedType] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::applids::feedtypes::MarketDepth() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MarketDepth], MarketDepth_ );
}

void
security_list::relatedsym::applids::feedtypes::set_MarketDepth( uint32_t val )
{
  MarketDepth_ = val;
  presence_map_[ix_MarketDepth] = true;
}

void
security_list::relatedsym::applids::reset()
{
  presence_map_.reset();
  FeedTypes_.clear();
}

std::pair<bool, const std::string&>
security_list::relatedsym::applids::ApplID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_ApplID], ApplID_ );
}

void
security_list::relatedsym::applids::set_ApplID( const std::string& val )
{
  ApplID_ = val;
  presence_map_[ix_ApplID] = true;
}

const std::vector<security_list::relatedsym::applids::feedtypes>&
security_list::relatedsym::applids::FeedTypes() const
{
  return FeedTypes_;
}

void
security_list::relatedsym::applids::add_FeedTypes( const feedtypes& val )
{
  FeedTypes_.push_back( val );
}

void
security_list::relatedsym::securityaltids::reset()
{
  presence_map_.reset();
}

std::pair<bool, const std::string&>
security_list::relatedsym::securityaltids::SecurityAltID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityAltID], SecurityAltID_ );
}

void
security_list::relatedsym::securityaltids::set_SecurityAltID( const std::string& val )
{
  SecurityAltID_ = val;
  presence_map_[ix_SecurityAltID] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::securityaltids::SecurityAltIDSource() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityAltIDSource], SecurityAltIDSource_ );
}

void
security_list::relatedsym::securityaltids::set_SecurityAltIDSource( const std::string& val )
{
  SecurityAltIDSource_ = val;
  presence_map_[ix_SecurityAltIDSource] = true;
}

void
security_list::relatedsym::underlyings::reset()
{
  presence_map_.reset();
}

std::pair<bool, const std::string&>
security_list::relatedsym::underlyings::UnderlyingSymbol() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_UnderlyingSymbol], UnderlyingSymbol_ );
}

void
security_list::relatedsym::underlyings::set_UnderlyingSymbol( const std::string& val )
{
  UnderlyingSymbol_ = val;
  presence_map_[ix_UnderlyingSymbol] = true;
}

std::pair<bool, uint64_t>
security_list::relatedsym::underlyings::UnderlyingSecurityID() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_UnderlyingSecurityID], UnderlyingSecurityID_ );
}

void
security_list::relatedsym::underlyings::set_UnderlyingSecurityID( uint64_t val )
{
  UnderlyingSecurityID_ = val;
  presence_map_[ix_UnderlyingSecurityID] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::underlyings::UnderlyingSecurityIDSource() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_UnderlyingSecurityIDSource], UnderlyingSecurityIDSource_ );
}

void
security_list::relatedsym::underlyings::set_UnderlyingSecurityIDSource( const std::string& val )
{
  UnderlyingSecurityIDSource_ = val;
  presence_map_[ix_UnderlyingSecurityIDSource] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::underlyings::UnderlyingSecurityExchange() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_UnderlyingSecurityExchange], UnderlyingSecurityExchange_ );
}

void
security_list::relatedsym::underlyings::set_UnderlyingSecurityExchange( const std::string& val )
{
  UnderlyingSecurityExchange_ = val;
  presence_map_[ix_UnderlyingSecurityExchange] = true;
}

std::pair<bool, decimal>
security_list::relatedsym::underlyings::IndexPct() const
{
  return std::pair<bool, decimal>( presence_map_[ix_IndexPct], IndexPct_ );
}

void
security_list::relatedsym::underlyings::set_IndexPct( decimal val )
{
  IndexPct_ = val;
  presence_map_[ix_IndexPct] = true;
}

std::pair<bool, decimal>
security_list::relatedsym::underlyings::IndexTheoreticalQty() const
{
  return std::pair<bool, decimal>( presence_map_[ix_IndexTheoreticalQty], IndexTheoreticalQty_ );
}

void
security_list::relatedsym::underlyings::set_IndexTheoreticalQty( decimal val )
{
  IndexTheoreticalQty_ = val;
  presence_map_[ix_IndexTheoreticalQty] = true;
}

void
security_list::relatedsym::instrattrib::reset()
{
  presence_map_.reset();
}

std::pair<bool, int32_t>
security_list::relatedsym::instrattrib::InstAttribType() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_InstAttribType], InstAttribType_ );
}

void
security_list::relatedsym::instrattrib::set_InstAttribType( int32_t val )
{
  InstAttribType_ = val;
  presence_map_[ix_InstAttribType] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::instrattrib::InstAttribValue() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_InstAttribValue], InstAttribValue_ );
}

void
security_list::relatedsym::instrattrib::set_InstAttribValue( const std::string& val )
{
  InstAttribValue_ = val;
  presence_map_[ix_InstAttribValue] = true;
}

void
security_list::relatedsym::tickrules::reset()
{
  presence_map_.reset();
}

std::pair<bool, decimal>
security_list::relatedsym::tickrules::StartTickPriceRange() const
{
  return std::pair<bool, decimal>( presence_map_[ix_StartTickPriceRange], StartTickPriceRange_ );
}

void
security_list::relatedsym::tickrules::set_StartTickPriceRange( decimal val )
{
  StartTickPriceRange_ = val;
  presence_map_[ix_StartTickPriceRange] = true;
}

std::pair<bool, decimal>
security_list::relatedsym::tickrules::EndTickPriceRange() const
{
  return std::pair<bool, decimal>( presence_map_[ix_EndTickPriceRange], EndTickPriceRange_ );
}

void
security_list::relatedsym::tickrules::set_EndTickPriceRange( decimal val )
{
  EndTickPriceRange_ = val;
  presence_map_[ix_EndTickPriceRange] = true;
}

std::pair<bool, decimal>
security_list::relatedsym::tickrules::TickIncrement() const
{
  return std::pair<bool, decimal>( presence_map_[ix_TickIncrement], TickIncrement_ );
}

void
security_list::relatedsym::tickrules::set_TickIncrement( decimal val )
{
  TickIncrement_ = val;
  presence_map_[ix_TickIncrement] = true;
}

std::pair<bool, int32_t>
security_list::relatedsym::tickrules::TickRuleType() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_TickRuleType], TickRuleType_ );
}

void
security_list::relatedsym::tickrules::set_TickRuleType( int32_t val )
{
  TickRuleType_ = val;
  presence_map_[ix_TickRuleType] = true;
}

void
security_list::relatedsym::legs::reset()
{
  presence_map_.reset();
}

std::pair<bool, const std::string&>
security_list::relatedsym::legs::LegSymbol() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_LegSymbol], LegSymbol_ );
}

void
security_list::relatedsym::legs::set_LegSymbol( const std::string& val )
{
  LegSymbol_ = val;
  presence_map_[ix_LegSymbol] = true;
}

std::pair<bool, uint64_t>
security_list::relatedsym::legs::LegSecurityID() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_LegSecurityID], LegSecurityID_ );
}

void
security_list::relatedsym::legs::set_LegSecurityID( uint64_t val )
{
  LegSecurityID_ = val;
  presence_map_[ix_LegSecurityID] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::legs::LegSecurityIDSource() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_LegSecurityIDSource], LegSecurityIDSource_ );
}

void
security_list::relatedsym::legs::set_LegSecurityIDSource( const std::string& val )
{
  LegSecurityIDSource_ = val;
  presence_map_[ix_LegSecurityIDSource] = true;
}

std::pair<bool, int32_t>
security_list::relatedsym::legs::LegRatioQty() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_LegRatioQty], LegRatioQty_ );
}

void
security_list::relatedsym::legs::set_LegRatioQty( int32_t val )
{
  LegRatioQty_ = val;
  presence_map_[ix_LegRatioQty] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::legs::LegSecurityType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_LegSecurityType], LegSecurityType_ );
}

void
security_list::relatedsym::legs::set_LegSecurityType( const std::string& val )
{
  LegSecurityType_ = val;
  presence_map_[ix_LegSecurityType] = true;
}

std::pair<bool, int32_t>
security_list::relatedsym::legs::LegSide() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_LegSide], LegSide_ );
}

void
security_list::relatedsym::legs::set_LegSide( int32_t val )
{
  LegSide_ = val;
  presence_map_[ix_LegSide] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::legs::LegSecurityExchange() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_LegSecurityExchange], LegSecurityExchange_ );
}

void
security_list::relatedsym::legs::set_LegSecurityExchange( const std::string& val )
{
  LegSecurityExchange_ = val;
  presence_map_[ix_LegSecurityExchange] = true;
}

void
security_list::relatedsym::lots::reset()
{
  presence_map_.reset();
}

std::pair<bool, int32_t>
security_list::relatedsym::lots::LotType() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_LotType], LotType_ );
}

void
security_list::relatedsym::lots::set_LotType( int32_t val )
{
  LotType_ = val;
  presence_map_[ix_LotType] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::lots::MinLotSize() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MinLotSize], MinLotSize_ );
}

void
security_list::relatedsym::lots::set_MinLotSize( uint32_t val )
{
  MinLotSize_ = val;
  presence_map_[ix_MinLotSize] = true;
}

void
security_list::relatedsym::reset()
{
  presence_map_.reset();
  ApplIDs_.clear();
  SecurityAltIDs_.clear();
  Underlyings_.clear();
  InstrAttrib_.clear();
  TickRules_.clear();
  Legs_.clear();
  Lots_.clear();
}

std::pair<bool, const std::string&>
security_list::relatedsym::Symbol() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_Symbol], Symbol_ );
}

void
security_list::relatedsym::set_Symbol( const std::string& val )
{
  Symbol_ = val;
  presence_map_[ix_Symbol] = true;
}

std::pair<bool, uint64_t>
security_list::relatedsym::SecurityID() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_SecurityID], SecurityID_ );
}

void
security_list::relatedsym::set_SecurityID( uint64_t val )
{
  SecurityID_ = val;
  presence_map_[ix_SecurityID] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::SecurityIDSource() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityIDSource], SecurityIDSource_ );
}

void
security_list::relatedsym::set_SecurityIDSource( const std::string& val )
{
  SecurityIDSource_ = val;
  presence_map_[ix_SecurityIDSource] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::SecurityExchange() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityExchange], SecurityExchange_ );
}

void
security_list::relatedsym::set_SecurityExchange( const std::string& val )
{
  SecurityExchange_ = val;
  presence_map_[ix_SecurityExchange] = true;
}

const std::vector<security_list::relatedsym::applids>&
security_list::relatedsym::ApplIDs() const
{
  return ApplIDs_;
}

void
security_list::relatedsym::add_ApplIDs( const applids& val )
{
  ApplIDs_.push_back( val );
}

const std::vector<security_list::relatedsym::securityaltids>&
security_list::relatedsym::SecurityAltIDs() const
{
  return SecurityAltIDs_;
}

void
security_list::relatedsym::add_SecurityAltIDs( const securityaltids& val )
{
  SecurityAltIDs_.push_back( val );
}

const std::vector<security_list::relatedsym::underlyings>&
security_list::relatedsym::Underlyings() const
{
  return Underlyings_;
}

void
security_list::relatedsym::add_Underlyings( const underlyings& val )
{
  Underlyings_.push_back( val );
}

std::pair<bool, int32_t>
security_list::relatedsym::ImpliedMarketIndicator() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_ImpliedMarketIndicator], ImpliedMarketIndicator_ );
}

void
security_list::relatedsym::set_ImpliedMarketIndicator( int32_t val )
{
  ImpliedMarketIndicator_ = val;
  presence_map_[ix_ImpliedMarketIndicator] = true;
}

const std::vector<security_list::relatedsym::instrattrib>&
security_list::relatedsym::InstrAttrib() const
{
  return InstrAttrib_;
}

void
security_list::relatedsym::add_InstrAttrib( const instrattrib& val )
{
  InstrAttrib_.push_back( val );
}

const std::vector<security_list::relatedsym::tickrules>&
security_list::relatedsym::TickRules() const
{
  return TickRules_;
}

void
security_list::relatedsym::add_TickRules( const tickrules& val )
{
  TickRules_.push_back( val );
}

const std::vector<security_list::relatedsym::legs>&
security_list::relatedsym::Legs() const
{
  return Legs_;
}

void
security_list::relatedsym::add_Legs( const legs& val )
{
  Legs_.push_back( val );
}

std::pair<bool, const std::string&>
security_list::relatedsym::SecurityUpdateAction() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityUpdateAction], SecurityUpdateAction_ );
}

void
security_list::relatedsym::set_SecurityUpdateAction( const std::string& val )
{
  SecurityUpdateAction_ = val;
  presence_map_[ix_SecurityUpdateAction] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::RoundLot() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_RoundLot], RoundLot_ );
}

void
security_list::relatedsym::set_RoundLot( uint32_t val )
{
  RoundLot_ = val;
  presence_map_[ix_RoundLot] = true;
}

std::pair<bool, uint64_t>
security_list::relatedsym::MinTradeVol() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_MinTradeVol], MinTradeVol_ );
}

void
security_list::relatedsym::set_MinTradeVol( uint64_t val )
{
  MinTradeVol_ = val;
  presence_map_[ix_MinTradeVol] = true;
}

const std::vector<security_list::relatedsym::lots>&
security_list::relatedsym::Lots() const
{
  return Lots_;
}

void
security_list::relatedsym::add_Lots( const lots& val )
{
  Lots_.push_back( val );
}

std::pair<bool, decimal>
security_list::relatedsym::MinPriceIncrement() const
{
  return std::pair<bool, decimal>( presence_map_[ix_MinPriceIncrement], MinPriceIncrement_ );
}

void
security_list::relatedsym::set_MinPriceIncrement( decimal val )
{
  MinPriceIncrement_ = val;
  presence_map_[ix_MinPriceIncrement] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::TickSizeDenominator() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_TickSizeDenominator], TickSizeDenominator_ );
}

void
security_list::relatedsym::set_TickSizeDenominator( uint32_t val )
{
  TickSizeDenominator_ = val;
  presence_map_[ix_TickSizeDenominator] = true;
}

std::pair<bool, decimal>
security_list::relatedsym::PriceDivisor() const
{
  return std::pair<bool, decimal>( presence_map_[ix_PriceDivisor], PriceDivisor_ );
}

void
security_list::relatedsym::set_PriceDivisor( decimal val )
{
  PriceDivisor_ = val;
  presence_map_[ix_PriceDivisor] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::MinOrderQty() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MinOrderQty], MinOrderQty_ );
}

void
security_list::relatedsym::set_MinOrderQty( uint32_t val )
{
  MinOrderQty_ = val;
  presence_map_[ix_MinOrderQty] = true;
}

std::pair<bool, uint64_t>
security_list::relatedsym::MaxOrderQty() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_MaxOrderQty], MaxOrderQty_ );
}

void
security_list::relatedsym::set_MaxOrderQty( uint64_t val )
{
  MaxOrderQty_ = val;
  presence_map_[ix_MaxOrderQty] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::InstrumentID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_InstrumentID], InstrumentID_ );
}

void
security_list::relatedsym::set_InstrumentID( const std::string& val )
{
  InstrumentID_ = val;
  presence_map_[ix_InstrumentID] = true;
}

std::pair<bool, int32_t>
security_list::relatedsym::MultiLegModel() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_MultiLegModel], MultiLegModel_ );
}

void
security_list::relatedsym::set_MultiLegModel( int32_t val )
{
  MultiLegModel_ = val;
  presence_map_[ix_MultiLegModel] = true;
}

std::pair<bool, int32_t>
security_list::relatedsym::MultiLegPriceMethod() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_MultiLegPriceMethod], MultiLegPriceMethod_ );
}

void
security_list::relatedsym::set_MultiLegPriceMethod( int32_t val )
{
  MultiLegPriceMethod_ = val;
  presence_map_[ix_MultiLegPriceMethod] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::Currency() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_Currency], Currency_ );
}

void
security_list::relatedsym::set_Currency( const std::string& val )
{
  Currency_ = val;
  presence_map_[ix_Currency] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::SettlCurrency() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SettlCurrency], SettlCurrency_ );
}

void
security_list::relatedsym::set_SettlCurrency( const std::string& val )
{
  SettlCurrency_ = val;
  presence_map_[ix_SettlCurrency] = true;
}

std::pair<bool, int32_t>
security_list::relatedsym::Product() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_Product], Product_ );
}

void
security_list::relatedsym::set_Product( int32_t val )
{
  Product_ = val;
  presence_map_[ix_Product] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::SecurityType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityType], SecurityType_ );
}

void
security_list::relatedsym::set_SecurityType( const std::string& val )
{
  SecurityType_ = val;
  presence_map_[ix_SecurityType] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::SecuritySubType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecuritySubType], SecuritySubType_ );
}

void
security_list::relatedsym::set_SecuritySubType( const std::string& val )
{
  SecuritySubType_ = val;
  presence_map_[ix_SecuritySubType] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::SecurityStrategyType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityStrategyType], SecurityStrategyType_ );
}

void
security_list::relatedsym::set_SecurityStrategyType( const std::string& val )
{
  SecurityStrategyType_ = val;
  presence_map_[ix_SecurityStrategyType] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::Asset() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_Asset], Asset_ );
}

void
security_list::relatedsym::set_Asset( const std::string& val )
{
  Asset_ = val;
  presence_map_[ix_Asset] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::SecurityDesc() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityDesc], SecurityDesc_ );
}

void
security_list::relatedsym::set_SecurityDesc( const std::string& val )
{
  SecurityDesc_ = val;
  presence_map_[ix_SecurityDesc] = true;
}

std::pair<bool, uint64_t>
security_list::relatedsym::NoShareIssued() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_NoShareIssued], NoShareIssued_ );
}

void
security_list::relatedsym::set_NoShareIssued( uint64_t val )
{
  NoShareIssued_ = val;
  presence_map_[ix_NoShareIssued] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::MaturityDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MaturityDate], MaturityDate_ );
}

void
security_list::relatedsym::set_MaturityDate( uint32_t val )
{
  MaturityDate_ = val;
  presence_map_[ix_MaturityDate] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::MaturityMonthYear() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MaturityMonthYear], MaturityMonthYear_ );
}

void
security_list::relatedsym::set_MaturityMonthYear( uint32_t val )
{
  MaturityMonthYear_ = val;
  presence_map_[ix_MaturityMonthYear] = true;
}

std::pair<bool, decimal>
security_list::relatedsym::StrikePrice() const
{
  return std::pair<bool, decimal>( presence_map_[ix_StrikePrice], StrikePrice_ );
}

void
security_list::relatedsym::set_StrikePrice( decimal val )
{
  StrikePrice_ = val;
  presence_map_[ix_StrikePrice] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::StrikeCurrency() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_StrikeCurrency], StrikeCurrency_ );
}

void
security_list::relatedsym::set_StrikeCurrency( const std::string& val )
{
  StrikeCurrency_ = val;
  presence_map_[ix_StrikeCurrency] = true;
}

std::pair<bool, int32_t>
security_list::relatedsym::ExerciseStyle() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_ExerciseStyle], ExerciseStyle_ );
}

void
security_list::relatedsym::set_ExerciseStyle( int32_t val )
{
  ExerciseStyle_ = val;
  presence_map_[ix_ExerciseStyle] = true;
}

std::pair<bool, int32_t>
security_list::relatedsym::PutOrCall() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_PutOrCall], PutOrCall_ );
}

void
security_list::relatedsym::set_PutOrCall( int32_t val )
{
  PutOrCall_ = val;
  presence_map_[ix_PutOrCall] = true;
}

std::pair<bool, decimal>
security_list::relatedsym::ContractMultiplier() const
{
  return std::pair<bool, decimal>( presence_map_[ix_ContractMultiplier], ContractMultiplier_ );
}

void
security_list::relatedsym::set_ContractMultiplier( decimal val )
{
  ContractMultiplier_ = val;
  presence_map_[ix_ContractMultiplier] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::ContractSettlMonth() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_ContractSettlMonth], ContractSettlMonth_ );
}

void
security_list::relatedsym::set_ContractSettlMonth( uint32_t val )
{
  ContractSettlMonth_ = val;
  presence_map_[ix_ContractSettlMonth] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::CFICode() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_CFICode], CFICode_ );
}

void
security_list::relatedsym::set_CFICode( const std::string& val )
{
  CFICode_ = val;
  presence_map_[ix_CFICode] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::CountryOfIssue() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_CountryOfIssue], CountryOfIssue_ );
}

void
security_list::relatedsym::set_CountryOfIssue( const std::string& val )
{
  CountryOfIssue_ = val;
  presence_map_[ix_CountryOfIssue] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::IssueDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_IssueDate], IssueDate_ );
}

void
security_list::relatedsym::set_IssueDate( uint32_t val )
{
  IssueDate_ = val;
  presence_map_[ix_IssueDate] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::DatedDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_DatedDate], DatedDate_ );
}

void
security_list::relatedsym::set_DatedDate( uint32_t val )
{
  DatedDate_ = val;
  presence_map_[ix_DatedDate] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::StartDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_StartDate], StartDate_ );
}

void
security_list::relatedsym::set_StartDate( uint32_t val )
{
  StartDate_ = val;
  presence_map_[ix_StartDate] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::EndDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_EndDate], EndDate_ );
}

void
security_list::relatedsym::set_EndDate( uint32_t val )
{
  EndDate_ = val;
  presence_map_[ix_EndDate] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::SettlType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SettlType], SettlType_ );
}

void
security_list::relatedsym::set_SettlType( const std::string& val )
{
  SettlType_ = val;
  presence_map_[ix_SettlType] = true;
}

std::pair<bool, uint32_t>
security_list::relatedsym::SettlDate() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_SettlDate], SettlDate_ );
}

void
security_list::relatedsym::set_SettlDate( uint32_t val )
{
  SettlDate_ = val;
  presence_map_[ix_SettlDate] = true;
}

std::pair<bool, uint64_t>
security_list::relatedsym::SecurityValidityTimestamp() const
{
  return std::pair<bool, uint64_t>( presence_map_[ix_SecurityValidityTimestamp], SecurityValidityTimestamp_ );
}

void
security_list::relatedsym::set_SecurityValidityTimestamp( uint64_t val )
{
  SecurityValidityTimestamp_ = val;
  presence_map_[ix_SecurityValidityTimestamp] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::MarketSegmentID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MarketSegmentID], MarketSegmentID_ );
}

void
security_list::relatedsym::set_MarketSegmentID( const std::string& val )
{
  MarketSegmentID_ = val;
  presence_map_[ix_MarketSegmentID] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::GovernanceIndicator() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_GovernanceIndicator], GovernanceIndicator_ );
}

void
security_list::relatedsym::set_GovernanceIndicator( const std::string& val )
{
  GovernanceIndicator_ = val;
  presence_map_[ix_GovernanceIndicator] = true;
}

std::pair<bool, int32_t>
security_list::relatedsym::CorporateActionEventID() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_CorporateActionEventID], CorporateActionEventID_ );
}

void
security_list::relatedsym::set_CorporateActionEventID( int32_t val )
{
  CorporateActionEventID_ = val;
  presence_map_[ix_CorporateActionEventID] = true;
}

std::pair<bool, const std::string&>
security_list::relatedsym::SecurityGroup() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SecurityGroup], SecurityGroup_ );
}

void
security_list::relatedsym::set_SecurityGroup( const std::string& val )
{
  SecurityGroup_ = val;
  presence_map_[ix_SecurityGroup] = true;
}

std::pair<bool, int32_t>
security_list::relatedsym::SecurityMatchType() const
{
  return std::pair<bool, int32_t>( presence_map_[ix_SecurityMatchType], SecurityMatchType_ );
}

void
security_list::relatedsym::set_SecurityMatchType( int32_t val )
{
  SecurityMatchType_ = val;
  presence_map_[ix_SecurityMatchType] = true;
}

void
security_list::reset()
{
  presence_map_.reset();
  RelatedSym_.clear();
}

std::pair<bool, const std::string&>
security_list::MsgType() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_MsgType], MsgType_ );
}

void
security_list::set_MsgType( const std::string& val )
{
  MsgType_ = val;
  presence_map_[ix_MsgType] = true;
}

std::pair<bool, const std::string&>
security_list::ApplVerID() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_ApplVerID], ApplVerID_ );
}

void
security_list::set_ApplVerID( const std::string& val )
{
  ApplVerID_ = val;
  presence_map_[ix_ApplVerID] = true;
}

std::pair<bool, uint32_t>
security_list::MsgSeqNum() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_MsgSeqNum], MsgSeqNum_ );
}

void
security_list::set_MsgSeqNum( uint32_t val )
{
  MsgSeqNum_ = val;
  presence_map_[ix_MsgSeqNum] = true;
}

std::pair<bool, const std::string&>
security_list::SendingTime() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_SendingTime], SendingTime_ );
}

void
security_list::set_SendingTime( const std::string& val )
{
  SendingTime_ = val;
  presence_map_[ix_SendingTime] = true;
}

std::pair<bool, uint32_t>
security_list::TotNoRelatedSym() const
{
  return std::pair<bool, uint32_t>( presence_map_[ix_TotNoRelatedSym], TotNoRelatedSym_ );
}

void
security_list::set_TotNoRelatedSym( uint32_t val )
{
  TotNoRelatedSym_ = val;
  presence_map_[ix_TotNoRelatedSym] = true;
}

std::pair<bool, const std::string&>
security_list::LastFragment() const
{
  return std::pair<bool, const std::string&>( presence_map_[ix_LastFragment], LastFragment_ );
}

void
security_list::set_LastFragment( const std::string& val )
{
  LastFragment_ = val;
  presence_map_[ix_LastFragment] = true;
}

const std::vector<security_list::relatedsym>&
security_list::RelatedSym() const
{
  return RelatedSym_;
}

void
security_list::add_RelatedSym( const relatedsym& val )
{
  RelatedSym_.push_back( val );
}



} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

