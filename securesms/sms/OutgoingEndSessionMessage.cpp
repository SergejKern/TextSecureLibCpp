#include "OutgoingEndSessionMessage.h"

// [x] done
// TFS ID: 

OutgoingEndSessionMessage::~OutgoingEndSessionMessage()
{
}
OutgoingEndSessionMessage::OutgoingEndSessionMessage(OutgoingTextMessage* base) : OutgoingTextMessage(base)
{
}
OutgoingEndSessionMessage::OutgoingEndSessionMessage(OutgoingTextMessage* message, char* body) : OutgoingTextMessage(message, body)
{
}
//@Override
bool OutgoingEndSessionMessage::IsEndSession()
{
  return true;
}
//@Override
OutgoingTextMessage* OutgoingEndSessionMessage::WithBody(char* body)
{
  return new OutgoingEndSessionMessage(this, body);
}
