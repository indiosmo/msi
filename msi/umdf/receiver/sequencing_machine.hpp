#ifndef APOENA_MSI_UMDF_RECEIVER_SEQUENCING_MACHINE_HPP
#define APOENA_MSI_UMDF_RECEIVER_SEQUENCING_MACHINE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_VECTOR_SIZE 30
#define BOOST_MPL_LIMIT_MAP_SIZE 30

#include <iostream>
#include <iomanip>

#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/mpl/vector.hpp>
// back-end
#include <boost/msm/back/state_machine.hpp>
//front-end
#include <boost/msm/front/state_machine_def.hpp>
// functors
#include <boost/msm/front/functor_row.hpp>
#include <boost/msm/front/euml/common.hpp>
// for func_state and func_state_machine
#include <boost/msm/front/euml/state_grammar.hpp>
#include <boost/msm/active_state_switching_policies.hpp>
//for operators
#include <boost/msm/front/euml/euml.hpp>

#include <msi/byte_conversion.hpp>
#include <msi/event.hpp>
#include <msi/logging/log.hpp>

#include <msi/umdf/receiver/channel_type.hpp>
#include <msi/umdf/recovery/recovery_service.hpp>
#include <msi/umdf/receiver/header.hpp>
#include <msi/umdf/receiver/chunk.hpp>
#include <msi/umdf/receiver/receiver_error.hpp>
#include <msi/umdf/receiver/events.hpp>

namespace msm = boost::msm;
namespace mf = boost::msm::front;
namespace mb = boost::msm::back;
namespace mpl = boost::mpl;


namespace apoena
{
namespace msi
{
namespace umdf
{
namespace receiver
{

static char const* const sequencing_machine_state_names[] =
{ "st_uninitialized", "st_sequenced", "st_gap", "st_recovery", "st_failure" };

class RECEIVER_Export sequencing_machine_
  : public mf::state_machine_def < sequencing_machine_ >
{
public:
  enum sequencing_state
  {
    state_ordered,
    state_unordered,
    state_old
  };

  sequencing_machine_( boost::asio::io_service& io_service,
                       const std::string& channel_id,
                       channel_type channel_type,
                       std::shared_ptr<recovery::recovery_service> recovery_service );


  void register_on_message_callback(
    event<const unsigned char*, std::size_t>::handler_t callback );

  void register_on_error_callback(
    event<receiver_error>::handler_t callback );

  /*************
  ** Policies **
  **************/
  typedef msm::active_state_switch_before_transition active_state_switch_policy;

  /***********
  ** States **
  ************/
  struct st_uninitialized_tag {};
  typedef mf::euml::func_state<st_uninitialized_tag> st_uninitialized;

  struct st_sequenced_tag {};
  typedef mf::euml::func_state<st_sequenced_tag> st_sequenced;

  struct st_gap_entry
  {
    template <class Event, class FSM, class STATE>
    void operator()( Event const&, FSM& fsm, STATE& )
    {
      fsm.gap_timer_.expires_from_now( std::chrono::milliseconds( k_gap_timeout ) );
      fsm.gap_timer_.async_wait(
        std::bind( &sequencing_machine_::handle_gap_timeout<FSM>,
                   &fsm, std::ref( fsm ), std::placeholders::_1 ) );
    }
  };

  struct st_gap_exit
  {
    template <class Event, class FSM, class STATE>
    void operator()( Event const&, FSM& fsm, STATE& )
    {
      fsm.gap_timer_.cancel();
    }
  };

  struct st_gap_tag;
  typedef boost::msm::front::euml::func_state<st_gap_tag, st_gap_entry, st_gap_exit> st_gap;

  struct st_recovery_entry
  {
    template <class Event, class FSM, class STATE>
    void operator()( Event const&, FSM& fsm, STATE& )
    {
      fsm.recovery_timer_.expires_from_now( std::chrono::milliseconds( k_recovery_timeout ) );
      fsm.recovery_timer_.async_wait(
        std::bind( &sequencing_machine_::handle_recovery_timeout<FSM>,
                   &fsm, std::ref( fsm ), std::placeholders::_1 ) );
    }
  };

  struct st_recovery_exit
  {
    template <class Event, class FSM, class STATE>
    void operator()( Event const&, FSM& fsm, STATE& )
    {
      fsm.recovery_timer_.cancel();
    }
  };

  struct st_recovery_tag {};
  typedef boost::msm::front::euml::func_state<st_recovery_tag, st_recovery_entry, st_recovery_exit> st_recovery;

  struct st_error_entry
  {
    template <class Event, class FSM, class STATE>
    void operator()( Event const& ev, FSM& fsm, STATE& )
    {
      fsm.on_error_( ev.error_ );
    }
  };

  struct st_error_tag {};
  typedef boost::msm::front::euml::func_state<st_error_tag, st_error_entry> st_error;

  typedef st_uninitialized initial_state;

  /************
  ** Actions **
  *************/
  struct ta_wait_first_message
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    void operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      if ( ev.current_chunk_ == 1 )
      {
        fsm.expected_seqnum_ = ev.seqnum_;
        fsm.expected_chunk_ = 1;
      }

      //initialize machine
      fsm.process_event( ev_initialized() );

      //process first message in initialized state
      fsm.process_event( ev );
    }
  };

