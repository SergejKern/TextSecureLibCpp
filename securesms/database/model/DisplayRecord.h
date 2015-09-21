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
    const unsigned char* body;
    const bool plaintext;

  public:
    Body(unsigned char* body, const bool plaintext) : plaintext(plaintext)
    {
      this->body = body;
    }

    bool IsPlaintext()
    {
      return this->plaintext;
    }

    const unsigned char* GetBody()
    {
      return body == NULL ? (const unsigned char*)"" : body;
    }
  };
protected:
  const OsIndependentContext* context;
  const long type;

private:
  const Recipients* recipients;
  const long dateSent;
  const long dateReceived;
  const long threadId;
  const Body* body;

public:
  DisplayRecord(OsIndependentContext* context, Body* body, Recipients* recipients, long dateSent, long dateReceived, long threadId, long type);
  const Body* GetBody();
  virtual char* GetDisplayBody() = 0;
  const Recipients* GetRecipients();
  long GetDateSent();
  long GetDateReceived();
  long GetThreadId();
  bool IsKeyExchange();
  bool IsEndSession();
  bool IsGroupUpdate();
  bool IsGroupQuit();
  bool IsGroupAction();
};
