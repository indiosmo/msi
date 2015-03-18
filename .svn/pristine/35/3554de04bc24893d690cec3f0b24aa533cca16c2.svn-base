#include <msi/msi_pch.hpp>
#include <msi/network/tcp/header.hpp>

namespace apoena
{
namespace msi
{
namespace network
{
namespace tcp
{

header::header()
{

}

unsigned char*
header::data()
{
  return data_.data();
}

uint32_t
header::decode() const
{
  const unsigned char* data = data_.data();
  return data[0] << 24 | data[1] << 16 | data[2] << 8 | data[3];
}

void
header::encode( uint32_t size )
{
  data_[0] = static_cast<unsigned char>( size >> 24 );
  data_[1] = static_cast<unsigned char>( size >> 16 );
  data_[2] = static_cast<unsigned char>( size >> 8 );
  data_[3] = static_cast<unsigned char>( size );
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

