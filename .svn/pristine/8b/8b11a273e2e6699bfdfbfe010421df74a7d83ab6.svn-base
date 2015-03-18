#ifndef APOENA_MSI_MARKETDATA_SERIALIZATION_REFERENCE_FIELD_SERIALIZER_HPP
#define APOENA_MSI_MARKETDATA_SERIALIZATION_REFERENCE_FIELD_SERIALIZER_HPP

#include <utility>
#include <vector>
#include <string>
#include <algorithm>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

template<typename ENTRY_T, typename SERIALIZER_T>
std::size_t
serialize_reference_field( std::pair<bool, const ENTRY_T&> field,
                           SERIALIZER_T& serializer,
                           std::vector<unsigned char>& dst,
                           const std::size_t length_offset,
                           const std::size_t data_offset )
{
  if ( field.first )
  {
    std::pair<const unsigned char*, std::size_t> serialized =
      serializer.serialize( field.second );

    std::size_t capacity = dst.size() - data_offset;

    if ( capacity < serialized.second )
    {
      dst.resize( dst.size() * 2 );
    }

    byte_conversion::uint32_to_be( dst.data() + length_offset, serialized.second );
    std::copy( serialized.first, serialized.first + serialized.second, dst.data() + data_offset );

    return serialized.second;
  }
  else
  {
    byte_conversion::uint32_to_be( dst.data() + length_offset, 0 );
    return 0;
  }
}

} // end of namespace
} // end of namespace
} // end of namespace
} // end of namespace

#endif /* APOENA_MSI_MARKETDATA_SERIALIZATION_REFERENCE_FIELD_SERIALIZER_HPP */