  struct ta_handle_message
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    void operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      auto state = fsm.sequence_message( ev.seqnum_, ev.current_chunk_ );

      switch ( state )
      {
        case state_ordered:
          fsm.handle_ordered_message( ev.seqnum_, ev.no_chunks_,
                                      ev.current_chunk_, ev.data_, ev.length_ );
          break;

        case state_unordered:
          fsm.process_event( ev_gap( ev.seqnum_, ev.no_chunks_,
                                     ev.current_chunk_, ev.data_, ev.length_ ) );
          break;

        default:
          break;
      }
    }
  };

  struct ta_enqueue_message
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    void operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      fsm.enqueue_message( ev.seqnum_, ev.no_chunks_,
                           ev.current_chunk_, ev.data_, ev.length_ );
    }
  };

  struct ta_reset
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    void operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      fsm.reset();
    }
  };

  struct ta_resend
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    void operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      fsm.process_event( ev );
    }
  };

  struct ta_handle_message_in_gap
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    void operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      auto state = fsm.sequence_message( ev.seqnum_, ev.current_chunk_ );

      switch ( state )
      {
        case state_ordered:
          fsm.handle_ordered_message( ev.seqnum_, ev.no_chunks_,
                                      ev.current_chunk_, ev.data_, ev.length_ );

          fsm.process_queue();

          if ( fsm.gap_queue_.empty() )
          {
            fsm.process_event( ev_sequenced() );
          }

          break;

        case state_unordered:
          fsm.enqueue_message( ev.seqnum_, ev.no_chunks_,
                               ev.current_chunk_, ev.data_, ev.length_ );
          break;

        default:
          break;
      }
    }
  };

  struct ta_request_recovery
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    void operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      //recovery includes the currently pending message
      fsm.assembly_queue_.clear();

      //if we are recovering while waiting for the rest of a multi chunk
      //message, ignore the multi chunk and expect chunk 1 from recovery
      fsm.expected_chunk_ = 1;

      fsm.recovery_service_->request_recovery( fsm.channel_id_,
          fsm.expected_seqnum_, fsm.gap_queue_.begin()->seqnum() );
    }
  };

  struct ta_handle_message_in_recovery
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    void operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      //messages before queue_.front().seqnum will be received in the recovery
      // so we can safely ignore them
      if ( ev.seqnum_ > fsm.gap_queue_.begin()->seqnum() )
      {
        fsm.enqueue_message( ev.seqnum_, ev.no_chunks_,
                             ev.current_chunk_, ev.data_, ev.length_ );
      }
    }
  };

  struct ta_handle_recovery_message
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    void operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      //we can safely assume recovery messages are ordered
      fsm.handle_ordered_message( ev.seqnum_, 1, 1, ev.data_, ev.length_ );
    }
  };

  struct ta_handle_recovery_ack
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    void operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      if ( ev.response_type_ != recovery::ApplRespType_Accepted )
      {
        fsm.process_event( ev_error( receiver_error_recovery_failed ) );
      }
    }
  };

  struct ta_handle_recovery_done
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    void operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      if ( ev.report_type_ == recovery::ApplReportType_Error )
      {
        fsm.process_event( ev_error( receiver_error_recovery_failed ) );
      }
      else
      {
        fsm.process_queue();

        if ( fsm.gap_queue_.empty() )
        {
          fsm.process_event( ev_sequenced() );
        }
        else
        {
          fsm.process_event( ev_gap_after_recovery() );
        }
      }
    }
  };

  /***********
  ** Guards **
  ************/
  struct gc_cyclic
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    bool operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      return fsm.channel_type_ == channel_type_cyclic;
    }
  };

  struct gc_queue_empty
  {
    template <class EVT, class FSM, class SourceState, class TargetState>
    bool operator()( EVT const& ev, FSM& fsm, SourceState&, TargetState& )
    {
      return fsm.gap_queue_.empty();
    }
  };

  /*********************
  ** Transition table **
  **********************/
  typedef mf::none none;

  typedef mf::ActionSequence_ < mpl::vector< ta_reset, ta_resend> >
  ta_reset_and_resend;

  struct transition_table : boost::mpl::vector<
      //       Start          Event                    Target         Action                            Guard
      //     +--------------+------------------------+--------------+---------------------------------+---------------------+
      mf::Row< st_uninitialized, ev_message, st_uninitialized, ta_wait_first_message, none>,
      mf::Row< st_uninitialized, ev_initialized, st_sequenced, none, none>,
      mf::Row< st_uninitialized, ev_error, st_error, none, none>,
      mf::Row< st_uninitialized, ev_reset, st_uninitialized, ta_reset, none>,
      //     +--------------+------------------------+--------------+---------------------------------+---------------------+
      mf::Row< st_sequenced, ev_message, st_sequenced, ta_handle_message, none>,
      mf::Row< st_sequenced, ev_gap, st_gap, ta_enqueue_message, none>,
      mf::Row< st_sequenced, ev_gap, st_uninitialized, ta_reset_and_resend, gc_cyclic>,
      mf::Row< st_sequenced, ev_error, st_error, none, none>,
      mf::Row< st_sequenced, ev_reset, st_uninitialized, ta_reset, none>,
      //     +--------------+------------------------+--------------+---------------------------------+---------------------+
      mf::Row< st_gap, ev_message, st_gap, ta_handle_message_in_gap, none>,
      mf::Row< st_gap, ev_sequenced, st_sequenced, none, none>,
      mf::Row< st_gap, ev_gap_timeout, st_recovery, ta_request_recovery, none>,
      mf::Row< st_gap, ev_gap_timeout, st_sequenced, none, gc_queue_empty>,
      mf::Row< st_gap, ev_error, st_error, none, none>,
      mf::Row< st_gap, ev_reset, st_uninitialized, ta_reset, none>,
      //     +--------------+------------------------+--------------+---------------------------------+---------------------+
      mf::Row< st_recovery, ev_message, st_recovery, ta_handle_message_in_recovery, none>,
      mf::Row< st_recovery, ev_recovery_message, st_recovery, ta_handle_recovery_message, none>,
      mf::Row< st_recovery, ev_recovery_ack, st_recovery, ta_handle_recovery_ack, none>,
      mf::Row< st_recovery, ev_recovery_done, st_recovery, ta_handle_recovery_done, none>,
      mf::Row< st_recovery, ev_sequenced, st_sequenced, none, none>,
      mf::Row< st_recovery, ev_gap_after_recovery, st_gap, none, none>,
      mf::Row< st_recovery, ev_error, st_error, none, none>,
      mf::Row< st_recovery, ev_reset, st_uninitialized, ta_reset, none>,
      //     +--------------+------------------------+--------------+---------------------------------+---------------------+
      mf::Row< st_error, ev_reset, st_uninitialized, ta_reset, none>
      > {};

  template <class FSM, class Event>
  void no_transition( Event const& e, FSM& fsm, int state )
  {
    std::cout << "unknown transition " << e.type() << " state " << get_fsm_state( fsm ) << std::endl;
  }

  template <class FSM>
  void handle_datagram( FSM& fsm, const unsigned char* buffer, std::size_t size )
  {
    ++packet_count_;

    std::size_t offset( 0 );
    header h;

    while ( extract_header( fsm, buffer, size, offset, &h ) )
    {
      fsm.process_event( ev_message( h.seqnum, h.no_chunks, h.current_chunk,
                                     buffer + offset + header::header_size, h.length ) );

      offset += header::header_size + h.length;
    }
  }

  template <class FSM>
  void handle_recovery_ack( FSM& fsm,
                            recovery::ApplRespType type,
                            recovery::ApplRespError error )
  {
    fsm.process_event( ev_recovery_ack( type, error ) );
  }

  template <class FSM>
  void handle_recovery_data( FSM& fsm, seqnum_t seqnum,
                             const unsigned char* buffer, std::size_t length )
  {
    fsm.process_event( ev_recovery_message( seqnum, buffer, length ) );
  }

  template <class FSM>
  void handle_recovery_report( FSM& fsm,
                               recovery::ApplReportType type,
                               recovery::ApplRespError error )
  {
    fsm.process_event( ev_recovery_done( type, error ) );
  }

  template <class FSM>
  void start( FSM& fsm )
  {
    fsm.heartbeat_timer_.expires_from_now( std::chrono::milliseconds( k_heartbeat_timeout ) );
    fsm.heartbeat_timer_.async_wait(
      std::bind( &sequencing_machine_::handle_heartbeat_timeout<FSM>,
                 &fsm, std::ref( fsm ), std::placeholders::_1 ) );
  }

  template <class FSM>
  void stop( FSM& fsm )
  {
    fsm.gap_timer_.cancel();
    fsm.recovery_timer_.cancel();
    fsm.heartbeat_timer_.cancel();
  }

  template <class FSM>
  void reset( FSM& fsm )
  {
    fsm.process_event( ev_reset() );
  }

