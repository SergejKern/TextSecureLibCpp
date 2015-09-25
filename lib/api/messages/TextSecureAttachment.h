#pragma once

/*
Port of TextSecureAttachment.java from libtextsecure-java
*/

// [x] done
// TFS ID: 265

#include "TextSecureAttachmentPointer.h"
#include "TextSecureAttachmentStream.h"

#include "..\..\..\osindependent\OsIndependentInputStream.h"

class TextSecureAttachment
{
private:
  const unsigned char* contentType;

protected:
  TextSecureAttachment(unsigned char* contentType)
  {
    this->contentType = contentType;
  }
public:
  /**
  * An interface to receive progress information on upload/download of
  * an attachment.
  */
  class ProgressListener
  {
    /**
    * Called on a progress change event.
    *
    * @param total The total amount to transmit/receive in bytes.
    * @param progress The amount that has been transmitted/received in bytes thus far
    */
  public:
    virtual void OnAttachmentProgress(long total, long progress) = 0;
  };
  class Builder
  {
  private:
    OsIndependentInputStream* inputStream;
    unsigned char* contentType;
    long length;
    ProgressListener* listener;
  public:
    Builder();
    Builder* WithStream(OsIndependentInputStream* inputStream);
    Builder* WithContentType(unsigned char* contentType);
    Builder* WithLength(long length);
    Builder* WithListener(ProgressListener* listener);
  public:
    TextSecureAttachmentStream* Build();
  };
public:
  unsigned char* GetContentType();
  virtual bool IsStream() = 0;
  virtual bool IsPointer() = 0;
  TextSecureAttachmentStream* AsStream();
  TextSecureAttachmentPointer* AsPointer();
  static Builder* NewStreamBuilder();
};
