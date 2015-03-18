#ifndef APOENA_MSI_UMDF_RECOVERY_FIX44_APPLICATIONMESSAGEREPORT_HPP
#define APOENA_MSI_UMDF_RECOVERY_FIX44_APPLICATIONMESSAGEREPORT_HPP

#include <quickfix/fix44/Message.h>
#include <msi/umdf/recovery/fix44/fix_fields.hpp>

namespace FIX44
{

  class ApplicationMessageReport : public Message
  {
  public:
    ApplicationMessageReport() : Message(MsgType()) {}
    ApplicationMessageReport(const FIX::Message& m) : Message(m) {}
    ApplicationMessageReport(const Message& m) : Message(m) {}
    ApplicationMessageReport(const ApplicationMessageReport& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("BY"); }

    ApplicationMessageReport(
      const FIX::ApplReportID& aApplReportID,
      const FIX::ApplReportType& aApplReportType,
	  const FIX::ApplReqType& aApplReqType,
	  const FIX::ApplReqID& aApplReqID,
	  const FIX::ApplResponseID& aApplResponseID)
    : Message(MsgType())
    {
      set(aApplReportID);
      set(aApplReportType);
	  set(aApplReqType);
	  set(aApplReqID);
	  set(aApplResponseID);
    }

    FIELD_SET(*this, FIX::ApplReportID);
    FIELD_SET(*this, FIX::ApplReportType);
	FIELD_SET(*this, FIX::ApplReqType);
	FIELD_SET(*this, FIX::ApplReqID);
	FIELD_SET(*this, FIX::ApplResponseID);

    FIELD_SET(*this, FIX::NoApplIDs);
    class NoApplIDs: public FIX::Group
    {
    public:
    NoApplIDs() : FIX::Group(1351,1355,FIX::message_order(1355,1350,1354,0)) {}
      FIELD_SET(*this, FIX::RefApplID);
      FIELD_SET(*this, FIX::RefApplLastSeqNum);
      FIELD_SET(*this, FIX::ApplResponseError);
    };
  };

}

#endif /* APOENA_MSI_UMDF_RECOVERY_FIX44_APPLICATIONMESSAGEREPORT_HPP */

