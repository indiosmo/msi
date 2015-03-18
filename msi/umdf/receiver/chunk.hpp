#ifndef APOENA_MSI_UMDF_RECEIVER_CHUNK_HPP
#define APOENA_MSI_UMDF_RECEIVER_CHUNK_HPP

#include <vector>
#include <cstdint>
#include <msi/umdf/receiver/receiver_export.hpp>
#include <msi/umdf/common/typedefs.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace receiver
{

class RECEIVER_Export chunk
{
public:
  chunk( seqnum_t seqnum, chunk_t no_chunks, chunk_t current_chunk,
         const unsigned char* data, std::size_t length );

  chunk( seqnum_t seqnum, chunk_t no_chunks, chunk_t current_chunk,
         std::vector<uint8_t>&& data );

  chunk( const chunk& rhs );
  chunk( chunk&& rhs );
  chunk& operator=( const chunk& rhs );
  chunk& operator=( chunk&& rhs );

  friend bool operator<( const chunk& lhs, const chunk& rhs )
  {
    if ( lhs.seqnum_ < rhs.seqnum_ )
    {
      //smaller seqnum
      return true;
    }
    else if ( lhs.seqnum_ == rhs.seqnum_ )
    {
      if ( lhs.no_chunks_ < rhs.no_chunks_ )
      {
        //same seqnum, less chunks (replay vs multi chunk)
        return true;
      }
      else if ( lhs.no_chunks_ == rhs.no_chunks_ &&
                lhs.current_chunk_ < rhs.current_chunk_ )
      {
        //same seqnum, same no_chunks, smaller chunk
        return true;
      }
    }

    return false;
  }

  seqnum_t seqnum() const
  {
    return seqnum_;
  }

  chunk_t no_chunks() const
  {
    return no_chunks_;
  }

  chunk_t current_chunk() const
  {
    return current_chunk_;
  }

  const std::vector<uint8_t>& data() const
  {
    return data_;
  }

private:
  seqnum_t seqnum_;
  chunk_t no_chunks_;
  chunk_t current_chunk_;
  std::vector<uint8_t> data_;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_RECEIVER_CHUNK_HPP */

