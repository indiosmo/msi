#ifndef APOENA_MSI_UMDF_RECOVERY_QUICKFIX_RECOVERY_SERVICE_HPP
#define APOENA_MSI_UMDF_RECOVERY_QUICKFIX_RECOVERY_SERVICE_HPP

#include <quickfix/Application.h>
#include <msi/umdf/recovery/recovery_export.hpp>
#include <msi/umdf/recovery/recovery_service.hpp>
#include <msi/umdf/recovery/fix44/messages.hpp>

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace recovery
{

class RECOVERY_Export quickfix_recovery_service
  : public recovery_service
  , public FIX::Application
{
public:
  virtual ~quickfix_recovery_service() {}
  virtual void connect() {}
  virtual void disconnect() {}
  virtual void request_recovery( const std::string& channel_id,
                                 seqnum_t first, seqnum_t last )
  {
    FIX::Message message;

    //TODO implement
    /*
    message.setField(FIX::ApplReqID(request_count_));
    message.setField(FIX::ApplReqType(type_retransmit));
    FIX::NoApplIDs requests;
    requests.setField(FIX::RefApplID(channel_id));
    requests.setField(FIX::ApplBegSeqNum(first));
    requests.setField(FIX::ApplEndSeqNum(last));
    message.addGroup(requests);

    FIX::Session::sendToTarget( message, session_id_ );
    */
  }

  //QuickFIX callbacks
  virtual void fromAdmin( const FIX::Message&, const FIX::SessionID& )
  throw( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon ) {}
  virtual void toAdmin( FIX::Message&, const FIX::SessionID& ) {}
  virtual void toApp( FIX::Message&, const FIX::SessionID& )
  throw( FIX::DoNotSend ) {}
  virtual void onLogon( const FIX::SessionID& sessionID ) {}
  virtual void onLogout( const FIX::SessionID& sessionID ) {}

  virtual void onCreate( const FIX::SessionID& sessionID )
  {
    session_id_ = sessionID;
  }

  void fromApp( const FIX::Message& message, const FIX::SessionID& sessionID )
  {
    const std::string& msgTypeValue
      = message.getHeader().getField( FIX::FIELD::MsgType );

    if ( msgTypeValue == "BX" )
    {
      handleRequestAck( message );
    }
    else if ( msgTypeValue == "BY" )
    {
      handleMessageReport( message );
    }
    else if ( msgTypeValue == "URDR" )
    {
      handleRawData( message );
    }
  }

  //TODO
  /*
  recovery_error get_error(const FIX::Message& message)
  {
      recovery_error error = recovery_error_unknown;

      FIX::NoApplIDs noApplIDsGroup;
      if (message.hasGroup(noApplIdsGroup))
      {
        message.getGroup(1, noApplIdsGroup);

        FIX::RefApplID refApplID;
        FIX::ApplResponseError err;
        noApplIdsGroup.get( refApplID );

      if ( noApplIdsGroup.isSet( err ) )
      {
        error = err.getValue();
      }
  }
  */

  void handleRequestAck( const FIX::Message& message )
  {
    FIX::ApplResponseType type;
    message.getField( type );

    //TODO implement
    /*
    if (type != type_accepted)
    {
      on_recovery_failed_(get_error(message));
    }
    */
  }

  void handleMessageReport( const FIX::Message& message )
  {
    FIX::ApplReportType report;
    message.getField( report );

    //TODO implement
    /*
    if (report.getValue() == success)
    {
      on_recovery_done_();
    }
    else
    {
      on_recovery_failed_(get_error(message));
    }
    */
  }

  void handleRawData( const FIX::Message& message )
  {
    FIX::RawData rawData;
    message.getField( rawData );

    FIX::ApplID applID;
    message.getField( applID );

    //TODO implement
    /*
    FIX::NoApplSeqNums noApplSeqNums;
    message.get( noApplSeqNums );

    const unsigned char* rawdata_ptr = reinterpret_cast<const_packet_t>( rawData.getString().c_str() );

    for ( int i=1; i <= noApplSeqNums; ++i )
    {
      FIX::RawDataLength innerRawDataLength;
      FIX::RawDataOffset rawDataOffset;
      FIX::ApplSeqNum applSeqNum;

      message.getGroup( i, noApplSeqNums );
      noApplSeqNums.get( innerRawDataLength );
      noApplSeqNums.get( rawDataOffset );
      noApplSeqNums.get( applSeqNum );

      Message msg;
      msg.no_chunks = 1;
      msg.current_chunk = 1;
      msg.seqnum = applSeqNum.getValue();
      msg.replace( rawdata_ptr + rawDataOffset.getValue(), innerRawDataLength.getValue() );

      on_recovery_data_( msg );
    }
    */
  }

private:
  FIX::SessionID session_id_;
  uint32_t request_count_;

};

} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_RECOVERY_QUICKFIX_RECOVERY_SERVICE_HPP */

