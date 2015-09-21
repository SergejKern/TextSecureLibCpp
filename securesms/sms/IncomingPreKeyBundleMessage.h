#pragma once

/*
Port of IncomingPreKeyBundleMessage.java from TextSecure-android
*/

// [x] done
// TFS ID: 195

#include "IncomingTextMessage.h"

class IncomingPreKeyBundleMessage : IncomingTextMessage
{
public:
  IncomingPreKeyBundleMessage(IncomingTextMessage* base, unsigned char* newBody) : IncomingTextMessage(base, newBody) { }
  //@Override
  IncomingPreKeyBundleMessage* WithMessageBody(unsigned char* messageBody)
  {
    return new IncomingPreKeyBundleMessage(this, messageBody);
  }
  //@Override
  bool IsPreKeyBundle() { return true; }
};
