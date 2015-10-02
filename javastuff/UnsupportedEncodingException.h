#pragma once

// java.io.IOException
// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/io/IOException.java#IOException

// [x] done
// TFS ID: none

#include "IOException.h"

//class UnsupportedEncodingException extends IOException{
class UnsupportedEncodingException : public IOException
{
private:
  static const long serialVersionUID = -4274276298326136670L;
public:
  UnsupportedEncodingException()
    : IOException()
  { }
  UnsupportedEncodingException(OsIndependentString* message)
    : IOException(message)
  { }
};
