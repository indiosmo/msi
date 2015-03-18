#ifndef APOENA_MSI_EVENT_HPP
#define APOENA_MSI_EVENT_HPP

#include <msi/event_handler.hpp>

namespace apoena
{
namespace msi
{

template<typename... Args>
class event
{
public:
  typedef typename event_handler<Args...>::type handler_t;

  void register_handler( handler_t handler )
  {
    handler_ = handler;
  }

  void operator()( const Args& ... args )
  {
    if ( handler_ )
    {
      handler_( args... );
    }
  }

  void operator()( Args&& ... args )
  {
    if ( handler_ )
    {
      handler_( std::forward<Args>( args )... );
    }
  }

private:
  handler_t handler_;
};

} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_EVENT_HPP */

