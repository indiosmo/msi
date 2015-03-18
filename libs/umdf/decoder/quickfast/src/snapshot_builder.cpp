#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp>
#include <memory>
#include <Common/Types.h>
#include <Messages/Field.h>
#include <msi/umdf/common/typedefs.hpp>
#include <msi/decimal/decimal.hpp>
#include <msi/umdf/messages/field_id.hpp>
#include <msi/umdf/decoder/quickfast/setter_t.hpp>
#include <msi/umdf/decoder/quickfast/snapshot_builder.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace decoder
{
namespace quickfast
{

snapshot_builder::mdentries_builder::underlyings_builder::underlyings_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::UnderlyingSecurityID, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::snapshot::mdentries::underlyings::set_UnderlyingSecurityID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::UnderlyingSecurityIDSource, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::underlyings::set_UnderlyingSecurityIDSource, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::UnderlyingSecurityExchange, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::underlyings::set_UnderlyingSecurityExchange, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::UnderlyingPx, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::snapshot::mdentries::underlyings::set_UnderlyingPx, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::UnderlyingPxType, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::underlyings::set_UnderlyingPxType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

}

void
snapshot_builder::mdentries_builder::underlyings_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::snapshot::mdentries::underlyings&
snapshot_builder::mdentries_builder::underlyings_builder::get_message() const
{
  return message_;
}

void
snapshot_builder::mdentries_builder::underlyings_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

snapshot_builder::mdentries_builder::mdentries_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;

  builders_[m::field_id::NoUnderlyings] = &underlyings_builder_;
  add_setter( m::field_id::MDEntryType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_MDEntryType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::Currency, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_Currency, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MDEntryPx, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::snapshot::mdentries::set_MDEntryPx, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::MDEntryInterestRate, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::snapshot::mdentries::set_MDEntryInterestRate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::IndexSeq, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_IndexSeq, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::MDEntrySize, q::ValueType::INT64,
              std::make_shared<setter<int64_t>>(
                std::bind( &m::snapshot::mdentries::set_MDEntrySize, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::MDEntrySize, q::ValueType::INT32,
              std::make_shared<setter<int64_t>>(
                std::bind( &m::snapshot::mdentries::set_MDEntrySize, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradeVolume, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::snapshot::mdentries::set_TradeVolume, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradeVolume, q::ValueType::UINT32,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::snapshot::mdentries::set_TradeVolume, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::MDEntryDate, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_MDEntryDate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::MDEntryTime, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_MDEntryTime, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MDInsertDate, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_MDInsertDate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::MDInsertTime, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_MDInsertTime, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::TickDirection, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_TickDirection, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::NetChgPrevDay, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::snapshot::mdentries::set_NetChgPrevDay, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::MDStreamID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_MDStreamID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::PriceType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_PriceType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradingSessionSubID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_TradingSessionSubID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityTradingStatus, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_SecurityTradingStatus, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradSesOpenTime, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::snapshot::mdentries::set_TradSesOpenTime, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradSesOpenTime, q::ValueType::UINT32,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::snapshot::mdentries::set_TradSesOpenTime, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradingSessionID, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_TradingSessionID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityTradingEvent, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_SecurityTradingEvent, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradeCondition, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_TradeCondition, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::OpenCloseSettlFlag, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_OpenCloseSettlFlag, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::OpenCloseSettlFlag, q::ValueType::ASCII,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_OpenCloseSettlFlag, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return boost::lexical_cast<uint32_t>( field->toString() );
  }, p::_1 ) ) );

  add_setter( m::field_id::OrderID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_OrderID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradeID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_TradeID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MDEntryBuyer, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_MDEntryBuyer, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MDEntrySeller, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_MDEntrySeller, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::QuoteCondition, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_QuoteCondition, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::NumberOfOrders, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_NumberOfOrders, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::MDEntryPositionNo, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_MDEntryPositionNo, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::DayCumQty, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_DayCumQty, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SellerDays, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_SellerDays, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SettPriceType, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_SettPriceType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::LastTradeDate, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_LastTradeDate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::PriceAdjustmentMethod, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_PriceAdjustmentMethod, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::PriceLimitType, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_PriceLimitType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::LowLimitPrice, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::snapshot::mdentries::set_LowLimitPrice, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::HighLimitPrice, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::snapshot::mdentries::set_HighLimitPrice, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::TradingReferencePrice, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::snapshot::mdentries::set_TradingReferencePrice, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::PriceBandMidpointPriceType, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::mdentries::set_PriceBandMidpointPriceType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::AvgDailyTradedQty, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::snapshot::mdentries::set_AvgDailyTradedQty, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::ExpireDate, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::snapshot::mdentries::set_ExpireDate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::EarlyTermination, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::snapshot::mdentries::set_EarlyTermination, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::MaxTradeVol, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::snapshot::mdentries::set_MaxTradeVol, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::PriceBandType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::mdentries::set_PriceBandType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  static_cast<snapshot_builder::mdentries_builder::underlyings_builder*>
  ( builders_[m::field_id::NoUnderlyings] )->register_on_message_callback( std::bind (
        &mdentries_builder::add_Underlyings, this, p::_1 ) );

}

void
snapshot_builder::mdentries_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::snapshot::mdentries&
snapshot_builder::mdentries_builder::get_message() const
{
  return message_;
}

qm::ValueMessageBuilder&
snapshot_builder::mdentries_builder::startSequence( const qm::FieldIdentity& identity,
    const std::string& applicationType,
    const std::string& applicationTypeNamespace,
    size_t fieldCount,
    const qm::FieldIdentity& lengthIdentity,
    size_t length )
{
  auto builder = builders_.find( lengthIdentity.id() );

  if ( builder != builders_.end() )
  {
    return *( builder->second );
  }
  else
  {
    std::stringstream ss;
    ss << "Unsupported sequence " << lengthIdentity.getLocalName() << "[" << lengthIdentity.id() << "]";
    throw std::runtime_error( ss.str() );
  }
}

void
snapshot_builder::mdentries_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

void
snapshot_builder::mdentries_builder::add_Underlyings( const messages::snapshot::mdentries::underlyings& entry )
{
  message_.add_Underlyings( entry );
}

snapshot_builder::snapshot_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;

  builders_[m::field_id::NoMDEntries] = &mdentries_builder_;
  add_setter( m::field_id::MsgType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::set_MsgType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MsgSeqNum, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::set_MsgSeqNum, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::ApplVerID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::set_ApplVerID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SendingTime, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::snapshot::set_SendingTime, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::LastMsgSeqNumProcessed, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::set_LastMsgSeqNumProcessed, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::TotNumReports, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::set_TotNumReports, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::TradeDate, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::set_TradeDate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::MDReqID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::set_MDReqID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MarketDepth, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::snapshot::set_MarketDepth, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::RptSeq, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::set_RptSeq, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityID, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::snapshot::set_SecurityID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityIDSource, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::snapshot::set_SecurityIDSource, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityExchange, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::snapshot::set_SecurityExchange, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  static_cast<snapshot_builder::mdentries_builder*>
  ( builders_[m::field_id::NoMDEntries] )->register_on_message_callback( std::bind (
        &snapshot_builder::add_MDEntries, this, p::_1 ) );

}

void
snapshot_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::snapshot&
snapshot_builder::get_message() const
{
  return message_;
}

qm::ValueMessageBuilder&
snapshot_builder::startSequence( const qm::FieldIdentity& identity,
                                 const std::string& applicationType,
                                 const std::string& applicationTypeNamespace,
                                 size_t fieldCount,
                                 const qm::FieldIdentity& lengthIdentity,
                                 size_t length )
{
  auto builder = builders_.find( lengthIdentity.id() );

  if ( builder != builders_.end() )
  {
    return *( builder->second );
  }
  else
  {
    std::stringstream ss;
    ss << "Unsupported sequence " << lengthIdentity.getLocalName() << "[" << lengthIdentity.id() << "]";
    throw std::runtime_error( ss.str() );
  }
}

bool
snapshot_builder::endMessage( qm::ValueMessageBuilder& messageBuilder )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();

  return true;
}

void
snapshot_builder::add_MDEntries( const messages::snapshot::mdentries& entry )
{
  message_.add_MDEntries( entry );
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
