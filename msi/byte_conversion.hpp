#ifndef APOENA_MSI_BYTE_CONVERSION_HPP
#define APOENA_MSI_BYTE_CONVERSION_HPP

#include <cstdint>

namespace apoena
{
namespace msi
{
namespace byte_conversion
{

inline
uint8_t
be_to_uint8( const unsigned char* data )
{
  uint8_t ret = 0;

  ret |= ( uint8_t )data[0];

  return ret;
}

inline
uint16_t
be_to_uint16( const unsigned char* data )
{
  uint16_t ret = 0;

  ret |= ( uint16_t )data[0] << 8;
  ret |= ( uint16_t )data[1];

  return ret;
}

inline
uint32_t
be_to_uint32( const unsigned char* data )
{
  uint32_t ret = 0;

  ret |= ( uint32_t )data[0] << 24;
  ret |= ( uint32_t )data[1] << 16;
  ret |= ( uint32_t )data[2] << 8;
  ret |= ( uint32_t )data[3];

  return ret;
}

inline
uint64_t
be_to_uint64( const unsigned char* data )
{
  uint64_t ret = 0;

  ret |= ( uint64_t )data[0] << 56;
  ret |= ( uint64_t )data[1] << 48;
  ret |= ( uint64_t )data[2] << 40;
  ret |= ( uint64_t )data[3] << 32;
  ret |= ( uint64_t )data[4] << 24;
  ret |= ( uint64_t )data[5] << 16;
  ret |= ( uint64_t )data[6] << 8;
  ret |= ( uint64_t )data[7];

  return ret;
}

inline
int32_t
be_to_int32( const unsigned char* data )
{
  int32_t ret = 0;

  ret |= ( int32_t )data[0] << 24;
  ret |= ( int32_t )data[1] << 16;
  ret |= ( int32_t )data[2] << 8;
  ret |= ( int32_t )data[3];

  return ret;
}

inline
int64_t
be_to_int64( const unsigned char* data )
{
  int64_t ret = 0;

  ret |= ( int64_t )data[0] << 56;
  ret |= ( int64_t )data[1] << 48;
  ret |= ( int64_t )data[2] << 40;
  ret |= ( int64_t )data[3] << 32;
  ret |= ( int64_t )data[4] << 24;
  ret |= ( int64_t )data[5] << 16;
  ret |= ( int64_t )data[6] << 8;
  ret |= ( int64_t )data[7];

  return ret;
}

inline
void
uint8_to_be( unsigned char* data, uint8_t value )
{
  data[0] = static_cast<unsigned char>( value );
}

inline
void
uint16_to_be( unsigned char* data, uint16_t value )
{
  data[0] = static_cast<unsigned char>( value >> 8 );
  data[1] = static_cast<unsigned char>( value );
}

inline
void
uint32_to_be( unsigned char* data, uint32_t value )
{
  data[0] = static_cast<unsigned char>( value >> 24 );
  data[1] = static_cast<unsigned char>( value >> 16 );
  data[2] = static_cast<unsigned char>( value >> 8 );
  data[3] = static_cast<unsigned char>( value );
}

inline
void
uint64_to_be( unsigned char* data, uint64_t value )
{
  data[0] = static_cast<unsigned char>( value >> 56 );
  data[1] = static_cast<unsigned char>( value >> 48 );
  data[2] = static_cast<unsigned char>( value >> 40 );
  data[3] = static_cast<unsigned char>( value >> 32 );
  data[4] = static_cast<unsigned char>( value >> 24 );
  data[5] = static_cast<unsigned char>( value >> 16 );
  data[6] = static_cast<unsigned char>( value >> 8 );
  data[7] = static_cast<unsigned char>( value );
}

inline
void
int32_to_be( unsigned char* data, int32_t value )
{
  data[0] = static_cast<unsigned char>( value >> 24 );
  data[1] = static_cast<unsigned char>( value >> 16 );
  data[2] = static_cast<unsigned char>( value >> 8 );
  data[3] = static_cast<unsigned char>( value );
}

inline
void
int64_to_be( unsigned char* data, int64_t value )
{
  data[0] = static_cast<unsigned char>( value >> 56 );
  data[1] = static_cast<unsigned char>( value >> 48 );
  data[2] = static_cast<unsigned char>( value >> 40 );
  data[3] = static_cast<unsigned char>( value >> 32 );
  data[4] = static_cast<unsigned char>( value >> 24 );
  data[5] = static_cast<unsigned char>( value >> 16 );
  data[6] = static_cast<unsigned char>( value >> 8 );
  data[7] = static_cast<unsigned char>( value );
}

} // end of namespace
} // end of namespace
} // end of namespace

#endif /* APOENA_MSI_BYTE_CONVERSION_HPP */
