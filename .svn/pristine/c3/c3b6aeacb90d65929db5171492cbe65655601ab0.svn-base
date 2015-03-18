#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_pch.hpp>
#include <memory>
#include <Common/Types.h>
#include <Messages/Field.h>
#include <msi/umdf/common/typedefs.hpp>
#include <msi/decimal/decimal.hpp>
#include <msi/umdf/messages/field_id.hpp>
#include <msi/umdf/decoder/quickfast/setter_t.hpp>
#include <msi/umdf/decoder/quickfast/security_list_builder.hpp>

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

security_list_builder::relatedsym_builder::applids_builder::feedtypes_builder::feedtypes_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::MDFeedType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::applids::feedtypes::set_MDFeedType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MarketDepth, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::applids::feedtypes::set_MarketDepth, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

}

void
security_list_builder::relatedsym_builder::applids_builder::feedtypes_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::security_list::relatedsym::applids::feedtypes&
security_list_builder::relatedsym_builder::applids_builder::feedtypes_builder::get_message() const
{
  return message_;
}

void
security_list_builder::relatedsym_builder::applids_builder::feedtypes_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

security_list_builder::relatedsym_builder::applids_builder::applids_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;

  builders_[m::field_id::NoMDFeedTypes] = &feedtypes_builder_;
  add_setter( m::field_id::ApplID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::applids::set_ApplID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  static_cast<security_list_builder::relatedsym_builder::applids_builder::feedtypes_builder*>
  ( builders_[m::field_id::NoMDFeedTypes] )->register_on_message_callback( std::bind (
        &applids_builder::add_FeedTypes, this, p::_1 ) );

}

void
security_list_builder::relatedsym_builder::applids_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::security_list::relatedsym::applids&
security_list_builder::relatedsym_builder::applids_builder::get_message() const
{
  return message_;
}

qm::ValueMessageBuilder&
security_list_builder::relatedsym_builder::applids_builder::startSequence( const qm::FieldIdentity& identity,
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
security_list_builder::relatedsym_builder::applids_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

void
security_list_builder::relatedsym_builder::applids_builder::add_FeedTypes( const messages::security_list::relatedsym::applids::feedtypes& entry )
{
  message_.add_FeedTypes( entry );
}

security_list_builder::relatedsym_builder::securityaltids_builder::securityaltids_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::SecurityAltID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::securityaltids::set_SecurityAltID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityAltIDSource, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::securityaltids::set_SecurityAltIDSource, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

}

void
security_list_builder::relatedsym_builder::securityaltids_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::security_list::relatedsym::securityaltids&
security_list_builder::relatedsym_builder::securityaltids_builder::get_message() const
{
  return message_;
}

void
security_list_builder::relatedsym_builder::securityaltids_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

security_list_builder::relatedsym_builder::underlyings_builder::underlyings_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::UnderlyingSymbol, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::underlyings::set_UnderlyingSymbol, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::UnderlyingSecurityID, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::security_list::relatedsym::underlyings::set_UnderlyingSecurityID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::UnderlyingSecurityIDSource, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::underlyings::set_UnderlyingSecurityIDSource, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::UnderlyingSecurityExchange, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::underlyings::set_UnderlyingSecurityExchange, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::IndexPct, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::security_list::relatedsym::underlyings::set_IndexPct, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::IndexTheoreticalQty, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::security_list::relatedsym::underlyings::set_IndexTheoreticalQty, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

}

void
security_list_builder::relatedsym_builder::underlyings_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::security_list::relatedsym::underlyings&
security_list_builder::relatedsym_builder::underlyings_builder::get_message() const
{
  return message_;
}

void
security_list_builder::relatedsym_builder::underlyings_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

security_list_builder::relatedsym_builder::instrattrib_builder::instrattrib_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::InstAttribType, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::instrattrib::set_InstAttribType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::InstAttribValue, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::instrattrib::set_InstAttribValue, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

}

void
security_list_builder::relatedsym_builder::instrattrib_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::security_list::relatedsym::instrattrib&
security_list_builder::relatedsym_builder::instrattrib_builder::get_message() const
{
  return message_;
}

void
security_list_builder::relatedsym_builder::instrattrib_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

security_list_builder::relatedsym_builder::tickrules_builder::tickrules_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::StartTickPriceRange, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::security_list::relatedsym::tickrules::set_StartTickPriceRange, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::EndTickPriceRange, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::security_list::relatedsym::tickrules::set_EndTickPriceRange, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::TickIncrement, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::security_list::relatedsym::tickrules::set_TickIncrement, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::TickRuleType, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::tickrules::set_TickRuleType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

}

void
security_list_builder::relatedsym_builder::tickrules_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::security_list::relatedsym::tickrules&
security_list_builder::relatedsym_builder::tickrules_builder::get_message() const
{
  return message_;
}

void
security_list_builder::relatedsym_builder::tickrules_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

