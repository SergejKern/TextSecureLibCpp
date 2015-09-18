#pragma once

/*
Port of OutgoingEncryptedMessage from TextSecure-android
*/

#include "OutgoingTextMessage.h"
class OutgoingEncryptedMessage :
  public OutgoingTextMessage
{
public:
private:
  OutgoingEncryptedMessage(OutgoingEncryptedMessage* base, char* body);
public:
  virtual ~OutgoingEncryptedMessage();
  OutgoingEncryptedMessage(Recipients* recipients, char* body);
  //@Override
  bool IsSecureMessage();
  //@Override
  OutgoingTextMessage* WithBody(char* body);
};