#include "DisplayRecord.h"
#include "..\SmsDatabase.h"

DisplayRecord::DisplayRecord(OsIndependentContext* context, Body* body, Recipients* recipients, long dateSent, long dateReceived, long threadId, long type)
  : type(type), dateSent(dateSent), dateReceived(dateReceived), threadId(threadId)
{
  this->context = context->GetApplicationContext();
  this->recipients = recipients;
  this->body = body;
}

const DisplayRecord::Body* DisplayRecord::GetBody()
{
  return this->body;
}

const Recipients* DisplayRecord::GetRecipients()
{
  return this->recipients;
}

long DisplayRecord::GetDateSent()
{
  return this->dateSent;
}

long DisplayRecord::GetDateReceived()
{
  return this->dateReceived;
}

long DisplayRecord::GetThreadId()
{
  return this->threadId;
}

bool DisplayRecord::IsKeyExchange()
{
  return SmsDatabase::Types::IsKeyExchangeType(type);
}

bool DisplayRecord::IsEndSession() {
  return SmsDatabase::Types::IsEndSessionType(type);
}

bool DisplayRecord::IsGroupUpdate()
{
  return SmsDatabase::Types::IsGroupUpdate(type);
}

bool DisplayRecord::IsGroupQuit()
{
  return SmsDatabase::Types::IsGroupQuit(type);
}

bool DisplayRecord::IsGroupAction()
{
  return IsGroupUpdate() || IsGroupQuit();
}

DisplayRecord::~DisplayRecord()
{
}
