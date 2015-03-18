#ifndef APOENA_MSI_EVENT_HANDLER_HPP
#define APOENA_MSI_EVENT_HANDLER_HPP

namespace apoena
{
namespace msi
{

template <typename... Args>
struct event_handler
{
  typedef std::function<void ( Args... )> type;
};

} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_EVENT_HANDLER_HPP */

