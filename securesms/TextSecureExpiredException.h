#pragma once

/*
Port of TextSecureExpiredException.java from TextSecure-android
*/

// [x] done
// TFS ID: 748

#include "..\javastuff\Exception.h"

class TextSecureExpiredException : Exception
{
public:
  TextSecureExpiredException(OsIndependentString* message)
    : Exception(message)
  { }
};
