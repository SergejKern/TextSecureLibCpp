#pragma once
/*
Port of class InvalidNumberException from TextSecure-android
*/

// [x] done
// TFS ID: 298

#include "..\..\..\javastuff\Throwable.h"

class InvalidNumberException : Throwable
{
public:
  InvalidNumberException(unsigned char* s)
    : Throwable(s)
  { }
};
