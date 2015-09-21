#include "OutgoingEncryptedMessage.h"

// [x] done
// TFS ID: 201

OutgoingEncryptedMessage::~OutgoingEncryptedMessage()
{
}

OutgoingEncryptedMessage::OutgoingEncryptedMessage(Recipients* recipients, unsigned char* body) : OutgoingTextMessage(recipients, body)
{
}

OutgoingEncryptedMessage::OutgoingEncryptedMessage(OutgoingEncryptedMessage* base, unsigned char* body) : OutgoingTextMessage(base, body)
{
}
//@Override
bool OutgoingEncryptedMessage::IsSecureMessage()
{
  return true;
}
//@Override
OutgoingTextMessage* OutgoingEncryptedMessage::WithBody(unsigned char* body)
{
  return new OutgoingEncryptedMessage(this, body);
}
