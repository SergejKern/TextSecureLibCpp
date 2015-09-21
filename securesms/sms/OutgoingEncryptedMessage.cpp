#include "OutgoingEncryptedMessage.h"

// [x] done
// TFS ID: 201

OutgoingEncryptedMessage::~OutgoingEncryptedMessage()
{
}

OutgoingEncryptedMessage::OutgoingEncryptedMessage(Recipients* recipients, char* body) : OutgoingTextMessage(recipients, body)
{
}

OutgoingEncryptedMessage::OutgoingEncryptedMessage(OutgoingEncryptedMessage* base, char* body) : OutgoingTextMessage(base, body)
{
}
//@Override
bool OutgoingEncryptedMessage::IsSecureMessage()
{
  return true;
}
//@Override
OutgoingTextMessage* OutgoingEncryptedMessage::WithBody(char* body)
{
  return new OutgoingEncryptedMessage(this, body);
}
