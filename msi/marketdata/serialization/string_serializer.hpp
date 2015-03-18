#ifndef APOENA_MSI_MARKETDATA_SERIALIZATION_STRING_SERIALIZER_HPP
#define APOENA_MSI_MARKETDATA_SERIALIZATION_STRING_SERIALIZER_HPP

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

std::size_t
serialize_string_field( std::pair<bool, const std::string&> field,
                        std::vector<unsigned char>& dst,
                        const std::size_t length_offset,
                        const std::size_t data_offset );

std::string
deserialize_string_field( const unsigned char* data,
                          const std::size_t length_offset,
                          const std::size_t data_offset );

} // end of namespace
} // end of namespace
} // end of namespace
} // end of namespace

#endif /* APOENA_MSI_MARKETDATA_SERIALIZATION_STRING_SERIALIZER_HPP */

