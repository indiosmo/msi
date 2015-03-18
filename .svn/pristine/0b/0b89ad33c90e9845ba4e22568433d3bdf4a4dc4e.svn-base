#include <msi/msi_pch.hpp>
#include <msi/umdf/receiver/chunk.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace receiver
{

chunk::chunk( seqnum_t seqnum, chunk_t no_chunks, chunk_t current_chunk,
              const unsigned char* data, std::size_t length )
  : seqnum_( seqnum )
  , no_chunks_( no_chunks )
  , current_chunk_( current_chunk )
  , data_( data, data + length )
{

}


chunk::chunk( seqnum_t seqnum, chunk_t no_chunks, chunk_t current_chunk,
              std::vector<uint8_t>&& data )
  : seqnum_( seqnum )
  , no_chunks_( no_chunks )
  , current_chunk_( current_chunk )
  , data_( std::move( data ) )
{

}


chunk::chunk( const chunk& rhs )
  : seqnum_( rhs.seqnum_ )
  , no_chunks_( rhs.no_chunks_ )
  , current_chunk_( rhs.current_chunk_ )
  , data_( rhs.data_ )
{

}

chunk::chunk( chunk&& rhs )
  : seqnum_( std::move( rhs.seqnum_ ) )
  , no_chunks_( std::move( rhs.no_chunks_ ) )
  , current_chunk_( std::move( rhs.current_chunk_ ) )
  , data_( std::move( rhs.data_ ) )
{

}
chunk& chunk::operator=( const chunk& rhs )
{
  if ( this != &rhs )
  {
    seqnum_ = rhs.seqnum_;
    no_chunks_ = rhs.no_chunks_;
    current_chunk_ = rhs.current_chunk_;
    data_ = rhs.data_;
  }

  return *this;
}

chunk& chunk::operator=( chunk&& rhs )
{
  if ( this != &rhs )
  {
    seqnum_ = std::move( rhs.seqnum_ );
    data_ = std::move( rhs.data_ );
    no_chunks_ = std::move( rhs.no_chunks_ );
    current_chunk_ = std::move( rhs.current_chunk_ );
  }

  return *this;
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

