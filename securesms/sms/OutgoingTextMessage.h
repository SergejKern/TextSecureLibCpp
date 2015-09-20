#pragma once

/*
Port of OutgoingTextMessage from TextSecure-android
*/

// [ ] done
// TFS ID: 205

#include "..\recipients\Recipients.h"
#include "..\database\model\SmsMessageRecord.h"

class OutgoingTextMessage
{
protected:
  const Recipients* recipients;
  const char* message;
  OutgoingTextMessage(OutgoingTextMessage* base);
public:
  OutgoingTextMessage(Recipients* recipients, char* message);
  OutgoingTextMessage(OutgoingTextMessage* base, char* body);
  virtual ~OutgoingTextMessage();
  const char* GetMessageBody();
  const Recipients* GetRecipients();
  bool IsKeyExchange();
  bool IsSecureMessage();
  bool IsEndSession();
  bool IsPreKeyBundle();
  static OutgoingTextMessage* From(SmsMessageRecord* record);
  OutgoingTextMessage* WithBody(char* body);
};