private:
  typedef boost::container::flat_set<chunk> queue_t;

  event<receiver_error> on_error_;
  event<const unsigned char* /*buffer*/, std::size_t /*length*/> on_message_;

  std::shared_ptr<recovery::recovery_service> recovery_service_;

  std::string channel_id_;
  channel_type channel_type_;

  seqnum_t expected_seqnum_ = 0;
  chunk_t expected_chunk_ = 0;

  queue_t assembly_queue_;
  std::size_t assembly_data_length_ = 0;

  static const unsigned int k_gap_timeout = 200; //ms
  boost::asio::steady_timer gap_timer_;
  queue_t gap_queue_;

  static const unsigned int k_recovery_timeout = 10000; //ms
  boost::asio::steady_timer recovery_timer_;

  static const unsigned int k_heartbeat_timeout = 40000; //ms
  boost::asio::steady_timer heartbeat_timer_;
  uint32_t packet_count_ = 0;

  void reset();

  bool is_old( seqnum_t seqnum, chunk_t chunk );

  bool is_ordered( seqnum_t seqnum, chunk_t chunk );

  sequencing_state sequence_message( seqnum_t seqnum, chunk_t chunk );

  void handle_ordered_message( seqnum_t seqnum, chunk_t no_chunks,
                               chunk_t current_chunk, const unsigned char* buffer, std::size_t length );

  std::vector<uint8_t> assemble_multi_chunk( const unsigned char* buffer, std::size_t length );

  void process_queue();

  void enqueue_message( seqnum_t seqnum, chunk_t no_chunks,
                        chunk_t current_chunk, const unsigned char* buffer, std::size_t length );

  template <class FSM>
  bool extract_header( FSM& fsm, const unsigned char* buffer,
                       std::size_t size, std::size_t offset, header* header )
  {
    if ( size - offset == 0 )
    {
      //end of packet
      return false;
    }

    if ( size - offset < header::header_size )
    {
      fsm.process_event( ev_error( receiver_error_bad_datagram ) );
      return false;
    }

    header->seqnum = byte_conversion::be_to_uint32( buffer + offset + header::offset_seqnum );
    header->no_chunks = byte_conversion::be_to_uint16( buffer + offset + header::offset_num_chunks );
    header->current_chunk = byte_conversion::be_to_uint16( buffer + offset + header::offset_current_chunk );
    header->length = byte_conversion::be_to_uint16( buffer + offset + header::offset_length );

    return true;
  }

  template <class FSM>
  void handle_gap_timeout( FSM& fsm, const boost::system::error_code& error )
  {
    if ( !error )
    {
      fsm.process_event( ev_gap_timeout() );
    }
  }

  template <class FSM>
  void handle_recovery_timeout( FSM& fsm, const boost::system::error_code& error )
  {
    if ( !error )
    {
      fsm.process_event( ev_error( receiver_error_recovery_timeout ) );
    }
  }

  template <class FSM>
  void handle_heartbeat_timeout( FSM& fsm, const boost::system::error_code& error )
  {
    if ( !error )
    {
      if ( packet_count_ == 0 )
      {
        fsm.process_event( ev_error( receiver_error_heartbeat_timeout ) );
      }
      else
      {
        packet_count_ = 0;
        fsm.heartbeat_timer_.expires_from_now( std::chrono::milliseconds( k_heartbeat_timeout ) );
        fsm.heartbeat_timer_.async_wait(
          std::bind( &sequencing_machine_::handle_heartbeat_timeout<FSM>,
                     &fsm, std::ref( fsm ), std::placeholders::_1 ) );
      }
    }
  }
};

typedef mb::state_machine<sequencing_machine_> sequencing_machine;

RECEIVER_Export std::string get_fsm_state( sequencing_machine const& p );

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_RECEIVER_SEQUENCING_MACHINE_HPP */
