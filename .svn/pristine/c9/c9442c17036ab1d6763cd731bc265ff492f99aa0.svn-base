#ifndef APOENA_MSI_UMDF_RECOVERY_FIX44_APPLICATIONMESSAGEREQUESTACK_HPP
#define APOENA_MSI_UMDF_RECOVERY_FIX44_APPLICATIONMESSAGEREQUESTACK_HPP

#include <quickfix/fix44/Message.h>
#include <msi/umdf/recovery/fix44/fix_fields.hpp>

namespace FIX44
{

  class ApplicationMessageRequestAck : public Message
  {
  public:
    ApplicationMessageRequestAck() : Message(MsgType()) {}
    ApplicationMessageRequestAck(const FIX::Message& m) : Message(m) {}
    ApplicationMessageRequestAck(const Message& m) : Message(m) {}
    ApplicationMessageRequestAck(const ApplicationMessageRequestAck& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("BX"); }

    ApplicationMessageRequestAck(
      const FIX::ApplResponseID& aApplResponseID,
	  const FIX::ApplReqID& aApplReqID,
	  const FIX::ApplReqType& aApplReqType,
	  const FIX::ApplResponseType& aApplResponseType)
    : Message(MsgType())
    {
      set(aApplResponseID);
	  set(aApplReqID);
	  set(aApplReqType);
	  set(aApplResponseType);
    }

    FIELD_SET(*this, FIX::ApplResponseID);
    FIELD_SET(*this, FIX::ApplReqID);
    FIELD_SET(*this, FIX::ApplReqType);
    FIELD_SET(*this, FIX::ApplResponseType);
    
    FIELD_SET(*this, FIX::NoApplIDs);
    class NoApplIDs: public FIX::Group
    {
    public:
    NoApplIDs() : FIX::Group(1351,1355,FIX::message_order(1355,1182,1183,1354,0)) {}
      FIELD_SET(*this, FIX::RefApplID);
      FIELD_SET(*this, FIX::ApplBegSeqNum);
      FIELD_SET(*this, FIX::ApplEndSeqNum);
      FIELD_SET(*this, FIX::ApplResponseError);
     
    };
  };

}

#endif /* APOENA_MSI_UMDF_RECOVERY_FIX44_APPLICATIONMESSAGEREQUESTACK_HPP */

