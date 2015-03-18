#ifndef APOENA_MSI_UMDF_COMMON_TYPEDEFS_H
#define APOENA_MSI_UMDF_COMMON_TYPEDEFS_H

#include <cstdint>

namespace apoena
{
namespace msi
{
namespace umdf
{

typedef uint_fast64_t securityid_t;
typedef uint_fast32_t seqnum_t;
//chunk_t covers both no_chunks and current_chunk
typedef uint_fast16_t chunk_t;
typedef uint_fast16_t data_length_t;


} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_COMMON_TYPEDEFS_H */

