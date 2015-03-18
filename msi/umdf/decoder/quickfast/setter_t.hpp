#ifndef APOENA_MSI_UMDF_DECODER_QUICKFAST__SETTER_T_HPP
#define APOENA_MSI_UMDF_DECODER_QUICKFAST__SETTER_T_HPP

#include <msi/umdf/decoder/quickfast/setter_base.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace decoder
{
namespace quickfast
{

template<typename FIELD_T>
class setter : public setter_base
{
public:
  setter( std::function<void ( FIELD_T )> setter,
          std::function<FIELD_T ( QuickFAST::Messages::FieldCPtr )> getter )
    : setter_( setter )
    , getter_( getter )
  {
  }

  virtual ~setter()
  {
  }

  virtual void set( QuickFAST::Messages::FieldCPtr field )
  {
    setter_( getter_( field ) );
  }

private:
  std::function<void( FIELD_T )> setter_;
  std::function<FIELD_T( QuickFAST::Messages::FieldCPtr )> getter_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_DECODER_QUICKFAST__SETTER_T_HPP */


