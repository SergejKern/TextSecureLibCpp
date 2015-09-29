#pragma once
/*
Port of class AccountVerificationTimeoutException from TextSecure-android
*/

// [x] done
// TFS ID: 637

#include "..\..\javastuff\Exception.h"
#include "..\..\osindependent\OsIndependentString.h"

class AccountVerificationTimeoutException : Exception
{
public:
  AccountVerificationTimeoutException()
    : Exception()
  { }
  AccountVerificationTimeoutException(OsIndependentString* detailMessage)
    : Exception(detailMessage)
  { }
  AccountVerificationTimeoutException(OsIndependentString* detailMessage, Throwable* throwable)
    : Exception(detailMessage, throwable)
  { }
  AccountVerificationTimeoutException(Throwable* throwable)
    : Exception(throwable)
  { }
};
