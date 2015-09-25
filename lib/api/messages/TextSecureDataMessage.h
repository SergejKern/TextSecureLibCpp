#pragma once
/*
Port of class TextSecureDataMessage from TextSecure-android
*/

// [x] done
// TFS ID: 269

#include "TextSecureAttachment.h"
#include "TextSecureGroup.h"
#include "..\..\..\owntemplates\List.h"
#include "..\..\..\osindependent\OsIndependentSystem.h"

/**
 * Represents a decrypted text secure message.
 */
class TextSecureDataMessage
{
public:
  class Builder
  {
  private:
    List<TextSecureAttachment*>* attachments = new LinkedList<TextSecureAttachment*>();
    long timestamp;
    TextSecureGroup* group;
    unsigned char* body;
    bool endSession;
  public:
    Builder() {}
    Builder* WithTimestamp(long timestamp)
    {
      this->timestamp = timestamp;
      return this;
    }
    Builder* AsGroupMessage(TextSecureGroup* group)
    {
      this->group = group;
      return this;
    }
    Builder* WithAttachment(TextSecureAttachment* attachment)
    {
      this->attachments->Add(attachment);
      return this;
    }
    Builder* WithAttachments(List<TextSecureAttachment*>* attachments)
    {
      this->attachments->AddAll(attachments);
      return this;
    }
    Builder* WithBody(unsigned char* body)
    {
      this->body = body;
      return this;
    }
    Builder* AsEndSessionMessage()
    {
      this->endSession = true;
      return this;
    }
    Builder* AsEndSessionMessage(bool endSession)
    {
      this->endSession = endSession;
      return this;
    }
    TextSecureDataMessage* Build()
    {
      if (this->timestamp == 0)
        this->timestamp = OsIndependentSystem::CurrentTimeMillis();
      return new TextSecureDataMessage(this->timestamp, this->group, this->attachments, this->body, this->endSession);
    }
  };
private:
  const long timestamp;
  List<TextSecureAttachment*>* attachments;
  const unsigned char* body;
  TextSecureGroup* group;
  const bool endSession;
public:
  /**
   * Construct a TextSecureMessage with a body and no attachments.
   *
   * @param timestamp The sent timestamp.
   * @param body The message contents.
   */
  TextSecureDataMessage(long timestamp, unsigned char* body)
    : timestamp(timestamp), endSession(false)
  {
    this->body = body;
  }
  TextSecureDataMessage(long timestamp, TextSecureAttachment* attachment, unsigned char* body)
    : timestamp(timestamp), endSession(false)
  {
    this->body = body;
    this->attachments->Add(attachment);
  }
  /**
   * Construct a TextSecureMessage with a body and list of attachments.
   *
   * @param timestamp The sent timestamp.
   * @param attachments The attachments.
   * @param body The message contents.
   */
  TextSecureDataMessage(long timestamp, List<TextSecureAttachment*>* attachments, unsigned char* body)
    : timestamp(timestamp), endSession(false)
  {
    this->body = body;
    this->attachments = attachments;
  }
  /**
   * Construct a TextSecure group message with attachments and body.
   *
   * @param timestamp The sent timestamp.
   * @param group The group information.
   * @param attachments The attachments.
   * @param body The message contents.
   */
  TextSecureDataMessage(long timestamp, TextSecureGroup* group, List<TextSecureAttachment*>* attachments, unsigned char* body)
    : timestamp(timestamp), endSession(false)
  {
    this->body = body;
    this->attachments = attachments;
    this->group = group;
  }
  /**
   * Construct a TextSecureMessage.
   *
   * @param timestamp The sent timestamp.
   * @param group The group information (or null if none).
   * @param attachments The attachments (or null if none).
   * @param body The message contents.
   * @param endSession Flag indicating whether this message should close a session.
   */
  TextSecureDataMessage(long timestamp, TextSecureGroup* group, List<TextSecureAttachment*>* attachments, unsigned char* body, bool endSession)
    : timestamp(timestamp), endSession(endSession)
  {
    this->body = body;
    this->group = group;
    this->attachments = attachments;
  }
  static Builder* NewBuilder()
  {
    return new Builder();
  }
  /**
   * @return The message timestamp.
   */
  long GetTimestamp() { return this->timestamp; }
  /**
   * @return The message attachments (if any).
   */
  List<TextSecureAttachment*>* GetAttachments() { return this->attachments; }
  /**
   * @return The message body (if any).
   */
  unsigned char* GetBody() { return (unsigned char*)this->body; }
  /**
   * @return The message group info (if any).
   */
  TextSecureGroup* GetGroupInfo() { return this->group; }
  bool IsEndSession() { return this->endSession; }
  bool IsGroupUpdate()
  {
    return this->group != nullptr && this->group->GetType() != Type::DELIVER;
  }
};
