#pragma once

/*
Port of OutgoingKeyExchangeMessage from TextSecure-android
*/

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
