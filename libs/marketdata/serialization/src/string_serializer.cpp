#include <msi/msi_pch.hpp>
#include <msi/marketdata/serialization/string_serializer.hpp>
#include <msi/byte_conversion.hpp>

namespace apoena
{
namespace msi
{
namespace marketdata
{
namespace serialization
{

std::size_t serialize_string_field( std::pair<bool, const std::string&> field,
                                    std::vector<unsigned char>& dst,
                                    const std::size_t length_offset,
                                    const std::size_t data_offset )
{
  if ( field.first )
  {
    std::size_t string_size = field.second.size();
    std::size_t capacity = dst.size() - data_offset;

    if ( capacity < string_size )
    {
      dst.resize( dst.size() + ( string_size * 2 ) );
    }

    byte_conversion::uint32_to_be( dst.data() + length_offset, string_size );
    std::copy( field.second.begin(), field.second.end(), dst.data() + data_offset );

    return string_size;
  }
  else
  {
    byte_conversion::uint32_to_be( dst.data() + length_offset, 0 );
    return 0;
  }
}

std::string deserialize_string_field( const unsigned char* data,
                                      const std::size_t length_offset,
                                      const std::size_t data_offset )
{
  std::size_t string_size = byte_conversion::be_to_uint32( data + length_offset );
  return std::string( data + data_offset, data + data_offset + string_size );
}

} // end of namespace
} // end of namespace
} // end of namespace
} // end of namespace
