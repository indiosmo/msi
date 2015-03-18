#include <msi/msi_pch.hpp>
#include <msi/marketdata/common/security_list.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{

void
security_list::add_instrument( const std::string& symbol, uint_fast64_t security_id )
{
  symbol_to_security_id_map_[symbol] = security_id;
  security_id_to_symbol_map_[security_id] = symbol;
}

void
security_list::add_instrument( const std::string& symbol,
                               uint_fast64_t security_id,
                               const std::string& group )
{
  add_instrument( symbol, security_id );
  instrument_security_group_[security_id] = group;
  security_group_members_[group].insert( security_id );
}

void
security_list::remove_instrument( uint_fast64_t security_id )
{
  auto it_symbol = security_id_to_symbol_map_.find( security_id );

  if ( it_symbol != security_id_to_symbol_map_.end() )
  {
    symbol_to_security_id_map_.erase( it_symbol->second );
    security_id_to_symbol_map_.erase( it_symbol );
  }

  auto it_group = instrument_security_group_.find( security_id );

  if ( it_group != instrument_security_group_.end() )
  {
    remove_from_group( security_id, it_group->second );
    instrument_security_group_.erase( it_group );
  }
}

void
security_list::update_instrument( uint_fast64_t security_id, const std::string& group )
{
  //remove from old group
  auto it_group = instrument_security_group_.find( security_id );

  if ( it_group != instrument_security_group_.end() )
  {
    remove_from_group( security_id, it_group->second );
  }

  //add to new group
  instrument_security_group_[security_id] = group;
  security_group_members_[group].insert( security_id );
}

std::pair<bool, const security_list::member_set_t*>
security_list::get_group_members( const std::string& group )
{
  auto it = security_group_members_.find( group );

  if ( it != security_group_members_.end() )
  {
    return std::make_pair( true, &it->second );
  }
  else
  {
    return std::make_pair( false, nullptr );
  }
}

std::pair<bool, const std::string*>
security_list::get_symbol( uint_fast64_t security_id )
{
  auto it = security_id_to_symbol_map_.find( security_id );

  if ( it != security_id_to_symbol_map_.end() )
  {
    return std::make_pair( true, &it->second );
  }
  else
  {
    return std::make_pair( false, nullptr );
  }
}

std::pair<bool, const std::string*>
security_list::get_group( uint_fast64_t security_id )
{
  auto it = instrument_security_group_.find( security_id );

  if ( it != instrument_security_group_.end() )
  {
    return std::make_pair( true, &it->second );
  }
  else
  {
    return std::make_pair( false, nullptr );
  }
}

std::pair<bool, uint_fast64_t>
security_list::get_security_id( const std::string& symbol )
{
  auto it = symbol_to_security_id_map_.find( symbol );

  if ( it != symbol_to_security_id_map_.end() )
  {
    return std::make_pair( true, it->second );
  }
  else
  {
    return std::make_pair( false, 0 );
  }
}

void
security_list::remove_from_group( uint_fast64_t security_id, const std::string& group )
{
  security_group_members_[group].erase( security_id );

  if ( security_group_members_[group].size() == 0 )
  {
    security_group_members_.erase( group );
  }
}

} //end of namespace
} //end of namespace
} //end of namespace


