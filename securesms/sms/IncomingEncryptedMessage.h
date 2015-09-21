#pragma once

/*
Port of IncomingEncryptedMessage.java from TextSecure-android
*/

// [x] done
// TFS ID: 192

#include "IncomingTextMessage.h"

class IncomingEncryptedMessage : IncomingTextMessage
{
public:
  IncomingEncryptedMessage(IncomingTextMessage* base, unsigned char* newBody) : IncomingTextMessage(base, newBody) { }

  //@Override
  IncomingTextMessage* WithMessageBody(unsigned char* body)
  {
    return new IncomingEncryptedMessage(this, body);
  }

  //@Override
  bool IsSecureMessage() { return true; }
};
