#ifndef APOENA_MSI_UMDF_RECEIVER_HEADER_HPP
#define APOENA_MSI_UMDF_RECEIVER_HEADER_HPP

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

struct RECEIVER_Export header
{
  enum offset
  {
    offset_seqnum        =0,
    offset_num_chunks     =4,
    offset_current_chunk  =6,
    offset_length        =8,
    offset_data          =10,

    header_size=offset_data
  };

  header()
  {
  }

  header( seqnum_t seqnum, chunk_t no_chunks, chunk_t current_chunk,
          data_length_t length )
    : seqnum( seqnum )
    , no_chunks( no_chunks )
    , current_chunk( current_chunk )
    , length( length )
  {
  }

  seqnum_t seqnum;
  chunk_t no_chunks;
  chunk_t current_chunk;
  data_length_t length;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_RECEIVER_HEADER_HPP */

