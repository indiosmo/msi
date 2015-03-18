#ifndef APOENA_MSI_MARKETDATA_COMMON_SECURITY_LIST_HPP
#define APOENA_MSI_MARKETDATA_COMMON_SECURITY_LIST_HPP

#include <cstdint>
#include <string>
#include <unordered_map>
#include <utility>
#include <boost/container/flat_set.hpp>
#include <msi/marketdata/common/marketdata_common_export.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{

class MARKETDATA_COMMON_Export security_list
{
public:
  typedef boost::container::flat_set<uint_fast64_t> member_set_t;
  typedef std::unordered_map<std::string, member_set_t> group_members_t;

  void add_instrument( const std::string& symbol, uint_fast64_t security_id );
  void add_instrument( const std::string& symbol, uint_fast64_t security_id, const std::string& group );
  void remove_instrument( uint_fast64_t security_id );
  void update_instrument( uint_fast64_t security_id, const std::string& group );

  std::pair<bool, const member_set_t*> get_group_members( const std::string& group );
  std::pair<bool, const std::string*> get_symbol( uint_fast64_t security_id );
  std::pair<bool, const std::string*> get_group( uint_fast64_t security_id );
  std::pair<bool, uint_fast64_t> get_security_id( const std::string& symbol );

private:
  void remove_from_group( uint_fast64_t security_id, const std::string& group );

  std::unordered_map<std::string, uint_fast64_t> symbol_to_security_id_map_;
  std::unordered_map<uint_fast64_t, std::string> security_id_to_symbol_map_;
  std::unordered_map<uint_fast64_t, std::string> instrument_security_group_;
  group_members_t security_group_members_;
};

} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_MARKETDATA_COMMON_SECURITY_LIST_HPP */

