#pragma once
/*
Port of class NoSuchMessageException from TextSecure-android
*/

// [x] done
// TFS ID: 478

#include "..\..\javastuff\Exception.h"

class NoSuchMessageException : Exception
{
public:
  NoSuchMessageException(unsigned char* s) 
    : Exception(s)
  {}
  NoSuchMessageException(Exception* e) 
    : Exception(e)
  {}
};
