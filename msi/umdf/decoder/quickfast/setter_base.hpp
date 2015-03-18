#ifndef APOENA_MSI_UMDF_DECODER_QUICKFAST_SETTER_BASE_HPP
#define APOENA_MSI_UMDF_DECODER_QUICKFAST_SETTER_BASE_HPP

#include <Messages/Field_fwd.h>
#include <msi/umdf/decoder/quickfast/umdf_decoder_quickfast_export.hpp>

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

class UMDF_DECODER_QUICKFAST_Export setter_base
{
public:
  virtual ~setter_base() = 0;

  virtual void set( QuickFAST::Messages::FieldCPtr field ) = 0;
};

inline setter_base::~setter_base()
{
}


} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_DECODER_QUICKFAST_SETTER_BASE_HPP */


