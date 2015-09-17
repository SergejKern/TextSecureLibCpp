#pragma once

/*
Port of OutgoingTextMessage from TextSecure-android
*/

#include "Recipients.h"
#include "SmsMessageRecord.h"

class OutgoingTextMessage
{
private:
  const Recipients recipients;
  const char* message;
public:
  OutgoingTextMessage(Recipients* recipients, char* message);
  OutgoingTextMessage(OutgoingTextMessage* base, char* body);
  virtual ~OutgoingTextMessage();
  char* GetMessageBody();
  Recipients* GetRecipients();
  bool IsKeyExchange();
  bool IsSecureMessage();
  bool IsEndSession();
  bool IsPreKeyBundle();
  static OutgoingTextMessage* From(SmsMessageRecord* record);
  OutgoingTextMessage* WithBody(char* body);
};
