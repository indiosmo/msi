#ifndef APOENA_MSI_UMDF_RECEIVER_RECEIVER_HPP
#define APOENA_MSI_UMDF_RECEIVER_RECEIVER_HPP

#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <msi/event.hpp>
#include <msi/marketdata/common/receiver.hpp>
#include <msi/network/multicast_receiver.hpp>
#include <msi/umdf/receiver/channel_type.hpp>
#include <msi/umdf/recovery/recovery_service.hpp>
#include <msi/umdf/receiver/receiver_error.hpp>
#include <msi/umdf/receiver/receiver_export.hpp>
#include <msi/umdf/receiver/sequencing_machine.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace receiver
{

class RECEIVER_Export receiver : public marketdata::receiver
{
public:
  receiver( boost::asio::io_service& io_service,
            const std::string& channel_id,
            channel_type channel_type,
            std::shared_ptr<recovery::recovery_service> recovery_service );

  receiver( const receiver& ) = delete;
  receiver& operator=( const receiver& ) = delete;

  virtual void register_on_receive_callback(
    event<const unsigned char*, std::size_t>::handler_t callback );

  void register_on_error_callback( event<receiver_error>::handler_t callback );

  virtual void run();
  virtual void stop();
  void reset();

  void add_multicast_group( const std::string& address,
                            unsigned short port,
                            std::size_t buffer_size );

private:
  event<receiver_error> on_error_;

  boost::asio::io_service& io_service_;

  bool running_ = false;

  channel_type channel_type_;

  sequencing_machine fsm_;
  std::shared_ptr<recovery::recovery_service> recovery_service_;
  std::vector<std::shared_ptr<network::multicast_receiver>> multicast_groups_;
  uint32_t current_group_ = 0;

  void run_sequential();
  void run_cyclic();
  void handle_error( receiver_error error );
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_RECEIVER_RECEIVER_HPP */

