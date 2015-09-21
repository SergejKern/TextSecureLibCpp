#pragma once

/*
Port of IncomingEndSessionMessage.java from TextSecure-android
*/

// [x] done
// TFS ID: 193

#include "IncomingTextMessage.h"

class IncomingEndSessionMessage : IncomingTextMessage
{
public:
  IncomingEndSessionMessage(IncomingTextMessage* base) : IncomingTextMessage(base, base->GetMessageBody()) { } { }
  IncomingEndSessionMessage(IncomingTextMessage* base, unsigned char* newBody) : IncomingTextMessage(base, newBody) { }
  //@Override
  IncomingEndSessionMessage* WithMessageBody(unsigned char* messageBody) {
    return new IncomingEndSessionMessage(this, messageBody);
  }
  //@Override
  bool IsEndSession() { return true; }
};
