#include "SmsMessageRecord.h"
#include "..\SmsDatabase.h"

SmsMessageRecord::~SmsMessageRecord()
{
}
SmsMessageRecord::SmsMessageRecord(OsIndependentContext* context, long id,
  Body* body, Recipients* recipients,
  Recipient* individualRecipient,
  int recipientDeviceId,
  long dateSent, long dateReceived,
  int receiptCount,
  long type, long threadId,
  int status, IdentityKeyMismatch* mismatches) : MessageRecord(context, id, body, recipients, individualRecipient, recipientDeviceId,
  dateSent, dateReceived, threadId, GetGenericDeliveryStatus(status), receiptCount, type,
  mismatches, nullptr)
{
}

//@Override
/*SpannableString*/ unsigned char* SmsMessageRecord::GetDisplayBody() 
{
  if (MmsSmsColumns::Types::IsFailedDecryptType(type))
  {
    // TODO return emphasisAdded(context.getString(R.string.MessageDisplayHelper_bad_encrypted_message));
  }
  else if (IsProcessedKeyExchange())
  {
    // TODO return new SpannableString("");
  }
  else if (IsStaleKeyExchange())
  {
    // TODO return emphasisAdded(context.getString(R.string.ConversationItem_error_received_stale_key_exchange_message));
  }
  else if (IsCorruptedKeyExchange())
  {
    // TODO return emphasisAdded(context.getString(R.string.SmsMessageRecord_received_corrupted_key_exchange_message));
  }
  else if (IsInvalidVersionKeyExchange())
  {
    // TODO return emphasisAdded(context.getString(R.string.SmsMessageRecord_received_key_exchange_message_for_invalid_protocol_version));
  }
  else if (MmsSmsColumns::Types::IsLegacyType(type))
  {
    // TODO return emphasisAdded(context.getString(R.string.MessageRecord_message_encrypted_with_a_legacy_protocol_version_that_is_no_longer_supported));
  }
  else if (IsBundleKeyExchange())
  {
    // TODO return emphasisAdded(context.getString(R.string.SmsMessageRecord_received_message_with_unknown_identity_key_click_to_process));
  }
  else if (IsIdentityUpdate())
  {
    // TODO return emphasisAdded(context.getString(R.string.SmsMessageRecord_received_updated_but_unknown_identity_information));
  }
  else if (IsKeyExchange() && IsOutgoing())
  {
    // TODO return new SpannableString("");
  }
  else if (IsKeyExchange() && !IsOutgoing())
  {
    // TODO return emphasisAdded(context.getString(R.string.ConversationItem_received_key_exchange_message_click_to_process));
  }
  else if (MmsSmsColumns::Types::IsDuplicateMessageType(type))
  {
    // TODO return emphasisAdded(context.getString(R.string.SmsMessageRecord_duplicate_message));
  }
  else if (MmsSmsColumns::Types::IsDecryptInProgressType(type))
  {
    // TODO return emphasisAdded(context.getString(R.string.MessageDisplayHelper_decrypting_please_wait));
  }
  else if (MmsSmsColumns::Types::IsNoRemoteSessionType(type))
  {
    // TODO return emphasisAdded(context.getString(R.string.MessageDisplayHelper_message_encrypted_for_non_existing_session));
  }
  else if (!GetBody()->IsPlaintext())
  {
    // TODO return emphasisAdded(context.getString(R.string.MessageNotifier_locked_message));
  }
  else if (MmsSmsColumns::Types::IsEndSessionType(type))
  {
    // TODO return emphasisAdded(context.getString(R.string.SmsMessageRecord_secure_session_ended));
  }
  else
  {
    // TODO return super.getDisplayBody();
  }
  return nullptr;
}

int SmsMessageRecord::GetGenericDeliveryStatus(int status)
{
  if (status == SmsDatabase::Status::STATUS_NONE)
  {
    return MessageRecord::DELIVERY_STATUS_NONE;
  }
  else if (status >= SmsDatabase::Status::STATUS_FAILED)
  {
    return MessageRecord::DELIVERY_STATUS_FAILED;
  }
  else if (status >= SmsDatabase::Status::STATUS_PENDING)
  {
    return MessageRecord::DELIVERY_STATUS_PENDING;
  }
  else
  {
    return MessageRecord::DELIVERY_STATUS_RECEIVED;
  }
}
