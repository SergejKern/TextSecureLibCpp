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
  Exception(OsIndependentString* message)
    : Throwable(message)
  { }
  Exception(OsIndependentString* message, Throwable* cause)
    : Throwable(message, cause)
  { }
  Exception(Throwable* cause)
    : Throwable(cause)
  { }
  Exception(OsIndependentString* message, Throwable cause, bool enableSuppression, bool writableStackTrace)
    : Throwable(message, cause, enableSuppression, writableStackTrace)
  { }
};

//  java.lang.RuntimeException
class RuntimeException : public Exception
{
public:
  RuntimeException()
    : Exception()
  { }
  RuntimeException(OsIndependentString* message)
    : Exception(message)
  { }
  RuntimeException(OsIndependentString* message, Throwable* cause)
    : Exception(message, cause)
  { }
  RuntimeException(Throwable* cause)
    : Exception(cause)
  { }
  RuntimeException(OsIndependentString* message, Throwable cause, bool enableSuppression, bool writableStackTrace)
    : Exception(message, cause, enableSuppression, writableStackTrace)
  { }
};

// java.lang.IllegalArgumentException
class IllegalArgumentException : public RuntimeException
{
public:
  IllegalArgumentException()
    : RuntimeException()
  { }
  IllegalArgumentException(OsIndependentString* message)
    : RuntimeException(message)
  { }
  IllegalArgumentException(OsIndependentString* message, Throwable* cause)
    : RuntimeException(message, cause)
  { }
  IllegalArgumentException(Throwable* cause)
    : RuntimeException(cause)
  { }
  IllegalArgumentException(OsIndependentString* message, Throwable cause, bool enableSuppression, bool writableStackTrace)
    : RuntimeException(message, cause, enableSuppression, writableStackTrace)
  { }
};

class NotImplementedException : public RuntimeException
{
public:
  NotImplementedException()
    : RuntimeException()
  { }
  NotImplementedException(OsIndependentString* message)
    : RuntimeException(message)
  { }
};
