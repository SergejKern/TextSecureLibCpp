#pragma once

/*
Port of OutgoingKeyExchangeMessage from TextSecure-android
*/

// [x] done
// TFS ID: 203

#include "OutgoingTextMessage.h"
class OutgoingKeyExchangeMessage :
  public OutgoingTextMessage
{
private:
  OutgoingKeyExchangeMessage(OutgoingKeyExchangeMessage* base, char* body);
public:
  virtual ~OutgoingKeyExchangeMessage();
  OutgoingKeyExchangeMessage(Recipients* recipients, char* message);
  //@Override
  bool IsKeyExchange();
  //@Override
  OutgoingTextMessage* WithBody(char* body);
};
