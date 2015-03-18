#ifndef APOENA_MSI_MARKETDATA_SERIALIZATION_SEQUENCE_SERIALIZER_HPP
#define APOENA_MSI_MARKETDATA_SERIALIZATION_SEQUENCE_SERIALIZER_HPP

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
serialize_sequence( const std::vector<ENTRY_T>& sequence,
                    SERIALIZER_T& serializer,
                    std::vector<unsigned char>& dst,
                    const std::size_t length_offset,
                    const std::size_t data_offset )
{
  if ( sequence.size() > 0 )
  {
    std::size_t sequence_offset = data_offset;

    byte_conversion::uint32_to_be( dst.data() + length_offset, sequence.size() );

    for ( auto entry : sequence )
    {
      std::pair<const unsigned char*, std::size_t> serialized = serializer.serialize( entry );
      std::size_t capacity = dst.size() - sequence_offset;

      if ( capacity < serialized.second )
      {
        dst.resize( dst.size() * 2 );
      }

      std::copy( serialized.first, serialized.first + serialized.second, dst.data() + sequence_offset );
      sequence_offset += serialized.second;
    }

    return sequence_offset - data_offset;
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

#endif /* APOENA_MSI_MARKETDATA_SERIALIZATION_SEQUENCE_SERIALIZER_HPP */

