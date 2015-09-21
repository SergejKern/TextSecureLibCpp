#include "OutgoingKeyExchangeMessage.h"

// [x] done
// TFS ID: 203

OutgoingKeyExchangeMessage::OutgoingKeyExchangeMessage(OutgoingKeyExchangeMessage* base, char* body) : OutgoingTextMessage(base, body)
{
}
OutgoingKeyExchangeMessage::~OutgoingKeyExchangeMessage()
{
}
OutgoingKeyExchangeMessage::OutgoingKeyExchangeMessage(Recipients* recipients, char* message) : OutgoingTextMessage(recipients, message)
{
}
//@Override
bool OutgoingKeyExchangeMessage::IsKeyExchange()
{
  return true;
}
//@Override
OutgoingTextMessage* OutgoingKeyExchangeMessage::WithBody(char* body)
{
  return new OutgoingKeyExchangeMessage(this, body);
}
