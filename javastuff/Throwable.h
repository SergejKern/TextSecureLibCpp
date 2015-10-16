#pragma once

// java.lang.Throwable
// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/6-b27/java/lang/Throwable.java#Throwable

// [ ] done
// TFS ID: none

#include "..\osindependent\OsIndependentString.h"

// public class Throwable implements Serializable {
class Throwable
{
private:
  OsIndependentString* detailMessage;
public:
  Throwable() {}
  Throwable(OsIndependentString* message) {}
  Throwable(OsIndependentString* message, Throwable* cause) {}
  Throwable(Throwable* cause) {}
  Throwable(OsIndependentString* message, Throwable cause, bool enableSuppression, bool writableStackTrace)
  { }
  virtual OsIndependentString* GetMessage()
  {
    return this->detailMessage;
  }
};

class Error : public Throwable
{
public:
  Error(Throwable* cause)
    : Throwable(cause)
  { }
};

class AssertionError : public Error
{
public:
  AssertionError(Throwable* cause)
    : Error(cause)
  { }
};
