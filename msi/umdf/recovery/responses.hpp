#ifndef APOENA_MSI_UMDF_RECOVERY_RESPONSES_HPP
#define APOENA_MSI_UMDF_RECOVERY_RESPONSES_HPP

namespace apoena
{
namespace msi
{
namespace umdf
{
namespace recovery
{

enum ApplRespType
{
  ApplRespType_Accepted = 0,
  ApplRespType_ChannelNotSpecified = 1,
  ApplRespType_RejectedOrPartial = 2,
  ApplRespType_AlreadyInProgress = 3,
  ApplRespType_MaxRangeExceeded = 4,
  ApplRespType_SystemTemporarilyUnavailable = 7
};

enum ApplRespError
{
  ApplRespError_None = -1,
  ApplRespError_InvalidChannel = 0,
  ApplRespError_MessagesNotAvailable = 1,
  ApplRespError_InvalidRange = 3,
  ApplRespError_MaxRangeExceeded = 4,
  ApplRespError_TopMessagesUAvailable = 5,
  ApplRespError_BottomMessagesUAvailable = 6,
  ApplRespError_TopAndBottomMessagesUnavailable = 7,
  ApplRespError_SystemUnavailable = 8
};

enum ApplReportType
{
  ApplReportType_Success = 3,
  ApplReportType_Error = 4
};


} //end of namespace
} //end of namespace
} //end of namespace
} //end of namespace

#endif /* APOENA_MSI_UMDF_RECOVERY_RESPONSES_HPP */

