#ifndef APOENA_MSI_DECIMAL_DECIMAL_HPP
#define APOENA_MSI_DECIMAL_DECIMAL_HPP

#include <cmath>
#include <cstdint>

namespace apoena
{
namespace msi
{

class decimal
{
public:
  typedef int64_t mantissa_t;
  typedef int8_t exponent_t;

  decimal()
    : mantissa_( 0 )
    , exponent_( 0 )
  {
  }

  decimal( mantissa_t mantissa, exponent_t exponent )
    : mantissa_( mantissa )
    , exponent_( exponent )
  {
  }

  mantissa_t mantissa() const
  {
    return mantissa_;
  }

  void set_mantissa( mantissa_t mantissa )
  {
    mantissa_ = mantissa;
  }

  exponent_t exponent() const
  {
    return exponent_;
  }

  void set_exponent( exponent_t exponent )
  {
    exponent_ = exponent;
  }

  double to_double() const
  {
    return double( double( mantissa_ ) * std::pow( 10.0L, exponent_ ) );
  }

  friend bool operator==( const decimal& lhs, const decimal& rhs );

  friend std::ostream& operator<< ( std::ostream& os, const decimal& d );

private:
  mantissa_t mantissa_;
  exponent_t exponent_;

};

inline bool operator==( const decimal& lhs, const decimal& rhs )
{
  return lhs.mantissa_ == rhs.mantissa_ && lhs.exponent_ == rhs.exponent_;
}

inline std::ostream& operator<<( std::ostream& os, const decimal& d )
{
  return os << d.mantissa() << "e" << ( uint32_t )d.exponent();
}

} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_DECIMAL_DECIMAL_HPP */

