#pragma once

/*
Port of OutgoingTextMessage from TextSecure-android
*/

// [x] done
// TFS ID: 205

#include "..\recipients\Recipients.h"
#include "..\database\model\SmsMessageRecord.h"

class OutgoingTextMessage
{
protected:
  Recipients* recipients;
  unsigned char* message;
  OutgoingTextMessage(OutgoingTextMessage* base);
public:
  OutgoingTextMessage(Recipients* recipients, unsigned char* message);
  OutgoingTextMessage(OutgoingTextMessage* base, unsigned char* body);
  virtual ~OutgoingTextMessage();
  unsigned char* GetMessageBody();
  Recipients* GetRecipients();
  bool IsKeyExchange();
  bool IsSecureMessage();
  bool IsEndSession();
  bool IsPreKeyBundle();
  static OutgoingTextMessage* From(SmsMessageRecord* record);
  OutgoingTextMessage* WithBody(unsigned char* body);
};