security_list_builder::relatedsym_builder::legs_builder::legs_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::LegSymbol, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::legs::set_LegSymbol, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::LegSecurityID, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::security_list::relatedsym::legs::set_LegSecurityID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::LegSecurityIDSource, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::legs::set_LegSecurityIDSource, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::LegRatioQty, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::legs::set_LegRatioQty, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::LegSecurityType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::legs::set_LegSecurityType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::LegSide, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::legs::set_LegSide, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::LegSecurityExchange, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::legs::set_LegSecurityExchange, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

}

void
security_list_builder::relatedsym_builder::legs_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::security_list::relatedsym::legs&
security_list_builder::relatedsym_builder::legs_builder::get_message() const
{
  return message_;
}

void
security_list_builder::relatedsym_builder::legs_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

security_list_builder::relatedsym_builder::lots_builder::lots_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;


  add_setter( m::field_id::LotType, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::lots::set_LotType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::MinLotSize, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::lots::set_MinLotSize, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

}

void
security_list_builder::relatedsym_builder::lots_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::security_list::relatedsym::lots&
security_list_builder::relatedsym_builder::lots_builder::get_message() const
{
  return message_;
}

void
security_list_builder::relatedsym_builder::lots_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

security_list_builder::relatedsym_builder::relatedsym_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;

  builders_[m::field_id::NoApplIDs] = &applids_builder_;
  builders_[m::field_id::NoSecurityAltID] = &securityaltids_builder_;
  builders_[m::field_id::NoUnderlyings] = &underlyings_builder_;
  builders_[m::field_id::NoInstrAttrib] = &instrattrib_builder_;
  builders_[m::field_id::NoTickRules] = &tickrules_builder_;
  builders_[m::field_id::NoLegs] = &legs_builder_;
  builders_[m::field_id::NoLotTypeRules] = &lots_builder_;
  add_setter( m::field_id::Symbol, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_Symbol, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityID, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::security_list::relatedsym::set_SecurityID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityIDSource, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_SecurityIDSource, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityExchange, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_SecurityExchange, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  static_cast<security_list_builder::relatedsym_builder::applids_builder*>
  ( builders_[m::field_id::NoApplIDs] )->register_on_message_callback( std::bind (
        &relatedsym_builder::add_ApplIDs, this, p::_1 ) );

  static_cast<security_list_builder::relatedsym_builder::securityaltids_builder*>
  ( builders_[m::field_id::NoSecurityAltID] )->register_on_message_callback( std::bind (
        &relatedsym_builder::add_SecurityAltIDs, this, p::_1 ) );

  static_cast<security_list_builder::relatedsym_builder::underlyings_builder*>
  ( builders_[m::field_id::NoUnderlyings] )->register_on_message_callback( std::bind (
        &relatedsym_builder::add_Underlyings, this, p::_1 ) );

  add_setter( m::field_id::ImpliedMarketIndicator, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::set_ImpliedMarketIndicator, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  static_cast<security_list_builder::relatedsym_builder::instrattrib_builder*>
  ( builders_[m::field_id::NoInstrAttrib] )->register_on_message_callback( std::bind (
        &relatedsym_builder::add_InstrAttrib, this, p::_1 ) );

  static_cast<security_list_builder::relatedsym_builder::tickrules_builder*>
  ( builders_[m::field_id::NoTickRules] )->register_on_message_callback( std::bind (
        &relatedsym_builder::add_TickRules, this, p::_1 ) );

  static_cast<security_list_builder::relatedsym_builder::legs_builder*>
  ( builders_[m::field_id::NoLegs] )->register_on_message_callback( std::bind (
        &relatedsym_builder::add_Legs, this, p::_1 ) );

  add_setter( m::field_id::SecurityUpdateAction, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_SecurityUpdateAction, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::RoundLot, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::set_RoundLot, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::MinTradeVol, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::security_list::relatedsym::set_MinTradeVol, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  static_cast<security_list_builder::relatedsym_builder::lots_builder*>
  ( builders_[m::field_id::NoLotTypeRules] )->register_on_message_callback( std::bind (
        &relatedsym_builder::add_Lots, this, p::_1 ) );

  add_setter( m::field_id::MinPriceIncrement, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::security_list::relatedsym::set_MinPriceIncrement, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::TickSizeDenominator, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::set_TickSizeDenominator, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::PriceDivisor, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::security_list::relatedsym::set_PriceDivisor, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::MinOrderQty, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::set_MinOrderQty, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::MaxOrderQty, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::security_list::relatedsym::set_MaxOrderQty, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::InstrumentID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_InstrumentID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MultiLegModel, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::set_MultiLegModel, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::MultiLegPriceMethod, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::set_MultiLegPriceMethod, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::Currency, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_Currency, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SettlCurrency, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_SettlCurrency, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::Product, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::set_Product, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_SecurityType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecuritySubType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_SecuritySubType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityStrategyType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_SecurityStrategyType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::Asset, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_Asset, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityDesc, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_SecurityDesc, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::NoShareIssued, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::security_list::relatedsym::set_NoShareIssued, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::MaturityDate, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::set_MaturityDate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::MaturityMonthYear, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::set_MaturityMonthYear, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::StrikePrice, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::security_list::relatedsym::set_StrikePrice, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::StrikeCurrency, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_StrikeCurrency, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::ExerciseStyle, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::set_ExerciseStyle, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::PutOrCall, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::set_PutOrCall, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::ContractMultiplier, q::ValueType::DECIMAL,
              std::make_shared<setter<decimal>>(
                std::bind( &m::security_list::relatedsym::set_ContractMultiplier, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    QuickFAST::Decimal qfd = field->toDecimal();
    return decimal( qfd.getMantissa(), qfd.getExponent() );
    ;
  }, p::_1 ) ) );

  add_setter( m::field_id::ContractSettlMonth, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::set_ContractSettlMonth, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::CFICode, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_CFICode, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::CountryOfIssue, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_CountryOfIssue, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::IssueDate, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::set_IssueDate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::DatedDate, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::set_DatedDate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::StartDate, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::set_StartDate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::EndDate, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::set_EndDate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SettlType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_SettlType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SettlDate, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::relatedsym::set_SettlDate, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityValidityTimestamp, q::ValueType::UINT64,
              std::make_shared<setter<uint64_t>>(
                std::bind( &m::security_list::relatedsym::set_SecurityValidityTimestamp, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt64();
  }, p::_1 ) ) );

  add_setter( m::field_id::MarketSegmentID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_MarketSegmentID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::GovernanceIndicator, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_GovernanceIndicator, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::CorporateActionEventID, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::set_CorporateActionEventID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityGroup, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::relatedsym::set_SecurityGroup, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::SecurityMatchType, q::ValueType::INT32,
              std::make_shared<setter<int32_t>>(
                std::bind( &m::security_list::relatedsym::set_SecurityMatchType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toInt32();
  }, p::_1 ) ) );

}

