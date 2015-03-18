#ifndef APOENA_MSI_NETWORK_TCP_HEADER_HPP
#define APOENA_MSI_NETWORK_TCP_HEADER_HPP

#include <utility>
#include <cstdint>
#include <array>
#include <msi/network/network_export.hpp>

namespace apoena
{
namespace msi
{
namespace network
{
namespace tcp
{

class NETWORK_Export header
{
public:
  header();
  header( const header& ) = delete;
  header& operator=( const header& ) = delete;

  const static std::size_t header_size = 4;

  unsigned char* data();

  uint32_t decode() const;

  void encode( uint32_t size );

private:
  std::array<unsigned char, header_size> data_;
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_NETWORK_TCP_HEADER_HPP */

