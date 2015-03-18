#ifndef APOENA_MSI_UMDF_RECOVERY_FIX44_APPLICATIONRAWDATAREPORTING_HPP
#define APOENA_MSI_UMDF_RECOVERY_FIX44_APPLICATIONRAWDATAREPORTING_HPP

#include <quickfix/fix44/Message.h>
#include <msi/umdf/recovery/fix44/fix_fields.hpp>

namespace FIX44
{

	class ApplicationRawDataReporting : public Message
	{
	public:
		ApplicationRawDataReporting() : Message(MsgType()) {}
		ApplicationRawDataReporting(const FIX::Message& m) : Message(m) {}
		ApplicationRawDataReporting(const Message& m) : Message(m) {}
		ApplicationRawDataReporting(const ApplicationRawDataReporting& m) : Message(m) {}
		static FIX::MsgType MsgType() { return FIX::MsgType("URDR"); }

		ApplicationRawDataReporting(
			const FIX::ApplReqID& aApplReqID,
			const FIX::ApplResponseID& aApplResponseID,
			const FIX::ApplID& aApplID,
			const FIX::ApplResendFlag& aApplResendFlag,
			const FIX::RawDataLength& aRawDataLength,
			const FIX::RawData& aRawData,
			const FIX::TotNumReports& aTotNumReports)
			: Message(MsgType())
		{
			set(aApplReqID);
			set(aApplResponseID);
			set(aApplID);
			set(aApplResendFlag);
			set(aRawDataLength);
			set(aRawData);
			set(aTotNumReports);
		}

		FIELD_SET(*this, FIX::ApplResponseID);
		FIELD_SET(*this, FIX::ApplReqID);
		FIELD_SET(*this, FIX::ApplID);
		FIELD_SET(*this, FIX::ApplResendFlag);
		FIELD_SET(*this, FIX::RawDataLength);
		FIELD_SET(*this, FIX::RawData);
		FIELD_SET(*this, FIX::TotNumReports);
		FIELD_SET(*this, FIX::NoApplSeqNums);
		class NoApplSeqNums: public FIX::Group
		{
		public:
			NoApplSeqNums() : FIX::Group(10054,1181,FIX::message_order
(1181,1350,10055,95,0)) {}
			FIELD_SET(*this, FIX::ApplSeqNum);
			FIELD_SET(*this, FIX::ApplLastSeqNum);
			FIELD_SET(*this, FIX::RawDataOffset);
			FIELD_SET(*this, FIX::RawDataLength);
		};
	};
}

#endif /* APOENA_MSI_UMDF_RECOVERY_FIX44_APPLICATIONRAWDATAREPORTING_HPP */

