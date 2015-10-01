#pragma once

// java.io.IOException
// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/io/IOException.java#IOException

// [x] done
// TFS ID: none

#include "Exception.h"

//class IOException extends Exception{
class IOException : public Exception
{
private:
  static const long serialVersionUID = 7818375828146090155L;
public:
  IOException() 
    : Exception() 
  { }
  IOException(OsIndependentString* message) 
    : Exception(message) 
  { }
  IOException(OsIndependentString* message, Throwable* cause) 
    : Exception(message, cause) 
  { }
  IOException(Throwable* cause) 
    : Exception(cause) 
  { }
};
