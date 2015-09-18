#include "OutgoingKeyExchangeMessage.h"


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
}
//@Override
OutgoingTextMessage* OutgoingKeyExchangeMessage::WithBody(char* body)
{
}
