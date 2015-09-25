#pragma once
/*
Port of class TextSecureSyncMessage from TextSecure-android
*/

// [x] done
// TFS ID: 283

#include "..\TextSecureAttachment.h"
#include "..\TextSecureGroup.h"
#include "SentTranscriptMessage.h"
#include "RequestMessage.h"

class TextSecureSyncMessage
{
private:
  SentTranscriptMessage* sent;
  TextSecureAttachment* contacts;
  TextSecureAttachment* groups;
  RequestMessage* request;
private:
  TextSecureSyncMessage(SentTranscriptMessage* sent, TextSecureAttachment* contacts, TextSecureAttachment* groups, RequestMessage* request)
  {
    this->sent = sent;
    this->contacts = contacts;
    this->groups = groups;
    this->request = request;
  }
public:
  static TextSecureSyncMessage* ForSentTranscript(SentTranscriptMessage* sent)
  {
    return new TextSecureSyncMessage(sent, nullptr, nullptr, nullptr);
  }
  static TextSecureSyncMessage* ForContacts(TextSecureAttachment* contacts)
  {
    return new TextSecureSyncMessage(nullptr, contacts, nullptr, nullptr);
  }
  static TextSecureSyncMessage* ForGroups(TextSecureAttachment* groups)
  {
    return new TextSecureSyncMessage(nullptr, nullptr, groups, nullptr);
  }
  static TextSecureSyncMessage* ForRequest(RequestMessage* request)
  {
    return new TextSecureSyncMessage(nullptr, nullptr, nullptr, request);
  }
  static TextSecureSyncMessage* Empty()
  {
    return new TextSecureSyncMessage(nullptr, nullptr, nullptr, nullptr);
  }
  SentTranscriptMessage* GetSent() { return this->sent; }
  TextSecureAttachment* GetGroups() { return this->groups; }
  TextSecureAttachment* GetContacts() { return this->contacts; }
  RequestMessage* GetRequest() { return this->request; }
};
