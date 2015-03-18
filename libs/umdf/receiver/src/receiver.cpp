#include <msi/msi_pch.hpp>
#include <utility>
#include <msi/umdf/receiver/receiver.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace receiver
{

receiver::receiver( boost::asio::io_service& io_service,
                    const std::string& channel_id,
                    channel_type channel_type,
                    std::shared_ptr<recovery::recovery_service> recovery_service )
  : io_service_( io_service )
  , channel_type_( channel_type )
  , fsm_( std::ref( io_service ), channel_id, channel_type, recovery_service )
  , recovery_service_( recovery_service )
{
  namespace p = std::placeholders;

  recovery_service_->register_on_ack_callback(
    std::bind( &sequencing_machine_::handle_recovery_ack<sequencing_machine>,
               &fsm_, std::ref( fsm_ ), p::_1, p::_2 ) );

  recovery_service_->register_on_data_callback(
    std::bind( &sequencing_machine_::handle_recovery_data<sequencing_machine>,
               &fsm_, std::ref( fsm_ ), p::_1, p::_2, p::_3 ) );

  recovery_service_->register_on_report_callback(
    std::bind( &sequencing_machine_::handle_recovery_report<sequencing_machine>,
               &fsm_, std::ref( fsm_ ), p::_1, p::_2 ) );

  fsm_.register_on_error_callback(
    std::bind( &receiver::handle_error, this, p::_1 ) );
}

void
receiver::register_on_receive_callback(
  event<const unsigned char*, std::size_t>::handler_t callback )
{
  fsm_.register_on_message_callback( callback );
}

void
receiver::register_on_error_callback(
  event<receiver_error>::handler_t callback )
{
  on_error_.register_handler( callback );
}

void
receiver::run()
{
  if ( running_ )
  {
    return;
  }

  running_ = true;

  switch ( channel_type_ )
  {
    case channel_type_sequential:
      run_sequential();
      break;

    case channel_type_cyclic:
      run_cyclic();
      break;

    default:
      break;
  }
}

void
receiver::stop()
{
  if ( !running_ )
  {
    return;
  }

  running_ = false;

  fsm_.stop( fsm_ );
  recovery_service_->disconnect();

  for ( auto mr : multicast_groups_ )
  {
    mr->stop();
  }
}

void
receiver::reset()
{
  fsm_.reset( fsm_ );
}

void
receiver::add_multicast_group( const std::string& address,
                               unsigned short port,
                               std::size_t buffer_size )
{
  namespace p = std::placeholders;

  auto channel = std::make_shared<network::multicast_receiver>(
                   address, port, buffer_size, std::ref( io_service_ ) );

  channel->register_on_receive_callback(
    std::bind( &sequencing_machine_::handle_datagram<sequencing_machine>,
               &fsm_, std::ref( fsm_ ), p::_1, p::_2 ) );

  multicast_groups_.push_back( channel );
}

void
receiver::run_sequential()
{
  fsm_.start( fsm_ );
  recovery_service_->connect();

  for ( auto group : multicast_groups_ )
  {
    group->start();
  }
}

void
receiver::run_cyclic()
{
  fsm_.start( fsm_ );
  multicast_groups_[current_group_ % multicast_groups_.size()]->start();
}

void
receiver::handle_error( receiver_error error )
{
  if ( channel_type_ == channel_type_cyclic && error == receiver_error_heartbeat_timeout )
  {
    multicast_groups_[current_group_ % multicast_groups_.size()]->stop();
    ++current_group_;
    fsm_.stop( fsm_ );
    fsm_.reset( fsm_ );
    run_cyclic();
  }

  on_error_( error );
}

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace
