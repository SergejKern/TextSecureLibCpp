#include "OutgoingKeyExchangeMessage.h"

// [x] done
// TFS ID: 203

OutgoingKeyExchangeMessage::OutgoingKeyExchangeMessage(OutgoingKeyExchangeMessage* base, unsigned char* body) : OutgoingTextMessage(base, body)
{
}
OutgoingKeyExchangeMessage::~OutgoingKeyExchangeMessage()
{
}
OutgoingKeyExchangeMessage::OutgoingKeyExchangeMessage(Recipients* recipients, unsigned char* message) : OutgoingTextMessage(recipients, message)
{
}
//@Override
bool OutgoingKeyExchangeMessage::IsKeyExchange()
{
  return true;
}
//@Override
OutgoingTextMessage* OutgoingKeyExchangeMessage::WithBody(unsigned char* body)
{
  return new OutgoingKeyExchangeMessage(this, body);
}
