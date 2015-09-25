#pragma once
/*
Port of class PushAttachmentData from TextSecure-android
*/

// [x] done
// TFS ID: 351

#include "..\..\api\messages\TextSecureAttachment.h"
#include "..\..\..\osindependent\OsIndependentInputStream.h"

class PushAttachmentData
{
private:
  const unsigned char* contentType;
  OsIndependentInputStream* data;
  const long dataSize;
  const char* key;
  TextSecureAttachment::ProgressListener* listener;

public:
  PushAttachmentData(unsigned char* contentType, OsIndependentInputStream* data, long dataSize, TextSecureAttachment::ProgressListener* listener, char* key)
    : dataSize(dataSize)
  {
    this->contentType = contentType;
    this->data = data;
    this->key = key;
    this->listener = listener;
  }
  unsigned char* GetContentType() { return (unsigned char*)this->contentType; }
  OsIndependentInputStream* GetData() { return this->data; }
  long GetDataSize() { return this->dataSize; }
  char* GetKey() { return (char*)this->key; }
  TextSecureAttachment::ProgressListener* GetListener() { return this->listener; }
};
