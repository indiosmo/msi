#ifndef APOENA_MSI_UMDF_RECEIVER_EVENTS_HPP
#define APOENA_MSI_UMDF_RECEIVER_EVENTS_HPP

#include <cstddef>
#include <string>
#include <msi/umdf/receiver/receiver_export.hpp>
#include <msi/umdf/common/typedefs.hpp>
#include <msi/umdf/receiver/receiver_error.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace receiver
{

enum fsm_event_type
{
  fsm_event_type_message,
  fsm_event_type_gap,
  fsm_event_type_recovery_message,
  fsm_event_type_recovery_ack,
  fsm_event_type_recovery_done,
  fsm_event_type_error,
  fsm_event_type_initialized,
  fsm_event_type_sequenced,
  fsm_event_type_gap_timeout,
  fsm_event_type_reset,
  fsm_event_type_gap_after_recovery
};

struct RECEIVER_Export ev_message
{
  ev_message( seqnum_t seqnum, chunk_t no_chunks, chunk_t current_chunk,
              const unsigned char* data, std::size_t length )
    : seqnum_( seqnum )
    , no_chunks_( no_chunks )
    , current_chunk_( current_chunk )
    , data_( data )
    , length_( length )
  {

  }

  fsm_event_type type() const
  {
    return fsm_event_type_message;
  }

  seqnum_t seqnum_;
  chunk_t no_chunks_;
  chunk_t current_chunk_;
  const unsigned char* data_;
  std::size_t length_;
};

struct RECEIVER_Export ev_gap
{
  ev_gap( seqnum_t seqnum, chunk_t no_chunks, chunk_t current_chunk,
          const unsigned char* data, std::size_t length )
    : seqnum_( seqnum )
    , no_chunks_( no_chunks )
    , current_chunk_( current_chunk )
    , data_( data )
    , length_( length )
  {

  }

  fsm_event_type type() const
  {
    return fsm_event_type_gap;
  }

  seqnum_t seqnum_;
  chunk_t no_chunks_;
  chunk_t current_chunk_;
  const unsigned char* data_;
  std::size_t length_;
};

struct RECEIVER_Export ev_recovery_message
{
  ev_recovery_message( seqnum_t seqnum, const unsigned char* data, std::size_t length )
    : seqnum_( seqnum )
    , data_( data )
    , length_( length )
  {

  }

  fsm_event_type type() const
  {
    return fsm_event_type_recovery_message;
  }

  seqnum_t seqnum_;
  const unsigned char* data_;
  std::size_t length_;
};

struct RECEIVER_Export ev_recovery_ack
{
  ev_recovery_ack( recovery::ApplRespType response_type,
                   recovery::ApplRespError response_error )
    : response_type_( response_type )
    , response_error_( response_error )
  {

  }

  fsm_event_type type() const
  {
    return fsm_event_type_recovery_ack;
  }

  recovery::ApplRespType response_type_;
  recovery::ApplRespError response_error_;
};

struct RECEIVER_Export ev_recovery_done
{
  ev_recovery_done( recovery::ApplReportType report_type,
                    recovery::ApplRespError response_error )
    : report_type_( report_type )
    , response_error_( response_error )
  {

  }

  fsm_event_type type() const
  {
    return fsm_event_type_recovery_done;
  }

  recovery::ApplReportType report_type_;
  recovery::ApplRespError response_error_;
};

struct RECEIVER_Export ev_error
{
  ev_error( receiver_error error )
    : error_( error )
  {

  }

  fsm_event_type type() const
  {
    return fsm_event_type_error;
  }

  receiver_error error_;
};

struct RECEIVER_Export ev_initialized
{
  fsm_event_type type() const
  {
    return fsm_event_type_initialized;
  }
};

struct RECEIVER_Export ev_sequenced
{
  fsm_event_type type() const
  {
    return fsm_event_type_sequenced;
  }
};

struct RECEIVER_Export ev_gap_timeout
{
  fsm_event_type type() const
  {
    return fsm_event_type_gap_timeout;
  }
};

struct RECEIVER_Export ev_reset
{
  fsm_event_type type() const
  {
    return fsm_event_type_reset;
  }
};

struct RECEIVER_Export ev_gap_after_recovery
{
  fsm_event_type type() const
  {
    return fsm_event_type_gap_after_recovery;
  }
};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_RECEIVER_EVENTS_HPP */
