#include "SmsMessageRecord.h"

SmsMessageRecord::~SmsMessageRecord()
{
}
// TODO OS SPECIFIC
SmsMessageRecord::SmsMessageRecord(/*Context*/ void* context, long id,
  Body* body, Recipients* recipients,
  Recipient* individualRecipient,
  int recipientDeviceId,
  long dateSent, long dateReceived,
  int receiptCount,
  long type, long threadId,
  int status, /*List<IdentityKeyMismatch>*/ void* mismatches) : MessageRecord(context, id, body, recipients, individualRecipient, recipientDeviceId,
  dateSent, dateReceived, threadId, GetGenericDeliveryStatus(status), receiptCount, type,
  mismatches, /*new LinkedList<NetworkFailure>()*/ nullptr)
{
}

//@Override
/*SpannableString*/ unsigned char* SmsMessageRecord::GetDisplayBody() 
{
  /* TODO 
  if (SmsDatabase.Types.isFailedDecryptType(type))
  {
    return emphasisAdded(context.getString(R.string.MessageDisplayHelper_bad_encrypted_message));
  }
  else if (isProcessedKeyExchange()) {
    return new SpannableString("");
  }
  else if (isStaleKeyExchange()) {
    return emphasisAdded(context.getString(R.string.ConversationItem_error_received_stale_key_exchange_message));
  }
  else if (isCorruptedKeyExchange()) {
    return emphasisAdded(context.getString(R.string.SmsMessageRecord_received_corrupted_key_exchange_message));
  }
  else if (isInvalidVersionKeyExchange()) {
    return emphasisAdded(context.getString(R.string.SmsMessageRecord_received_key_exchange_message_for_invalid_protocol_version));
  }
  else if (MmsSmsColumns.Types.isLegacyType(type)) {
    return emphasisAdded(context.getString(R.string.MessageRecord_message_encrypted_with_a_legacy_protocol_version_that_is_no_longer_supported));
  }
  else if (isBundleKeyExchange()) {
    return emphasisAdded(context.getString(R.string.SmsMessageRecord_received_message_with_unknown_identity_key_click_to_process));
  }
  else if (isIdentityUpdate()) {
    return emphasisAdded(context.getString(R.string.SmsMessageRecord_received_updated_but_unknown_identity_information));
  }
  else if (isKeyExchange() && isOutgoing()) {
    return new SpannableString("");
  }
  else if (isKeyExchange() && !isOutgoing()) {
    return emphasisAdded(context.getString(R.string.ConversationItem_received_key_exchange_message_click_to_process));
  }
  else if (SmsDatabase.Types.isDuplicateMessageType(type)) {
    return emphasisAdded(context.getString(R.string.SmsMessageRecord_duplicate_message));
  }
  else if (SmsDatabase.Types.isDecryptInProgressType(type)) {
    return emphasisAdded(context.getString(R.string.MessageDisplayHelper_decrypting_please_wait));
  }
  else if (SmsDatabase.Types.isNoRemoteSessionType(type)) {
    return emphasisAdded(context.getString(R.string.MessageDisplayHelper_message_encrypted_for_non_existing_session));
  }
  else if (!getBody().isPlaintext()) {
    return emphasisAdded(context.getString(R.string.MessageNotifier_locked_message));
  }
  else if (SmsDatabase.Types.isEndSessionType(type)) {
    return emphasisAdded(context.getString(R.string.SmsMessageRecord_secure_session_ended));
  }
  else {
    return super.getDisplayBody();
  }
  */
  return nullptr;
}

int SmsMessageRecord::GetGenericDeliveryStatus(int status)
{
  if (status == SmsDatabase.Status.STATUS_NONE)
  {
    return MessageRecord::DELIVERY_STATUS_NONE;
  }
  else if (status >= SmsDatabase.Status.STATUS_FAILED)
  {
    return MessageRecord::DELIVERY_STATUS_FAILED;
  }
  else if (status >= SmsDatabase.Status.STATUS_PENDING)
  {
    return MessageRecord::DELIVERY_STATUS_PENDING;
  }
  else
  {
    return MessageRecord::DELIVERY_STATUS_RECEIVED;
  }
}
