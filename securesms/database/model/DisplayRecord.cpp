#include "DisplayRecord.h"


public DisplayRecord(Context* context, Body* body, Recipients* recipients, long dateSent, long dateReceived, long threadId, long type)
{
  this->context = context.getApplicationContext();
  this->threadId = threadId;
  this->recipients = recipients;
  this->dateSent = dateSent;
  this->dateReceived = dateReceived;
  this->type = type;
  this->body = body;
}

public Body* GetBody() {
  return body;
}

public abstract SpannableString getDisplayBody();

public Recipients getRecipients() {
  return recipients;
}

public long getDateSent() {
  return dateSent;
}

public long getDateReceived() {
  return dateReceived;
}

public long getThreadId() {
  return threadId;
}

public boolean isKeyExchange() {
  return SmsDatabase.Types.isKeyExchangeType(type);
}

public boolean isEndSession() {
  return SmsDatabase.Types.isEndSessionType(type);
}

public boolean isGroupUpdate() {
  return SmsDatabase.Types.isGroupUpdate(type);
}

public boolean isGroupQuit() {
  return SmsDatabase.Types.isGroupQuit(type);
}

public boolean isGroupAction() {
  return isGroupUpdate() || isGroupQuit();
}


DisplayRecord::~DisplayRecord()
{
}
