#ifndef APOENA_MSI_PRINT_UTIL_HPP
#define APOENA_MSI_PRINT_UTIL_HPP

#include <iostream>
#include <iomanip>

namespace apoena
{
namespace msi
{

void
print_buffer_hex( const unsigned char* buffer, const size_t size )
{
  for ( unsigned int i = 0; i < size; i++ )
  {
    std::cout << std::setw( 2 ) << std::setfill( '0' ) << std::hex;
    std::cout << ( short )( buffer[i] ) << ' ';
  }

  std::cout << std::setfill( ' ' ) << std::setw( 0 ) << std::dec;
  std::cout << std::endl;
}

template<typename T, typename U>
void print_pair( const std::pair<T,U>& p )
{
  std::cout << p.first << ":" << p.second << std::endl;
}

} // end of namespace
} // end of namespace

#endif /* APOENA_MSI_PRINT_UTIL_HPP */
