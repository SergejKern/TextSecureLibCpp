#pragma once

#include "..\..\recipients\Recipients.h"
#include "..\..\..\osindependent\OsIndependentContext.h"

#if (_MSC_VER > 1500)
#define NULL nullptr
#endif

// [x] done
// TFS ID: 300

class DisplayRecord
{
public:
  virtual ~DisplayRecord();

public:
  static class Body
  {
  private:
    unsigned char* body;
    bool plaintext;

  public:
    Body(unsigned char* body, const bool plaintext) : plaintext(plaintext)
    {
      this->body = body;
    }

    bool IsPlaintext()
    {
      return this->plaintext;
    }

    unsigned char* GetBody()
    {
      return body == NULL ? (unsigned char*)"" : body;
    }
  };
protected:
  const OsIndependentContext* context;
  const long type;

private:
  Recipients* recipients;
  const long dateSent;
  const long dateReceived;
  const long threadId;
  Body* body;

public:
  DisplayRecord(OsIndependentContext* context, Body* body, Recipients* recipients, long dateSent, long dateReceived, long threadId, long type);
  Body* GetBody();
  virtual unsigned char* GetDisplayBody() = 0;
  Recipients* GetRecipients();
  long GetDateSent();
  long GetDateReceived();
  long GetThreadId();
  bool IsKeyExchange();
  bool IsEndSession();
  bool IsGroupUpdate();
  bool IsGroupQuit();
  bool IsGroupAction();
};
