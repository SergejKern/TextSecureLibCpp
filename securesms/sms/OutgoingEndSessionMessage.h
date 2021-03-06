#pragma once

/*
Port of OutgoingEndSessionMessage from TextSecure-android
*/

// [x] done
// TFS ID: 202

#include "OutgoingTextMessage.h"
class OutgoingEndSessionMessage :
  public OutgoingTextMessage
{
public:
  virtual ~OutgoingEndSessionMessage();
  OutgoingEndSessionMessage(OutgoingTextMessage* base);
  OutgoingEndSessionMessage(OutgoingTextMessage* message, unsigned char* body);
  //@Override
  bool IsEndSession();
  //@Override
  OutgoingTextMessage* WithBody(unsigned char* body);
};
