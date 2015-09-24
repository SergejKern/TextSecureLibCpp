#pragma once

/*
Port of TextSecureAttachmentPointer.java from libtextsecure-java
*/

// [x] done
// TFS ID: 266

#include "TextSecureAttachment.h"

/**
 * Represents a received TextSecureMessage attachment "handle."  This
 * is a pointer to the actual attachment content, which needs to be
 * retrieved using {@link org.whispersystems.textsecure.api.TextSecureMessageReceiver#retrieveAttachment(TextSecureAttachmentPointer, java.io.File)}
 *
 * @author Moxie Marlinspike
 */
class TextSecureAttachmentPointer : public TextSecureAttachment
{
private:
  const long id;
  const char* key;
  const unsigned char* relay;
  TextSecureAttachmentPointer(long id, unsigned char* contentType, char* key, unsigned char* relay)
    : TextSecureAttachment(contentType), id(id)
  {
    this->key = key;
    this->relay = relay;
  }
  long GetId() { return id; }
  char* GetKey() { return (char*)key; }
  //@Override
  bool IsStream() { return false; }
  //@Override
  bool IsPointer() { return true; }
  unsigned char* GetRelay() { return (unsigned char*)this->relay; }
};
