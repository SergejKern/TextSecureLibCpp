#pragma once
/*
Port of class NoExternalStorageException from TextSecure-android
*/

// [x] done
// TFS ID: 477

#include "..\..\javastuff\Exception.h"

class NoExternalStorageException : Exception
{
public:
  NoExternalStorageException()
  {
  }
  NoExternalStorageException(unsigned char* detailMessage)
    : Exception(detailMessage)
  { }
  NoExternalStorageException(/*Throwable*/Exception* throwable)
    : Exception(throwable)
  { }
  NoExternalStorageException(unsigned char* detailMessage, /*Throwable*/Exception* throwable)
    : Exception(detailMessage, throwable)
  { }
};
