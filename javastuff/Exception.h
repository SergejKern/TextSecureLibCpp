#pragma once

// java.util.concurrent.ExecutionException
// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/6-b27/java/lang/Exception.java#Exception

// [x] done
// TFS ID: none

#include "Throwable.h"

class Exception : public Throwable
{
private:
  static const long serialVersionUID = -3387516993124229948L;
public:
  Exception() 
    : Throwable() 
  { }
  Exception(unsigned char* message)
    : Throwable(message)
  { }
  Exception(unsigned char* message, Throwable* cause)
    : Throwable(message, cause)
  { }
  Exception(Throwable* cause)
    : Throwable(cause)
  { }
};
