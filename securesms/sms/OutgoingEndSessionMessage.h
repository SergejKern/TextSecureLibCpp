#pragma once

/*
Port of OutgoingEndSessionMessage from TextSecure-android
*/

#include "OutgoingTextMessage.h"
class OutgoingEndSessionMessage :
  public OutgoingTextMessage
{
public:
  virtual ~OutgoingEndSessionMessage();
  OutgoingEndSessionMessage(OutgoingTextMessage* base);
  OutgoingEndSessionMessage(OutgoingTextMessage* message, char* body);
  //@Override
  bool IsEndSession();
  //@Override
  OutgoingTextMessage* WithBody(char* body);
};
