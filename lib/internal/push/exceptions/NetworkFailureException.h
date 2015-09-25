#pragma once
/*
Port of class NetworkFailureException from TextSecure-android
*/

// [x] done
// TFS ID: 291

#include "..\..\..\..\javastuff\Exception.h"

class NetworkFailureException : public Exception
{
private:
  const unsigned char* e164number;
public:
  NetworkFailureException(unsigned char* e164number, Exception* nested)
    : Exception(nested)
  {
    this->e164number = e164number;
  }
  const unsigned char* GetE164number() 
  {
    return this->e164number;
  }
};
