#pragma once

/*
Port of OutgoingEncryptedMessage from TextSecure-android
*/

// [x] done
// TFS ID: 201

#include "OutgoingTextMessage.h"
class OutgoingEncryptedMessage :
  public OutgoingTextMessage
{
private:
  OutgoingEncryptedMessage(OutgoingEncryptedMessage* base, unsigned char* body);
public:
  virtual ~OutgoingEncryptedMessage();
  OutgoingEncryptedMessage(Recipients* recipients, unsigned char* body);
  //@Override
  bool IsSecureMessage();
  //@Override
  OutgoingTextMessage* WithBody(unsigned char* body);
};
