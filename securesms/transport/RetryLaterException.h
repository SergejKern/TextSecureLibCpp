#pragma once
/*
Port of class RetryLaterException from TextSecure-android
*/

// [x] done
// TFS ID: 651

#include "..\..\javastuff\Exception.h"

class RetryLaterException : Exception
{
public:
  RetryLaterException(Exception e) : Exception(e) { }
};
