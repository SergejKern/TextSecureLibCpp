#pragma once

// java.io.IOException
// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/io/IOException.java#IOException

// [ ] done
// TFS ID: none

#include "IOException.h"

//class IOException extends Exception{
class InvalidProtocolBufferException : public IOException
{
private:
  static const long serialVersionUID = -1616151763072450476L;
public:
  InvalidProtocolBufferException()
    : IOException()
  { }
  InvalidProtocolBufferException(OsIndependentString* message)
    : IOException(message)
  { }
  InvalidProtocolBufferException(OsIndependentString* message, Throwable* cause)
    : IOException(message, cause)
  { }
  InvalidProtocolBufferException(Throwable* cause)
    : IOException(cause)
  { }
};
