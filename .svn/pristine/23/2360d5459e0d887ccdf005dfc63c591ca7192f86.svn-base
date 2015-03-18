#ifndef APOENA_MSI_UMDF_RECOVERY_FIX44_APPLICATIONMESSAGEREQUEST_HPP
#define APOENA_MSI_UMDF_RECOVERY_FIX44_APPLICATIONMESSAGEREQUEST_HPP

#include <quickfix/fix44/Message.h>
#include <msi/umdf/recovery/fix44/fix_fields.hpp>

namespace FIX44
{

  class ApplicationMessageRequest : public Message
  {
  public:
    ApplicationMessageRequest() : Message(MsgType()) {}
    ApplicationMessageRequest(const FIX::Message& m) : Message(m) {}
    ApplicationMessageRequest(const Message& m) : Message(m) {}
    ApplicationMessageRequest(const ApplicationMessageRequest& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("BW"); }

    ApplicationMessageRequest(
      const FIX::ApplReqID& aApplReqID,
      const FIX::ApplReqType& aApplReqType )
    : Message(MsgType())
    {
      set(aApplReqID);
      set(aApplReqType);
    }

    FIELD_SET(*this, FIX::ApplReqID);
    FIELD_SET(*this, FIX::ApplReqType);
    FIELD_SET(*this, FIX::NoApplIDs);
    class NoApplIDs: public FIX::Group
    {
    public:
    NoApplIDs() : FIX::Group(1351,1355,FIX::message_order(1355,1182,1183,0)) {}
      FIELD_SET(*this, FIX::RefApplID);
      FIELD_SET(*this, FIX::ApplBegSeqNum);
      FIELD_SET(*this, FIX::ApplEndSeqNum);
    };
  };

}

#endif /* APOENA_MSI_UMDF_RECOVERY_FIX44_APPLICATIONMESSAGEREQUEST_HPP */

