#pragma once

/*
Port of BitmapDecodingException.java from TextSecure-android
*/

// [x] done
// TFS ID: 210

#include "..\..\javastuff\Exception.h"

class BitmapDecodingException : Exception
{
public:
  BitmapDecodingException(unsigned char* s) : Exception(s) { }
};
