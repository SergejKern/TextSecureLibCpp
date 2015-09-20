#pragma once

/*
Port of SmsMessageRecord from TextSecure-android
*/

#include "MessageRecord.h"

// [ ] done
// TFS ID: 304

class SmsMessageRecord :
  public MessageRecord
{
public:
  virtual ~SmsMessageRecord();


  // TODO OS SPECIFIC
  SmsMessageRecord(/*Context*/ void* context, long id,
    Body* body, Recipients* recipients,
    Recipient* individualRecipient,
    int recipientDeviceId,
    long dateSent, long dateReceived,
    int receiptCount,
    long type, long threadId,
    int status, /*List<IdentityKeyMismatch> TODO */void* mismatches);

  long GetType() { return this->type; }

  //@Override
  /*SpannableString*/ unsigned char* GetDisplayBody();
  //@Override
  bool IsMms() { return false; }
  //@Override
  bool IsMmsNotification() { return false; }

  static int GetGenericDeliveryStatus(int status);
};
