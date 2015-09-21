#pragma once

/*
Port of OutgoingPrekeyBundleMessage from TextSecure-android
*/

// [x] done
// TFS ID: 204

#include "OutgoingTextMessage.h"

class OutgoingPrekeyBundleMessage : OutgoingTextMessage
{
public:
  OutgoingPrekeyBundleMessage(OutgoingTextMessage* message, unsigned char* body) : OutgoingTextMessage(message, body) { }

  //@Override
  bool IsPreKeyBundle() { return true; }

  //@Override
  OutgoingTextMessage* WithBody(unsigned char* body)
  {
    return new OutgoingPrekeyBundleMessage(this, body);
  }
};
