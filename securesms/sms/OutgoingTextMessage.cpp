/*
Port of OutgoingTextMessage from TextSecure-android
*/

// [x] done
// TFS ID: 

#include "OutgoingTextMessage.h"
#include "OutgoingEncryptedMessage.h"
#include "OutgoingEndSessionMessage.h"
#include "OutgoingKeyExchangeMessage.h"

OutgoingTextMessage::OutgoingTextMessage(Recipients* recipients, char* message)
{
  this->recipients = recipients;
  this->message = message;
}

OutgoingTextMessage::OutgoingTextMessage(OutgoingTextMessage* base, char* body)
{
  this->recipients = base->GetRecipients();
  this->message = body;
}

OutgoingTextMessage::OutgoingTextMessage(OutgoingTextMessage* base)
{
  this->recipients = base->GetRecipients();
  this->message = base->GetMessageBody();
}

const char* OutgoingTextMessage::GetMessageBody()
{
  return this->message;
}

const Recipients* OutgoingTextMessage::GetRecipients()
{
  return this->recipients;
}

bool OutgoingTextMessage::IsKeyExchange()
{
  return false;
}

bool OutgoingTextMessage::IsSecureMessage()
{
  return false;
}

bool OutgoingTextMessage::IsEndSession()
{
  return false;
}

bool OutgoingTextMessage::IsPreKeyBundle()
{
  return false;
}

OutgoingTextMessage* OutgoingTextMessage::From(SmsMessageRecord* record)
{
  if (record->IsSecure())
  {
    return new OutgoingEncryptedMessage(record->GetRecipients(), record->GetBody()->GetBody());
  }
  else if (record->IsKeyExchange())
  {
    return new OutgoingKeyExchangeMessage(record->GetRecipients(), record->GetBody()->GetBody());
  }
  else if (record->IsEndSession())
  {
    return new OutgoingEndSessionMessage(new OutgoingTextMessage(record->GetRecipients(), record->GetBody()->GetBody()));
  }
  else
  {
    return new OutgoingTextMessage(record->GetRecipients(), record->GetBody()->GetBody());
  }
}

OutgoingTextMessage* OutgoingTextMessage::WithBody(char* body)
{
  return new OutgoingTextMessage(this, body);
}

OutgoingTextMessage::~OutgoingTextMessage()
{
}
