#include "MmsSmsColumns.h"

bool MmsSmsColumns::Types::IsDraftMessageType(long type)
{
  return (type & BASE_TYPE_MASK) == BASE_DRAFT_TYPE;
}

bool MmsSmsColumns::Types::IsFailedMessageType(long type)
{
  return (type & BASE_TYPE_MASK) == BASE_SENT_FAILED_TYPE;
}

bool MmsSmsColumns::Types::IsOutgoingMessageType(long type)
{
  // works with C++11
  for (long outgoingType : OUTGOING_MESSAGE_TYPES)
  {
    if ((type & BASE_TYPE_MASK) == outgoingType)
    {
      return true;
    }
  }
  return false;
}
bool MmsSmsColumns::Types::IsForcedSms(long type)
{
  return (type & MESSAGE_FORCE_SMS_BIT) != 0;
}
bool MmsSmsColumns::Types::IsPendingMessageType(long type)
{
  return
    (type & BASE_TYPE_MASK) == BASE_OUTBOX_TYPE ||
    (type & BASE_TYPE_MASK) == BASE_SENDING_TYPE;
}
bool MmsSmsColumns::Types::IsPendingSmsFallbackType(long type)
{
  return (type & BASE_TYPE_MASK) == BASE_PENDING_INSECURE_SMS_FALLBACK ||
    (type & BASE_TYPE_MASK) == BASE_PENDING_SECURE_SMS_FALLBACK;
}
bool MmsSmsColumns::Types::IsPendingSecureSmsFallbackType(long type)
{
  return (type & BASE_TYPE_MASK) == BASE_PENDING_SECURE_SMS_FALLBACK;
}
bool MmsSmsColumns::Types::IsPendingInsecureSmsFallbackType(long type)
{
  return (type & BASE_TYPE_MASK) == BASE_PENDING_INSECURE_SMS_FALLBACK;
}
bool MmsSmsColumns::Types::IsInboxType(long type)
{
  return (type & BASE_TYPE_MASK) == BASE_INBOX_TYPE;
}
bool MmsSmsColumns::Types::IsSecureType(long type)
{
  return (type & SECURE_MESSAGE_BIT) != 0;
}
bool MmsSmsColumns::Types::IsPushType(long type)
{
  return (type & PUSH_MESSAGE_BIT) != 0;
}
bool MmsSmsColumns::Types::IsEndSessionType(long type)
{
  return (type & END_SESSION_BIT) != 0;
}
bool MmsSmsColumns::Types::IsKeyExchangeType(long type)
{
  return (type & KEY_EXCHANGE_BIT) != 0;
}
bool MmsSmsColumns::Types::IsStaleKeyExchange(long type)
{
  return (type & KEY_EXCHANGE_STALE_BIT) != 0;
}
bool MmsSmsColumns::Types::IsProcessedKeyExchange(long type)
{
  return (type & KEY_EXCHANGE_PROCESSED_BIT) != 0;
}
bool MmsSmsColumns::Types::IsCorruptedKeyExchange(long type)
{
  return (type & KEY_EXCHANGE_CORRUPTED_BIT) != 0;
}
bool MmsSmsColumns::Types::IsInvalidVersionKeyExchange(long type)
{
  return (type & KEY_EXCHANGE_INVALID_VERSION_BIT) != 0;
}
bool MmsSmsColumns::Types::IsBundleKeyExchange(long type)
{
  return (type & KEY_EXCHANGE_BUNDLE_BIT) != 0;
}
bool MmsSmsColumns::Types::IsIdentityUpdate(long type)
{
  return (type & KEY_EXCHANGE_IDENTITY_UPDATE_BIT) != 0;
}
bool MmsSmsColumns::Types::IsGroupUpdate(long type)
{
  return (type & GROUP_UPDATE_BIT) != 0;
}
bool MmsSmsColumns::Types::IsGroupQuit(long type)
{
  return (type & GROUP_QUIT_BIT) != 0;
}
bool MmsSmsColumns::Types::IsSymmetricEncryption(long type)
{
  return (type & ENCRYPTION_SYMMETRIC_BIT) != 0;
}
bool MmsSmsColumns::Types::IsAsymmetricEncryption(long type)
{
  return (type & ENCRYPTION_ASYMMETRIC_BIT) != 0;
}
bool MmsSmsColumns::Types::IsFailedDecryptType(long type)
{
  return (type & ENCRYPTION_REMOTE_FAILED_BIT) != 0;
}
bool MmsSmsColumns::Types::IsDuplicateMessageType(long type)
{
  return (type & ENCRYPTION_REMOTE_DUPLICATE_BIT) != 0;
}
bool MmsSmsColumns::Types::IsDecryptInProgressType(long type)
{
  return (type & ENCRYPTION_ASYMMETRIC_BIT) != 0;
}
bool MmsSmsColumns::Types::IsNoRemoteSessionType(long type)
{
  return (type & ENCRYPTION_REMOTE_NO_SESSION_BIT) != 0;
}
bool MmsSmsColumns::Types::IsLegacyType(long type)
{
  return (type & ENCRYPTION_REMOTE_LEGACY_BIT) != 0 ||
    (type & ENCRYPTION_REMOTE_BIT) != 0;
}
long MmsSmsColumns::Types::TranslateFromSystemBaseType(long theirType)
{
  switch ((int)theirType)
  {
  case 1: return BASE_INBOX_TYPE;
  case 2: return BASE_SENT_TYPE;
  case 3: return BASE_DRAFT_TYPE;
  case 4: return BASE_OUTBOX_TYPE;
  case 5: return BASE_SENT_FAILED_TYPE;
  case 6: return BASE_OUTBOX_TYPE;
  }
  return BASE_INBOX_TYPE;
}
int MmsSmsColumns::Types::TranslateToSystemBaseType(long type)
{
  if (IsInboxType(type))
    return 1;
  else if (IsOutgoingMessageType(type))
    return 2;
  else if (IsFailedMessageType(type))
    return 5;
  return 1;
}
