#include "TextSecureAttachment.h"

TextSecureAttachment::TextSecureAttachment(unsigned char* contentType)
{
  this->contentType = contentType;
}
TextSecureAttachment::Builder::Builder() {}
TextSecureAttachment::Builder* TextSecureAttachment::Builder::WithStream(OsIndependentInputStream* inputStream)
{
  this->inputStream = inputStream;
  return this;
}
TextSecureAttachment::Builder* TextSecureAttachment::Builder::WithContentType(unsigned char* contentType)
{
  this->contentType = contentType;
  return this;
}
TextSecureAttachment::Builder* TextSecureAttachment::Builder::WithLength(long length)
{
  this->length = length;
  return this;
}
TextSecureAttachment::Builder* TextSecureAttachment::Builder::WithListener(ProgressListener* listener)
{
  this->listener = listener;
  return this;
}
TextSecureAttachmentStream* TextSecureAttachment::Builder::Build()
{
  // TODO if (inputStream == nullptr)
  //  throw new IllegalArgumentException("Must specify stream!");
  // TODO if (contentType == nullptr)
  //  throw new IllegalArgumentException("No content type specified!");
  // TODO if (length == 0)
  //  throw new IllegalArgumentException("No length specified!");

  return new TextSecureAttachmentStream(inputStream, contentType, length, listener);
}
unsigned char* TextSecureAttachment::GetContentType()
{
  return (unsigned char*)this->contentType;
}
TextSecureAttachmentStream* TextSecureAttachment::AsStream()
{
  return (TextSecureAttachmentStream*)this;
}

TextSecureAttachmentPointer* TextSecureAttachment::AsPointer()
{
  return (TextSecureAttachmentPointer*)this;
}

TextSecureAttachment::Builder* TextSecureAttachment::NewStreamBuilder()
{
  return new TextSecureAttachment::Builder();
}
