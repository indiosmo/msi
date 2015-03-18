#include <msi/msi_pch.hpp>
#include <msi/umdf/receiver/sequencing_machine.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace receiver
{

sequencing_machine_::sequencing_machine_( boost::asio::io_service& io_service,
    const std::string& channel_id,
    channel_type channel_type,
    std::shared_ptr<recovery::recovery_service> recovery_service )
  : recovery_service_( recovery_service )
  , channel_id_( channel_id )
  , channel_type_( channel_type )
  , gap_timer_( io_service )
  , recovery_timer_( io_service )
  , heartbeat_timer_( io_service )
{

}

void
sequencing_machine_::register_on_message_callback(
  event<const unsigned char*, std::size_t>::handler_t callback )
{
  on_message_.register_handler( callback );
}

void sequencing_machine_::register_on_error_callback( event<receiver_error>::handler_t callback )
{
  on_error_.register_handler( callback );
}

void
sequencing_machine_::reset()
{
  expected_seqnum_ = 0;
  expected_chunk_ = 0;
  assembly_queue_.clear();
  assembly_data_length_ = 0;
  gap_queue_.clear();
}

bool
sequencing_machine_::is_old( seqnum_t seqnum, chunk_t chunk )
{
  if ( channel_type_ == channel_type_cyclic )
  {
    //cyclic channels treat old packets as unordered
    return false;
  }

  bool old_seqnum = seqnum < expected_seqnum_;
  bool old_chunk = seqnum == expected_seqnum_ && chunk < expected_chunk_;

  return old_seqnum || old_chunk;
}

bool
sequencing_machine_::is_ordered( seqnum_t seqnum, chunk_t chunk )
{
  return seqnum == expected_seqnum_ && chunk == expected_chunk_;
}

sequencing_machine_::sequencing_state
sequencing_machine_::sequence_message( seqnum_t seqnum, chunk_t chunk )
{
  if ( is_ordered( seqnum, chunk ) )
  {
    return state_ordered;
  }
  else if ( is_old( seqnum, chunk ) )
  {
    return state_old;
  }
  else
  {
    return state_unordered;
  }
}

void
sequencing_machine_::handle_ordered_message( seqnum_t seqnum, chunk_t no_chunks,
    chunk_t current_chunk, const unsigned char* buffer, std::size_t length )
{
  if ( no_chunks == 1 )
  {
    on_message_( buffer, length );
    ++expected_seqnum_;
  }
  else
  {
    if ( current_chunk == no_chunks )
    {
      std::vector<uint8_t> full_msg = assemble_multi_chunk( buffer, length );

      on_message_( full_msg.data(), full_msg.size() );

      assembly_queue_.clear();
      assembly_data_length_ = 0;

      ++expected_seqnum_;
      expected_chunk_ = 1;
    }
    else
    {
      assembly_data_length_ += length;
      assembly_queue_.insert( assembly_queue_.end(),
                              receiver::chunk( seqnum, no_chunks, current_chunk, buffer, length ) );

      ++expected_chunk_;
    }
  }
}

std::vector<uint8_t>
sequencing_machine_::assemble_multi_chunk( const unsigned char* buffer, std::size_t length )
{
  std::vector<uint8_t> data;
  data.reserve( assembly_data_length_ + length );

  for ( auto chunk : assembly_queue_ )
  {
    std::move( chunk.data().begin(), chunk.data().end(), std::back_inserter( data ) );
  }

  std::move( buffer, buffer + length, std::back_inserter( data ) );

  return data;
}

void
sequencing_machine_::process_queue()
{
  while ( gap_queue_.size() > 0 )
  {
    auto chunk = gap_queue_.begin();
    auto state = sequence_message( chunk->seqnum(), chunk->current_chunk() );

    switch ( state )
    {
      case state_ordered:
        handle_ordered_message( chunk->seqnum(), chunk->no_chunks(), chunk->current_chunk(),
                                chunk->data().data(), chunk->data().size() );

        gap_queue_.erase( chunk );
        break;

      case state_old:
        gap_queue_.erase( chunk );
        break;

      case state_unordered:
        goto exit;
    }
  }

exit:
  ;
}

void
sequencing_machine_::enqueue_message( seqnum_t seqnum, chunk_t no_chunks,
                                      chunk_t current_chunk, const unsigned char* buffer, std::size_t length )
{
  gap_queue_.insert( gap_queue_.end(),
                     receiver::chunk( seqnum, no_chunks, current_chunk, buffer, length ) );
}

std::string
get_fsm_state( sequencing_machine const& p )
{
  return std::string( sequencing_machine_state_names[p.current_state()[0]] );
}


} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

