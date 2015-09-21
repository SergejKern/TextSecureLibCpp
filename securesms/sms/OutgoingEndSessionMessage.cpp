#include "OutgoingEndSessionMessage.h"

// [x] done
// TFS ID: 202

OutgoingEndSessionMessage::~OutgoingEndSessionMessage()
{
}
OutgoingEndSessionMessage::OutgoingEndSessionMessage(OutgoingTextMessage* base) : OutgoingTextMessage(base)
{
}
OutgoingEndSessionMessage::OutgoingEndSessionMessage(OutgoingTextMessage* message, unsigned char* body) : OutgoingTextMessage(message, body)
{
}
//@Override
bool OutgoingEndSessionMessage::IsEndSession()
{
  return true;
}
//@Override
OutgoingTextMessage* OutgoingEndSessionMessage::WithBody(unsigned char* body)
{
  return new OutgoingEndSessionMessage(this, body);
}
