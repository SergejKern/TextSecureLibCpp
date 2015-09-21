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
  OutgoingKeyExchangeMessage(OutgoingKeyExchangeMessage* base, unsigned char* body);
public:
  virtual ~OutgoingKeyExchangeMessage();
  OutgoingKeyExchangeMessage(Recipients* recipients, unsigned char* message);
  //@Override
  bool IsKeyExchange();
  //@Override
  OutgoingTextMessage* WithBody(unsigned char* body);
};
