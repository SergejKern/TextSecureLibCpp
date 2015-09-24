#pragma once

/*
Port of TextSecureAttachmentStream.java from libtextsecure-java
*/

// [x] done
// TFS ID: 267

#include "TextSecureAttachment.h"

/**
 * Represents a local TextSecureAttachment to be sent.
 */
class TextSecureAttachmentStream : public TextSecureAttachment
{
private:
  OsIndependentInputStream* inputStream;
  const long length;
  ProgressListener* listener;

public:
  TextSecureAttachmentStream(OsIndependentInputStream* inputStream, unsigned char* contentType, long length, ProgressListener* listener)
    : TextSecureAttachment(contentType), length(length)
  {
    this->inputStream = inputStream;
    this->listener = listener;
  }
  //@Override
  bool IsStream() { return true; }
  //@Override
  bool IsPointer() { return false; }
  OsIndependentInputStream* GetInputStream() { return this->inputStream; }
  long GetLength() { return length; }

  ProgressListener* GetListener() { return this->listener; }
};