void
security_list_builder::relatedsym_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::security_list::relatedsym&
security_list_builder::relatedsym_builder::get_message() const
{
  return message_;
}

qm::ValueMessageBuilder&
security_list_builder::relatedsym_builder::startSequence( const qm::FieldIdentity& identity,
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
security_list_builder::relatedsym_builder::endSequenceEntry( qm::ValueMessageBuilder& entry )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();
}

void
security_list_builder::relatedsym_builder::add_ApplIDs( const messages::security_list::relatedsym::applids& entry )
{
  message_.add_ApplIDs( entry );
}

void
security_list_builder::relatedsym_builder::add_SecurityAltIDs( const messages::security_list::relatedsym::securityaltids& entry )
{
  message_.add_SecurityAltIDs( entry );
}

void
security_list_builder::relatedsym_builder::add_Underlyings( const messages::security_list::relatedsym::underlyings& entry )
{
  message_.add_Underlyings( entry );
}

void
security_list_builder::relatedsym_builder::add_InstrAttrib( const messages::security_list::relatedsym::instrattrib& entry )
{
  message_.add_InstrAttrib( entry );
}

void
security_list_builder::relatedsym_builder::add_TickRules( const messages::security_list::relatedsym::tickrules& entry )
{
  message_.add_TickRules( entry );
}

void
security_list_builder::relatedsym_builder::add_Legs( const messages::security_list::relatedsym::legs& entry )
{
  message_.add_Legs( entry );
}

void
security_list_builder::relatedsym_builder::add_Lots( const messages::security_list::relatedsym::lots& entry )
{
  message_.add_Lots( entry );
}

security_list_builder::security_list_builder()
{
  namespace m = messages;
  namespace q = QuickFAST;
  namespace p = std::placeholders;

  builders_[m::field_id::NoRelatedSym] = &relatedsym_builder_;
  add_setter( m::field_id::MsgType, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::set_MsgType, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::ApplVerID, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::set_ApplVerID, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::MsgSeqNum, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::set_MsgSeqNum, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::SendingTime, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::set_SendingTime, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  add_setter( m::field_id::TotNoRelatedSym, q::ValueType::UINT32,
              std::make_shared<setter<uint32_t>>(
                std::bind( &m::security_list::set_TotNoRelatedSym, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toUInt32();
  }, p::_1 ) ) );

  add_setter( m::field_id::LastFragment, q::ValueType::ASCII,
              std::make_shared<setter<std::string>>(
                std::bind( &m::security_list::set_LastFragment, &message_, p::_1 ),
                std::bind( []( q::Messages::FieldCPtr field )
  {
    return field->toString();
  }, p::_1 ) ) );

  static_cast<security_list_builder::relatedsym_builder*>
  ( builders_[m::field_id::NoRelatedSym] )->register_on_message_callback( std::bind (
        &security_list_builder::add_RelatedSym, this, p::_1 ) );

}

void
security_list_builder::register_on_message_callback( on_message_t callback )
{
  on_message_ = callback;
}

const messages::security_list&
security_list_builder::get_message() const
{
  return message_;
}

qm::ValueMessageBuilder&
security_list_builder::startSequence( const qm::FieldIdentity& identity,
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
security_list_builder::endMessage( qm::ValueMessageBuilder& messageBuilder )
{
  if ( on_message_ )
  {
    on_message_( message_ );
  }

  message_.reset();

  return true;
}

void
security_list_builder::add_RelatedSym( const messages::security_list::relatedsym& entry )
{
  message_.add_RelatedSym( entry );
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
