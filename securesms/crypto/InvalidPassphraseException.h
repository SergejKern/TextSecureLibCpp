#pragma once

/*
Port of InvalidPassphraseException from TextSecure-android
*/

// [x] done
// TFS ID: 445

#include "..\..\javastuff\Exception.h"

class InvalidPassphraseException : public Exception
{
public:
  InvalidPassphraseException() : Exception() { }
  InvalidPassphraseException(OsIndependentString* detailMessage) : Exception(detailMessage) { }
  InvalidPassphraseException(Throwable* throwable) : Exception(throwable) { }
  InvalidPassphraseException(OsIndependentString* detailMessage, Throwable* throwable) : Exception(detailMessage, throwable) { }
};
