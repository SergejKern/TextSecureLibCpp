#pragma once
/*
Port of class UnregisteredUserException from TextSecure-android
*/

// [x] done
// TFS ID: 296

#include "..\..\..\..\javastuff\Exception.h"
//import java.io.IOException;

class UnregisteredUserException /*extends IOException*/
  : public Exception
{
private:
  const unsigned char* e164number;
public:
  UnregisteredUserException(unsigned char* e164number, Exception* exception)
    : Exception(exception)
  {
    this->e164number = e164number;
  }
  const unsigned char* GetE164Number() { return this->e164number; }
};
