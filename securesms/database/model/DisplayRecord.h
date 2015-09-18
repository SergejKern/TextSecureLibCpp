#pragma once

#include "Recipients.h"

class DisplayRecord
{
public:
  virtual ~DisplayRecord();

public:
  static class Body
  {
  private: 
    const char* body;
    const bool plaintext;

  public:
    Body(char* body, const bool plaintext) : plaintext(plaintext)
    {
      this->body = body;
    }

    bool IsPlaintext()
    {
      return this->plaintext;
    }

    char* GetBody()
    {
      return body == nullptr ? "" : body;
    }
  };
protected:
  //const Context* context;
  const void* context; // TODO
  const long type;

private:
  const Recipients* recipients;
  const long dateSent;
  const long dateReceived;
  const long threadId;
  const Body* body;

public:
  DisplayRecord(void* context, Body* body, Recipients* recipients, long dateSent, long dateReceived, long threadId, long type);
  Body* GetBody();
  virtual char* getDisplayBody() = 0;
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
